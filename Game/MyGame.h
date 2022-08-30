#pragma once
#include "Framework/Game.h"
#include "Framework/EventManager.h"

class MyGame : public Skyers::Game, public Skyers::INotify
{
public:
	enum class GameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver,

	};



	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Skyers::Renderer& renderer) override;

	void OnAddPoints(const Skyers::Event& event);
	void OnPlayerDead(const Skyers::Event& event);

private:
	GameState m_gameState = GameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;

	// Inherited via INotify
	virtual void OnNotify(const Skyers::Event& event) override;
};
