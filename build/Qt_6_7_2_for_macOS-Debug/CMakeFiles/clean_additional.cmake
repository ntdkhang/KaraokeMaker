# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/KaraokeMaker_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/KaraokeMaker_autogen.dir/ParseCache.txt"
  "KaraokeMaker_autogen"
  )
endif()
