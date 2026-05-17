#include "Games.hpp"
#include "SaveManager.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

class SimpleGame : public Game {
 public:
  explicit SimpleGame(std::string n) : n_(std::move(n)) {}
  const char* name() const override { return n_.c_str(); }
  void run(SaveManager& save, int difficulty) override {
    int best = save.get(std::string("score.") + n_, 0);
    std::cout << "\n[" << n_ << "] difficulty=" << difficulty << " best=" << best << "\n";
    std::cout << "Enter score achieved this session: ";
    int s = 0; std::cin >> s;
    if (s > best) { save.set(std::string("score.") + n_, s); std::cout << "New highscore!\n"; }
    save.set(std::string("plays.") + n_, save.get(std::string("plays.") + n_, 0) + 1);
  }
 private:
  std::string n_;
};

class SudokuGame : public Game {
 public:
  const char* name() const override { return "Sudoku"; }
  void run(SaveManager& save, int difficulty) override {
    int solved = save.get("sudoku.solved", 0);
    std::cout << "Sudoku difficulty " << difficulty << ". Solved so far=" << solved << "\n";
    std::cout << "Type 1 if solved, 0 otherwise: ";
    int ok=0; std::cin>>ok; if(ok) save.set("sudoku.solved", solved+1);
  }
};

std::unique_ptr<Game> makeTetris(){ return std::make_unique<SimpleGame>("Tetris"); }
std::unique_ptr<Game> makeSudoku(){ return std::make_unique<SudokuGame>(); }
std::unique_ptr<Game> makeWaterSort(){ return std::make_unique<SimpleGame>("WaterSort"); }
std::unique_ptr<Game> makeMemoryMatch(){ return std::make_unique<SimpleGame>("MemoryMatch"); }
std::unique_ptr<Game> makeBlockBlast(){ return std::make_unique<SimpleGame>("BlockBlast"); }
std::unique_ptr<Game> makeFruitMerge(){ return std::make_unique<SimpleGame>("FruitMerge"); }
std::unique_ptr<Game> makeHangman(){ return std::make_unique<SimpleGame>("Hangman"); }
std::unique_ptr<Game> makeCheckers(){ return std::make_unique<SimpleGame>("Checkers"); }
std::unique_ptr<Game> makeSnake(){ return std::make_unique<SimpleGame>("Snake"); }
std::unique_ptr<Game> makeGame2048(){ return std::make_unique<SimpleGame>("2048"); }
std::unique_ptr<Game> makeMinesweeper(){ return std::make_unique<SimpleGame>("Minesweeper"); }
