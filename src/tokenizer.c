#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c == ' '|| c == '\t')
    {
      return 1;
    }else
    {
      return 0;
    }
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if(c == ' '|| c == '\t')
    {
      return 0;
    }else
    {
      return 1;
    }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *word)
{
  int i=0;
  while(*(word + i)){
    if (non_space_char(*(word + i))){
      return word + i;
    }
    i++;
  }
  return word + i;
}
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  int i=0;
  while(*(word + i)){
    if(space_char(*(word + i))){
      return word + i;
    }
    i++;
  }
  return word + i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  char *iter = str;
  int count = 0;
  int i = 0;//pointer is on the first char in the first word
  iter = word_start(iter);
  while(*iter){
    if(non_space_char(*iter)){
      count++;
    }
    iter=word_terminator(iter);
    iter=word_start(iter);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  char *s = (char*)malloc(len+1 * sizeof(char));
  int i = 0;
  while(i < len){
    s[i] = *inStr;
    inStr++;
    i++;
  }
  return s;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/



// a token is a segment created by splitting a string given at the delimeter returning an array of the segments

char **tokenize(char *str)
{
  int size = count_words(str);
  char **tokens = malloc((size + 1) * sizeof(char *));
  int i;
  int length;
  char *p = str;
  for(i = 0; i < size; i++){
    p = word_start(p);
    char *front = word_start(p);
    char *end = word_terminator(p);
    tokens[i] = copy_str(p,end-front);
    p = word_terminator(p);
  }
  tokens[i] = '\0';
  return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i]; i++) {
    printf("%d) %s\n",i, tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. 
   void free_tokens(char **tokens);*/
void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}
