all : clean
	gcc -Wall -Wextra -Werror -o graph graph.c print.c infix.c postfix.c stack.c
	./graph

clean :
	rm -rf graph

clang_format_check :
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c

clang_format_do :
	clang-format -i *.c
