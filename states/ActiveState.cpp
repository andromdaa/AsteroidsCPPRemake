//
// Created by Cole on 4/21/2022.
//

#include "ActiveState.h"
#include "EndState.h"
#include "../util/Util.h"

using namespace sf;

ActiveState::ActiveState(sf::RenderWindow &window, GameManager &gameManager) :
        GameState(window, gameManager),
        player(gameManager.getPlayer()),
        resourceManager(gameManager.getResourceManager()),
        asteroidManager(gameManager.getAsteroidManager()),
        projectileManager(gameManager.getProjectileManager()),
        window(gameManager.getWindow()) {
    resourceManager.text.setCharacterSize(24);
    asteroidManager.createAsteroids();
}

std::shared_ptr<ActiveState> ActiveState::Instance(sf::RenderWindow &window, GameManager &gameManager) {
    static std::shared_ptr<ActiveState> self;
    if (self == nullptr) {
        auto p = new ActiveState(window, gameManager);
        self = std::shared_ptr<ActiveState>(p);
    }
    return self;
}

void ActiveState::handleInput() {
    if (player.leftRotationSpeed <= player.LOWER_ROTATION_BOUND) player.leftRotationSpeed = player.LOWER_ROTATION_BOUND;
    else if (player.rightRotationSpeed >= player.UPPER_ROTATION_BOUND)
        player.rightRotationSpeed = player.UPPER_ROTATION_BOUND;

    if (player.speed >= player.UPPER_SPEED_BOUND) player.speed = player.UPPER_SPEED_BOUND;
    if (player.speed <= player.LOWER_SPEED_BOUND) player.speed = player.LOWER_SPEED_BOUND;

    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.leftRotationSpeed -= player.ROTATION_INC;
        player.rotate(player.leftRotationSpeed);
    } else if (player.leftRotationSpeed < 0 && !Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.leftRotationSpeed += .25f;
        player.rotate(player.leftRotationSpeed);
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.rightRotationSpeed += player.ROTATION_INC;
        player.rotate(player.rightRotationSpeed);
    } else if (player.rightRotationSpeed > 0 && !Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.rightRotationSpeed -= .25f;
        player.rotate(player.rightRotationSpeed);
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.speed += player.SPEED_INC;
        player.updatePlayerPos(gameManager.getDelta());
    }

    if (!Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (player.speed > 0) player.speed -= 2.5f; //passively slow down the player, approach 0
        if (player.speed < 0) player.speed += 1.f; //if player is bounced off wall, passively approach 0 speed
        player.updatePlayerPos(gameManager.getDelta());
    } else {
        player.speed -= 0.50f; //actively slow player
        player.updatePlayerPos(gameManager.getDelta());
    }

    gameManager.getParticleSystem().setEmitter(player.getPosition());
}

sf::Vector2f ActiveState::getMovement(const sf::Shape &shape, float speed, double dt) {
    auto x = (float) (speed * sin(shape.getRotation() * (float) M_PI / 180) *
                      dt);
    auto y = (float) (-speed * cos(shape.getRotation() * (float) M_PI / 180) *
                      dt);

    return {x, y};
}


bool ActiveState::locationAllowed(float x, float y, sf::Vector2f movementInc, float radius) {
    if ((x + movementInc.x) + radius > GameManager::getWidth() || (x + movementInc.x) < radius) return false;
    if ((y + movementInc.y) + radius > GameManager::getHeight() || (y + movementInc.y) < radius) return false;
    return true;
}

void ActiveState::handleEvents() {
    sf::Event event{};
    window.pollEvent(event);
    bool collision = Util::checkPlayerCollision(player, gameManager.getAsteroidManager());

    //if player is colliding and was previously not colliding
    if (collision && !player.isColliding) {
        player.isColliding = true;
        int lives = player.healthSystem.decreaseLives();
        if (lives <= 0) transitionState(&gameManager);
    } else if (!collision && player.isColliding) {
        player.isColliding = false;
    }

    if (event.key.code == sf::Keyboard::Escape) {
        window.close();
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
        if (!isActive) {
            isActive = true;
            return;
        }
        gameManager.getProjectileManager().spawnProjectile(player);
        if (gameManager.enableAudio) gameManager.getResourceManager().playFireSound();
    }
}

void ActiveState::tickState() {
    GameState::tickState();
    handleEvents();
    handleInput();
}

void ActiveState::renderState() {
    window.draw(gameManager.getParticleSystem());
    player.drawPlayerElements(window);
    projectileManager.drawAll(window);
    asteroidManager.drawAll(window);
}

void ActiveState::transitionState(GameManager *g) {
    changeState(g, EndState::Instance(window, gameManager));
    isActive = false;
}

void ActiveState::reset() {
    player.reset();
    gameManager.getParticleSystem().reset();
    window.clear();
    projectileManager.reset();
    asteroidManager.reset();
    GameManager::score = 0;
}






