#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c ==' '||c=='\t'){
    return 1;
  }
 return 0;
}

int non_space_char(char c){
  if(c==' '|| c=='\t'){
    return 0;
  }
   return 1;
  }

 char *word_start(char *str){
      int pointer = 0;
      while(space_char(str[pointer]==1)){
	pointer++;
      }
      pointer++; //done to get to the next char
      return(str[pointer]);
    return str;
 } 
  char *word_terminator(char *str){
    while(non_space_char(*str)==1){ 
      str++;//pointer ++
      if(*str==32){ //end of str is 32
	return str;
      }
    }
  return "0";
  }

int count_words(char *str){
  int i = 0;
 
  while(str){
    str = word_terminator(str);
    str = word_start(str);
    i++; 
  }
  return i;
}

char *copy_str(char *inStr,short len){
  char* copy = (char*)malloc(len+1 * sizeof(char));
  int i =0;
  while(i<len){
    copy[i]=inStr[i];
    i++;
  }
  return copy;
}



 char **tokenize(char* str){
  int words = count_words(str);
  char **grid = (char**)malloc((words +1),  *sizeof(char*)); //

  char* start = str; // tokenizer recieves pointer to the first char
  char* end = word_terminator(str); //creates pointer to the lat char
  int i = 0;
  
  for(i; i<words; i++){
    if(i>0){
      start = word_start(end);
      end = word_terminator(start);
    }
    size = end - start;
    grid[i] = malloc(size * sizeof(char)); //alocates memory for thst size

    for(int j = 0; j< size; j++){ //places the char in the array 
      grid[i][j] = start[j];
    }
    grid[i] = 0;
  return grid;
  }

void print_tokens(char **grid){
  while(**grid != '\0'){  //equivalent to while the pointer is not null
    printf("%s\n", **grid);
    grid++;
  }
}

void free_tokens(char **grid){
  int i =0;
  while(*grid[i] != '\0'){
    free(grid[i]);
    i++;
  }
  free(grid);
}
 }
 
