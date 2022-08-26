#pragma once
#include "Renderer/Renderer.h"
#include "Engine.h"
#include "Framework/GameObject.h"
#include "Serialization/Json.h"
#include "Serialization/Serializable.h"

#include<list>
#include <memory>

namespace Skyers

{
	//foreward declaration
	class Actor;
	class Rendnerer;
	class Game;

	class Scene : public GameObject, public ISerializable
	{
	public:
		Scene() = default;
		Scene(Game* game) : m_game { game} {}
		Scene(const Scene& other) {}
		~Scene() = default;
		
		CLASS_DECLARATION(Scene)

		void Update() override;
		void Initialize() override;
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value)override;

		template<typename T>
		T* GetActor();

		Game* getGame() { return m_game; }

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
		Game* m_game;

	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}

		return nullptr;
	}


}