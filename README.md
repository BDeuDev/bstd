# BSTD

BSTD is a lightweight C library that provides string utilities and string-view helpers, focused on simplicity, safety, and ease of use.

## Overview

This library provides basic types and functions for working with dynamic strings (`bstd_string`) and non-owning string views (`bstd_strview`). It also includes a minimal error and result handling system.

## Key Features

- Dynamic strings with creation, concatenation, reversal, and uppercase/lowercase operations.
- Non-owning string views for substring handling without copying memory.
- Inspection functions: starts-with, ends-with, includes, equals, and split operations.
- Typed results and errors for a safer API.

## Requirements

- C compiler (`gcc`, `clang`, or compatible)
- `make`
- Standard C library

## Build

From the project root:

```bash
make
```

This builds the library object files.

## Testing

Build and run the full test suite with:

```bash
make test
```

## Formatting

Format all source, header, and example files with:

```bash
make format
```

Check formatting without modifying files using:

```bash
make format-check
```

## Benchmarks

Build the benchmarks and run:

```bash
make bench
```

## Examples

Build the example programs with:

```bash
make examples
```

Run the examples with:

```bash
make run-examples
```

## Project Structure

- `include/bstd/` - Public library headers
- `src/` - Library implementation
- `tests/` - Test cases organized by module
- `examples/` - Example usage code
- `docs/` - Doxygen docs
- `bench/` - Benchmarks
- `Makefile` - Build and test rules

## Main API

### `bstd_string`

- `bstd_string_new(char *cstr)`
- `bstd_string_slice(const bstd_string *s, size_t start_idx, size_t end_idx)`
- `bstd_string_reverse(bstd_string s)`
- `bstd_string_concat(bstd_string s, bstd_string d)`
- `bstd_string_to_uppercase(const bstd_string *s)`
- `bstd_string_to_lowercase(const bstd_string *s)`
- `bstd_string_to_uppercase_inplace(bstd_string *s)`
- `bstd_string_to_lowercase_inplace(bstd_string *s)`

### `bstd_strview`

- `bstd_strview_new(const char *cstr)`
- `bstd_strview_slice(bstd_strview s, size_t start_idx, size_t end_idx)`
- `bstd_strview_starts_with(bstd_strview s, bstd_strview prefix)`
- `bstd_strview_ends_with(bstd_strview s, bstd_strview suffix)`
- `bstd_strview_includes(bstd_strview s, bstd_strview search)`
- `bstd_strview_equals(bstd_strview s, bstd_strview c)`
- `bstd_strview_next_char(bstd_strview *s, char *out)`
- `bstd_strview_advance(bstd_strview *s, size_t n)`
- `bstd_strview_consume_prefix(bstd_strview *s, bstd_strview prefix)`

## Basic Usage

Include the required headers in your code:

```c
#include <bstd/string.h>
#include <bstd/strview.h>
```

Then compile your application with the include path:

```bash
gcc -Iinclude src/main.c src/string.c src/strview.c src/error.c -o my_app
```

## License

See the `LICENSE` file for the project license terms.
