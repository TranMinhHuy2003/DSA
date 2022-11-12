#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* pnext;
};
typedef struct Node NODE;

struct List
{
    NODE* phead;
    NODE* ptail;
};
typedef struct List LIST;

NODE* CreateNode (int x) {
    NODE* p=new NODE;
    if (p==NULL) {
        return NULL;
    }
    p->data=x;
    p->pnext=NULL;
    return p;
}

void CreateList (LIST &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

void AddHead (LIST &l, NODE* p) {
    if (l.phead==NULL) { //Nếu danh sách rỗng thì head=tail=p
        l.phead=p;
        l.ptail=p;
    } else {
        p->pnext=l.phead;//Móc địa chỉ
        l.phead=p;//Di dời head
    }
}

void AddTail (LIST &l, NODE* p) {
    if (l.phead==NULL) {//Nếu danh sách rỗng thì head=tail=p
        l.phead=p;
        l.ptail=p;
    } else {
        l.ptail->pnext=p;//Móc địa chỉ
        l.ptail=p;//Di dời tail
    }
}

void PrinList (LIST l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<"\t";
    }
    cout <<endl;
}

void PrintListUsingWhile (LIST l) {
    NODE* k=l.phead;
    while (k!=NULL) {
        cout <<k->data<<"\t";
        k=k->pnext;
    }
    cout <<endl;
}

int main () {
    NODE* p1=CreateNode(20);
    NODE* p2=CreateNode(30);
    NODE* p3=CreateNode(50);
    /*cout <<p1<<endl;
    cout <<p1->data<<endl;
    cout <<p1->pnext<<endl;*/
    LIST l;
    CreateList(l);
    /*cout <<l.phead<<endl;
    cout <<l.ptail<<endl;
    cout <<l.phead->data<<endl;
    cout <<l.ptail->data;*/
    AddHead(l,p1);
    AddHead(l,p2);
    AddTail(l,p3);
    PrinList(l);
    system("pause");
    system("cls");
    return 0;
}