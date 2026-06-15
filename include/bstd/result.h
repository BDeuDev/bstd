#ifndef RESULT_H
#define RESULT_H

#include "bstd/error.h"
#include "stdbool.h"

typedef struct
{
    bool ok;
    bstd_error error;
} bstd_result;

#endif