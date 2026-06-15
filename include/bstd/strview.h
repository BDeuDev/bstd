/**
 * @defgroup strview String Views
 * @brief Non-owning string slices.
 * @{
 */

#ifndef BSTD_STRVIEW_H
#define BSTD_STRVIEW_H

#include <bstd/error.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    const char *data;
    size_t length;
} bstd_strview;

typedef struct
{
    bool ok;
    union
    {
        bstd_strview value;
        bstd_error error;
    };
} bstd_strview_result;

typedef struct
{
    bstd_strview source;
    size_t current_index;
    bstd_strview qry;
} bstd_strview_split_iter;

typedef struct
{
    bstd_strview left;
    bstd_strview right;
} bstd_strview_split_once_result;

#define BSTD_STRVIEW_EMPTY                                                                         \
    (bstd_strview)                                                                                 \
    {                                                                                              \
        .data = NULL, .length = 0                                                                  \
    }
/**
 * @brief Creates a string view from a null-terminated C string.
 *
 * Creates a non-owning view over the provided string.
 * No memory allocation or copy is performed.
 *
 * @param cstr Null-terminated source string.
 *
 * @return A string view referencing the original string.
 *
 * @warning The source string must remain valid for the
 *          lifetime of the returned view.
 */
bstd_strview bstd_strview_new(const char *cstr);

/**
 * @brief Prints a string view followed by a newline.
 *
 * Writes the contents of the string view to stdout.
 *
 * @param s String view to print.
 */
void bstd_strview_print(bstd_strview s);

/**
 * @brief Prints a string view without a trailing newline.
 *
 * Writes the contents of the string view to stdout.
 *
 * @param s String view to print.
 */
void bstd_strview_print_raw(bstd_strview s);

/**
 * @brief Creates a slice of a string view.
 *
 * Returns a new view referencing the range
 * [start_idx, end_idx) of the source view.
 *
 * No memory allocation or copy is performed.
 *
 * @param s Source string view.
 * @param start_idx Starting index (inclusive).
 * @param end_idx Ending index (exclusive).
 *
 * @return A result containing the sliced view on
 *         success, or an out-of-bounds error.
 *
 * @warning The range must satisfy:
 *          start_idx <= end_idx <= s.length
 */
bstd_strview_result bstd_strview_slice(bstd_strview s, size_t start_idx, size_t end_idx);

/**
 * @brief Checks whether a string view starts with a prefix.
 *
 * @param s Source string view.
 * @param prefix Prefix to compare.
 *
 * @return true if the source begins with the prefix,
 *         false otherwise.
 */
bool bstd_strview_starts_with(bstd_strview s, bstd_strview prefix);

/**
 * @brief Checks whether a string view ends with a suffix.
 *
 * @param s Source string view.
 * @param sufix Suffix to compare.
 *
 * @return true if the source ends with the suffix,
 *         false otherwise.
 */
bool bstd_strview_ends_with(bstd_strview s, bstd_strview sufix);

/**
 * @brief Checks whether a string view contains another view.
 *
 * Searches for the first occurrence of the provided
 * substring within the source view.
 *
 * @param s Source string view.
 * @param search Substring to search for.
 *
 * @return true if found, false otherwise.
 */
bool bstd_strview_includes(bstd_strview s, bstd_strview search);

/**
 * @brief Compares two string views for equality.
 *
 * Both length and contents must match.
 *
 * @param s First string view.
 * @param c Second string view.
 *
 * @return true if both views contain identical data,
 *         false otherwise.
 */
bool bstd_strview_equals(bstd_strview s, bstd_strview c);

/**
 * @brief Consumes the next character from a view.
 *
 * Writes the first character to `out` and advances
 * the view by one character.
 *
 * No memory allocation is performed.
 *
 * @param s String view to consume from.
 * @param out Output character.
 *
 * @return true if a character was consumed,
 *         false otherwise.
 */
bool bstd_strview_next_char(bstd_strview *s, char *out);

/**
 * @brief Advances a string view by a number of characters.
 *
 * Moves the beginning of the view forward by `n`
 * characters.
 *
 * @param s String view to modify.
 * @param n Number of characters to skip.
 *
 * @return true on success, false if the operation
 *         would move beyond the end of the view.
 */
bool bstd_strview_advance(bstd_strview *s, size_t n);

/**
 * @brief Consumes a prefix if present.
 *
 * If the string view begins with the specified prefix,
 * the prefix is removed from the view.
 *
 * @param s String view to modify.
 * @param prefix Prefix to consume.
 *
 * @return true if the prefix was consumed,
 *         false otherwise.
 */
bool bstd_strview_consume_prefix(bstd_strview *s, bstd_strview prefix);

/**
 * @brief Checks whether a string view is empty.
 *
 * A view is considered empty if its length is zero
 * or if it contains only whitespace characters.
 *
 * @param s String view to check.
 *
 * @return true if empty, false otherwise.
 */
bool bstd_strview_is_empty(bstd_strview s);

/**
 * @brief Removes leading whitespace from a view.
 *
 * Advances the beginning of the view until the first
 * non-whitespace character is reached.
 *
 * No memory allocation or copy is performed.
 *
 * @param s String view to modify.
 */
void bstd_strview_trim_left(bstd_strview *s);

/**
 * @brief Removes trailing whitespace from a view.
 *
 * Shrinks the view until the last character is not
 * whitespace.
 *
 * No memory allocation or copy is performed.
 *
 * @param s String view to modify.
 */
void bstd_strview_trim_right(bstd_strview *s);

/**
 * @brief Removes leading and trailing whitespace.
 *
 * Equivalent to calling:
 *
 * @code
 * bstd_strview_trim_left(s);
 * bstd_strview_trim_right(s);
 * @endcode
 *
 * @param s String view to modify.
 */
void bstd_strview_trim(bstd_strview *s);

/**
 * @brief Creates a split iterator.
 *
 * Creates an iterator that yields segments of the
 * source view separated by the specified delimiter.
 *
 * No memory allocation is performed.
 *
 * @param s Source string view.
 * @param q Delimiter.
 *
 * @return A split iterator.
 */
bstd_strview_split_iter bstd_strview_split(bstd_strview *s, bstd_strview q);

/**
 * @brief Splits a string view at the first occurrence
 *        of a delimiter.
 *
 * Searches for the first occurrence of the delimiter
 * and returns the left and right portions.
 *
 * Example:
 *
 * @code
 * "key=value"
 *
 * left  -> "key"
 * right -> "value"
 * @endcode
 *
 * @param s Source string view.
 * @param q Delimiter.
 *
 * @return A structure containing the left and right
 *         views around the delimiter.
 *
 * @note If the delimiter is not found, the left view
 *       contains the original string and the right
 *       view is empty.
 */
bstd_strview_split_once_result bstd_strview_split_once(bstd_strview *s, bstd_strview q);

/**
 * @brief Creates a line iterator.
 *
 * Equivalent to splitting on '\n'.
 *
 * @param s Source string view.
 *
 * @return A split iterator over lines.
 */
bstd_strview_split_iter bstd_strview_split_lines(bstd_strview *s);

/**
 * @brief Returns the next segment from a split iterator.
 *
 * Retrieves the next token separated by the iterator's
 * delimiter.
 *
 * @param iter Split iterator.
 *
 * @return The next token, or BSTD_STRVIEW_EMPTY if
 *         iteration has completed.
 */
bstd_strview bstd_strview_split_iter_next(bstd_strview_split_iter *iter);

#endif

/** @} */