#pragma once
#include "GameObject.h"
#include "Componet.h"
#include <vector>
#include <memory>



namespace Skyers
{
	class Scene;
	
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}
		

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddChild(std::unique_ptr<Actor> child);

		virtual void OnCollison(Actor* other) {}

		void AddComponet(std::unique_ptr<Componet> componet);
		template<typename T>
		T* GetComponet();

		float GetRadius() { return 0; }// m_model.GetRadius();
	

		std::string& GetTag() { return m_tag; }

		friend class Scene;

		Transform m_transform;
	protected:
		std::string m_tag;
		bool m_destroy = false;
		//physics
		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;
		std::vector<std::unique_ptr<Componet>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;
		Actor* m_parent = nullptr;
	};
	template<typename T>
	inline T* Actor::GetComponet()
	{
		for (auto& componet : m_components)
		{
			T* result = dynamic_cast<T*>(componet.get());
			if (result) return result;
		}

		return nullptr;
	}

}