#include "pch.h"
#include "World.h"


World::World()
{
}


World::~World()
{
}

std::vector<std::array<sf::Vector3f, 2>>::iterator World::GetLinesBegin()
{
	return lines.begin();
}

std::vector<std::array<sf::Vector3f, 2>>::iterator World::GetLinesEnd()
{
	return lines.end();
}

std::vector<std::array<sf::Vector3f, 3>>::iterator World::GetTrianglesBegin()
{
	return triangles.begin();
}

std::vector<std::array<sf::Vector3f, 3>>::iterator World::GetTrianglesEnd()
{
	return triangles.end();
}
