#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"
#include "toDoList.h"



int main(int argc, const char * argv[])
{
  	TYPE task1;
	TYPE task2;
	TYPE task3;
	TYPE task4;
	TYPE task5;
	TYPE task6;
	TYPE task7;
	TYPE task8;
	TYPE task9;
	TYPE task10;

	DynArr *mainList;
	DynArr *sortedList;
	mainList = createDynArr(10);
	sortedList = createDynArr(10);

	/* create tasks */
	task1 = createTask(9, "task 1");
	task2 = createTask(3, "task 2");
	task3 = createTask(2, "task 3");
	task4 = createTask(4, "task 4");
	task5 = createTask(5, "task 5");
	task6 = createTask(7, "task 6");
	task7 = createTask(8, "task 7");
	task8 = createTask(6, "task 8");
	task9 = createTask(1, "task 9");
	task10 = createTask(0, "task 10");

	/* add tasks to the dynamic array */

	printf("ADDING FIRST ELEMENT\n");
	addHeap(mainList, task1, compare);
    printDynArr(mainList, print_type);
	printf("ADDING SECOND ELEMENT\n");
	addHeap(mainList, task2, compare);
    printDynArr(mainList, print_type);
	printf("ADDING THIRD ELEMENT\n");
	addHeap(mainList, task3, compare);
    printDynArr(mainList, print_type);
	printf("ADDING FOURTH ELENENT\n");
	addHeap(mainList, task4, compare);
    printDynArr(mainList, print_type);
	printf("ADDING FIFTH ELEMENT\n");
	addHeap(mainList, task5, compare);
    printDynArr(mainList, print_type);
	printf("ADDING 6TH ELEMENT\n");
	addHeap(mainList, task6, compare);
    printDynArr(mainList, print_type);
	printf("ADDING 7TH ELEMENT\n");
	addHeap(mainList, task7, compare);
    printDynArr(mainList, print_type);
	printf("ADDING 8TH ELEMENT\n");
	addHeap(mainList, task8, compare);
    printDynArr(mainList, print_type);
	printf("ADDING 9TH ELEMENT\n");
	addHeap(mainList, task9, compare);
    printDynArr(mainList, print_type);
	printf("ADDING 10TH ELEMENT\n");
	addHeap(mainList, task10, compare);
    printDynArr(mainList, print_type);
    
	printDynArr(mainList, print_type);

	

	//We will add values at random to the list sortedList
	//and will be sorting in one go, rather than by slowly creating a heap
	//as elements are added
	addDynArr(sortedList, task4);
	addDynArr(sortedList, task6);
	addDynArr(sortedList, task5);
	addDynArr(sortedList, task8);
	addDynArr(sortedList, task10);
	addDynArr(sortedList, task7);
	addDynArr(sortedList, task1);
	addDynArr(sortedList, task3);
	addDynArr(sortedList, task2);
	addDynArr(sortedList, task9);
	printf("Before Sort Called \n");

    printDynArr(sortedList, print_type);
	/* sort tasks */
	sortHeap(sortedList, compare);

	printf("After Sort Called \n");

	/* print sorted tasks from the dynamic array */
    printDynArr(sortedList, print_type);

	return 0;
}
