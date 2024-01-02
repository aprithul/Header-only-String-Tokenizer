
### Changelog
* The library no longer owns memory, and instead works with a preallocated buffer.


## API
#### `char** tokenize(void* allocated_buffer, const char* string, const char* delimiter, int* token_count)`

Finds the tokens in `string`, and puts them in allocated_buffer. Also assigns `token_count` to the number of items in the array.
#### Parameter:
* `allocated_buffer`: pre-allocated buffer to store tokens
* `string`: a C-style string
* `delimiter`: the string to use for tokenizing. Currently only uses the first character of this string as the delimiter
* `token_count`: returns the number of tokens found through this pointer

---

#### `int get_token_count(const char* string, const char* delimiter)`
Returns the number of tokens in `string`.
#### Parameter:
* `string`: the string we want to analyze
* `delimiter`: the delimiter to use (only the first character of `delimiter` is used)

---

#### `unsigned int get_safe_allocation_size(int string_len)`
Get the minimum safe size of the buffer to allocate for storing tokens
#### Parameter:
* `string_len`: length of the string we will tokenize

#### Return:
returns the minimum safe size
