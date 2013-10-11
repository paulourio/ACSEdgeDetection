# Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> 

MAKEFLAGS += --no-print-directory

.PHONY: all clean release debug lint

all: debug

release: build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
	cd build && make -j9

debug: build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug
	cd build && scan-build -v make -j9

build: 
	mkdir build

lint:
	cpplint --filter=-whitespace/tab,-whitespace/labels,-whitespace/braces --root=moead *.cc *.h

clean:
	$(RM) -R build/
 
