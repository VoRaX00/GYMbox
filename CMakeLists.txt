cmake_minimum_required(VERSION 3.25)
project(GYMbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(GYMbox main.cpp Button.h GYMbox.cpp GYMbox.h Player.cpp Player.h DynamicObject.cpp DynamicObject.h ButtonPlayer.h ButtonPlayer.cpp Game.h Game.cpp ButtStrong.h ButtStrong.cpp)

set(SFML_DIR "${MY_PATH}/lib/sfml/GCC 7.3.0 MinGW (SEH) - 64-bit/SFML-2.6.0/lib/cmake/SFML")

target_link_libraries(GYMbox sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6 REQUIRED graphics network audio window system)
