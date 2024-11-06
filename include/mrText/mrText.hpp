#pragma once
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <termios.h>
#include <unistd.h>

class mrText {
private:
  termios original_term;
  char buffer;
  std::fstream file;
  std::filesystem::path file_path;

  const void write_escape_seq(const char seq[]);
  const void write();
  const void raw_mode();

public:
  mrText() noexcept;
  mrText(std::string file_name) noexcept;
  ~mrText() noexcept;
  const void run();
  const void create_file();
};
