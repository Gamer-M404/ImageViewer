#include<stdio.h>
#include<stdlib.h>
#include "sdl_manager.h"
#include "file_manager.h"


int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_resource_init(&window, &surface);
    FILE* pic = read_pic("../assets/example.ppm");
    read_header(pic);
    resolution r = read_resolution(pic);
    render_pic(&surface, pic, r.pwidth, r.pheight);
    show_pic(&window);
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
        }
        SDL_Delay(16);  // ~60 FPS, avoids 100% CPU busy-waiting
    }
    fclose(pic);
    destroy_SDL_resource(&window);
    return 0;
}