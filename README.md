## API

#### `char** tokenize(const char* string, const char* delimiter, int* token_count)`

Finds the tokens in `string`, puts them in an array of strings and returns it. Also assigns `token_count` with the number of items in the array.
#### Parameter:
* `string`: is a null terminated C-style string
* `delimiter`: is the character to use for tokenizing. Currently only takes the first character of the string as the delimiter.
* `token_count`: contains the number of tokens found after function completes
#### Return:
An array of C-style null terminated strings. Strings is allocated on the heap. `token_count` is assigned to have the number of tokens in the array.  
</br></br></br></br>

#### `void dispose_tokens(char** token_array, int token_count)`

Frees memory allocated for the tokens when `tokenize(...)` was called. **ALWAYS CALL THIS DISPOSE FUNCTION ONCE `token_array` IS NOT NEEDED ANYMORE**. Don't access the `token_array` after disposing. 
#### Parameter:
* `token_array`: the array returned by tokenize that holds all the tokens. 
* `token_count`: the number of tokens in `token_array`.
</br></br></br></br></br>


#### `int get_token_count(const char* string, const char* delimiter)`
Returns the number of tokens in `string`
#### Parameter:
* `string`: the string we want to analyze
* `delimiter`: the delimiter to use (only the first character of `delimiter` string)

#### Return:
returns the number of tokens in the string.
