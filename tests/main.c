#include "test.h"

extern test_result test_string_new(void);
extern test_result test_string_new_null(void);
extern test_result test_string_new_empty(void);
extern test_result test_string_new_null_terminated(void);
extern test_result test_string_new_deep_copy(void);
extern test_result test_string_new_length(void);
extern test_result test_string_new_capacity(void);
extern test_result test_string_clone(void);
extern test_result test_string_clone_lenght(void);
extern test_result test_string_clone_capacity(void);
extern test_result test_string_slice(void);
extern test_result test_string_slice_invalid_range(void);
extern test_result test_string_to_uppercase(void);
extern test_result test_string_to_uppercase_null(void);
extern test_result test_string_to_uppercase_already_upper(void);
extern test_result test_string_to_uppercase_inplace(void);
extern test_result test_string_to_uppercase_inplace_null(void);
extern test_result test_string_to_lowercase(void);
extern test_result test_string_to_lowercase_null(void);
extern test_result test_string_to_lowercase_already_lower(void);
extern test_result test_string_reverse(void);
extern test_result test_string_reverse_null(void);
extern test_result test_string_concat(void);
extern test_result test_string_concat_null(void);
extern test_result test_string_concat_inplace(void);
extern test_result test_string_concat_inplace_null(void);
extern test_result test_string_push_char(void);
extern test_result test_string_push_char_null(void);
extern test_result test_string_clear(void);
extern test_result test_string_destroy(void);
extern test_result test_string_reserve(void);
extern test_result test_string_replace_basic(void);
extern test_result test_string_replace_longer(void);
extern test_result test_string_replace_shorter(void);
extern test_result test_string_replace_beginning(void);
extern test_result test_string_replace_entire_string(void);
extern test_result test_string_replace_not_found(void);
extern test_result test_string_replace_length_grows(void);
extern test_result test_string_replace_length_shrinks(void);
extern test_result test_string_replace_invalid_string(void);
extern test_result test_string_replace_invalid_search(void);
extern test_result test_string_replace_invalid_replace(void);
extern test_result test_string_replace_empty_search(void);
extern test_result test_string_replace_same_size(void);

extern test_result test_strview_new(void);
extern test_result test_strview_slice(void);
extern test_result test_strview_slice_invalid_range(void);
extern test_result test_strview_slice_invalid_end_idx(void);
extern test_result test_strview_starts_with_ok(void);
extern test_result test_strview_starts_with_failed(void);
extern test_result test_strview_starts_with_invalid_len(void);
extern test_result test_strview_ends_with_ok(void);
extern test_result test_strview_ends_with_failed(void);
extern test_result test_strview_ends_with_invalid_len(void);
extern test_result test_strview_includes(void);
extern test_result test_strview_includes_failed(void);
extern test_result test_strview_includes_empty(void);
extern test_result test_strview_equals(void);
extern test_result test_strview_equals_failed(void);
extern test_result test_strview_next_char(void);
extern test_result test_strview_next_char_null(void);
extern test_result test_strview_next_char_empty(void);
extern test_result test_strview_advance(void);
extern test_result test_strview_advance_empty(void);
extern test_result test_strview_advance_null(void);
extern test_result test_strview_consume_prefix(void);
extern test_result test_strview_consume_prefix_empty(void);
extern test_result test_strview_consume_prefix_empty_source(void);
extern test_result test_strview_consume_prefix_null(void);
extern test_result test_strview_consume_prefix_wrong(void);
extern test_result test_strview_is_empty(void);
extern test_result test_strview_is_not_empty(void);
extern test_result test_strview_is_empty_withspaces(void);
extern test_result test_strview_trim_left(void);
extern test_result test_strview_trim_left_multiple(void);
extern test_result test_strview_trim_right(void);
extern test_result test_strview_trim_right_multiple(void);
extern test_result test_strview_trim(void);
extern test_result test_strview_trim_multiple(void);
extern test_result test_strview_split(void);
extern test_result test_strview_split_lines(void);
extern test_result test_strview_split_iter_next(void);
extern test_result test_strview_split_lines_iter_next(void);
extern test_result test_strview_split_once(void);

int main(void)
{
    test_case tests[] = {
        {"test_string_new", test_string_new},
        {"test_string_clone", test_string_clone},
        {"test_string_new_null", test_string_new_null},
        {"test_string_new_empty", test_string_new_empty},
        {"test_string_new_null_terminated", test_string_new_null_terminated},
        {"test_string_new_deep_copy", test_string_new_deep_copy},
        {"test_string_new_length", test_string_new_length},
        {"test_string_new_capacity", test_string_new_capacity},
        {"test_string_clone", test_string_clone},
        {"test_string_clone_lenght", test_string_clone_lenght},
        {"test_string_clone_capacity", test_string_clone_capacity},
        {"test_string_slice", test_string_slice},
        {"test_string_invalid_range", test_string_slice_invalid_range},
        {"test_string_to_uppercase", test_string_to_uppercase},
        {"test_string_to_uppercase_null", test_string_to_uppercase_null},
        {"test_string_to_uppercase_already_upper", test_string_to_uppercase_already_upper},
        {"test_string_to_uppercase_inplace", test_string_to_uppercase_inplace},
        {"test_string_to_uppercase_inplace_null", test_string_to_uppercase_inplace_null},
        {"test_string_to_lowercase", test_string_to_lowercase},
        {"test_string_to_lowercase_null", test_string_to_lowercase_null},
        {"test_string_to_lowercase_already_lower", test_string_to_lowercase_already_lower},
        {"test_string_reverse", test_string_reverse},
        {"test_string_reverse_null", test_string_reverse_null},
        {"test_string_concat", test_string_concat},
        {"test_string_concat_null", test_string_concat_null},
        {"test_string_concat_inplace", test_string_concat_inplace},
        {"test_string_concat_inplace_null", test_string_concat_inplace_null},
        {"test_string_push_char", test_string_push_char},
        {"test_string_push_char_null", test_string_push_char_null},
        {"test_string_clear", test_string_clear},
        {"test_string_destroy", test_string_destroy},
        {"test_string_reserve", test_string_reserve},

        {"test_strview_new", test_strview_new},
        {"test_strview_slice", test_strview_slice},
        {"test_strview_slice_invalid_range", test_strview_slice_invalid_range},
        {"test_strview_slice_invalid_end_idx", test_strview_slice_invalid_end_idx},
        {"test_strview_starts_with_failed", test_strview_starts_with_failed},
        {"test_strview_starts_with_ok", test_strview_starts_with_ok},
        {"test_strview_starts_with_invalid_len", test_strview_starts_with_invalid_len},
        {"test_strview_ends_with_failed", test_strview_ends_with_failed},
        {"test_strview_ends_with_ok", test_strview_ends_with_ok},
        {"test_strview_ends_with_invalid_len", test_strview_ends_with_invalid_len},
        {"test_strview_includes", test_strview_includes},
        {"test_strview_includes_failed", test_strview_includes_failed},
        {"test_strview_includes_empty", test_strview_includes_empty},
        {"test_strview_equals", test_strview_equals},
        {"test_strview_equals_failed", test_strview_equals_failed},
        {"test_strview_next_char", test_strview_next_char},
        {"test_strview_next_char_null", test_strview_next_char_null},
        {"test_strview_next_char_empty", test_strview_next_char_empty},
        {"test_strview_advance", test_strview_advance},
        {"test_strview_advance_empty", test_strview_advance_empty},
        {"test_strview_advance_null", test_strview_advance_null},
        {"test_strview_consume_prefix", test_strview_consume_prefix},
        {"test_strview_consume_prefix_wrong", test_strview_consume_prefix_wrong},
        {"test_strview_consume_prefix_empty", test_strview_consume_prefix_empty},
        {"test_strview_consume_prefix_empty_source", test_strview_consume_prefix_empty_source},
        {"test_strview_consume_prefix_null", test_strview_consume_prefix_null},
        {"test_strview_is_empty", test_strview_is_empty},
        {"test_strview_is_empty_withspaces", test_strview_is_empty_withspaces},
        {"test_strview_is_not_empty", test_strview_is_not_empty},
        {"test_strview_trim_left", test_strview_trim_left},
        {"test_strview_trim_left_multiple", test_strview_trim_left_multiple},
        {"test_strview_trim_right", test_strview_trim_right},
        {"test_strview_trim_right_multiple", test_strview_trim_right_multiple},
        {"test_strview_trim", test_strview_trim},
        {"test_strview_trim_multiple", test_strview_trim_multiple},
        {"test_strview_split", test_strview_split},
        {"test_strview_split_lines", test_strview_split_lines},
        {"test_strview_split_iter_next", test_strview_split_iter_next},
        {"test_strview_split_lines_iter_next", test_strview_split_lines_iter_next},
        {"test_strview_split_once", test_strview_split_once},
        {"test_string_replace_basic", test_string_replace_basic},
        {"test_string_replace_longer", test_string_replace_longer},
        {"test_string_replace_shorter", test_string_replace_shorter},
        {"test_string_replace_beginning", test_string_replace_beginning},
        {"test_string_replace_entire_string", test_string_replace_entire_string},
        {"test_string_replace_not_found", test_string_replace_not_found},
        {"test_string_replace_length_grows", test_string_replace_length_grows},
        {"test_string_replace_length_shrinks", test_string_replace_length_shrinks},
        {"test_string_replace_invalid_string", test_string_replace_invalid_string},
        {"test_string_replace_invalid_search", test_string_replace_invalid_search},
        {"test_string_replace_invalid_replace", test_string_replace_invalid_replace},
        {"test_string_replace_empty_search", test_string_replace_empty_search},
        {"test_string_replace_same_size", test_string_replace_same_size},
    };

    size_t count = sizeof(tests) / sizeof(test_case);
    size_t failed = 0;
    size_t pass = 0;
    for (size_t i = 0; i < count; i++)
    {
        printf("[RUNNING] %s\n", tests[i].name);

        test_result result = tests[i].fn();

        if (result == TEST_OK)
        {
            printf("[OK] %s\n\n", tests[i].name);
            pass++;
        }
        else
        {
            printf("[FAILED] %s\n\n", tests[i].name);
            failed++;
        }
    }
    printf("[TESTS PASSED] [%zu/%zu]  \n", pass, count);

    return 0;
}