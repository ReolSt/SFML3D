#pragma once
#include <array>
class Camera
{
public:
	Camera();
	~Camera();
	void Rotate(sf::Vector2f delta);
	sf::Vector3f Transform(sf::Vector3f vertex);
private:
	std::array<std::array<float, 3>, 3> transform_matrix;
	sf::Vector3f position;
	float pan, tilt;
	void UpdateMatrix();
};

