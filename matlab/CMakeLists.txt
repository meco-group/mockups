cmake_minimum_required(VERSION 3.1...3.16)

# https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf
# https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
# https://dominikberner.ch/cmake-interface-lib/

project(matlab
  LANGUAGES C CXX)

set(INSTALL_PREFIX  "")

get_directory_property(hasParent PARENT_DIRECTORY)
if(hasParent)
  set(INSTALL_PREFIX "${PROJECT_NAME}/")
endif()
  
  

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(mex SHARED src/mex.cpp include/mex.h include/mex_versions.h include/mex_Export.h)
add_library(mx SHARED src/mx.cpp include/mex.h include/matrix.h include/matrix_versions.h include/mx_Export.h)
add_library(ut SHARED src/ut.cpp include/ut.h include/ut_Export.h)
add_library(eng SHARED src/eng.cpp include/eng_Export.h)

include(GenerateExportHeader)

GENERATE_EXPORT_HEADER(
    mex
    BASE_NAME mex
	EXPORT_MACRO_NAME mex_Export
	EXPORT_FILE_NAME include/mex_Export.h
    STATIC_DEFINE mex_BUILT_AS_STATIC
)
GENERATE_EXPORT_HEADER(
    mx
    BASE_NAME mx
	EXPORT_MACRO_NAME mx_Export
	EXPORT_FILE_NAME include/mx_Export.h
    STATIC_DEFINE mx_BUILT_AS_STATIC
)
GENERATE_EXPORT_HEADER(
    ut
    BASE_NAME ut
	EXPORT_MACRO_NAME ut_Export
	EXPORT_FILE_NAME include/ut_Export.h
    STATIC_DEFINE ut_BUILT_AS_STATIC
)
GENERATE_EXPORT_HEADER(
    eng
    BASE_NAME eng
	EXPORT_MACRO_NAME eng_Export
	EXPORT_FILE_NAME include/eng_Export.h
    STATIC_DEFINE eng_BUILT_AS_STATIC
)
#target_include_directories(mex PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
#target_include_directories(mx PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
#target_include_directories(ut PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
#target_include_directories(eng PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")

if (NOT MATLAB_API_VERSION)
  set(MATLAB_API_VERSION 800)
endif()


if (MATLAB_API_VERSION)
  target_compile_definitions(mex PUBLIC "MATLAB_API_VERSION=${MATLAB_API_VERSION}")
  target_compile_definitions(mx PUBLIC "MATLAB_API_VERSION=${MATLAB_API_VERSION}")
endif()

set_target_properties(mex mx ut eng PROPERTIES CXX_STANDARD 11)

if(WIN32)
  set_target_properties(mex mx ut eng PROPERTIES PREFIX "lib" IMPORT_PREFIX "lib")
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

if(APPLE)
 if (${CMAKE_HOST_SYSTEM_PROCESSOR} MATCHES "arm64")
   set(MATLAB_MEX_EXT "mexmaca${NBITS_TWO}")
 else()
   set(MATLAB_MEX_EXT "mexmaci${NBITS_TWO}")
 endif()
elseif(WIN32)
  set(MATLAB_MEX_EXT "mexw${NBITS_TWO}")
else()
  set(MATLAB_MEX_EXT "mexa${NBITS_TWO}")
endif()


set(LIBRARIES mex mx ut eng)

if(WIN32)
  configure_file(mexext.bat.in mexext.bat)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mexext.bat DESTINATION bin)
  install(FILES mex.bat DESTINATION bin)
else()
  add_executable(mexext src/mexext.c)
  target_compile_definitions(mexext PRIVATE MATLAB_MEX_EXT=\"${MATLAB_MEX_EXT}\")
  set(LIBRARIES ${LIBRARIES} mexext)
  add_executable(mexex src/mexex.c)
  set_target_properties(mexex PROPERTIES OUTPUT_NAME "mex")
  set(LIBRARIES ${LIBRARIES} mexex)
endif()

install(TARGETS ${LIBRARIES} EXPORT matlabTargets
  LIBRARY DESTINATION ${INSTALL_PREFIX}lib
  ARCHIVE DESTINATION ${INSTALL_PREFIX}${ARCHIVE_DIR}
  RUNTIME DESTINATION ${INSTALL_PREFIX}${RUNTIME_DIR})


add_library(matlab INTERFACE)
target_link_libraries(matlab INTERFACE mex mx ut eng)

if(WIN32)
  target_compile_definitions(matlab INTERFACE __STDC_UTF_16__ WINMAT64)
endif()

install(TARGETS matlab EXPORT matlabTargets
  LIBRARY DESTINATION ${INSTALL_PREFIX}lib
  ARCHIVE DESTINATION ${INSTALL_PREFIX}lib
  RUNTIME DESTINATION ${INSTALL_PREFIX}bin
  INCLUDES DESTINATION ${INSTALL_PREFIX}include)

target_include_directories(mex PUBLIC
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)

target_include_directories(ut PUBLIC
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(mx PUBLIC
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)

target_include_directories(matlab INTERFACE
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${INSTALL_PREFIX}include>
)



install(DIRECTORY include/ DESTINATION ${INSTALL_PREFIX}include)

install(EXPORT matlabTargets
  FILE matlabTargets.cmake
  NAMESPACE matlab::
  DESTINATION cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/matlabConfigVersion.cmake
  VERSION 1.2014a
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  INSTALL_DESTINATION
  cmake)



install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/matlabConfigVersion.cmake"
  DESTINATION cmake
)

install(FILES src/c_mexapi_version.c
  DESTINATION ${INSTALL_PREFIX}src
)

