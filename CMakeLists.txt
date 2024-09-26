cmake_minimum_required(VERSION 3.14)

project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_FLAGS "-std=c++20 -O2 -g")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(Lib SHARED src/PerfectCache.cc)

add_executable(TESTS src/TESTS.cc)
add_executable(LFUMAIN src/LFUMain.cc)
add_executable(PERFECTMAIN src/PerfectCacheMain.cc)

target_include_directories(TESTS PUBLIC include/)
target_include_directories(LFUMAIN PUBLIC include/)

target_include_directories(PERFECTMAIN PUBLIC include/)
target_include_directories(Lib PUBLIC include/)

target_link_libraries(TESTS GTest::gtest_main Lib)
target_link_libraries(PERFECTMAIN Lib)

include(GoogleTest)
gtest_discover_tests(TESTS)