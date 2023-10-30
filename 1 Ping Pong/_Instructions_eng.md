Implementation of interactive ping pong with the following settings. The game is developed in C language, in structural style and works from the terminal, and tested with cppcheck analyzer and clang-format style linter

* Keys:
A/Z and K/M - to move the rackets;
Space Bar - to skip an action at a certain step of the game in step-by-step mode.

* Graphics
The field is a 80 x 25-symbol rectangle.
Racket size is 3 symbols;
Ball size is 1 symbol.

* UI/UX
When one of the players scores 21 points, congratulations to the winner are displayed on the screen and the game ends.

To start playing:
    gcc -Wall -Wextra -Werror -lncurses -o Pong Pong.c
    ./Pong