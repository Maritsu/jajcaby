#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
	public:
		RenderWindow(const char* title, int w, int h);
		SDL_Texture* loadTexture(const char* filepath);
		void clean();
		void clear();
		void render(SDL_Texture* texture);
		void display();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};
