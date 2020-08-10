add_library(mex SHARED mex.c ../include/mex.h)
add_library(mx SHARED mx.c)
add_library(ut SHARED ut.c)

target_include_directories(mex PUBLIC
  $<BUILD_INTERFACE:${mex_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS mex mx ut EXPORT matlabTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)


