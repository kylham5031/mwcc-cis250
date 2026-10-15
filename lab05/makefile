build:
		gcc -Wall -Wextra -o copy2 copy2.c

debug:
		gcc -g -o copy2 copy2.c

memcheck: build
		valgrind --leak-check=full ./copy2 source.txt target.txt

clean:
		rm -f copy2 target.txt
