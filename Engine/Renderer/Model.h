#pragma once
#include "Renderer.h"
#include <vector>
#include <string>

namespace Skyers
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<Skyers::Vector2>& points, const Skyers::Color& color) :
			m_points{ points },
			m_color{ color }
		{
		}
		
		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);

		void Load(const std::string& filename);

		float CaculateRadius();

		float GetRadius() { return m_radius; }

	private:
		Skyers::Color m_color{0,0,0,0};
		std::vector<Skyers::Vector2> m_points;

		float m_radius = 0;
	};
}
