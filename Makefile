.PHONY: dependencies build

dependencies:
	git clone https://github.com/clibplus/clibplus.git
	cd clibplus; make
	pm -i str
	pm -i arr
	pm -i Net

	mv /usr/local/lib/Net/* /usr/local/lib/
	ldconfig

build:
	gcc main.c -o main -lstr -larr -lmap -lweb -lwebcfg -lwebsign