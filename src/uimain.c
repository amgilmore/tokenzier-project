#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "tokenizer.h"
#include "history.h"

int count = 0;
int MAX = 3000;
int main()
{
  char user_input[300];
  /* Initialize the linked list to keep the history. */
  List *history = init_history(); 
  while(1){
  //ui section
  printf("\nEnter a String. Enter '+' to see history. Type '=' to exit");
  //case to print the history
  printf("\n");
  fgets(user_input,MAX,stdin);
  if(user_input[0] == '='){
    printf("\nThank you");
    break;
  }
     else if(user_input[0] == '+') {
	printf("\nHistory");
	print_history(history);
	break;
      }else
	{
	  //else handles the string being given
	  printf("\n User Input: %s", user_input);
	  char *begin = word_start(user_input);
	  printf("\n word start: %c", *begin);

	  int words = count_words(user_input);
	  printf("\n word count: %d", words);
	  //char ** is a pointer to a pointer
	  //** is used to initialize tokens to basically an array
	  char** tokens = tokenize(user_input);
	  printf("\n");
	  // printf(tokens);
	  //calls method to print tokens
	  print_tokens(tokens);
	  //calls method to add the history, and *tokens to the history file
	  //  add_history(history,*tokens);
	  // free_tokens(tokens);
      }
  }
}
=======


int main()
{
  char userInput[100];
  
>>>>>>> 3e08ab78ba980b5f16a465a8a83dd93aa32f3b6a
