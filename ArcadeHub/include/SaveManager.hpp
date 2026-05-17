#pragma once
#include <map>
#include <string>

class SaveManager {
 public:
  explicit SaveManager(const std::string& path);
  void load();
  void flush() const;
  int get(const std::string& key, int def = 0) const;
  void set(const std::string& key, int value);

 private:
  std::string path_;
  std::map<std::string, int> ints_;
};
