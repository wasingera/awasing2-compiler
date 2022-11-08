bminor: main.o scanner.o parser.o expr.o stmt.o type.o decl.o param_list.o scope.o hash_table.o symbol.o resolve.o typecheck.o
	gcc -o $@ $^ -g

test-printer: bminor
	./tests/printer_tests/run_tests.sh

test-parser: bminor
	./tests/parser_tests/run_tests.sh

test-scanner: bminor
	./tests/scanner_tests/run_tests.sh

main.o: main.c tokens.h
	gcc -c -o $@ main.c -g

typecheck.o: typecheck.c typecheck.h
	gcc -c -o $@ typecheck.c

hash_table.o: hash_table.c hash_table.h
	gcc -c -o $@ hash_table.c
	
resolve.o: resolve.c resolve.h
	gcc -c -o $@ resolve.c

symbol.o: symbol.c symbol.h
	gcc -c -o $@ symbol.c

scope.o: scope.c scope.h
	gcc -c -o $@ scope.c

decl.o: decl.c decl.h
	gcc -c -o $@ decl.c

param_list.o: param_list.c param_list.h
	gcc -c -o $@ param_list.c

stmt.o: stmt.c stmt.h
	gcc -c -o $@ stmt.c -g

expr.o: expr.c expr.h
	gcc -c -o $@ expr.c -g

type.o: type.c type.h
	gcc -c -o $@ type.c

scanner.o: scanner.c tokens.h
	gcc -c -o $@ scanner.c -g

parser.o: parser.c tokens.h
	gcc -c -o $@ parser.c -g

scanner.c: scanner.flex
	flex -o $@ scanner.flex

parser.c: parser.bison
	bison -o $@ --defines=tokens.h parser.bison -r all --report-file=parser.output

clean:
	rm ./bminor ./*.o
	find tests -name "*.out*" -type f -delete

clean-tests:
	find tests -name "*.out*" -type f -delete
