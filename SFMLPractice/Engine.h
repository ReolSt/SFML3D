#pragma once
#include "pch.h"
#include <memory>
#include "World.h"
#include "Camera.h"
struct Perspective
{
	float fov = 90;
	float aspect;
	float near = 0;
	float far = 1;
};
class Engine
{
public:
	Engine();
	~Engine();
	std::shared_ptr<sf::RenderWindow> window;
	std::array<float,4> Project(sf::Vector3f vertex);
	void Render();
private:
	unsigned int windowWidth;
	unsigned int windowHeight;
	sf::String windowTitle;
	World world;
	Camera camera;
	Perspective perspective;
	std::array<std::array<float, 4>, 4> projection_matrix;
	void UpdateMatrix();
};

