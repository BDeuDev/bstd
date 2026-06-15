#ifndef ERROR_H
#define ERROR_H

typedef enum
{
    BSTD_OK = 0,

    BSTD_ERR_NULL,
    BSTD_ERR_OOM,
    BSTD_ERR_INVALID_ARG,

    BSTD_ERR_OUT_OF_BOUNDS,
    BSTD_ERR_INVALID_UTF8,

    BSTD_ERR_NOT_FOUND,

} bstd_error;

const char *bstd_error_to_string(bstd_error err);

#endif