#include <iostream>
#include <string>
using namespace std;

struct INode {
    int data;
    struct INode* pnext;
};
typedef struct INode INODE;

struct IList {
    INODE* phead;
    INODE* ptail;
};
typedef struct IList ILIST;

void CreateIList (ILIST &il) {
    il.phead=il.ptail=NULL;
}

INODE* CreateINode (int x) {
    INODE* p=new INODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void ipush (ILIST &il, INODE* p) {
    if (il.phead==NULL) {
        il.phead=il.ptail=p;
    } else {
        p->pnext=il.phead;
        il.phead=p;
    }
}

int ipop (ILIST &il, int &x) {
    INODE* p;
    if (il.phead!=NULL) {
        x=il.phead->data;
        p=il.phead;
        il.phead=il.phead->pnext;
        if (il.phead==NULL) {
            il.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void ChuyenDoiCoSo (int n) {  //Chuyển đổi hệ 10 sang hệ nhị phân
    ILIST stack;
    int t,dem=0;
    while (n!=0)
    {
        t=n%2;
        n=n/2;
        ipush(stack,CreateINode(t));
        dem++;
    }
    for (int i=0; i<dem; i++) {
        int x;
        ipop(stack,x);
        cout <<x;
    }
}

int main () {
    cout <<"\n\t\t=====CHUYEN HE THAP PHAN SANG NHI PHAN=====\n";
    ChuyenDoiCoSo(8);
    system("pause");
    system("cls");
    return 0;
}