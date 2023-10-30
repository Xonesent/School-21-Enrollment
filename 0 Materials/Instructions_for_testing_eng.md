* Style tests:  
To run the style check, run the following command:  
    clang-format -n src/sourcefile_name.c  
To download clang-format, enter one of the following commands in the terminal:  
    brew install clang-format  
or if you have root rights (for Ubuntu / Linux Mint / Debian)  
    sudo apt install clang-format  

* Test for correct operation with memory:  
To run your executable file using this utility, type in the terminal:  
    leaks -atExit -- ./main.out | grep LEAK:  

* VALGRIND:  
To install it on your computer, type one of the following commands:  
    brew install valgrind  
or if you have root rights (for Ubuntu / Linux Mint / Debian)  
    sudo apt install valgrind  
To run your executable file using this utility, type in the terminal:  
    valgrind --tool=memcheck --leak-check=yes. /main. out  