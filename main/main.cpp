#include "mrText/mrText.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {

  try {
    if (argc > 1) {
      mrText editor(argv[1]);
      editor.run();
    } else {
      mrText editor;
      editor.run();
    }
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    return -1;
  }
  return 0;
}
