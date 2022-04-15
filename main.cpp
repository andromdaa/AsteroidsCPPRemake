#include "Player.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include "CircleShapeNode.h"
#include <SFML/Audio.hpp>
#include <list>
#include <random>
#include <unordered_map>

const int WIDTH = 800;
const int HEIGHT = 600;
sf::SoundBuffer buffer;
sf::Sound sound;
sf::Music music;
sf::CircleShape circles[5];
Player player(15.f, WIDTH, HEIGHT); //make this extend/implement sf::CircleShape?
std::list<sf::CircleShape> projectiles;
std::list<sf::ConvexShape> collidables;
const double ROTATION_SPEED = 0.005f;
const float PROJECTILE_SPEED = 600.f;
const double PI = 3.14159265f;
const double UPPER_ROTATION_BOUND = .1f;
const double LOWER_ROTATION_BOUND = -.1f;
const double ALLOWED_NEGATIVE_SPEED = -0.1f;
const double LOWER_SPEED_BOUND = -100.f;
const unsigned short UPPER_SPEED_BOUND= 500;
const char MAX_ALLOWED_COLLIDABLES = 10;
struct twoFloats {
	float x;
	float y;
};

struct pollEventArgs { //transition this into class with custom constructor
	sf::Window* window = nullptr;
	float dt = 0;
	float speed = 0;
	float rotationSpeed = 0;
} args;


enum class Sizes { SM, MED, LRG};
void pollEvents(pollEventArgs& args);
bool locationAllowed(float x, float y, float radius);
void processMovement(float& speed, float& dt);
void addProjectile(sf::Vector2f vec);
twoFloats getSpeeds(float speed, float dt, sf::CircleShape loc);
bool checkCollision(sf::CircleShape projectile, sf::RectangleShape shape);
bool drawProjectile(sf::RenderWindow& window, std::list<sf::CircleShape>::iterator it);
void spawnCollidables(Sizes size, int count, int xSize, int ySize);

int main()
{
	sf::ContextSettings settings; //add prompt would you like to enable anti-aliasing
	sf::Clock deltaClock;
	sf::Time time;

	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Default, settings);

	//window settings
	args.window = &window;
	//player settings

	//load assets
	if (!buffer.loadFromFile("assets/sounds/fire.ogg"))
		return -1;
	sound.setBuffer(buffer);
	sound.setVolume(50.f);

	if (!music.openFromFile("assets/sounds/music.wav")) return -1;
	//music.play();
	

	while (window.isOpen()) {
		time = deltaClock.restart();
		args.dt = time.asSeconds();

		//event polling, to update what is to be rendered next
        pollEvents(args);

		//render things
		window.clear();
		window.draw(player.playerObj);

		spawnCollidables(Sizes(rand() % 3), collidables.size(), window.getSize().x, window.getSize().y);

		std::list<sf::CircleShape>::iterator it = projectiles.begin();
		std::list<sf::ConvexShape>::iterator itConvex = collidables.begin();

		//while (itConvex != collidables.end()) {
		//	window.draw(*itConvex);
		//	itConvex++;
		//}

		while (it != projectiles.end()) {
			sf::CircleShape shape = *it;
			/*if (!shape.getGlobalBounds().intersects(collisionCoords[shape.getPosition()])) {
				window.draw(shape);
			}
			else {
				projectiles.erase(it);
			}*/

			it++;
		}

		window.display();
	}

	return 0;
}


void pollEvents(pollEventArgs& args) {
	sf::Event event;
	sf::Window& window = *args.window;
	window.pollEvent(event); //required function, also used for space bar released

	float dt = args.dt; 
	float& speed = args.speed; //reference due to continous value
	float& rotationSpeed = args.rotationSpeed; //reference due to continous value
	bool up, down, left, right, space; //key states
	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	space = ((event.type == sf::Event::KeyReleased)
		&& (event.key.code == sf::Keyboard::Space));

	//if statements not chained due to causing reduced performance

	if (speed >= UPPER_SPEED_BOUND) {
		speed = UPPER_SPEED_BOUND;
	}   

	if (speed <= LOWER_SPEED_BOUND) {
		speed = LOWER_SPEED_BOUND;
	}

	if (rotationSpeed >= UPPER_ROTATION_BOUND) {
		rotationSpeed = UPPER_ROTATION_BOUND;
	}

	if (rotationSpeed <= LOWER_ROTATION_BOUND) {
		rotationSpeed = LOWER_ROTATION_BOUND;
	}

	if(up) {
		speed += 0.25f;
		processMovement(speed, dt);
	}

	if (!up) {
		if (speed > 0) {
			speed -= 0.10f;
		}

		if (speed < 0) {
			speed += 0.035f;
		}
		processMovement(speed, dt);
	}

	if (down) {
		speed -= 0.03f;
	}

	if (left) {
		rotationSpeed -= ROTATION_SPEED;
		player.rotate(rotationSpeed);
	}

	if (right) {
		rotationSpeed += ROTATION_SPEED;
		player.rotate(rotationSpeed);
	}

	if (space) {
		//sound.play();
		addProjectile(player.playerPos);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}
}

bool locationAllowed(float x, float y, float radius) {
	if (x + radius > WIDTH || x < 0 + radius) {
		return false;
	}
	if (y + radius > HEIGHT || y < 0 + radius) {
		return false;
	}
	return true;
}

void processMovement(float& speed, float& dt) {
	float radius = player.playerRadius;
	float playerX = player.playerPos.x;
	float playerY = player.playerPos.y;


	twoFloats speeds = getSpeeds(speed, dt, player.playerObj);

	if (locationAllowed(playerX + speeds.x, playerY + speeds.y, radius)) {
		player.move(speeds.x, speeds.y);
	}
	else {
		speed = -speed;
	}
}

void addProjectile(sf::Vector2f vec)
{
	sf::CircleShape temp(2.5f);
	temp.setPosition(player.getPoint());
	temp.setRotation(player.playerObj.getRotation());
	projectiles.push_back(temp);

}

twoFloats getSpeeds(float speed, float dt, sf::CircleShape loc) {

	float x = (speed * sin(loc.getRotation() * PI / 180) *
		dt);
	float y = ( -speed * cos(loc.getRotation() * PI / 180) *
		dt);


	return {
		x,
		y 
	};
}

bool checkCollision(sf::CircleShape projectile, sf::RectangleShape shape) {
	return projectile.getGlobalBounds().intersects(shape.getGlobalBounds());
}

bool drawProjectile(sf::RenderWindow& window, std::list<sf::CircleShape>::iterator it)
{
	sf::CircleShape& projectile = *it;

	twoFloats projectileSpeeds = getSpeeds(PROJECTILE_SPEED, args.dt, projectile);
	float x, y;
	x = projectileSpeeds.x;
	y = projectileSpeeds.y;
	x += projectile.getPosition().x;
	y += projectile.getPosition().y;

	if (locationAllowed(x, y, projectile.getRadius())) {
		projectile.move(projectileSpeeds.x, projectileSpeeds.y);
		window.draw(projectile);
		return true;
	}
	else {
		return false;
	}
}

void spawnCollidables(Sizes size, int count, int xSize, int ySize)
{
	std::mt19937 eng;

	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };
	eng.seed(seed);

	std::uniform_int_distribution<> distX(0, xSize - 1);
	std::uniform_int_distribution<> distY(0, ySize - 1);


	if (count >= MAX_ALLOWED_COLLIDABLES) return;

	sf::ConvexShape shape;
	shape.setPointCount(6);
	shape.setPoint(0, sf::Vector2f(10, 0));
	shape.setPoint(1, sf::Vector2f(40, 10));
	shape.setPoint(2, sf::Vector2f(45, 50));
	shape.setPoint(3, sf::Vector2f(7, 53));
	shape.setPoint(4, sf::Vector2f(0, 40));
	shape.setPoint(5, sf::Vector2f(4, 10));
	shape.setPoint(6, sf::Vector2f(10, 0));


	float x = distX(eng);
	float y = distY(eng);
	float angle = rand() % 360;

	if (size == Sizes::SM) shape.setScale(0.5f, 0.5f);
	else if (size == Sizes::MED) shape.setScale(0.75f, 0.75f);
	else if (size == Sizes::LRG) shape.setScale(1.f, 1.f);

	if (locationAllowed(x, y, 0)) shape.setPosition(x, y);
	shape.setRotation(angle);
	
	collidables.push_back(shape);

}

