#include "Engine.h"
#include <iostream>


int main()
{

	Skyers::InitializeMemory();

	Skyers::SetFilePath("../Assets");

	Skyers::g_renderer.Initialize();
	Skyers::g_inputSystem.Initialize();
	Skyers::g_audio.Initialize();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	std::shared_ptr<Skyers::Texture> texture = std::make_shared<Skyers::Texture>();
	texture->Create(Skyers::g_renderer, "Sprites/Ryu-Neutral.png");

	bool quit = false;

	while (!quit)
		{
		// update (engine)
		Skyers::g_time.Tick();
		Skyers::g_inputSystem.Update();
		Skyers::g_audio.Update();

		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_escape) == Skyers::InputSystem::KeyState::Pressed) quit = true;

		// render
		Skyers::g_renderer.BeginFrame();
		Skyers::g_renderer.Draw(texture, { 400, 300 }, 0);
		Skyers::g_renderer.EndFrame();
	}
	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();

}