#include "bstd/error.h"

const char *bstd_error_to_string(bstd_error err)
{
    switch (err)
    {
    case BSTD_OK:
        return "OK";
    case BSTD_ERR_NULL:
        return "Null pointer";
    case BSTD_ERR_OOM:
        return "Out of memory";
    case BSTD_ERR_INVALID_ARG:
        return "Invalid argument";
    case BSTD_ERR_OUT_OF_BOUNDS:
        return "Out of bounds";
    case BSTD_ERR_NOT_FOUND:
        return "Not found";
    default:
        return "Unknown error";
    }
}