#include "file_manager.h"

FILE* read_pic(const char* path){
    FILE* pic = fopen(path, "rb");
    if(!pic){
        fprintf(stderr, "Failed to open %s", path);
        return 1;
    }
}

void read_header(FILE* pic){
    char line[32];
    fgets(line, 32, pic);
}

resolution read_resolution(FILE* pic){
    char size[32];
    do{
        fgets(size, 32, pic);
    }while(size[0] == '#');
    int w = 0;
    int h = 0;
    sscanf(size, "%d %d", &w, &h);
    resolution r = {w, h};
    return r;
}