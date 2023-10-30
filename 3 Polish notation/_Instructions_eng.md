Implementation of polish notation with the following settings. The programm is developed in C language, in structural style and works from the terminal, and tested with cppcheck analyzer and clang-format style linter

* Conditions
The size of the field for displaying graphs is a rectangle of 25 by 80 points.
Definition area - [0; 4 Pi]
Range of values - [-1; 1]
Orientation of the coordinate plane - the ordinate axis is directed downward, the abscissa axis is directed to the right.
The center of coordinates is middle of the left border (point {0, 13}).
You don't need to draw axes.
Nothing but the graph should be displayed.
Values are rounded according to the rules of mathematics.

* Graphics
The field should be displayed using Star symbol for the chart line and "." for the rest of the screen space.

* Modules
Expression parsing and creating a list of lexical units.
Translation into Polish notation and calculation using this notation.
Drawing a graph in the terminal.
library for organizing dynamic data structures (stack, list, etc.).

To start programm:
    make all
    // sin(x)...