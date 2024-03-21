
#ifndef mex_Export_H
#define mex_Export_H

#ifdef mex_BUILT_AS_STATIC
#  define mex_Export
#  define MEX_NO_EXPORT
#else
#  ifndef mex_Export
#    ifdef mex_EXPORTS
        /* We are building this library */
#      define mex_Export __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define mex_Export __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MEX_NO_EXPORT
#    define MEX_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MEX_DEPRECATED
#  define MEX_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MEX_DEPRECATED_EXPORT
#  define MEX_DEPRECATED_EXPORT mex_Export MEX_DEPRECATED
#endif

#ifndef MEX_DEPRECATED_NO_EXPORT
#  define MEX_DEPRECATED_NO_EXPORT MEX_NO_EXPORT MEX_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MEX_NO_DEPRECATED
#    define MEX_NO_DEPRECATED
#  endif
#endif

#endif
