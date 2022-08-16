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
	Skyers::Engine::Instance().Register();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	//std::shared_ptr<Skyers::Texture> texture = std::make_shared<Skyers::Texture>();
	//texture->Create(Skyers::g_renderer, "Sprites/SpaceShips.png");
	std::shared_ptr<Skyers::Texture> texture = Skyers::g_resource.Get<Skyers::Texture>("Sprites/SpaceShips.png", &Skyers::g_renderer);

	Skyers::g_audio.AddAudio("Laser", "Sound/Laser_Shoot.wav");


	std::shared_ptr<Skyers::Model> model = Skyers::g_resource.Get<Skyers::Model>("Model/Player.txt");
	std::shared_ptr<Skyers::Model> model2 = Skyers::g_resource.Get<Skyers::Model>("Model/Player.txt");

	//create actors


	Skyers::Transform transform{ {400,300},90,{1,1 } };
	//std::unique_ptr<Skyers::Actor> actor = std::make_unique<Skyers::Actor>(transform);
	std::unique_ptr<Skyers::Actor> actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Actor");
	actor->m_transform = transform;
	Skyers::Scene scene;

	std::unique_ptr<Skyers::Componet> pComponet = Skyers::Factory::Instance().Create<Skyers::Componet>("PlayerComponet");
	actor->AddComponet(std::move(pComponet));



	std::unique_ptr<Skyers::ModelComponet> mComponet = std::make_unique<Skyers::ModelComponet>();
	mComponet->m_model = Skyers::g_resource.Get<Skyers::Model>("Model/Player.txt");
	actor->AddComponet(std::move(mComponet));

	std::unique_ptr<Skyers::AudioComponet> aComponet = std::make_unique<Skyers::AudioComponet>();
	aComponet->m_soundName = "Laser";
	actor->AddComponet(std::move(aComponet));

	std::unique_ptr<Skyers::Componet> phComponet = Skyers::Factory::Instance().Create<Skyers::Componet>("PhysiscsComponet");
	actor->AddComponet(std::move(phComponet));

	Skyers::Transform transformC{ Skyers::Vector2{40,30}, 0, {1,1} };
	std::unique_ptr<Skyers::Actor> child = std::make_unique<Skyers::Actor>(transformC);

	std::unique_ptr<Skyers::ModelComponet> mcComponent = std::make_unique<Skyers::ModelComponet>();
	mcComponent->m_model = Skyers::g_resource.Get<Skyers::Model>("Model/Player.txt");

	actor->AddChild(std::move(child));



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
		//Skyers::g_renderer.Draw(texture, { 400, 300 }, angle,{2,2},{0.5f,0.5f});
		Skyers::g_renderer.EndFrame();
	}
	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();

};