#include <stdio.h>
#include <stdlib.h>

void tokenize(void* allocated_buffer, const char* string, const char* delimiter, int* token_count);
void dispose_tokens(char** split_string_array, int token_count);
int get_token_count(const char* string, const char* delimiter);
unsigned int get_safe_allocation_size(int string_len);

#ifdef STRING_TOKENIZER_IMPL
#undef STRING_TOKENIZER_IMPL

#ifndef MAX_TOKEN_COUNT
#define MAX_TOKEN_COUNT 1024 // @todo : is 1024 enough tokens?
#endif 

int token_index_buffer[MAX_TOKEN_COUNT]; 

void tokenize(void* allocated_buffer, const char* string, const char* delimiter, int* token_count)
{
	*token_count = get_token_count(string, delimiter);

	char** ptr_ptr = (char**)allocated_buffer; // store pointers to the char arrays in the first token_count char** addresses
	char* ptr = (char*)((char**)allocated_buffer + (*token_count)); // store the actual char arrays after that
	int prev = -1;

	for(int i=0; i<(*token_count); i++)
	{
		int substr_buffer_len = token_index_buffer[i] - prev; // this will give a len one higher than substring len,
															// the +1 is for the '\0' character
		*ptr_ptr = ptr;
		ptr_ptr++;

		for(int j = prev+1; j< prev + substr_buffer_len; j++, ptr++) // copy sub string
			*ptr = string[j];

		*ptr = '\0';
		ptr++;

		prev = token_index_buffer[i];
	}
}

void dispose_tokens(char** token_array, int token_count)
{
	while(--token_count >= 0)	
		free(token_array[token_count]);

	free(token_array);
}


int get_token_count(const char* string, const char* delimiter)
{
	int token_cnt = 0;
	int i = 0;
	for(; string[i] != '\0'; i++)
	{
		if(string[i] == delimiter[0]) // @todo : support multi character delimiter
		{
			token_index_buffer[token_cnt] = i;
			token_cnt++;
		}
	}

	// last token isn't accounted for, so handle that	
	token_index_buffer[token_cnt] = i;
	token_cnt++;
	
	
	return token_cnt;
}


unsigned int get_safe_allocation_size(int string_len)
{
	// can have a max of string_len+1 tokens (when every character is a delimiter)
	// can't have more than string_len different strings, each of which requires a '\0', so x2
	return sizeof(char*)*(string_len+1) + sizeof(char)*string_len*2;
}

#endif
