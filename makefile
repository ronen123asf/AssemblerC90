output : main.o signTable.o ErrorCheck.o preAssembler.o binary.o codeFiles.o stdout.o secondPass.o firstPass.o assembler.o utils.o

main.o: main.c header.h
		gcc -c -Wall -ansi -pedantic main.c -o main.o -lm
signTable.o: signTable.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o signTable.o -lm
ErrorCheck.o: ErrorCheck.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o ErrorCheck.o -lm
preAssembler.o: preAssembler.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o preAssembler.o -lm
binary.o: binary.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o binary.o -lm
codeFiles.o: codeFiles.c header.h
	gcc -c -Wall -ansi -pedantic codeFiles.c -o main.o -lm
stdout.o: stdout.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o stdout.o -lm
secondPass.o: secondPass.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o secondPass.o -lm
firstPass.o: firstPass.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o firstPass.o -lm
assembler.o: assembler.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o assembler.o -lm
utils.o : utils.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o utils.o -lm