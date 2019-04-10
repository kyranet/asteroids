#include "Logger.h"

unique_ptr<Logger> Logger::instance_ = unique_ptr<Logger>();

Logger::Logger() = default;

Logger::~Logger() {  // NOLINT
  log_.close();
}

void Logger::initInstance(const string& filename) {
  log_.open(filename);
  worker_.start();
}

Logger* Logger::getInstance() {
  if (instance_ == nullptr) {
    instance_.reset(new Logger());
  }
  return instance_.get();
}

void Logger::log(const string& info) {
  log([info]() { return info; });
}

void Logger::log(const function<string()>& f) {
  worker_.execute([this, f]() { log_ << f().c_str() << '\n'; });
}
