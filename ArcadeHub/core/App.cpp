#include "App.hpp"
#include "SaveManager.hpp"
#include "Games.hpp"
#include <iostream>

App::App() : saves_(new SaveManager("storage/arcadehub.sav")) { saves_->load(); }

void App::ensureGames() {
  if (!games_.empty()) return;
  games_.push_back(makeTetris()); games_.push_back(makeSudoku()); games_.push_back(makeWaterSort());
  games_.push_back(makeMemoryMatch()); games_.push_back(makeBlockBlast()); games_.push_back(makeFruitMerge());
  games_.push_back(makeHangman()); games_.push_back(makeCheckers()); games_.push_back(makeSnake());
  games_.push_back(makeGame2048()); games_.push_back(makeMinesweeper());
}

void App::drawMenu() const {
  std::cout << "\n=== Arcade Hub ===\nDifficulty: " << difficulty_ << "\n";
  std::cout << "Select game index, -1=settings, -2=stats, -9=exit\n";
  for (size_t i = 0; i < games_.size(); ++i) std::cout << i << ": " << games_[i]->name() << "\n";
}

void App::drawStats() const { std::cout << "Total launches: " << saves_->get("stat.launches", 0) << "\n"; }

void App::drawSettings() const { std::cout << "Set difficulty (0-2): "; }

void App::launchGame(size_t index) {
  saves_->set(std::string("unlock.") + games_[index]->name(), 1);
  games_[index]->run(*saves_, difficulty_);
  saves_->flush();
}

void App::run() {
  ensureGames();
  saves_->set("stat.launches", saves_->get("stat.launches", 0) + 1);
  while (true) {
    drawMenu();
    int x; if (!(std::cin >> x)) break;
    if (x == -9) break;
    if (x == -2) { drawStats(); continue; }
    if (x == -1) { drawSettings(); std::cin >> difficulty_; saves_->set("settings.difficulty", difficulty_); continue; }
    if (x >= 0 && x < (int)games_.size()) launchGame((size_t)x);
  }
  saves_->flush();
}
