#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* pnext;
};
typedef struct node NODE;

struct list {
    NODE* phead;
    NODE* ptail; 
};
typedef struct list List;

void CreateList (List &l) {
    l.phead=NULL; 
    l.ptail=NULL;
}

NODE* CreateNode (int x) {
    NODE* p=new NODE;
    if (p==NULL) {
        exit(1);
    }
    p->data=x;
    p->pnext=NULL;
    return p;
}

void AddHead (List &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead=p;
    }
}

void AddTail (List &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=p;
        l.ptail=p;
    } else {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

void AddAfterQ(LIST &L, NODE* p, NODE* Q) {
    if (Q != NULL) {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q)
            L.pTail = p;
    } else
        AddHead(L, p); 
}

NODE* SearchNode(LIST L, int x) {
    NODE* p = L.pHead;
    while (p != NULL && p->info != x)
        p = p->pNext;
    return p;
}

bool RemoveHead(LIST &L, int &x) {
    NODE *p;
    if (L.pHead !=NULL) {
        x = L.pHead->info;
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
            L.pTail = NULL;
        delete p;
        return 1; 
    }
    return 0;
}

bool RemoveAfterQ(LIST &l, NODE *Q, int &x) {
    NODE *p;
    if (Q != NULL) {
        p = Q->pNext; 
        if (p != NULL) { 
            if (p == l.pTail) 
                l.pTail = Q; 
            Q->pNext = p->pNext;
            x = p->info;
            delete p;
        }
        return 1;
    }
    return 0;
}

bool RemoveX(LIST &L, int x) {
    NODE *Q, *p;
    Q = NULL;
    p = L.pHead;
    while (p!=NULL && p->info!=x) {
        Q = p;
        p = p->pNext;
    }
    if (p == NULL) return 0; 
    if (Q != NULL) RemoveAfterQ(L, Q, x);
    else RemoveHead(L, x);
    return 1;
}

void RemoveList(LIST &L) {
    NODE * p;
    while (L.pHead != NULL) {
        p = L.pHead;
        L.pHead = p->pNext;
    delete p;
    }
    L.pTail = NULL;
}

void PrintList (List l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<" ";
    }
}


int main() {
    List l;
    CreateList(l); 
    AddTail(l,CreateNode(1));
    AddTail(l,CreateNode(2));
    AddTail(l,CreateNode(3));
    AddHead(l,CreateNode(4));
    AddHead(l,CreateNode(5));
    PrintList(l);
    return 0;
}