#include <stdlib.h>
#include <stdio.h>

char** tokenize(const char* string, const char* delimiter, int* token_count);
void dispose_tokens(char** split_string_array, int token_count);
int get_token_count(const char* string, const char* delimiter);

#ifdef STRING_TOKENIZER_IMPL
#undef STRING_TOKENIZER_IMPL

#ifndef MAX_TOKEN_COUNT
#define MAX_TOKEN_COUNT 1024 // @todo : is 1024 enough tokens?
#endif 

int token_index_buffer[MAX_TOKEN_COUNT]; 

char** tokenize(const char* string, const char* delimiter, int* token_count)
{
	char** parsed_str = NULL;
	*token_count = get_token_count(string, delimiter);
	parsed_str = (char**)malloc(sizeof(char*) * (*token_count));

	int prev = -1;
	for(int i=0; i<(*token_count); i++)
	{
		int substr_buffer_len = token_index_buffer[i] - prev; // this will give a len one higher than substring len,
								      // the +1 is for the '\0' character
		parsed_str[i] = (char*)malloc(sizeof(char)*(substr_buffer_len)); 
		parsed_str[i][substr_buffer_len-1] = '\0';

		for(int j = prev+1, k = 0; j< prev + substr_buffer_len; j++, k++) // copy sub string
			parsed_str[i][k] = string[j];
	
		prev = token_index_buffer[i];
	}

	return parsed_str;
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


#endif
