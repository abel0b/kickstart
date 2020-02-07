CXX=g++

all: build

build: solve

solve: main.cpp
	$(CXX) -march=native main.cpp -o solve

.PHONY: test
test: solve
	python testing_tool.py ./solve
