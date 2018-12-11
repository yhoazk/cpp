
all: clean asm


clean:
	rm -rf ./*.s

asm:
	#g++ -S -O3 post_inc.cpp;
	#g++ -S -O3 pre_inc.cpp;
	g++ -S -O3 *.cpp
	meld post_inc.s pre_inc.s &
