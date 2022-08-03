#include "Model.h"
#include "../Core/File.h"

#include <iostream>
#include <sstream>

namespace Skyers
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CaculateRadius();
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{
		// draw model points
		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			Skyers::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			Skyers::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		Skyers::ReadFile(filename, buffer);

		// read color
		
		std::istringstream stream(buffer);
		stream >> m_color;

		//m_color.r = 255;
		//m_color.g = 255;
		//m_color.b = 255;
		//m_color.a = 255;

		
		std::string line;
		std::getline(stream, line);

		// get number of points
		size_t numPoints = std::stoi(line);

		// read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}

	}

	float Model::CaculateRadius()
	{
		float radius = 0;

		//find the largets lenght
		for (auto point : m_points)
		{
			if (point.Length() > radius)
			{
				radius = point.Length();
			}
		}

		return radius;
	}

}
