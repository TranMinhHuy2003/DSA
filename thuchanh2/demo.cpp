#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* pnext;
};
typedef struct Node NODE;

struct List {
    NODE* phead;
    NODE* ptail;
};
typedef struct List LIST;

void CreateList (LIST &l) {
    l.phead=l.ptail=NULL;
}

NODE* CreateNode (int x) {
    NODE* p=new NODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void AddHead (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead=p;
    }
}

void AddTail (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

bool RemoveHead (LIST &l) {
    if (l.phead!=NULL) {
        NODE* p=l.phead;
        l.phead=l.phead->pnext;
        if (l.phead==NULL) {
            l.ptail=NULL;
        }
        delete p;
        return true;
    }
    return false;
}

bool RemoveTail (LIST &l) {
    if (l.phead!=NULL) {
        for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
            if (k->pnext==l.ptail) {
                delete l.ptail;
                k->pnext=NULL;
                l.ptail=k;
            } else if (k==l.ptail) {
                delete l.ptail;
                l.phead=l.ptail=NULL;
            }
            return true;
        }
    }
    return false;
}

bool RemoveAfterQ (LIST &l, NODE* Q) {
    NODE* p;
    if (Q!=NULL) {
        p=Q->pnext;
        if (p!=NULL) {
            if (p==l.ptail) {
                l.ptail=Q;
            } else {
                Q->pnext=p->pnext;
            }
            delete p;
        }
        return true;
    }
    return false;
}

bool RemoveX (LIST &l, int x) {
    NODE* Q,p;
    NODE* Q=NULL;
    NODE* p=l.phead;
    while (p!=NULL&&p.data!=x) {
        Q=p;
        p=p->pnext;
    }
    if (p==NULL) {
        return false;
    } 
    if (Q==NULL) {
        RemoveHead(l);
    } else {
        RemoveAfterQ(l,Q);
    }
    return true;
}

void PrintList (LIST l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<"\t";
    }
}

int main () {
    LIST l;
    CreateList(l);
    AddHead(l,CreateNode(2));
    PrintList(l);
    cout <<endl;
    RemoveTail(l);
    PrintList(l);
    system("pause");
    system("cls");
    return 0;
}