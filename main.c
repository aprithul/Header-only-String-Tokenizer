#include <stdio.h>
#include <assert.h>

#define STRING_TOKENIZER_IMPL
#include "string_tokenizer.h"


int main()
{

	assert(get_token_count("pri", ",") == 1);
	assert(get_token_count(",", ",") == 2);
	assert(get_token_count("pri,oi", ",") == 2);
	assert(get_token_count(",pri,", ",") == 3);
	assert(get_token_count(",,,", ",") == 4);
	assert(get_token_count("", ",") == 1);
	assert(get_token_count(",p,p", ",") == 3);
	assert(get_token_count(",,pri",",") == 3);
	
	
	void print_tokens(const char* str, const char* del);
	print_tokens(",,,",",");
	print_tokens("pri,thul,oi,shie", ",");
	print_tokens("", ",");
	print_tokens(",", ",");
	print_tokens("p,", ",");
	print_tokens(",p", ",");
	print_tokens("pri",",");

	return 0;
}


void print_tokens(const char* str, const char* del)
{
	int token_count = 0;
	char** tokens = tokenize(str, del, &token_count);
	printf("\"%s\" has #%d tokens\n", str, token_count);
	for(int i=0; i<token_count; i++)
	{
		printf("token #%d : %s\n", i+1, tokens[i]);
	}

	dispose_tokens(tokens, token_count);
}
