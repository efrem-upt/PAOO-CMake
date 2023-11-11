cmake_minimum_required(VERSION 3.10)
project(Vaultify)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Database)
add_subdirectory(Entry)
add_subdirectory(LoginEntry)
add_subdirectory(CreditCardEntry)
add_subdirectory(SecureNoteEntry)

add_executable(Vaultify main.cpp)

target_link_libraries(Vaultify PUBLIC Database)
target_link_libraries(Vaultify PUBLIC Entry)
target_link_libraries(Vaultify PUBLIC LoginEntry)
target_link_libraries(Vaultify PUBLIC CreditCardEntry)
target_link_libraries(Vaultify PUBLIC SecureNoteEntry)

target_include_directories(Vaultify PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Entry"
                          "${PROJECT_SOURCE_DIR}/LoginEntry"
                          "${PROJECT_SOURCE_DIR}/CreditCardEntry"
                          "${PROJECT_SOURCE_DIR}/SecureNoteEntry"
                          "${PROJECT_SOURCE_DIR}/Database"
                          )
