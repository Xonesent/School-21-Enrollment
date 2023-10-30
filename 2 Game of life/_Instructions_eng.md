Implementation of game of life with the following settings. The game is developed in C language, in structural style and works from the terminal, and tested with cppcheck analyzer and clang-format style linter

* Graphics:
Treat the playing field - a rectangle of 80 by 25 cells – as a matrix of the state of the "game".
It is assumed that the field is "closed to itself", for example, in the lower right square, the neighbor on the right is the lower left square, and the neighbor on the bottom is the upper right.
Provide for original initialization of the "game" state via stdin. Prepare at least 5 files with initial states for quick launch and initialization through input redirection.

To start playing:
    gcc -Wall -Wextra -Werror -lncurses -o Game_of_life Game_of_life.c
    ./Game_of_life < "file_path"
                    Scenarios/1.txt
                    Scenarios/2.txt
                    Scenarios/3.txt
                    Scenarios/4.txt
                    Scenarios/5.txt