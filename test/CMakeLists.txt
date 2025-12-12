cmake_minimum_required(VERSION 3.14)

project(CaravanTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(Caravan REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(Caravan_test source/Caravan_test.cpp)
target_link_libraries(Caravan_test PRIVATE Caravan::Caravan)
target_compile_features(Caravan_test PRIVATE cxx_std_26)

add_test(NAME Caravan_test COMMAND Caravan_test)

# ---- End-of-file commands ----

add_folders(Test)
