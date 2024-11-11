set(HEADER_LIST "${Mr_Text_SOURCE_DIR}/include/mrText/mrText.hpp")

add_library(mrText mrText.cpp ${HEADER_LIST})

target_include_directories(mrText PUBLIC ../include)

target_link_libraries(mrText PRIVATE)

target_compile_features(mrText PUBLIC)


