#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string data;
    struct SNode* pnext;
};
typedef struct SNode SNODE;

struct SList {
    SNODE* phead;
    SNODE* ptail;
};
typedef struct SList SLIST;

void CreateSList (SLIST &sl) {
    sl.phead=sl.ptail=NULL;
}

SNODE* CreateSNode (string x) {
    SNODE* p=new SNODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void spush (SLIST &sl, SNODE* p) {
    if (sl.phead==NULL) {
        sl.phead=sl.ptail=p;
    } else {
        p->pnext=sl.phead;
        sl.phead=p;
    }
}

int spop (SLIST &sl, string &x) {
    SNODE* p;
    if (sl.phead!=NULL) {
        x=sl.phead->data;
        p=sl.phead;
        sl.phead=sl.phead->pnext;
        if (sl.phead==NULL) {
            sl.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void reverseString(string x) //Đảo chuỗi: thực hiện đảo từ trong chuỗi
{
    SLIST stack;
    CreateSList(stack);
	string s,a[50];
    x+=" ";
    int k=0,length=x.length();
    for (int i=0; i<length; i++) {
        if(x[i]!=' ') {
            s.push_back(x[i]);
        }
        if (x[i]!=' '&&x[i+1]==' ') {
            spush(stack,CreateSNode(s));
            k++;
            s="";
        }
    }
    for (int i=0; i<k; i++) {
        string b;
        spop(stack,b);
        if (i==k-1) {
            cout <<b;
        } else {
            cout <<b<<" ";
        }
    }
}

int main () {
    string b="Lan di hoc";
    cout <<"\n\t\t======DAO TU TRONG CHUOI======\n";
    reverseString(b);
    system("pause");
    system("cls");
    return 0;
}