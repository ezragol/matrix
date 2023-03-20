#ifndef _LIB_DEBUG_H_
#define _LIB_DEBUG_H_

#include <stdio.h>
#include <stdlib.h>

// wrap in do-while-loop so it works inside unbracketed loops and only runs once
#define debug(...)                     \
    do                                 \
    {                                  \
        fprintf(stderr, "[[debug]] "); \
        fprintf(stderr, __VA_ARGS__);  \
        fprintf(stderr, "\n");         \
    } while (0);

#define fail(code, ...)                \
    do                                 \
    {                                  \
        fprintf(stderr, "[[fatal]] "); \
        fprintf(stderr, __VA_ARGS__);  \
        exit(code);                    \
    } while (0);

#endif