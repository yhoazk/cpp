APP:=initial_iter

all: clean comp run

clean:
	rm -f ${APP}.exe

comp:
	clang++ -g -Wall -Wextra -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe

# Run trace

