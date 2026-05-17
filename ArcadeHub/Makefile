APP_NAME=ArcadeHub
CXX?=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -Iinclude -Igames
SRC=$(wildcard src/*.cpp) $(wildcard core/*.cpp) $(wildcard games/*.cpp) $(wildcard storage/*.cpp)
OBJ=$(patsubst %.cpp,build/%.o,$(SRC))

ifeq ($(OS),Windows_NT)
EXEEXT=.exe
else
EXEEXT=
endif

BIN=output/$(APP_NAME)$(EXEEXT)
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
	rm -rf build output/$(APP_NAME) output/$(APP_NAME).exe output/$(APP_NAME).nwa output/$(APP_NAME).nwa.exe

.PHONY: all clean
