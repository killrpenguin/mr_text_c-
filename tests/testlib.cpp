#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <iostream>
#include <mrText/mrText.hpp>
#include <sstream>

TEST_CASE("Check parse_cursor_pos", "[main]") {
  mrText editor;
  std::istringstream testBuffer("40;120R");

  std::cin.rdbuf(testBuffer.rdbuf());
  std::streambuf *buffer_p = testBuffer.rdbuf();
  std::tuple<unsigned int, unsigned int> ret_val{editor.parse_pos(buffer_p)};

  REQUIRE(std::get<0>(ret_val) == 40);
  REQUIRE(std::get<1>(ret_val) == 120);
}

TEST_CASE("Check line write", "[main]") {
  // std::ostringstream testBuffer{};
  // std::cout.rdbuf(testBuffer.rdbuf());
  // std::string line{"this is a test"};

}

//  Clear buffer with these two member functions between asserts.
//  testBuffer.str("");
//  testBuffer.clear();
