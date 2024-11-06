#include <asm-generic/errno-base.h>
#include <cstdio>
#include <cstdlib>
#include <errno.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <mrText/mrText.hpp>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <termios.h>
#include <unistd.h>

const static char CLR_SCRN[5]{"\x1b[2J"};
const static char CURSOR_HOME[7]{"\x1b[H"};

mrText::mrText() noexcept {
  raw_mode();
  write_escape_seq(CLR_SCRN);
  write_escape_seq(CURSOR_HOME);
}

mrText::mrText(std::string file_name) noexcept : file_path(file_name) {
  raw_mode();
  write_escape_seq(CLR_SCRN);
  write_escape_seq(CURSOR_HOME);
}

mrText::~mrText() noexcept {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_term);
  write_escape_seq(CLR_SCRN);
  write_escape_seq(CURSOR_HOME);
}

const void mrText::write() {
  std::cout.write(&buffer, sizeof(buffer));
  std::cout.flush();
}

const void mrText::write_escape_seq(const char seq[]) {
  std::cout.write(seq, sizeof(&seq));
  std::cout.flush();
}

const void mrText::raw_mode() {
  if (tcgetattr(STDIN_FILENO, &original_term) != 0) {
    throw std::runtime_error("Unable to backup terminal settings.");
    // Do not try to continue if a valid backup terminal settings struct can be
    // established.
    std::abort();
  }
  struct termios raw_term;
  raw_term = original_term;

  raw_term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw_term.c_oflag &= ~(OPOST);
  raw_term.c_cflag |= (CS8);
  raw_term.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw_term.c_cc[VMIN] = 0;
  raw_term.c_cc[VTIME] = 1;

  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_term) != 0) {
    throw std::runtime_error("Unable to set raw terminal settings.");
  }
}

const void mrText::create_file() {
  std::cout << file_path;
  // if (file_path.empty()) {
  //   std::filesystem::path new_file{"new.txt"};
  //   file_path = new_file;
  // }
  // std::string line;
  // std::fstream new_file{file_path,
  //                       file.binary | file.trunc | file.in | file.out};

  // while (std::getline(new_file, line)) {
  //   std::cout << line;
  // }
  // new_file.close();
}

const void mrText::run() {
  while (true) {
    if (read(STDIN_FILENO, &buffer, 1) == 1) {
      write();
    }
    if (buffer == 'q') {
      write_escape_seq(CLR_SCRN);
      break;
    }
  }
}
