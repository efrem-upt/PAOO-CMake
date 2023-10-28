add_library(Database Database.cpp)

target_include_directories(Database 
 PUBLIC
  ../Entry/
)