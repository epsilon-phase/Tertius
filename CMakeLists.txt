cmake_minimum_required(VERSION 3.0)
project(Tertius)

set(Tertius_VERSION_MINOR 0)
set(Tertius_VERSION_MAJOR 0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1 0 --dirty)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/GitSha1.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/GitSHA1.cpp" @ONLY)

find_package(SFML 2.4 REQUIRED system window graphics)

add_executable(Tertius ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/GitSHA1.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/blueprint_layer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/blueprint_renderer.cpp )
target_link_libraries(Tertius ${EXECUTABLE_NAME} ${SFML_LIBRARIES})

