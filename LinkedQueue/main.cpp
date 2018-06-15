#include <iostream>

using namespace std;

typedef int Elemtype;
typedef int Status;

typedef struct Node{
    Elemtype elem;
    Node *next;
}LinkedNode;

typedef struct LinkedQueue{
    Node *front,*rear;
    int length;
}Queue;

LinkedQueue *InitLinkedQueue(void){
    LinkedQueue* linkedQueue=(LinkedQueue *)malloc(sizeof(LinkedQueue));
    linkedQueue->front=(Node *)malloc(sizeof(Node));
    linkedQueue->rear=linkedQueue->front;
    linkedQueue->length=0;
    return linkedQueue;
}

Status EnterLinkedLinkedQueue(LinkedQueue *linkedQueue,Elemtype elem){
    Node *node=(Node *)malloc(sizeof(Node));
    node->elem=elem;
    linkedQueue->rear->next=node;
    linkedQueue->rear=node;
    return 1;
}

bool IsEmpty(LinkedQueue *linkedQueue){
    if(linkedQueue->rear==linkedQueue->front){
        return true;
    }
    else{
        return false;
    }
}

Elemtype OutLinkedQueue(LinkedQueue *linkedQueue,Elemtype *elem){
    if(IsEmpty(linkedQueue)) exit(-1);
    Node *getNode=linkedQueue->front->next;
    *elem=getNode->elem;
    linkedQueue->front->next=getNode->next;
    if(linkedQueue->rear==getNode)
        linkedQueue->rear=linkedQueue->front;
    free(getNode);
    return *elem;
}

int main(int argc,char *argv[]){
    LinkedQueue *linkedQueue=InitLinkedQueue();
    EnterLinkedLinkedQueue(linkedQueue,10);
    cout<<linkedQueue->front->next->elem<<endl;
    return 0;
}