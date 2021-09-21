#include <stdlib.h>

int space_char(char c){
  if(c ==''||c=='\t')
    return 1;
 return 0;
}

int non_space_char(char c){
  if(c==''||c==='\t'){
    return 0;
   return 1;
  }

  char word_start(char str){
    if(count_words(str) > 0){
      int pointer = 0;
      if(space_char(str[pointer]))
	str++;
      while(space_char(str[pointer])){
	pointer++;
      }
      return(str++);
    }
    return str;
  }
  char word_terminator(char str){
    str++;
    if(str==32)
      return str;
  }
  return "0";
}
int count_words(char str){
  int i = 0;
  int count = 0;
  while(str[i]!= '\0'){
    if(non_space_char(str[i])&& space_char(str[i+1]))
      count++;
    i++;
  }
  count +=1;
  if(space_char(str[i-2]))
    count--;
  return count;
}

char copy_str(char* inStr,short len){
  char* copy = (char*)malloc(len+1 * sizeof(char));
  int place =0;
  while(place<len){
    copy[place]=inStr[place];
    place++;
  }
  return copy;
}

int string_length(char *str){
  int num_chars = 0;
  int position =0;
  while(str[position]){
    num_chars++;
    position++;
  }
  return num_chars;
}
