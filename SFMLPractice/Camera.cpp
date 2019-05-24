#include "pch.h"
#include <cmath>
#include "Camera.h"


Camera::Camera()
{
	UpdateMatrix();
}


Camera::~Camera()
{
}

void Camera::Rotate(sf::Vector2f delta)
{
	pan += delta.x;
	tilt += delta.y;
	UpdateMatrix();
}

void Camera::UpdateMatrix()
{
	transform_matrix =
	{
		{
			{cos(pan), sin(pan), 0.f},
         	{-sin(pan) * sin(tilt), cos(pan)* sin(tilt), -cos(tilt)},
        	{-sin(pan)*cos(tilt), cos(pan) * cos(tilt), sin(tilt)}
		}
	};
}

sf::Vector3f Camera::Transform(sf::Vector3f vertex)
{
	sf::Vector3f diff_vector =
	{
		vertex.x - position.x,
		vertex.y - position.y,
		vertex.z - position.z
	};
	sf::Vector3f transformed_vertex = { 0.f, 0.f, 0.f };

	for (int i = 0; i < 3; ++i)
	{
		transformed_vertex.x += transform_matrix[0][i] * diff_vector.x;
		transformed_vertex.y += transform_matrix[1][i] * diff_vector.y;
		transformed_vertex.z += transform_matrix[2][i] * diff_vector.z;
	}
	return transformed_vertex;
}