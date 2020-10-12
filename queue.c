#include <stdlib.h>
#include "reporter.h"
#include "queue.h"

struct QueueNode {
  SearchTree Element;
  struct QueueNode *Next;
};

struct QueueRecord{
	queueNode front;
	queueNode rear;

};

Queue CreateQueue(void){
    Queue Q =malloc(sizeof(Queue));
    FatalErrorMemory(Q);
    Q->front=NULL;
    Q->rear=NULL;
    return Q;

}
void DisposeQueue( Queue Q ){
    queueNode temp;
    while(Q->front!=NULL){
        temp = Q->front;
        Q->front = Q->front->Next;
        free(temp);
    }
    Q->front=NULL;
    Q->rear=NULL;
    return;
}
void Enqueue( SearchTree X, Queue Q ){
    queueNode newNode=malloc(sizeof(queueNode));
    FatalErrorMemory(newNode);
    newNode->Element=X;
    newNode->Next=NULL;
    if(Q->rear==NULL){
        Q->front= Q->rear = newNode;
        
    }
    else{
        Q->rear->Next=newNode;
        Q->rear=newNode;
    }
    return;
}

SearchTree Front( Queue Q ){
    return Q->front->Element;

}
SearchTree Dequeue( Queue Q ){
    if(Q->front==NULL){
        return NULL;
    }
    SearchTree value = Q->front->Element;
    queueNode temp=Q->front;
    free(temp);
    
    
    Q->front=Q->front->Next;
    if(Q->front==NULL){
        Q->rear=NULL;
    }
    return value;

}
int IsEmptyQueue( Queue Q ){
    return Q->front==NULL;

}
