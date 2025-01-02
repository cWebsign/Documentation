.PHONY: dependencies build

dependencies:
	git clone https://github.com/clibplus/clibplus.git
	cd clibplus; make
	pm -i str
	pm -i arr
	pm -i Net
	pm -i map

	mv /usr/local/lib/Net/* /usr/local/lib/
	ldconfig

build:
	gcc main.c src/*.c src/doc/*.c assets/*.c assets/doc/*.c -lwebsign -lstr -larr -lmap -lfile -g -g1 -ggdb

	