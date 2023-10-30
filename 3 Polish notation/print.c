#include "print.h"

void draw_generation(int (*matrix)[WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == 0) {
                printf(".");
            } else if (matrix[i][j] == 1) {
                printf("*");
            }
        }
        printf("\n");
    }
}

void set_points(int (*matrix)[WIDTH], double count, int i) {
    if (count >= -1 && count <= 1) {
        if (count < 0) {
            double value2 = -1;
            int j = 24;
            while (value2 < count) {
                value2 += 1.0 / 11;
                j--;
            }
            matrix[j][i] = 1;
        } else {
            double value2 = 0;
            int j = 13;
            while (value2 < count - 1.0 / 14 && j > 0) {
                value2 += 1.0 / 14;
                j--;
            }
            matrix[j][i] = 1;
        }
    }
}
