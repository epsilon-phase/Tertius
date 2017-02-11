cmake_minimum_required(VERSION 3.0)
project(Tertius)

set(Tertius_VERSION_MINOR 0)
set(Tertius_VERSION_MAJOR 0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)

find_package(SFML 2.4 REQUIRED system window graphics)

add_executable(Tertius src/main.cpp)
target_link_libraries(Tertius ${EXECUTABLE_NAME} ${SFML_LIBRARIES})
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/GitSha1.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/GitSHA1.cpp" @ONLY)
target_sources(Tertius PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/GitSha1.cpp" src/GitSha1.h)

