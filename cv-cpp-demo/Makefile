CXX = g++

INCLUDES = -I/usr/local/include/opencv4

LIBS = $(shell pkg-config --libs opencv4)

COMPILER_FLAGS = -std=c++11

img : img.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

camera : camera.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

video : video.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

draw : draw.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

color-detect : color-detect.cpp
	$(CXX) $(COMPILER_FLAGS) $< $(INCLUDES) $(LIBS) -o $@.exe

clean:
	rm -rf *.exe *.gdb *.o


