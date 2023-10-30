#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25

void draw_generation(int (*matrix)[WIDTH]);
void set_points(int (*matrix)[WIDTH], double count, int i);

#endif
