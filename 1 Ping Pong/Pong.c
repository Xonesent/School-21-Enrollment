#include <curses.h>  // Библиотека, чтобы считывать клавиши с клавиатуры.
#include <stdio.h>
#include <unistd.h>  // Библиотека для приостановления выполнения программы.

int main(void) {
    initscr();             // Инициализация библиотеки curses.
    keypad(stdscr, true);  // Включаем режим чтения функциональных клавиш.
    halfdelay(100);
    nodelay(stdscr, true);
    cbreak();  // Отключение буферизации ввода. То есть клавиша enter не нужна для окончания ввода.
    noecho();  // Отключение отображения вводимых символов.
    curs_set(0);  // Отключение курсора.

    int shift = 1;  // Отступ от края поля до края рамки.
    int width = 80 + 2 * shift;
    int height = 25 + 2 * shift;

    int ball_x = width / 2;
    int ball_y = height / 2;
    int ball_x_orientation = 1;
    int ball_y_orientation = 0;

    int left_platform_x = 0 + shift;
    int left_platform_y = height / 2;

    int right_platform_x = width - 1 - shift;
    int right_platform_y = height / 2;

    int left_platform_count = 0;
    int right_platform_count = 0;

    char movement;

    clear();
    usleep(33000);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Углы рамки.
            if ((x == 0 && y == 0) || (x == width - (shift / 2 + shift % 2) && y == 0) ||
                (x == 0 && y == height - (shift / 2 + shift % 2)) ||
                (x == width - (shift / 2 + shift % 2) && y == height - (shift / 2 + shift % 2))) {
                printw("+");
            } else if (x == 0 || x == width - (shift / 2 + shift % 2)) {
                printw("|");
            } else if (y == 0 || y == height - (shift / 2 + shift % 2)) {
                printw("-");
            } else if (x == ball_x && y == ball_y) {
                printw("o");
            } else if (x == left_platform_x && -1 <= y - left_platform_y && y - left_platform_y <= 1) {
                printw("l");
            } else if (x == right_platform_x && -1 <= y - right_platform_y && y - right_platform_y <= 1) {
                printw("r");
            } else if (x == (width / 2 - (shift % 2 + shift / 2)) ||
                       x == (width / 2 - (shift % 2 + shift / 2) +
                             1)) {  // Отрисовывание вертикальных прямых в центре поля. (Могут быть баги с
                                    // другим значением shift'а.)
                printw("|");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    printw("\n");

    int table_height = 3;
    for (int y = 0; y < table_height; y++) {
        if (y == 0 || y == table_height - 1) {  // Первая и последняя строка в таблице счёта.
            for (int x = 0; x < width; x++) {
                if (x == 0) {
                    printw("+");
                } else if (x == width - 1) {
                    printw("+\n");
                } else if (x == width / 2 - (shift % 2 + shift / 2) ||
                           x == width / 2 - (shift % 2 + shift / 2) + 1) {
                    printw("|");
                } else {
                    printw("-");
                }
            }
        } else {
            for (int x = 0; x < width - 2; x++) {
                if (x == 0 || x == width / 2 - (shift % 2 + shift / 2) - 1 ||
                    x == width / 2 - (shift % 2 + shift / 2)) {
                    printw("|");
                } else if (x == width - 3) {
                    printw("|\n");
                } else if (x == (width / 2 - (shift % 2 + shift / 2)) - 1 - 3) {
                    printw("%2d", left_platform_count);
                } else if (x == (width / 2 - (shift % 2 + shift / 2) + 1) + 1 + 1) {
                    printw("%2d", right_platform_count);
                } else {
                    printw(" ");
                }
            }
        }
    }
    printw("\n");

    while (left_platform_count < 21 && right_platform_count < 21) {
        for (int tick = 0; tick < 4; tick++) {
            movement = getch();
            if (movement == 'A' || movement == 'a' || movement == 'Z' || movement == 'z') {
                if ((movement == 'A' || movement == 'a') && left_platform_y >= (0 + 2 + shift)) {
                    left_platform_y -= 1;
                } else if ((movement == 'Z' || movement == 'z') &&
                           left_platform_y <= (height - 1 - 2 - shift)) {
                    left_platform_y += 1;
                }
            } else if (movement == 'K' || movement == 'k' || movement == 'M' || movement == 'm') {
                if ((movement == 'K' || movement == 'k') && right_platform_y >= (0 + 2 + shift)) {
                    right_platform_y -= 1;
                } else if ((movement == 'M' || movement == 'm') &&
                           right_platform_y <= (height - 1 - 2 - shift)) {
                    right_platform_y += 1;
                }
            }
        }
        int left_platform_y_up = left_platform_y - 1;
        int left_platform_y_down = left_platform_y + 1;

        int right_platform_y_up = right_platform_y - 1;
        int right_platform_y_down = right_platform_y + 1;

        if (ball_x == (left_platform_x + 1 + shift) && ball_y == left_platform_y_up) {
            ball_x_orientation *= -1;
            ball_y_orientation = -1;
        } else if (ball_x == (left_platform_x + 1 + shift) && ball_y == left_platform_y) {
            ball_x_orientation *= -1;
            ball_y_orientation = 0;
        } else if (ball_x == (left_platform_x + 1 + shift) && ball_y == left_platform_y_down) {
            ball_x_orientation *= -1;
            ball_y_orientation = 1;
        } else if (ball_x == left_platform_x &&
                   (ball_y < left_platform_y_down || ball_y > left_platform_y_up)) {
            right_platform_count += 1;
            ball_x = width / 2;
            ball_y = height / 2;
            ball_x_orientation = -1;
            ball_y_orientation = 0;
            left_platform_x = 0 + shift;
            left_platform_y = height / 2;
            right_platform_x = width - 1 - shift;
            right_platform_y = height / 2;
        } else if (ball_x == (right_platform_x - 1 - shift) && ball_y == right_platform_y_up) {
            ball_x_orientation *= -1;
            ball_y_orientation = -1;
        } else if (ball_x == (right_platform_x - 1 - shift) && ball_y == right_platform_y) {
            ball_x_orientation *= -1;
            ball_y_orientation = 0;
        } else if (ball_x == (right_platform_x - 1 - shift) && ball_y == right_platform_y_down) {
            ball_x_orientation *= -1;
            ball_y_orientation = 1;
        } else if (ball_x == right_platform_x &&
                   (ball_y < right_platform_y_down || ball_y > right_platform_y_up)) {
            left_platform_count += 1;
            ball_x = width / 2;
            ball_y = height / 2;
            ball_x_orientation = 1;
            ball_y_orientation = 0;
            left_platform_x = 0 + shift;
            left_platform_y = height / 2;
            right_platform_x = width - 1 - shift;
            right_platform_y = height / 2;
        } else if (ball_y == shift || ball_y == height - 1 - shift) {
            ball_y_orientation *= -1;
        }
        ball_x += ball_x_orientation;
        ball_y += ball_y_orientation;

        clear();
        usleep(33000);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Углы рамки.
                if ((x == 0 && y == 0) || (x == width - (shift / 2 + shift % 2) && y == 0) ||
                    (x == 0 && y == height - (shift / 2 + shift % 2)) ||
                    (x == width - (shift / 2 + shift % 2) && y == height - (shift / 2 + shift % 2))) {
                    printw("+");
                } else if (x == 0 || x == width - (shift / 2 + shift % 2)) {
                    printw("|");
                } else if (y == 0 || y == height - (shift / 2 + shift % 2)) {
                    printw("-");
                } else if (x == ball_x && y == ball_y) {
                    printw("o");
                } else if (x == left_platform_x && -1 <= y - left_platform_y && y - left_platform_y <= 1) {
                    printw("l");
                } else if (x == right_platform_x && -1 <= y - right_platform_y && y - right_platform_y <= 1) {
                    printw("r");
                } else if (x == (width / 2 - (shift % 2 + shift / 2)) ||
                           x == (width / 2 - (shift % 2 + shift / 2) +
                                 1)) {  // Отрисовывание вертикальных прямых в центре поля. (Могут быть баги с
                                        // другим значением shift'а.)
                    printw("|");
                } else {
                    printw(" ");
                }
            }
            printw("\n");
        }
        printw("\n");

        for (int y = 0; y < table_height; y++) {
            if (y == 0 || y == table_height - 1) {  // Первая и последняя строка в таблице счёта.
                for (int x = 0; x < width; x++) {
                    if (x == 0) {
                        printw("+");
                    } else if (x == width - 1) {
                        printw("+\n");
                    } else if (x == width / 2 - (shift % 2 + shift / 2) ||
                               x == width / 2 - (shift % 2 + shift / 2) + 1) {
                        printw("|");
                    } else {
                        printw("-");
                    }
                }
            } else {
                for (int x = 0; x < width - 2; x++) {
                    if (x == 0 || x == width / 2 - (shift % 2 + shift / 2) - 1 ||
                        x == width / 2 - (shift % 2 + shift / 2)) {
                        printw("|");
                    } else if (x == width - 3) {
                        printw("|\n");
                    } else if (x == (width / 2 - (shift % 2 + shift / 2)) - 1 - 3) {
                        printw("%2d", left_platform_count);
                    } else if (x == (width / 2 - (shift % 2 + shift / 2) + 1) + 1 + 1) {
                        printw("%2d", right_platform_count);
                    } else {
                        printw(" ");
                    }
                }
            }
        }
        printw("\n");
    }
    endwin();  // Завершение работы с библиотекой curses.
    clear();
    table_height = 3;  // Также как с shift'ом можно сделать размер таблицы счёта зависимым.
    for (int y = 0; y < table_height; y++) {
        if (y == 0 || y == table_height - 1) {  // Первая и последняя строка в таблице счёта.
            for (int x = 0; x < width; x++) {
                if (x == 0) {
                    printw("+");
                } else if (x == width - 1) {
                    printf("+\n");
                } else {
                    printf("-");
                }
            }
        } else {
            if (left_platform_count == 21) {
                printf("|\t\t !!! Winner !!! Левый игрок победил !!! Winner !!!              |\n");
            } else if (right_platform_count == 21) {
                printf("|\t\t !!! Winner !!! Правый игрок победил !!! Winner !!!             |\n");
            }
        }
    }
    return 0;
}
