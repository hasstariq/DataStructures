#include <stdio.h>
#include <stdlib.h>
#include "Stack/stack.h"

typedef int ElementType;
struct node {                                      
   ElementType value; 
   struct node *next; 
}; 

typedef struct node Node; 
typedef Node *List; 
typedef Node *Position; 

void insert_start(List *head, ElementType value);
void insert_end(List *head, ElementType value);

int isEmpty(List head);
void printList(List head);  //printList
void printList_recursive(List head);
void printList_backward_iterative(List head);
void printList_backward_recursive(List head);
void SwapWithNext(Position BeforeP, List head);
int find(List head, ElementType value);
int find_recursive(List head, ElementType value);
List union_list(List L1, List L2);
List reverseList(List);
List reverseList_recursive(List L);
List reverseList_stack(List L);

int delete_first(List *head);
int delete_last(List *head);


int main(void)
{ 
   List Head = NULL;
   ElementType item; 

   item = 1;
   int i=0;
   for (i=0; i<10; i++) {
        insert_start (&Head, i);
        }
        printList(Head);
        if (!isEmpty(Head)) { 
          //  delete(&Head, item);
        //    Head = delete_first(Head);
        }

   //printing List: 4)a
   //it is importatnt to use the temporary variable
   List temp = Head;
   if (isEmpty(Head)) {
       printf("NULL\n");
   } 
   else { 
       while (temp!= NULL) {
            printf("%d --> ", temp->value );
            temp = temp->next;
        }
       printf("NULL\n");
    }
   //       end of 4)a 

   printf("\nCalling printList backward_iterative\n");
   printList_backward_iterative(Head);
   printf("\n-------done\n");

   printf("Tesing find...........\n");
   if (find_recursive (Head, 6)) {
   printf("FOUND\n");
   }
   else
   {
   printf("NOT FOUND\n");
   }
   //delete_last(&Head);
   //printList(Head);

   
   //Testing SwapWithNext Function
   temp = Head;
   temp=temp->next;
   temp=temp->next;
   printList(temp);
   SwapWithNext(temp, Head);
   printList(Head);

   List L2=NULL;
   for (i=5; i<15; i++) 
       insert_start (&L2, i);
   
    List result = union_list(Head, L2);
    printList(result);
}

List union_list(List L1, List L2) {
    List result=NULL;

    // Insert all elements of list1 to the result list 
    while (L1!= NULL)  {
         insert_start(&result, L1->value); 
         L1 = L1->next; 
    }

    // Insert those elements of list2 which are not 
    // present in result list 
    while ( L2 != NULL) 
    { 
        if (!find(result, L2->value)) 
            insert_start(&result, L2->value); 
        L2 = L2->next; 
    } 
    return result; 
}

int find(List head, ElementType value) {
    while (head!=NULL) {
        if (head->value == value)
            return 1;
        head = head->next;    
    }
    return 0;
}

int find_recursive(List head, ElementType value) {
    if (head!=NULL) {
        if (head->value == value)
            return 1;
        
        else
        return find_recursive(head->next, value);
    }
    return 0;
}


void SwapWithNext(Position BeforeP, List Head) {
    
    Position P, AfterP;
    P = BeforeP->next;
    AfterP = P->next; /* Both P and AfterP assumed not NULL. */
    P->next = AfterP->next;
    BeforeP->next = AfterP;
    AfterP->next = P;


}

void insert_start(List *head, ElementType value) {

   List newPtr = malloc(sizeof(Node)); // create node

   if (newPtr != NULL) { // is space available
      newPtr->value = value; // place value in node
      newPtr->next = *head; // link to the beginning of the linked list
      *head = newPtr;
      
   } 
   else {
      printf("%c not inserted. No memory available.\n", value);
   }

}

void insert_end(List *head, ElementType value) {

	List newPtr = malloc(sizeof(Node)); // create node
	List currentPtr = *head;
	List previousPtr;

	if (newPtr != NULL) { // is space available
		newPtr->value = value; // place value in node
		newPtr->next = NULL; // link to the beginning of the linked list

		// loop to find the correct location in the list       

		currentPtr = *head;
		
		//if the linked list is empty
		if (*head == NULL) {
			*head = newPtr;
			return;
		}
		else {

			while (currentPtr->next != NULL ) 
				currentPtr = currentPtr->next;  

			currentPtr->next  = newPtr;
		}

	} 
	else {
		printf("%c not inserted. No memory available.\n", value);
	} 


}

int delete_first(List *head)
{

   if (*head == NULL)
   	return 0;
   else{	
      List tempPtr = *head; 
      
      *head = (*head)->next; 
      //is this enough?
      //No, you should free the memory, that's why we free it.


      free(tempPtr); // free the de-threaded node
      
      return 1;
   } 
}

int delete_last(List *head)
{
   if (*head == NULL)
   	return 0;
   else if ( (*head)->next == NULL) {
	   //only one element
        free(*head);
   	*head = NULL; 
    
    //Why set to NULL is required?
    //Setting unused pointers to NULL is a defensive style,
    //protecting against dangling pointer bugs. If a dangling 
    //pointer is accessed after it is freed, you may read or 
    //overwrite random memory. If a null pointer is accessed, 
    //you get an immediate crash on most systems, telling you right away what the error is.
    //https://stackoverflow.com/questions/1025589/setting-variable-to-null-after-free

	return 1;
   }
   else {
	   List currentPtr = *head;
	   while (currentPtr->next->next != NULL)	
		   currentPtr = currentPtr->next;


	   List temp = currentPtr->next;
	   currentPtr->next = currentPtr->next->next;
	   free(temp);
	   temp = NULL;
	   return 1;
   }

   return 1;
}


int delete_last_different(List *head)
{
  
    if (*head == NULL) {
	    return 0;
    }
    else{ 
	   List previousPtr = NULL;
	   List currentPtr = *head;

	   // loop to find the correct location in the list
	   while (currentPtr->next != NULL ) { 
		   previousPtr = currentPtr; // walk to ...  
		   currentPtr = currentPtr->next; // ... next node  
	   } 
	   if (previousPtr == NULL)
	   	*head = NULL;
	   else
	   	previousPtr->next = currentPtr->next;

	   free (currentPtr);

	   return 1;
   } 

}

// return 1 if the list is empty, 0 otherwise
int isEmpty(List head)
{ 
   return head == NULL;
} 

// print the list
void printList(List currentPtr)
{ 
   // if list is empty
    if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else { 
      puts("The list is:");

      while (currentPtr != NULL) { 
         printf("%d --> ", currentPtr->value);
         currentPtr = currentPtr->next;   
      } 

      puts("NULL\n");
   }
}

// print the list
void printList_recursive(List currentPtr)
{ 
    if (isEmpty(currentPtr)) {
        puts("NULL\n");
        return;
    } 
    else { 

        printf("%d --> ", currentPtr->value);
        printList_recursive(currentPtr->next);

    } 
}


void printList_backward_recursive(List currentPtr) {
    if (isEmpty(currentPtr)) {
        printf("NULL  ");
        return;
    } 
    else { 
        printList_backward_recursive(currentPtr->next);
        printf(" <-- %d ", currentPtr->value);

    } 
}
List reverseList_stack(List L) {

    List reverseL = NULL;
   Stack S = CreateStack(100);
   while (L!=NULL) {
        Push(S, L->value); 

   }

    while (!IsEmpty(S) ) {
        insert_start( &reverseL, Pop(S));
    }
    
   return reverseL;
}

List reverseList_recursive(List L) {

    List temp, prev, node1 = NULL;

    if (L==NULL)
        return NULL;
    if (L->next ==NULL) 
        return L;
    node1 = reverseList_recursive(L->next);
    L->next->next = L;
    L->next = NULL;
    return node1;

}

List reverseList(List L) {

   List prev = NULL;
   List next;

   while (L!=NULL) {
        
        next = L->next;
        L->next = prev;
        prev = L;
        L=next;
   }
    
   return prev;
    
}
/*

The following function canges the list (reverse the list)
and then print it regularly
*/

void printList_backward_iterative(List currentPtr) {

    List temp = reverseList_stack(currentPtr);
    if (isEmpty(temp)) {
        puts("NULL\n");
        return;
    } 
    else { 
        List t = temp;
        while (t!= NULL) {
            printf("%d --> ", t->value);
            t = t->next;
        }
        printf("NULL\n");
    } 
}

/*
void printList_backward_iterative(List currentPtr) {
    List temp, prev, Last;

    if (isEmpty(currentPtr)) {
        puts("NULL\n");
        return;
    } 
    else { 

        Last =NULL;

        while (Last != currentPtr) {

            temp = currentPtr;

            while (temp!= Last) {
                prev = temp;
                temp = temp->next;
            }

            printf("%d --> ", prev->value);
            Last = prev;
        }

        printf("NULL\n");
    } 
} */
