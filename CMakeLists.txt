cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(CreateCircle)

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})



add_executable(CreateCircle CreateCircle.cxx)

target_link_libraries(CreateCircle  ${ITK_LIBRARIES})
