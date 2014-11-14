#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  char  filename[128]; 
  FILE *filepointer;

  int taskpri;
  char taskname[128];
  struct Task * mytask;

  DynArr * mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
	  if(cmd == 'l'){
		  printf("Please type a file name:");
		  scanf("%s", filename);
		  printf("Loading file...\n");
		  filepointer = fopen(filename, "r");
		  loadList(mainList, filepointer);
	  }

	  else if(cmd == 's'){
		  printf("Please type a file name:");
		  scanf("%s", filename);
		  filepointer = fopen(filename, "w");
		  printf("Saving file...\n");
		  saveList(mainList, filepointer);
	  }

	  else if(cmd == 'a'){
		  printf("Give the task a name: ");
		  scanf("%s", taskname);
		  printf("And now the priority: ");
		  scanf("%d", &taskpri);
//		  printf("Adding task...\n");
		  mytask = createTask(taskpri, taskname);
		  addHeap(mainList, mytask, compare);
	  }

	  else if(cmd == 'g'){
		  //if(mainList->size == 0){
		//	  printf("Your list is empty! Hooray!\n");
		 // }
		  //else{
			  mytask = getMinHeap(mainList);
			  printf("Your first task is: %s\n", mytask->description);
		 // }
	  }

	  else if(cmd == 'r'){
		  mytask = getMinHeap(mainList);
		  printf("Your first task (%s) has been compleated! (or removed...)\n", mytask->description);
		  removeMinHeap(mainList, compare);
	  }

	  else if(cmd == 'p'){
		  printDynArr(mainList, print_type);
	  }
	  

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
