project(Vaultify)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Database)
add_subdirectory(Entry)

add_executable(Vaultify main.cpp)

target_link_libraries(Vaultify PUBLIC Database)
target_link_libraries(Vaultify PUBLIC Entry)

target_include_directories(Vaultify PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Entry"
                          "${PROJECT_SOURCE_DIR}/Database"
                          )
