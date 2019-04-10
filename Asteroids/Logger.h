#pragma once
#include <fstream>
#include "Worker.h"

class Logger final {
  Logger();
  static unique_ptr<Logger> instance_;
  Worker worker_;
  ofstream log_;

 public:
  void initInstance(const string& filename);
  static Logger* getInstance();
  void log(const string& info);
  void log(const function<string()>& f);
  ~Logger();  // NOLINT
};
