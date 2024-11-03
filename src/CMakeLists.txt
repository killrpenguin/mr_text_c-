set(HEADER_LIST "${Vulkan_Triangle_SOURCE_DIR}/include/my_lib/lib.hpp")

add_library(my_lib lib.cpp ${HEADER_LIST})

target_include_directories(my_lib PUBLIC ../include)

target_link_libraries(my_lib PRIVATE)

target_compile_features(my_lib PUBLIC cxx_std_11)


