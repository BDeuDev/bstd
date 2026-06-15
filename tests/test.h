#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>

#define ASSERT(expr)                                                                               \
    do                                                                                             \
    {                                                                                              \
        if (!(expr))                                                                               \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Assertion: %s\n",                                                            \
                   __FILE__, __LINE__, #expr);                                                     \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

#define ASSERT_NOT(expr)                                                                           \
    do                                                                                             \
    {                                                                                              \
        if (expr)                                                                                  \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Assertion: %s\n",                                                            \
                   __FILE__, __LINE__, #expr);                                                     \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

#define ASSERT_EQ(expected, actual)                                                                \
    do                                                                                             \
    {                                                                                              \
        if ((expected) != (actual))                                                                \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Expected: %lld\n"                                                            \
                   "  Actual:   %lld\n",                                                           \
                   __FILE__, __LINE__, (long long)(expected), (long long)(actual));                \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

#define ASSERT_NOT_EQ(expected, actual)                                                            \
    do                                                                                             \
    {                                                                                              \
        if ((expected) == (actual))                                                                \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Expected: %lld\n"                                                            \
                   "  Actual:   %lld\n",                                                           \
                   __FILE__, __LINE__, (long long)(expected), (long long)(actual));                \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

#define ASSERT_STR_EQ(expected, actual)                                                            \
    do                                                                                             \
    {                                                                                              \
        if (strcmp((expected), (actual)) != 0)                                                     \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Expected: \"%s\"\n"                                                          \
                   "  Actual:   \"%s\"\n",                                                         \
                   __FILE__, __LINE__, (expected), (actual));                                      \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

#define ASSERT_STR_EQ_WLEN(expected, actual, len)                                                  \
    do                                                                                             \
    {                                                                                              \
        if (memcmp((expected), (actual), (len)) != 0)                                              \
        {                                                                                          \
            printf("[FAILED] %s:%d\n"                                                              \
                   "  Expected: \"%s\"\n"                                                          \
                   "  Actual:   \"%s\"\n",                                                         \
                   __FILE__, __LINE__, (expected), (actual));                                      \
                                                                                                   \
            return TEST_FAILED;                                                                    \
        }                                                                                          \
    } while (0)

typedef enum
{
    TEST_OK,
    TEST_FAILED
} test_result;

typedef test_result (*test_fn)(void);

typedef struct
{
    const char *name;
    test_fn fn;
} test_case;

#endif