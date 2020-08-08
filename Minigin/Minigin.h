#pragma once
struct SDL_Window;
namespace dae
{
	class Minigin
	{
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
	private:
		static const int MsPerUpdate = 16; //16 for 60 fps, 33 for 30 fps, 8 for 120fps
		SDL_Window* m_Window{};

		void LoadFPSCounter() const;
		void LoadDaeImage() const;
		void LoadProg4AssignmentText() const;
	};
}