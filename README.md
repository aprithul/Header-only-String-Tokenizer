## API

#### `char** tokenize(const char* string, const char* delimiter, int* token_count)`

Finds the tokens in `string`, puts them in an array of strings and returns it. Also assigns `token_count` to the number of items in the array.
#### Parameter:
* `string`: a C-style string
* `delimiter`: the string to use for tokenizing. Currently only uses the first character of this string as the delimiter
* `token_count`: returns the number of tokens found through this pointer
#### Return:
An array of C-style strings. All strings are allocated on the heap. `token_count` is assigned to have the number of tokens in the array.

---

#### `void dispose_tokens(char** token_array, int token_count)`

Frees the memory allocated when `tokenize(...)` was called. **ALWAYS CALL THIS DISPOSE FUNCTION ONCE `token_array` IS NOT NEEDED ANYMORE**. Don't access the `token_array` after disposing. 
#### Parameter:
* `token_array`: the array returned by tokenize that holds all the tokens. 
* `token_count`: the number of tokens in `token_array`.

---

#### `int get_token_count(const char* string, const char* delimiter)`
Returns the number of tokens in `string`.
#### Parameter:
* `string`: the string we want to analyze
* `delimiter`: the delimiter to use (only the first character of `delimiter` is used)

#### Return:
returns the number of tokens in the string.
