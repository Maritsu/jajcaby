#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int w, int h) 
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to initialize. Err: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* filepath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filepath);

	if (texture == NULL) 
		std::cout << "Failed to load texture. Err: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::clean() {
	 SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* texture) {
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}
