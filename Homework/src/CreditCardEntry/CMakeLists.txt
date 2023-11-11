add_library(CreditCardEntry CreditCardEntry.cpp)
target_link_libraries(CreditCardEntry PUBLIC Entry)
target_include_directories(CreditCardEntry 
 PUBLIC
  ../Entry/
)