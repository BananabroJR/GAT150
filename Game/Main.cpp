#include "Engine.h"
#include "MyGame.h"
#include <iostream>




int main()
{
	Skyers::InitializeMemory();

	Skyers::SetFilePath("../Assets");

	Skyers::g_renderer.Initialize();
	Skyers::g_inputSystem.Initialize();
	Skyers::g_audio.Initialize();
	Skyers::g_resource.Initialize();
	Skyers::g_physics.Initialize();
	Skyers::g_event.Initialize();
	Skyers::Engine::Instance().Register();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600, true);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	//create game
	std::unique_ptr<MyGame> game = std::make_unique<MyGame>();
	game->Initialize();
	

	bool quit = false;

	while (!quit)
	{
		// update (engine)
		Skyers::g_time.Tick();
		Skyers::g_inputSystem.Update();
		Skyers::g_audio.Update();
		Skyers::g_event.Update();


		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_escape) == Skyers::InputSystem::KeyState::Pressed) quit = true;

		Skyers::g_physics.Update();
		
		game->Update();

		Skyers::g_renderer.BeginFrame();
		// render

		game->Draw(Skyers::g_renderer);
	
		Skyers::g_renderer.EndFrame();
	}
	game->Shutdown();
	game.reset();

	Skyers::Factory::Instance().Shutdown();
	
	Skyers::g_physics.Shutdown();
	Skyers::g_resource.Shutdown();
	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();
	Skyers::g_event.Shutdown();

};