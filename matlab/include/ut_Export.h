
#ifndef ut_Export_H
#define ut_Export_H

#ifdef ut_BUILT_AS_STATIC
#  define ut_Export
#  define UT_NO_EXPORT
#else
#  ifndef ut_Export
#    ifdef ut_EXPORTS
        /* We are building this library */
#      define ut_Export __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ut_Export __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef UT_NO_EXPORT
#    define UT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef UT_DEPRECATED
#  define UT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef UT_DEPRECATED_EXPORT
#  define UT_DEPRECATED_EXPORT ut_Export UT_DEPRECATED
#endif

#ifndef UT_DEPRECATED_NO_EXPORT
#  define UT_DEPRECATED_NO_EXPORT UT_NO_EXPORT UT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef UT_NO_DEPRECATED
#    define UT_NO_DEPRECATED
#  endif
#endif

#endif
