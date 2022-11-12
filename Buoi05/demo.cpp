#include <iostream>
#include <string.h>
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
    l.phead=NULL;
    l.ptail=NULL;
}

NODE* CreateNode (char x) {
    NODE* p=new NODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void push (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead=p;
    }
}

int pop (LIST &l, int &x) {
    NODE *p;
    if (l.phead !=NULL) {
        x = l.phead->data;
        p = l.phead;
        l.phead = l.phead->pnext;
        if (l.phead == NULL)
            l.ptail = NULL;
        delete p;
        return 1; 
    }
    return 0;
} 

int isEmpty (LIST l) {
    if (l.phead==NULL) {
        return 1;
    }
    return 0;
}

int Top (LIST l) {
    return l.phead->data;
}

void EnQueue (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

int DeQueue (LIST &l, int &x) {
    NODE* p;
    if (l.phead!=NULL) {
        x=l.phead->data;
        p=l.phead;
        l.phead=l.phead->pnext;
        if (l.phead==NULL) {
            l.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

int IsEmpty (LIST l) {
    if (l.phead==NULL) {
        return 1;
    }
    return 0;
}

int Front (LIST l) {
    return l.phead->data;
}

int Back (LIST l) {
    return l.ptail->data;
}

/*void DaoMang (char a[]) {
    LIST stack;
    for (int i=0; i<strlen(a); i++) {
        push(stack,CreateNode(a[i]));
    }
    for (int i=0; i<strlen(a); i++) {
        char x;
        pop(stack,x);
        a[i]=x;
    }
    for (int i=0; i<strlen(a); i++) {
        cout <<a[i];
    }
}*/

void ChuyenDoiCoSo (int n) {
    LIST stack;
    int t,dem=0;
    while (n!=0)
    {
        t=n%2;
        n=n/2;
        push(stack,CreateNode(t));
        dem++;
    }
    for (int i=0; i<dem; i++) {
        int x;
        pop(stack,x);
        cout <<x;
    }
}

int main () {
    char a[]="abcdefg";
    //DaoMang(a);
    ChuyenDoiCoSo(11);
    system("pause");
    system("cls");
    return 0;
}

