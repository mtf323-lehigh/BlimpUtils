all:
	mkdir -p bin
	$(CXX) src/queuetest.cpp -Iinclude -std=c++17 -O3 -o bin/queuetest

clean:
	rm -r bin