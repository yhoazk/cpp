## sudo dnf install opengl*

APP=test

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -lglut -lGL -Wall -Wextra -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe

