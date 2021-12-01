#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List* history;
  history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List* list, char* str)
{
  Item *new = malloc(sizeof(Item));
  //if list is empty
  if (list->root == NULL){
    new->id = 1;
    list->root = new;
  }
  else {
    Item *currItem = list->root;
    while(currItem->next != NULL)
      {
	currItem = currItem->next;
      }
    //update id
    new->id = currItem->id + 1;
    currItem->next = new;
  }
  // new string is added to linked list
  new->str = str;
  new->next = NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List* list, int id)

{
  if (list->root == NULL)
    {
      return "List is empty";
    }else
    {
      Item* temp = list->root;
      //traverse linked list
      while (temp != NULL)
	{
	  if (temp->id == id)
	    return temp->str;
	  temp = temp->next;
	}
      return "Item number not found\n";
    }
}

/*Print the entire contents of the list. */
void print_history(List* list)
{
  Item* temp = (list->root);
  //traverse linked list and print id and string
  while (temp != NULL)
    {
      printf("History Item [%d]: %s \n", temp->id, temp->str);
      temp = temp->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List* list )
{
  Item* temp;
  Item* temp1;
  temp  = list -> root;
  while (temp != NULL)
    {
      temp1 = temp;
      temp = temp->next;
      free(temp1);
    }
  free(list);
}
