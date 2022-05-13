add_library(weapons
  none.cpp
  staff.cpp
  hammer.cpp
  knife.cpp
  bow.cpp
  sword_big.cpp
  spear.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
