
prog_name = random_lib

CC = g++ -std=c++11

all: clean comp run

clean:
	rm -rf ./${prog_name}.exe

comp:
	${CC} -o ${prog_name}.exe ${prog_name}.cpp


run:
	./${prog_name}.exe 0
