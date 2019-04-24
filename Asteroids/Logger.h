#pragma once
#include <fstream>
#include <memory>
#include "Worker.h"

class Logger final {
  Logger();
  static std::unique_ptr<Logger> instance_;
  Worker worker_;
  ofstream log_;

 public:
  void initInstance(const string& filename);
  static Logger* getInstance();
  void log(const string& info);
  void log(const function<string()>& f);
  ~Logger();  // NOLINT
};
