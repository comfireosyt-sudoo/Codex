#pragma once
#include <memory>
#include <string>
#include <vector>

 #include "Game.hpp"
#include "SaveManager.hpp"

class App {
 public:
  App();
  void run();

 private:
  void drawMenu() const;
  void drawStats() const;
  void drawSettings() const;
  void launchGame(size_t index);
  void ensureGames();

  std::vector<std::unique_ptr<Game>> games_;
  std::unique_ptr<SaveManager> saves_;
  int selected_ = 0;
  int difficulty_ = 1;
};
