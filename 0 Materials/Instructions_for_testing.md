* Стилевые тесты.
Чтобы запустить проверку на стиль, выполните следующую команду:  
    clang-format -n src/sourcefile_name.c  
Чтобы скачать clang-format, введите в терминал одну из следующих команд:  
    brew install clang-format  
или, если у вас есть root-права (для Ubuntu / Linux Mint / Debian)  
    sudo apt install clang-format  

* LEAKS  
Чтобы запустить ваш исполняемый файл с помощью этой утилиты, наберите в терминале:  
leaks -atExit -- ./main.out | grep LEAK:  

* VALGRIND  
Чтобы установить valgrind на компьютер, введите одну из следующих команд:  
    brew install valgrind  
или, если у вас есть root-права (для Ubuntu / Linux Mint / Debian)  
    sudo apt install valgrind  
Чтобы запустить ваш исполняемый файл с помощью этой утилиты, наберите в терминале:  
    valgrind --tool=memcheck --leak-check=yes  ./main.out  
