#include "infix.h"
#include "postfix.h"
#include "print.h"

int main() {
    int matrix[HEIGHT][WIDTH] = {0};
    char infix_str[100];
    char postfix_str[100];
    printf("Введите выражение: ");
    fgets(infix_str, sizeof(infix_str), stdin);
    dijkstra(infix_str, postfix_str);
    double value1 = 0;
    for (int i = 0; i < WIDTH; i++) {
        double count = -1 * evaluate_rpn(postfix_str, value1);
        set_points(matrix, count, i);
        value1 += (4 * M_PI) / (WIDTH - 1);
    }
    draw_generation(matrix);
    return 0;
}
