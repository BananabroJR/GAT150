#include "Engine.h"
#include <iostream>




int main()
{
	Skyers::InitializeMemory();

	Skyers::SetFilePath("../Assets");

	

//	int i1;
//	Skyers::json::Get(document, "integer1", i1);
//	std::cout << i1 << std::endl;

//	int i2;
//	Skyers::json::Get(document, "integer2", i2);
//	std::cout << i2 << std::endl;
	

	Skyers::g_renderer.Initialize();
	Skyers::g_inputSystem.Initialize();
	Skyers::g_audio.Initialize();
	Skyers::g_resource.Initialize();
	Skyers::Engine::Instance().Register();

	Skyers::g_renderer.CreateWindow("Neumont", 800, 600);
	Skyers::g_renderer.SetClearColor(Skyers::Color{ 0, 0, 0, 255 });

	Skyers::Scene scene;

	//move these two lines up above and uncomment the commented out code for json assingment.
	rapidjson::Document document; 
	bool success = Skyers::json::Load("level.txt", document); //change "level.txt" back to "json.txt" for the assingment 

	scene.Read(document); //comment this out for json assingment


	bool quit = false;

	while (!quit)
	{
		// update (engine)
		Skyers::g_time.Tick();
		Skyers::g_inputSystem.Update();
		Skyers::g_audio.Update();

		if (Skyers::g_inputSystem.GetKeyState(Skyers::key_escape) == Skyers::InputSystem::KeyState::Pressed) quit = true;


		scene.Update();

		// render

		scene.Draw(Skyers::g_renderer);
	
		Skyers::g_renderer.EndFrame();
	}
	

	Skyers::g_audio.Shutdown();
	Skyers::g_renderer.Shutdown();
	Skyers::g_inputSystem.Shutdown();

};