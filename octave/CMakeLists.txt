cmake_minimum_required(VERSION 3.1...3.16)

# https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf
# https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
# https://dominikberner.ch/cmake-interface-lib/

project(octave
  LANGUAGES C)

set(INSTALL_PREFIX  "")

get_directory_property(hasParent PARENT_DIRECTORY)
if(hasParent)
  set(INSTALL_PREFIX "${PROJECT_NAME}/")
endif()
  
  

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIBRARY_NAME octinterp_adaptor)

add_library(${LIBRARY_NAME} SHARED src/mex.c include/mex.h)

if(WIN32)
  set_target_properties(${LIBRARY_NAME} PROPERTIES PREFIX "lib" IMPORT_PREFIX "lib")
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

set(OCTAVE_MEX_EXT "mex")

install(TARGETS ${LIBRARY_NAME} EXPORT octaveTargets
  LIBRARY DESTINATION ${INSTALL_PREFIX}lib
  ARCHIVE DESTINATION ${INSTALL_PREFIX}${ARCHIVE_DIR}
  RUNTIME DESTINATION ${INSTALL_PREFIX}${RUNTIME_DIR})


add_library(octave INTERFACE)

if(WIN32)
  target_link_libraries(octave INTERFACE ${LIBRARY_NAME})
  target_compile_definitions(octave INTERFACE __STDC_UTF_16__ WINMAT64)
endif()

install(TARGETS octave EXPORT octaveTargets
  LIBRARY DESTINATION ${INSTALL_PREFIX}lib
  ARCHIVE DESTINATION ${INSTALL_PREFIX}lib
  RUNTIME DESTINATION ${INSTALL_PREFIX}bin
  INCLUDES DESTINATION ${INSTALL_PREFIX}include)

target_include_directories(${LIBRARY_NAME} PUBLIC
  $<BUILD_INTERFACE:${octave_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)

target_include_directories(octave INTERFACE
  $<BUILD_INTERFACE:${octave_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)



install(DIRECTORY include/ DESTINATION ${INSTALL_PREFIX}include)

install(EXPORT octaveTargets
  FILE octaveTargets.cmake
  NAMESPACE octave::
  DESTINATION cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/octaveConfigVersion.cmake
  VERSION 7.3
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  INSTALL_DESTINATION
  cmake)



install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/octaveConfigVersion.cmake"
  DESTINATION cmake
)
