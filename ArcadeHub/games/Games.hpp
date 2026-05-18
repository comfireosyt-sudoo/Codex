#pragma once
#include "Game.hpp"
#include <memory>

std::unique_ptr<Game> makeTetris();
std::unique_ptr<Game> makeSudoku();
std::unique_ptr<Game> makeWaterSort();
std::unique_ptr<Game> makeMemoryMatch();
std::unique_ptr<Game> makeBlockBlast();
std::unique_ptr<Game> makeFruitMerge();
std::unique_ptr<Game> makeHangman();
std::unique_ptr<Game> makeCheckers();
std::unique_ptr<Game> makeSnake();
std::unique_ptr<Game> makeGame2048();
std::unique_ptr<Game> makeMinesweeper();
