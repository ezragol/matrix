#include <stdio.h>
#include <stdlib.h>

#define debug(...)                 \
    fprintf(stderr, "[[debug]] "); \
    fprintf(stderr, __VA_ARGS__);  \
    fprintf(stderr, "\n")
    
#define fail(code, ...)            \
    fprintf(stderr, "[[fatal]] "); \
    fprintf(stderr, __VA_ARGS__);  \
    exit(code)