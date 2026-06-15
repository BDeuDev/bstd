/**
 * @defgroup string Dynamic Strings
 * @brief Heap allocated string utilities.
 * @{
 */

/**
 * @file string.h
 * @brief Dynamic string implementation.
 */

#ifndef BSTD_STRING_H
#define BSTD_STRING_H

#include "bstd/error.h"
#include "bstd/result.h"
#include <stdbool.h>
#include <stddef.h>

#define BSTD_STRING_NULL_TERM 1

typedef struct
{
    char *data;
    size_t length;
    size_t capacity;
} bstd_string;

typedef struct
{
    bool ok;
    union
    {
        bstd_string value;
        bstd_error error;
    };
} bstd_string_result;

/**
 * @brief Creates a new dynamic string.
 *
 * Allocates memory on the heap and copies the contents
 * of the provided C string.
 *
 * @param cstr Null-terminated string to copy.
 *
 * @return A result containing the created string or an
 *         error if allocation failed.
 */
bstd_string_result bstd_string_new(char *cstr);

/**
 * @brief Creates a substring from a string.
 *
 * Allocates memory on the heap and copies the characters
 * in the range [start_idx, end_idx) into a new
 * `bstd_string`.
 *
 * The returned string owns its memory independently from
 * the source string and must be destroyed when no longer
 * needed.
 *
 * Example:
 * @code
 * bstd_string_result hello =
 *     bstd_string_new("Hello World");
 *
 * bstd_string_result slice =
 *     bstd_string_slice(
 *         &hello.value,
 *         0,
 *         5
 *     );
 *
 * // slice.value.data == "Hello"
 * @endcode
 *
 * @param s Source string.
 * @param start_idx Starting index (inclusive).
 * @param end_idx Ending index (exclusive).
 *
 * @return A result containing the created substring on
 *         success, or an error if the indices are invalid
 *         or memory allocation fails.
 *
 * @warning The range must satisfy:
 *          start_idx <= end_idx <= s->length
 */
bstd_string_result bstd_string_slice(const bstd_string *s, size_t start_idx, size_t end_idx);

/**
 * @brief Converts a string to uppercase.
 *
 * Creates a new string with all ASCII lowercase letters
 * converted to their uppercase equivalents.
 *
 * The returned string owns its memory independently from
 * the source string and must be destroyed when no longer
 * needed.
 *
 * @param s Source string.
 *
 * @return A result containing the uppercase string on
 *         success, or an error if the input is invalid
 *         or memory allocation fails.
 *
 * @warning Only ASCII characters are transformed.
 *          UTF-8 and locale-specific characters are not
 *          supported.
 */
bstd_string_result bstd_string_to_uppercase(const bstd_string *s);

/**
 * @brief Converts a string to lowercase.
 *
 * Creates a new string with all ASCII uppercase letters
 * converted to their lowercase equivalents.
 *
 * The returned string owns its memory independently from
 * the source string and must be destroyed when no longer
 * needed.
 *
 * @param s Source string.
 *
 * @return A result containing the lowercase string on
 *         success, or an error if the input is invalid
 *         or memory allocation fails.
 *
 * @warning Only ASCII characters are transformed.
 *          UTF-8 and locale-specific characters are not
 *          supported.
 */
bstd_string_result bstd_string_to_lowercase(const bstd_string *s);

/**
 * @brief Converts a string to uppercase in place.
 *
 * Replaces all ASCII lowercase letters in the string
 * with their uppercase equivalents.
 *
 * No additional memory allocation is performed.
 *
 * @param s String to modify.
 *
 * @return A success result or an error if the input
 *         string is invalid.
 *
 * @warning Only ASCII characters are transformed.
 */
bstd_result bstd_string_to_uppercase_inplace(bstd_string *s);

/**
 * @brief Converts a string to lowercase in place.
 *
 * Replaces all ASCII uppercase letters in the string
 * with their lowercase equivalents.
 *
 * No additional memory allocation is performed.
 *
 * @param s String to modify.
 *
 * @return A success result or an error if the input
 *         string is invalid.
 *
 * @warning Only ASCII characters are transformed.
 */
bstd_result bstd_string_to_lowercase_inplace(bstd_string *s);

/**
 * @brief Creates a reversed copy of a string.
 *
 * Allocates a new string containing the characters of
 * the source string in reverse order.
 *
 * The returned string owns its memory independently from
 * the source string.
 *
 * @param s Source string.
 *
 * @return A result containing the reversed string on
 *         success, or an error if allocation fails.
 */
bstd_string_result bstd_string_reverse(bstd_string s);

/**
 * @brief Concatenates two strings.
 *
 * Creates a new string containing the contents of `s`
 * followed by the contents of `d`.
 *
 * The returned string owns its memory independently from
 * both source strings.
 *
 * @param s Left-hand string.
 * @param d Right-hand string.
 *
 * @return A result containing the concatenated string
 *         on success, or an error if allocation fails.
 */
bstd_string_result bstd_string_concat(bstd_string s, bstd_string d);

/**
 * @brief Appends one string to another.
 *
 * Extends `s` by appending the contents of `d`.
 *
 * The internal buffer may be reallocated if additional
 * capacity is required.
 *
 * @param s Destination string.
 * @param d String to append.
 *
 * @return A success result or an error if allocation
 *         fails.
 */
bstd_result bstd_string_concat_inplace(bstd_string *s, bstd_string d);

/**
 * @brief Replaces the first occurrence of a substring.
 *
 * Searches for the first occurrence of `search` within
 * the string and replaces it with `replace`.
 *
 * The internal buffer may be reallocated if the
 * replacement requires additional capacity.
 *
 * If the search string is not found, the string remains
 * unchanged.
 *
 * @param s String to modify.
 * @param search Substring to search for.
 * @param replace Replacement substring.
 *
 * @return A success result, or an error if the input is
 *         invalid or memory allocation fails.
 *
 * @warning `search` must not be an empty string.
 */
bstd_result bstd_string_replace(bstd_string *s, const char *search, const char *replace);

/**
 * @brief Appends a character to the end of a string.
 *
 * Increases the string length by one and places the
 * specified character at the end.
 *
 * The internal buffer may be reallocated if additional
 * capacity is required.
 *
 * @param s String to modify.
 * @param c Character to append.
 *
 * @return A success result or an error if allocation
 *         fails.
 */
bstd_result bstd_string_push_char(bstd_string *s, char c);

/**
 * @brief Removes all characters from a string.
 *
 * Sets the string length to zero and writes a null
 * terminator at the beginning of the buffer.
 *
 * The allocated capacity remains unchanged.
 *
 * @param s String to clear.
 */
void bstd_string_clear(bstd_string *s);

/**
 * @brief Releases the memory owned by a string.
 *
 * Frees the internal buffer and resets all fields to
 * their default values.
 *
 * @param s String to destroy.
 *
 * @warning The string must not be used after calling
 *          this function unless it is reinitialized.
 */
void bstd_string_destroy(bstd_string *s);

/**
 * @brief Ensures a minimum capacity.
 *
 * Reallocates the internal buffer if necessary so that
 * the string can hold at least `n` characters without
 * further allocations.
 *
 * The string contents are preserved.
 *
 * @param s String to reserve capacity for.
 * @param n Desired minimum capacity.
 *
 * @return A success result or an out-of-memory error.
 */
bstd_result bstd_string_reserve(bstd_string *s, size_t n);

/**
 * @brief Shrinks the allocation to fit the current size.
 *
 * Reallocates the internal buffer so that the capacity
 * matches the current string length.
 *
 * The string contents are preserved.
 *
 * @param s String to shrink.
 *
 * @return A success result or an out-of-memory error.
 */
bstd_result bstd_string_shrink_to_fit(bstd_string *s);

/**
 * @brief Creates a deep copy of a string.
 *
 * Allocates a new buffer and copies the contents of the
 * source string.
 *
 * The returned string owns its memory independently from
 * the original string.
 *
 * @param s String to clone.
 *
 * @return A result containing the cloned string on
 *         success, or an error if allocation fails.
 */
bstd_string_result bstd_string_clone(bstd_string *s);

#endif

/** @} */