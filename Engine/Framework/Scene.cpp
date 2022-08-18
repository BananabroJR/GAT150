#include "Scene.h"
#include "Actor.h"
#include "Factory.h"

#include <algorithm>


namespace Skyers
{
	void Scene::Update()
	{
		auto itor = m_actors.begin();
		while (itor != m_actors.end())
		{
			(*itor)->Update();
			if ((*itor)->m_destroy)
			{
				itor = m_actors.erase(itor);
			}
			else
			{
				itor++;
			}
		
		}

		//check collision
		for (auto itor1 = m_actors.begin(); itor1 != m_actors.end(); itor1++ )
		{
			for (auto itor2 = m_actors.begin(); itor2 != m_actors.end(); itor2++)
			{
				if (itor1 == itor2)
				{
					continue;
				}

				float radius = (*itor1)->GetRadius() + (*itor2)->GetRadius();
				float distance = (*itor1)->m_transform.position.Distance((*itor2)->m_transform.position);

				if (distance < radius) //aka if there is a collison
				{
					(*itor1)->OnCollision((*itor2).get());
					(*itor2)->OnCollision((*itor1).get());
				}
			}
		}
	}

	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actors)
		{
			actor->Draw(renderer);
		}
	}

	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}

	bool Scene::Write(const rapidjson::Value& value) const
	{

		return true;
	}

	bool Scene::Read(const rapidjson::Value& value)
	{
		if (!value.HasMember("actors") && !value["actors"].IsArray())
		{
			return false;
		}

		//read actors
		for (auto& actorValue : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(actorValue, type);

			auto actor = Factory::Instance().Create<Actor>(type);
			if (actor)
			{
				// read actor
				actor->Read(actorValue);
				Add(std::move(actor));
			}
			
		}

		return true;
	}

}