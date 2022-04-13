#include "Player.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>

int WIDTH = 800;
int HEIGHT = 600;
const double ROTATION_SPEED = 0.01f;
const float PROJECTILE_SPEED = 600.f;
const double PI = 3.14159265f;
const double UPPER_ROTATION_BOUND = .1f;
const double LOWER_ROTATION_BOUND = -.1f;
const double ALLOWED_NEGATIVE_SPEED = -0.1f;
const double LOWER_SPEED_BOUND = -100.f;
const unsigned short UPPER_SPEED_BOUND= 500;
Player player(15.f, WIDTH, HEIGHT);

sf::CircleShape circles[2];
sf::CircleShape& projectile = circles[1];
std:: vector<sf::CircleShape> projectiles;

struct pollEventArgs { //transition this into class with custom constructor
	sf::Window* window = nullptr;
	float dt = 0;
	float speed = 0;
	float rotationSpeed = 0;
} args;

struct speedFloats {
	float& x;
	float& y;
};

void pollEvents(pollEventArgs& args);
bool locationAllowed(float x, float y, float radius);
void processMovement(float& speed, float& dt);
void sendProjectile(sf::Vector2f vec);
speedFloats getSpeeds(float speed, float dt, sf::CircleShape loc);

int main()
{
	float dt, speed, rotationSpeed;
	sf::ContextSettings settings; //add prompt would you like to enable anti-aliasing
	sf::Clock deltaClock;
	sf::Time time;

	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Default, settings);

	//window settings
	args.window = &window;
	//player settingsa

	while (window.isOpen()) {
		time = deltaClock.restart();
		args.dt = time.asSeconds();

		//event polling, to update what is to be rendered next
        pollEvents(args);

		//render things
		window.clear();
		window.draw(player.playerObj);

		for (auto& projectile : projectiles) {
			speedFloats projectileSpeeds = getSpeeds(PROJECTILE_SPEED, args.dt, projectile);
			projectile.move(projectileSpeeds.x, projectileSpeeds.y);
			window.draw(projectile);
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
		sendProjectile(player.playerPos);
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


	speedFloats speeds = getSpeeds(speed, dt, player.playerObj);

	if (locationAllowed(playerX + speeds.x, playerY + speeds.y, radius)) {
		player.move(speeds.x, speeds.y);
	}
	else {
		speed = -speed;
	}
}

void sendProjectile(sf::Vector2f vec)
{
	sf::CircleShape temp(2.5f);
	temp.setPosition(player.getPoint());
	temp.setRotation(player.playerObj.getRotation());
	projectiles.push_back(temp);
	//if projectile collides/exits viewable area, delete pointer
}

speedFloats getSpeeds(float speed, float dt, sf::CircleShape loc) {

	float x = (speed * sin(loc.getRotation() * PI / 180) *
		dt);
	float y = ( -speed * cos(loc.getRotation() * PI / 180) *
		dt);


	return {
		x,
		y 
	};
}
