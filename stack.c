/*
Stack package using a fixed size array.  Push/pop pointers to elements.
*/

#include <stdlib.h>
#include <stdio.h>
#include "reporter.h"
#include "stack.h"


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};


void MakeEmpty( Stack S )
{
    S->TopOfStack = EmptyTOS;
}

void printStack(Stack S)
{
    printf("\n Stack content \n");
    int i=0;
    for (i=0; i < S->TopOfStack + 1 ;i++)
        printf("%c\n", S->Array[i]);
}


Stack CreateStack( int count )
{
    Stack S;

    if( count < MinStackSize )
        fprintf(stderr,"Stack size is too small" );

    S = malloc( sizeof( struct StackRecord ) );
    if( S == NULL )
        FatalErrorMemory(S);

    S->Array = malloc( sizeof( ElementType ) * count );
    if( S->Array == NULL )
        FatalErrorMemory( "Out of space!!!" );
    S->Capacity = count;
    MakeEmpty( S );

    return S;
}


void DestroyStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}


ElementType TopOfStack(Stack S) {
    if( IsEmpty( S ) ) {
        return -1;
    }
    else {
        return S->Array[S->TopOfStack];
    }
}

ElementType Pop(Stack S) {
    if( !IsEmpty( S ) ) {
        ElementType elem = S->Array[ S->TopOfStack ];

        //free(S->Array[ S->TopOfStack ]);
        S->TopOfStack--;
        return elem;
    }
    else {

    //FatalErrorMemory(S);
    return -1;  /* Return value used to avoid warning */
    }

}

void Push(Stack S, ElementType X) {

    if( IsFull( S ) ) {
        printf("Error: Full stack" );
        S->Array = realloc(S->Array, S->Capacity * 2 * sizeof(ElementType)); 
        S->Capacity = S->Capacity * 2;

        if (S->Array == NULL) {
            FatalErrorMemory( "Out of space!!!" );
            exit(1);
        }
    }
    S->Array[ ++S->TopOfStack ] = X;
}

int IsEmpty( Stack S ) 
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull( Stack S ) 
{
    return S->TopOfStack == S->Capacity - 1;
}

