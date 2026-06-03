#include "sdl_manager.h"
#define WIDTH 800
#define HEIGHT 600

void SDL_resource_init(SDL_Window **window, SDL_Surface** surface){
    *window = SDL_CreateWindow(
        "My Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );
     if (!(*window)) {
        fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    *surface = SDL_GetWindowSurface(*window);
}

void destroy_SDL_resource(SDL_Window **window){
    SDL_DestroyWindow(*window);
    SDL_Quit();
}


void render_pic(SDL_Surface** surface, FILE* pic, int pwidth, int pheight){
    for (int y = 0; y < pheight; y++) {
        for (int x = 0; x < pwidth; x++) {
            Uint8 r = fgetc(pic);
            Uint8 g = fgetc(pic);
            Uint8 b = fgetc(pic);
            Uint32 color = SDL_MapRGB((*surface)->format, r, g, b);
            SDL_Rect pixel = (SDL_Rect){x, y, 1, 1};
            SDL_FillRect(*surface, &pixel, color);
        }
    }
}

void show_pic(SDL_Window **window){
    SDL_UpdateWindowSurface(*window);
}