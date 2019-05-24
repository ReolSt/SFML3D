#pragma once
#include <vector>
#include <array>
class World
{
public:
	World();
	~World();
	std::vector<std::array<sf::Vector3f, 2>>::iterator GetLinesBegin();
	std::vector<std::array<sf::Vector3f, 2>>::iterator GetLinesEnd();
	std::vector<std::array<sf::Vector3f, 3>>::iterator GetTrianglesBegin();
	std::vector<std::array<sf::Vector3f, 3>>::iterator GetTrianglesEnd();
private:
	std::vector<std::array<sf::Vector3f, 2>> lines;
	std::vector<std::array<sf::Vector3f, 3>> triangles;
};

