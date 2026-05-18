#include "SaveManager.hpp"
#include <fstream>
#include <sstream>

SaveManager::SaveManager(const std::string& path) : path_(path) {}

void SaveManager::load() {
  ints_.clear();
  std::ifstream in(path_);
  if (!in.good()) return;
  std::string line;
  while (std::getline(in, line)) {
    std::istringstream ss(line);
    std::string key; int val;
    if (std::getline(ss, key, '=') && (ss >> val)) ints_[key] = val;
  }
}

void SaveManager::flush() const {
  std::ofstream out(path_, std::ios::trunc);
  if (!out.good()) return;
  for (const auto& kv : ints_) out << kv.first << '=' << kv.second << '\n';
}

int SaveManager::get(const std::string& key, int def) const {
  auto it = ints_.find(key);
  return it == ints_.end() ? def : it->second;
}

void SaveManager::set(const std::string& key, int value) { ints_[key] = value; }
