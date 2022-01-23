APP:=curl_example

all: clean comp run

clean:
	rm -f ${APP}.exe

comp:
	g++ -std=c++14 -Wall -o ${APP}.exe -lcurl ${APP}.cpp

run:
	./${APP}.exe
