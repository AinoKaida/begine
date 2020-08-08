#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include <SDL.h>
#include "TextComponent.h"
#include "TextureComponent.h"
#include "Scene.h"
#include "FPSCounter.h"

using namespace std;
using namespace std::chrono;

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */

void dae::Minigin::LoadFPSCounter() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 26);
	auto tc = std::make_shared<TextComponent>("", font);
	tc->SetPosition(20, 20);

	auto fps = std::make_shared<FPSCounter>(tc);
	scene.Add(fps);
}

void dae::Minigin::LoadDaeImage() const
{

}

void dae::Minigin::LoadProg4AssignmentText() const
{
	//auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto tc = std::make_shared<TextComponent>("", font);
	//tc->SetPosition(80, 20);
}

void dae::Minigin::LoadGame() const
{
	LoadFPSCounter();
	LoadDaeImage();
	LoadProg4AssignmentText();
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		// Statics
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		auto& time = TimeManager::GetInstance();

		// Catch up Game Loop
		auto previousTime = high_resolution_clock::now();
		float lag{ 0.f };

		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			time.deltaTime = duration<float, milli>(currentTime - previousTime).count();
			previousTime = currentTime;
			lag += time.getDeltaTime();
			time.lag = lag;

			doContinue = input.ProcessInput();

			while (lag >= MsPerUpdate)
			{
				sceneManager.Update();
				lag -= MsPerUpdate;
				time.lag = lag;
			}

			renderer.Render();
		}
	}

	Cleanup();
}

