# CMakeList.txt : CMake project for mpgre1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

project ("mpgre")

find_package(Vulkan REQUIRED)
find_package(VulkanHeaders CONFIG)
message(STATUS Vulkan "Include directory: ${Vulkan_INCLUDE_DIRS}")

include_directories(AFTER ${Vulkan_INCLUDE_DIRS})
include_directories(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)


file(GLOB PROJECT_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB PROJECT_INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable (mpgre_test ${PROJECT_SOURCE_FILES} ${PROJECT_INCLUDE_FILES})

target_link_libraries(mpgre_test PRIVATE Vulkan::Vulkan)
target_link_libraries(mpgre_test PRIVATE Vulkan::Headers)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET mpgre_test PROPERTY CXX_STANDARD 20)
endif()

