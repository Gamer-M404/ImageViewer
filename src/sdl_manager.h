#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H

#include<SDL2/SDL.h>

// init the resource
void SDL_resource_init(SDL_Window **window, SDL_Surface** surface);
// destroy the resource
void destroy_SDL_resource(SDL_Window **window);
// render the picture
void render_pic(SDL_Surface** surface, FILE* pic, int pwidth, int pheight);
// show the picture
void show_pic(SDL_Window **window);


#endif