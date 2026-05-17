#pragma once
#include <string>
class SaveManager;

class Game {
 public:
  virtual ~Game() = default;
  virtual const char* name() const = 0;
  virtual void run(SaveManager& save, int difficulty) = 0;
};
