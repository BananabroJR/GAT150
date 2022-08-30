#include "MyGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"
#include <iostream>


void MyGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);

	m_scene = std::make_unique<Skyers::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/tilemap.txt","scenes/level.txt"};

	for (auto names : sceneNames)
	{
		bool success = Skyers::json::Load(names, document);

		if (!success)
		{
			LOG("could not load scene name %s", names.c_str());
			continue;
		}

		m_scene->Read(document);
	}

	m_scene->Initialize();

	for (int i = 0; i < 10; i++)
	{
		auto actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Coin");
		actor->m_transform.position = { Skyers::randomf(0,800.0f),100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));

	}

	Skyers::g_event.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnAddPoints,this,std::placeholders::_1));

}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)
	{
	case MyGame::GameState::titleScreen:
		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_space) == Skyers::InputSystem::KeyState::Pressed)
		{
			m_gameState = GameState::startLevel;
		}
		

		break;
	case MyGame::GameState::startLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Coin");
			actor->m_transform.position = { Skyers::randomf(0,800.0f),100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		for (int i = 0; i < 3; i++)
		{
			auto actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Ghost");
			actor->m_transform.position = { Skyers::randomf(0,800.0f),100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = GameState::game;
		break;


	case MyGame::GameState::game:
		break;
	case MyGame::GameState::playerDead:
		m_stateTimer -= Skyers::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? GameState::startLevel : GameState::gameOver;
		}

		break;
	case MyGame::GameState::gameOver:
		break;
	default:
		break;
	}

	m_scene->Update();
}

void MyGame::Draw(Skyers::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnAddPoints(const Skyers::Event& event)
{
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void MyGame::OnPlayerDead(const Skyers::Event& event)
{
	m_gameState = GameState::playerDead;
	m_lives--;
	m_stateTimer = 3;

}

void MyGame::OnNotify(const Skyers::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		AddPoints(std::get<int>(event.data));
	}

	if (event.name == "EVENT_PLAYER_DEAD")
	{
		m_gameState = GameState::playerDead;
		m_lives--;
		m_stateTimer = 3;
	}
}


