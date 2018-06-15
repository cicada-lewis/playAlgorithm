#include <iostream>
using namespace std;

typedef int Elemtype;
typedef int Status;

typedef struct Node{
    Elemtype elem;
    struct Node *next;
}Node;



Node* CreateCirclarLinklist(Node *head,Elemtype felem){
    Node *fnode=(Node *)malloc(sizeof(Node));
    fnode->elem=felem;
    fnode->next=fnode;
    head=fnode;
    return head;
};

Status InsertNode(Node *head,Elemtype elem){
    Node *node=(Node *)malloc(sizeof(Node));
    node->elem=elem;
    node->next=head->next;
    head->next=node;
    head=node;
    return 1;
}

void TravelCirclarLinklist(Node *head){
    Node *p=head;
    do{
        cout<<p->elem<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}

Node *CreateCirclarLinklistWithTail(Elemtype elem){
    Node *tail=(Node *)malloc(sizeof(Node));
    Node *fnode=(Node *)malloc(sizeof(Node));
    fnode->elem=elem;
    fnode->next=fnode;
    tail->next=fnode;
    return tail;
}

Status InsertNodeByTail(Node *tail,Elemtype elem){
    Node *node=(Node *)malloc(sizeof(Node));
    node->elem=elem;
    node->next=tail->next->next->next;
    tail->next->next=node;
    return 1;
}

void TravelCirclarLinklistByTail(Node *tail){
    Node *p=tail->next;
    do{
        cout<<p->elem<<" ";
        p=p->next;
    }while(p!=tail->next);
    cout<<endl;
}

int main(int argc,char *argv[]){

    Node *head=CreateCirclarLinklist(head,10);
    InsertNode(head,11);
    InsertNode(head,100);
    TravelCirclarLinklist(head);
    cout<<endl;
    Node *tail=CreateCirclarLinklistWithTail(110);
    InsertNodeByTail(tail,120);
//    cout<<tail->next->elem<<" "<<tail->next->next->elem<<" "<<tail->next->next->next->elem<<endl;
    TravelCirclarLinklistByTail(tail);
    return 0;

}