#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  int debuggingDyn = 0; //If 1, will use the dynamic Array functions,
  						//to debug the list stuff. Else, use heap funcitons.
  char cmd[3] = " ";
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
	scanf("%s", cmd);
      /* clear the trailing newline character */
      //while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
	  if(cmd[0] == 'l'){
		  printf("Please type a file name:");
		  scanf("%s", filename);
		  printf("Loading file...\n");
		  filepointer = fopen(filename, "r");
		  loadList(mainList, filepointer);
	  }

	  else if(cmd[0] == 's'){
		  printf("Please type a file name:");
		  scanf("%s", filename);
		  filepointer = fopen(filename, "w");
		  printf("Saving file...\n");
		  saveList(mainList, filepointer);
	  }

	  else if(cmd[0] == 'a'){
		  printf("Give the task a name: ");
		  scanf("%s", taskname);
		  printf("And now the priority: ");
		  scanf("%d", &taskpri);
//		  printf("Adding task...\n");
		  mytask = createTask(taskpri, taskname);

		  //Using the dynamic array to test
		  if (debuggingDyn == 1){
		      addDynArrOrd(mainList, mytask, compare);
		  }
		  else{
		  	  addHeap(mainList, mytask, compare);
		  }
	  }

	  else if(cmd[0] == 'g'){
		  //if(mainList->size == 0){
		//	  printf("Your list is empty! Hooray!\n");
		 // }
		  //else{
			  if(debuggingDyn == 1){
				  mytask = getDynArr(mainList, 0);
			  }
			  else{
			      mytask = getMinHeap(mainList);
			  }
			  printf("Your first task is: %s\n", mytask->description);
		 // }
	  }

	  else if(cmd[0] == 'r'){
          if(debuggingDyn == 1){
			  mytask = getDynArr(mainList, 0);
		  }
		  else{
		      mytask = getMinHeap(mainList);
		  }
		  printf("Your first task (%s) has been compleated! (or removed...)\n", mytask->description);

		  if(debuggingDyn == 1){
			  removeAtDynArr(mainList, 0);
		  }
		  else{
			  removeMinHeap(mainList, compare);
		  }
	  }

	  else if(cmd[0] == 'p'){
		  printDynArr(mainList, print_type);
	  }
	  

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd[0] != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
