all: tests

tests: tests.cpp
	g++ -std=c++11 tests.cpp -o tests


test: tests
	./tests "$(try)"
	
clean:
	rm -f tests