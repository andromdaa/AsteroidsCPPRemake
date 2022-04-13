#pragma warning(push, 0)
#include <SFML/Graphics.hpp>
#pragma warning(pop)
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>


int WIDTH = 800;
int HEIGHT = 600;
const double BULLET_SPEED = 200.f;
const double ROTATION_SPEED = 0.01f;
const double PI = 3.14159265f;
const double UPPER_ROTATION_BOUND = .15f;
const double LOWER_ROTATION_BOUND = -.15f;
const double ALLOWED_NEGATIVE_SPEED = -0.1f;
const double LOWER_SPEED_BOUND = -100.f;
const unsigned short UPPER_SPEED_BOUND= 500;

sf::CircleShape circles[2];
sf::CircleShape& player = circles[0];
sf::CircleShape& projectile = circles[1];
std:: vector<sf::CircleShape> projectiles;

struct pollEventArgs {
	sf::Window& window;
	float& dt;
	float& speed;
	float& rotationSpeed;
};

struct speedFloats {
	float& x;
	float& y;
};

void pollEvents(pollEventArgs& args);
bool locationAllowed(float x, float y, float radius);
void processMove(float& speed, float& dt);
void sendProjectile(sf::Vector2f vec);
speedFloats getSpeeds(float& speed, float& dt);

int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	//add prompt would you like to enable anti-aliasing

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Default, settings);

	sf::Vector2f pos;
	float radius;

	player = sf::CircleShape(15.f, 3);
	player.setOrigin(player.getRadius(), player.getRadius());
	player.setPosition(WIDTH / 2, HEIGHT / 2);


	sf::Clock deltaClock;
	sf::Time time;
	float dt, speed, rotationSpeed;
	speed = 0;
	dt = 0;
	rotationSpeed = 0;

	pollEventArgs args = { window, dt, speed, rotationSpeed};

	while (window.isOpen()) {
		time = deltaClock.restart();
		dt = time.asSeconds();

        pollEvents(args);

		//render things
		window.clear();
		window.draw(player);

		for (auto& projectile : projectiles) {
			projectile.move(BULLET_SPEED * sin(projectile.getRotation() * PI / 180) *
				dt, -BULLET_SPEED * cos(projectile.getRotation() * PI / 180) *
				dt);
			window.draw(projectile);
		}

		window.display();
	}

	return 0;
}


void pollEvents(pollEventArgs& args) {
	sf::Event event;
	sf::Window& window = args.window;
	float& dt = args.dt;
	float& speed = args.speed;
	float& rotationSpeed = args.rotationSpeed;
	float x, y;

	std::cout << rotationSpeed << std::endl;

	window.pollEvent(event);

	bool up, down, left, right, space;

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
		processMove(speed, dt);
	}

	if (!up) {
		if (speed > 0) {
			speed -= 0.10f;
		}
		if (speed < 0) {
			speed += 0.035f;
		}
		processMove(speed, dt);
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
		sendProjectile(player.getPosition());
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

void processMove(float& speed, float& dt) {
	float radius = player.getRadius();
	float playerX = player.getPosition().x;
	float playerY = player.getPosition().y;

	//edit this to make it work with projectiles

	speedFloats speeds = getSpeeds(speed, dt);

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
	temp.setPosition(player.getTransform().transformPoint(player.getPoint(0)));
	temp.setRotation(player.getRotation());
	projectiles.push_back(temp);
	//if projectile collides/exits viewable area, delete pointer
}

speedFloats getSpeeds(float& speed, float& dt) {
	float x = speed * sin(player.getRotation() * PI / 180) *
		dt;
	float y = -speed * cos(player.getRotation() * PI / 180) *
		dt;

	return {
		x,
		y
	};
}