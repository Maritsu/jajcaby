#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "SDL_INIT FUCKED UP: SDL_ERR: " << SDL_GetError() << std::endl;
		return 1;
	}
	if (!(IMG_Init(IMG_INIT_PNG))) {
		std::cout << "IMG_INIT FUCKED UP: ING_ERR: " << SDL_GetError() << std::endl;
		return 1;
	}

	RenderWindow window("Jajcaby DEV", 1280, 720);

	bool running = true;

	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
		}
	}

	window.clean();
	SDL_Quit();

    return 0;
}
