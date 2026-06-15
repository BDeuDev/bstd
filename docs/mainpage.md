# BSTD

A lightweight C library for systems programming.

---

## Overview

BSTD is a minimal C library focused on:

- performance
- predictability
- zero external dependencies
- clean and explicit APIs

It provides foundational utilities commonly needed in systems-level development.

---

## Features

- Dynamic Strings
- String Views (non-owning slices)
- Vectors
- Error handling utilities
- Result types for explicit error propagation

---

## Example

```c
bstd_string_result str = bstd_string_new("Hello BSTD");

if (str.ok)
{
    printf("%s\n", str.value.data);
}
```

---

## Modules

- `string.h` – dynamic string implementation
- `strview.h` – zero-copy string views
- `vec.h` – dynamic arrays
- `stack.h` – stack utilities
- `error.h` – error handling
- `result.h` – result types

---

## Documentation

Full API reference is available in the generated documentation.
