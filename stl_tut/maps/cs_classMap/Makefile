APP=cs_map
all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -Wextra -g -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
