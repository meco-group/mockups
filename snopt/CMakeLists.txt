cmake_minimum_required(VERSION 3.10)

project(snopt
  LANGUAGES CXX)

set(INSTALL_PREFIX  "")

get_directory_property(hasParent PARENT_DIRECTORY)
if(hasParent)
  set(INSTALL_PREFIX "${PROJECT_NAME}/")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(snopt SHARED src/snopt.cpp include/snopt_cwrap.h)

set_target_properties(snopt PROPERTIES OUTPUT_NAME snopt7)

if(WIN32)
  set_target_properties(snopt PROPERTIES PREFIX "" IMPORT_PREFIX "")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(NBITS_TWO "32")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(NBITS_TWO "64")
endif()

set(ARCHIVE_DIR lib)
set(RUNTIME_DIR bin)
  
if(${CMAKE_GENERATOR} MATCHES "Visual Studio*")
  set(ARCHIVE_DIR extern/lib/win${NBITS_TWO}/microsoft)
  set(RUNTIME_DIR bin/win${NBITS_TWO})
elseif(${CMAKE_GENERATOR} MATCHES "MSYS Makefiles")
  set(ARCHIVE_DIR extern/lib/win${NBITS_TWO}/mingw${NBITS_TWO})
  set(RUNTIME_DIR bin/win${NBITS_TWO})
endif()


install(TARGETS snopt EXPORT snoptTargets
  LIBRARY DESTINATION ${INSTALL_PREFIX}lib
  ARCHIVE DESTINATION ${INSTALL_PREFIX}lib
  RUNTIME DESTINATION ${INSTALL_PREFIX}bin
  INCLUDES DESTINATION ${INSTALL_PREFIX}include)

target_include_directories(snopt PUBLIC
  $<BUILD_INTERFACE:${snopt_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)

install(DIRECTORY include/ DESTINATION ${INSTALL_PREFIX}include)

install(EXPORT snoptTargets
  FILE snoptTargets.cmake
  NAMESPACE snopt::
  DESTINATION cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/snoptConfigVersion.cmake
  VERSION 13.1
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  INSTALL_DESTINATION
  cmake)



install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/snoptConfigVersion.cmake"
  DESTINATION cmake
)
