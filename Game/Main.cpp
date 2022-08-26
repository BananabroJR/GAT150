#include "Engine.h"
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
	Skyers::Engine::Instance().Register();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	Skyers::Scene scene;
	
	rapidjson::Document document; 
	bool success = Skyers::json::Load("level.txt", document); 

	scene.Read(document);
	scene.Initialize();

	for (int i = 0; i < 10; i++)
	{
	auto actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Coin");
	actor->m_transform.position = { Skyers::randomf( 0,800.0f),100.0f };
	actor->Initialize();

	scene.Add(std::move(actor));

	}

	bool quit = false;

	while (!quit)
	{
		// update (engine)
		Skyers::g_time.Tick();
		Skyers::g_inputSystem.Update();
		Skyers::g_audio.Update();

		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_escape) == Skyers::InputSystem::KeyState::Pressed) quit = true;

		Skyers::g_physics.Update();
		scene.Update();

		Skyers::g_renderer.BeginFrame();
		// render

		scene.Draw(Skyers::g_renderer);
	
		Skyers::g_renderer.EndFrame();
	}
	scene.RemoveAll();
	Skyers::Factory::Instance().Shutdown();
	
	Skyers::g_physics.Shutdown();
	Skyers::g_resource.Shutdown();
	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();

};