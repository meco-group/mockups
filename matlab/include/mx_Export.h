
#ifndef mx_Export_H
#define mx_Export_H

#ifdef mx_BUILT_AS_STATIC
#  define mx_Export
#  define MX_NO_EXPORT
#else
#  ifndef mx_Export
#    ifdef mx_EXPORTS
        /* We are building this library */
#      define mx_Export __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define mx_Export __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MX_NO_EXPORT
#    define MX_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MX_DEPRECATED
#  define MX_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MX_DEPRECATED_EXPORT
#  define MX_DEPRECATED_EXPORT mx_Export MX_DEPRECATED
#endif

#ifndef MX_DEPRECATED_NO_EXPORT
#  define MX_DEPRECATED_NO_EXPORT MX_NO_EXPORT MX_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MX_NO_DEPRECATED
#    define MX_NO_DEPRECATED
#  endif
#endif

#endif
