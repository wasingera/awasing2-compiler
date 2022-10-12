bminor: main.o scanner.o parser.o
	gcc -o $@ $^

test-parser: bminor
	./tests/parser_tests/run_tests.sh

main.o: main.c tokens.h
	gcc -c -o $@ main.c

scanner.o: scanner.c tokens.h
	gcc -c -o $@ scanner.c

parser.o: parser.c tokens.h
	gcc -c -o $@ parser.c

scanner.c: scanner.flex
	flex -o $@ scanner.flex

parser.c: parser.bison
	bison -o $@ --defines=tokens.h parser.bison -r all --report-file=parser.output

clean:
	rm ./bminor ./*.o
