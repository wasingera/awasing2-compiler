bminor: main.o scanner.o
	gcc -o $@ $^

main.o: main.c tokens.h
	gcc -c -o $@ main.c

scanner.o: scanner.c tokens.h
	gcc -c -o $@ scanner.c

scanner.c: scanner.flex
	flex -o $@ scanner.flex

clean:
	rm ./bminor ./tests/*.out ./tests/sample/*.out ./*.o
