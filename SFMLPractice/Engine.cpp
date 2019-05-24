#include "pch.h"
#include "Engine.h"
#include <array>

Engine::Engine()
{
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), windowTitle);
}


Engine::~Engine()
{

}

std::array<float,4> Engine::Project(sf::Vector3f vertex)
{
	std::array<float, 4> vector = { vertex.x, vertex.y, vertex.z, 1 };
	std::array<float, 4> projected_vector = { 0.f, 0.f, 0.f, 0.f };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			projected_vector[i] += projection_matrix[i][j] * vector[i];
		}
	}
	return projected_vector;
}

void Engine::Render()
{
	window->clear();
	{
		auto itr_end = world.GetLinesEnd();
		for (auto itr = world.GetLinesBegin(); itr != itr_end; ++itr)
		{
			std::array<sf::Vector3f, 2> transformed = 
			{
				camera.Transform(itr->at(0)), camera.Transform(itr->at(1))
			};
			std::array<std::array<float, 4>, 2> projected =
			{
				Project(transformed.at(0)), Project(transformed.at(1))
			};
			sf::Vertex line[2];
			for (int i = 0; i < 2; ++i)
			{
				line[i].position = { projected.at(i)[0] * windowWidth, projected.at(i)[1] * windowHeight};
			}
			window->draw(line, 2, sf::Lines);
		}
	}
	{
		auto itr_end = world.GetTrianglesEnd();
		for (auto itr = world.GetTrianglesBegin(); itr != itr_end; ++itr)
		{
			std::array<sf::Vector3f, 3> transformed =
			{
				camera.Transform(itr->at(0)), camera.Transform(itr->at(1)), camera.Transform(itr->at(2))
			};
			std::array<std::array<float, 4>, 3> projected =
			{
				Project(transformed.at(0)), Project(transformed.at(1)), Project(transformed.at(2))
			};
			sf::ConvexShape triangle(3);
			for(int i=0;i<3;++i)
			{
				triangle.setPoint(i, { projected.at(i)[0] * windowWidth, projected.at(i)[0] * windowHeight});
			}
			window->draw(triangle);
		}
	}
	window->display();
}

void Engine::UpdateMatrix()
{
	projection_matrix =
	{
		{
			{ (float)windowWidth, 0.f, 0.f, 0.f },
	        { 0.f, (float)windowHeight, 0.f, 0.f },
         	{ 0.f, 0.f, perspective.far / (perspective.far - perspective.near), 1.f },
        	{ 0.f, 0.f, perspective.near * perspective.far / (perspective.far - perspective.near), 0.f }
		}
	};
}
