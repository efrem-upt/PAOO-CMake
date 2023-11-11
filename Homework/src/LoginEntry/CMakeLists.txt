add_library(LoginEntry LoginEntry.cpp)
target_link_libraries(LoginEntry PUBLIC Entry)
target_include_directories(LoginEntry 
 PUBLIC
  ../Entry/
)