# BSTD

A lightweight C library.

## Features

- Dynamic Strings
- String Views
- Vectors
- Error Handling
- Result Types

## Example

```c
bstd_string_result str =
    bstd_string_new("Hello BSTD");

if (str.ok)
{
    printf("%s\n", str.value.data);
}
```

## Modules

See the API reference for complete documentation.