
#ifndef eng_Export_H
#define eng_Export_H

#ifdef eng_BUILT_AS_STATIC
#  define eng_Export
#  define ENG_NO_EXPORT
#else
#  ifndef eng_Export
#    ifdef eng_EXPORTS
        /* We are building this library */
#      define eng_Export __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define eng_Export __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ENG_NO_EXPORT
#    define ENG_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ENG_DEPRECATED
#  define ENG_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ENG_DEPRECATED_EXPORT
#  define ENG_DEPRECATED_EXPORT eng_Export ENG_DEPRECATED
#endif

#ifndef ENG_DEPRECATED_NO_EXPORT
#  define ENG_DEPRECATED_NO_EXPORT ENG_NO_EXPORT ENG_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ENG_NO_DEPRECATED
#    define ENG_NO_DEPRECATED
#  endif
#endif

#endif
