CXX = g++

INCLUDES = -I/usr/local/include/opencv4

LIBS = $(shell pkg-config --libs opencv4)

COMPILER_FLAGS = -std=c++11

face-detect : face-detect.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

clean:
	rm -rf *.exe *.gdb *.o


