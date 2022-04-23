#include <iostream>
#include <cmath>
//#include <SFML/Audio.hpp>
#include <list>
#include "GameManager.h"
#include "SFML/Audio/AlResource.hpp"
//
//std::list<sf::ConvexShape> collidables;
//
//
//struct twoFloats {
//    float x;
//    float y;
//};

//struct pollEventArgs { //transition this into class with custom constructor
//    sf::Window *window = nullptr;
//    float dt = 0;
//    float speed = 0;
//    float rotationSpeed = 0;
//} args;


//enum class Sizes {
//    SM, MED, LRG
//};
//
//sf::CircleShape getPlayer();
//
//void pollEvents(pollEventArgs &args, sf::CircleShape &player, sf::Sound& sound);
//
//bool locationAllowed(float x, float y, float radius, const sf::ConvexShape *collide = nullptr);
//
//void playerInputMovement(float &speed, float &dt, sf::CircleShape &player);
//
//twoFloats getSpeeds(float speed, float dt, const sf::Shape &loc);
//
//sf::CircleShape *drawProjectile(sf::RenderWindow &window, std::list<sf::CircleShape>::iterator it);
//
//void spawnCollide(int xSize, int ySize);

int main() {
    GameManager gameManger;
    GameManager::resourceManager->startMusic();

    while(gameManger.window.isOpen()) {
        gameManger.tick();
        gameManger.eventHandler.handle();
        gameManger.player.processInput(&gameManger.player);

        gameManger.window.clear();

        gameManger.window.draw(gameManger.player);

        gameManger.window.display();
    }


    return 0;
}

//    args.window = &window;

//    spawnCollide(window.getSize().x, window.getSize().y);



//    while(window.isOpen()) {
//        EventHandler::handle(window);
//
//        bool up, down, left, right, space; //key states
//        up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
//        down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
//        left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
//        right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
////        space = ((event.type == sf::Event::KeyReleased)
////                 && (event.key.code == sf::Keyboard::Space));
//
//        if (left) {
//            player.processInput(&player, Keys::Left);
//        }
//
//        if (right) {
//            player.processInput(&player, Keys::Right);
//        }
//
//        window.clear();
//        window.draw(score);
//        window.draw(player);
//        window.display();
//
//    }




//    while (window.isOpen()) {
//        time = deltaClock.restart();
//        args.dt = time.asSeconds();
//
//        //event polling, to update what is to be rendered next
//        pollEvents(args, player, sound);
//
//        //render things
//        window.clear();
//        window.draw(score);
//        window.draw(player);
//
//        auto it = projectiles.begin();
//        auto itConvex = collidables.begin();
//
//        while (itConvex != collidables.end()) {
//            window.draw(*itConvex);
//            itConvex++;
//        }
//
//        itConvex = collidables.begin();
//        while (it != projectiles.end()) {
//            sf::CircleShape *temp = drawProjectile(window, it);
//            if (temp != nullptr) {
//                while (itConvex != collidables.end()) {
//                    sf::ConvexShape tempC = *itConvex;
//                    sf::FloatRect bounds = tempC.getGlobalBounds();
//                    window.draw(tempC);
//
//                    if (temp->getGlobalBounds().intersects(sf::FloatRect(
//                            bounds.left - 5, bounds.top - 10, bounds.width - 5, bounds.height - 5))) //reverse this
//                    {
//                        score.setString("Score  " + std::to_string(scoreVal += (int) ((100 * tempC.getScale().x) + (75 * tempC.getScale().y))));
//                        collidables.erase(itConvex++);
//                        projectiles.erase(it++);
//                    } else {
//                        itConvex++;
//                    }
//                }
//                it++;
//            } else {
//                projectiles.erase(it++);
//            }
//        }
//
//        window.display();
//    }


//bool locationAllowed(float x, float y, float radius) {
//    if (x + radius > WIDTH || x < 0 + radius) { //window out of bounds
//        return false;
//    }
//    if (y + radius > HEIGHT || y < 0 + radius) { //window out of bounds
//        return false;
//    }
//
//    return true;
//}
//
//void playerInputMovement(float &speed, float &dt, sf::CircleShape &player) {
//    float radius = player.getRadius();
//    float playerX = player.getPosition().x;
//    float playerY = player.getPosition().y;
//
//    twoFloats speeds = getSpeeds(speed, dt, player);
//    if (locationAllowed(playerX + speeds.x, playerY + speeds.y, radius)) {
//        player.move(speeds.x, speeds.y);
//    } else {
//        speed = -speed;
//    }
//}
//
//twoFloats getSpeeds(float speed, float dt, const sf::Shape &loc) {
//
//    float x = (speed * sin(loc.getRotation() * (float) PI / 180) *
//               dt);
//    float y = (-speed * cos(loc.getRotation() * (float) PI / 180) *
//               dt);
//
//    return {
//            x,
//            y
//    };
//}
//
//sf::CircleShape *drawProjectile(sf::RenderWindow &window, std::list<sf::CircleShape>::iterator it) {
//    sf::CircleShape &projectile = *it;
////    sf::ConvexShape& collide = *itCollide;
//
//    twoFloats projectileSpeeds = getSpeeds(PROJECTILE_SPEED, args.dt, projectile);
////    twoFloats collideSpeeds = getSpeeds(COLLIDE_SPEED, args.dt, collide);
//
//    float pX, pY, cX, cY;
//    pX = projectileSpeeds.x;
//    pY = projectileSpeeds.y;
//    pX += projectile.getPosition().x;
//    pY += projectile.getPosition().y;
//
////    cX = collideSpeeds.x;
////    cY = collideSpeeds.y;
////    cX += projectile.getPosition().x;
////    cY += projectile.getPosition().y;
//
//    if (locationAllowed(pX, pY, projectile.getRadius())) {
//        projectile.move(projectileSpeeds.x, projectileSpeeds.y);
//        window.draw(projectile);
//        return &projectile;
//    } else {
//        return nullptr;
//    }
//}
//
//void spawnCollide(int xSize, int ySize) {
//    std::mt19937 eng;
//
//    std::random_device r;
//    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
//    eng.seed(seed);
//
//    std::uniform_int_distribution<> distX(0, xSize - 1);
//    std::uniform_int_distribution<> distY(0, ySize - 1);
//
//
//    sf::ConvexShape shape;
//    shape.setPointCount(6);
//    shape.setPoint(0, sf::Vector2f(10, 0));
//    shape.setPoint(1, sf::Vector2f(40, 10));
//    shape.setPoint(2, sf::Vector2f(45, 50));
//    shape.setPoint(3, sf::Vector2f(7, 53));
//    shape.setPoint(4, sf::Vector2f(0, 40));
//    shape.setPoint(5, sf::Vector2f(4, 10));
//
//    for (int amount = 0; amount < MAX_ALLOWED_COLLIDABLES; amount++) {
//        auto size = Sizes(rand() % 3);
//
//        float x = distX(eng);
//        float y = distY(eng);
//        float angle = rand() % 360;
//
//        if (size == Sizes::SM) shape.setScale(0.5f, 0.5f);
//        else if (size == Sizes::MED) shape.setScale(0.75f, 0.75f);
//        else if (size == Sizes::LRG) shape.setScale(1.f, 1.f);
//
//        if (locationAllowed(x, y, 0)) shape.setPosition(x, y);
//        shape.setRotation(angle);
//
//        auto bounds = shape.getLocalBounds();
//        shape.setOrigin(bounds.width / 2, bounds.height / 2);
//        collidables.push_back(shape);
//    }
//
//}
//
//sf::CircleShape getPlayer() {
//    sf::CircleShape player(15.f, 3);
//    player.setOrigin(player.getRadius(), player.getRadius());
//    player.setPosition(WIDTH / 2, HEIGHT / 2);
//    return player;
//}

