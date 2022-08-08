#include "Engine.h"
#include <iostream>



int main()
{

	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;

	Skyers::InitializeMemory();

	Skyers::SetFilePath("../Assets");

	Skyers::g_renderer.Initialize();
	Skyers::g_inputSystem.Initialize();
	Skyers::g_audio.Initialize();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	std::shared_ptr<Skyers::Texture> texture = std::make_shared<Skyers::Texture>();
	texture->Create(Skyers::g_renderer, "Sprites/Ryu-Neutral.png");

	//create actors
	Skyers::Scene scene;


	Skyers::Transform transform{ {100,100},90,{3,3 } };
	std::unique_ptr<Skyers::Actor> actor = std::make_unique<Skyers::Actor>(transform);

	std::unique_ptr<Skyers::PlayerComponet> pComponet = std::make_unique<Skyers::PlayerComponet>();
	actor->AddComponet(std::move(pComponet));

	std::unique_ptr<Skyers::SpriteComponet> sComponet = std::make_unique<Skyers::SpriteComponet>();
	sComponet->m_texture = texture;
	actor->AddComponet(std::move(sComponet));


	scene.Add(std::move(actor));

	float angle = 0;

	bool quit = false;

	while (!quit)
		{
		// update (engine)
		Skyers::g_time.Tick();
		Skyers::g_inputSystem.Update();
		Skyers::g_audio.Update();

		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_escape) == Skyers::InputSystem::KeyState::Pressed) quit = true;

		angle += 180.0f * Skyers::g_time.deltaTime;
		scene.Update();

		// render
		Skyers::g_renderer.BeginFrame();
		scene.Draw(Skyers::g_renderer);
		Skyers::g_renderer.Draw(texture, { 400, 300 }, angle,{2,2},{0.5f,0.5f});
		Skyers::g_renderer.EndFrame();
	}
	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();

}