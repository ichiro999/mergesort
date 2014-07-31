all:
	gcc -o testmain testmain.c -std=gnu99 -g

clean:
	- rm -rf testmain
