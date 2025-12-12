cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    Caravan
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(Caravan_Caravan INTERFACE)
add_library(Caravan::Caravan ALIAS Caravan_Caravan)

set_property(
    TARGET Caravan_Caravan PROPERTY
    EXPORT_NAME Caravan
)

target_include_directories(
    Caravan_Caravan ${warning_guard}
    INTERFACE
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(Caravan_Caravan INTERFACE cxx_std_26)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${Caravan_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT Caravan_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of Caravan"
  )
endif()

include(cmake/dev-mode.cmake)
