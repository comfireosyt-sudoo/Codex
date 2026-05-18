APP_NAME=ArcadeHub
CXX?=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -Iinclude -Igames
SRC=$(wildcard src/*.cpp) $(wildcard core/*.cpp) $(wildcard games/*.cpp) $(wildcard storage/*.cpp)
OBJ=$(patsubst %.cpp,build/%.o,$(SRC))
NWA=output/$(APP_NAME).nwa

all: $(NWA)

build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NWA): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@
	@echo "Packaged $(NWA)"

clean:
	rm -rf build output/$(APP_NAME).nwa output/$(APP_NAME).exe output/$(APP_NAME).nwa.exe

.PHONY: all clean
