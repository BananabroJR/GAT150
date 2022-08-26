#pragma once
#include "Framework/Game.h"


class MyGame : public Skyers::Game
{
public:
	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Skyers::Renderer& renderer) override;
};
