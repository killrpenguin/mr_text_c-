
#pragma once

#include <filesystem>
#include <fstream>
#include <termios.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

class mrText {
private:
  termios original_term;
  char buffer;
  std::vector<char> parsing_buffer;
  bool running;
  
  
  std::fstream file_strm;
  const std::filesystem::path file_name;

  void raw_mode();
  void display_key() noexcept;
  void init_file() noexcept;
  void display_file() noexcept;
  void position_cursor(unsigned int row, unsigned int col) noexcept;

protected:
public:
  using cursor_pos = const std::tuple<unsigned int, unsigned int>;

  std::uint32_t row;
  std::uint32_t col;

  mrText() noexcept;
  mrText(std::string file_name) noexcept;
  ~mrText();

  cursor_pos parse_pos(std::streambuf *pbuf) noexcept;
  void parse_key() noexcept;
  void parse_ctrl_event() noexcept;
  void screen_size() noexcept;
  void run() noexcept;
};

typedef void (*functionPtr)();

enum class twoCharKeys {
  Esc = '\x1b',
  Backspace = '\x08',
  Tab = '\x09',
  Enter = '\x0A',
  Delete = '\x7F',
};

enum class ctrl {
  A = 0x01,
  B = 0x02,
  C = 0x03,
  D = 0x04,
  E = 0x05,
  F = 0x06,
  G = 0x07,
  H = 0x08,
  I = 0x09,
  J = 0x0A,
  K = 0x0B,
  L = 0x0C,
  M = 0x0D,
  N = 0x0E,
  O = 0x0F,
  P = 0x10,
  Q = 0x11,
  R = 0x12,
  S = 0x13,
  T = 0x14,
  U = 0x15,
  V = 0x16,
  W = 0x17,
  X = 0x18,
  Y = 0x19,
  Z = 0x1A,
};

const std::unordered_map<ctrl, functionPtr> createCtrlKeyMap() noexcept;

void killLine() noexcept;
void cursorDown() noexcept;
void cursorUp() noexcept;
void cursorLeft() noexcept;
void cursorRight() noexcept;
void deleteChar() noexcept;

struct hexTable {
  const static int ctrlBegin;
  const static int ctrlEnd;
  const static int exitEditor;
  const static int asciiBegin;
  const static int asciiEnd;
};

struct escSeqs {
  const static std::string RN;
  const static std::string CLR_SCRN;
  const static std::string CURSOR_HOME;
  const static std::string CLR_LN;
  const static std::string CLRSCRN_CURSREND;
  const static std::string CLRLN_CURSRFRD;
  const static std::string CLRLN_CURSRBK;
  const static std::string GETCURSORPOS;
  const static std::string SHOWCURSOR;
  const static std::string HIDECURSOR;
  const static std::string SCROLLUP;
  const static std::string SCROLLDOWN;
  const static std::string MVLEFT;
  const static std::string MVRIGHT;
  const static std::string MVUP;
  const static std::string MVDOWN;
  const static std::string MVFARRIGHT;
  const static std::string MVFARDOWN;
};
