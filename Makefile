.PHONY: build run all format
build:
	c++ main.cpp -o toDo
run:
	./toDo
all: build run
format:
	clang-format -i main.cpp
