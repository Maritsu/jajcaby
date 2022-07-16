#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"
// #include "board.hpp"

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_INIT FUCKED UP: SDL_ERR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_INIT FUCKED UP: ING_ERR: " << SDL_GetError() << std::endl;

	RenderWindow window("Jajcaby DEV", 1280, 720);

	// SDL_Texture* egg = window.loadTexture("res/img/eggW.png");

	bool running = true;

	SDL_Event event;
	// Board gameBoard;
	// gameBoard.clean();
	// gameBoard.start();

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
		}

		window.clean();
		// window.render(egg);
		// window.display();
	}

	window.clean();
	SDL_Quit();

    return 0;
}
