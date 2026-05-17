APP_NAME=ArcadeHub
CXX?=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -Iinclude -Igames
SRC=$(wildcard src/*.cpp) $(wildcard core/*.cpp) $(wildcard games/*.cpp) $(wildcard storage/*.cpp)
OBJ=$(patsubst %.cpp,build/%.o,$(SRC))
BIN=output/$(APP_NAME)
NWA=output/$(APP_NAME).nwa

all: $(NWA)

build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@

$(NWA): $(BIN)
	@cp $(BIN) $(NWA)
	@echo "Packaged $(NWA)"

clean:
	rm -rf build output/$(APP_NAME) output/$(APP_NAME).nwa

.PHONY: all clean
