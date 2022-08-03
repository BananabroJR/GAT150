#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"



namespace Skyers
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : 
			GameObject{ transform },
			m_model{ model } {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		virtual void OnCollison(Actor* other) {}

		float GetRadius() { return m_model.GetRadius(); }

		std::string& GetTag() { return m_tag; }

		friend class Scene;

	protected:
		std::string m_tag;
		bool m_destroy = false;
		//physics
		Vector2 m_velocity;
		float m_damping = 1;

		Model m_model;
		Scene* m_scene = nullptr;
	};
}