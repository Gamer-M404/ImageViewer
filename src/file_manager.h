#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include<stdio.h>

typedef struct resolution{
    int pwidth;
    int pheight;
}resolution;

// open the picture with read mode
FILE* read_pic(const char* path);
// skip the ppm header
void read_header(FILE* pic);
// read the resolution of the ppm
resolution read_resolution(FILE* pic);

#endif