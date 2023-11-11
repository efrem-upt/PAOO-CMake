add_library(SecureNoteEntry SecureNoteEntry.cpp)
target_link_libraries(SecureNoteEntry PUBLIC Entry)
target_include_directories(SecureNoteEntry 
 PUBLIC
  ../Entry/
)