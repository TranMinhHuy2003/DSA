#include <iostream>
#include <string.h>
using namespace std;

struct CNode {
    char data;
    struct CNode* pnext;
};
typedef struct CNode CNODE;

struct CList {
    CNODE* phead;
    CNODE* ptail;
};
typedef struct CList CLIST;

void CreateCList (CLIST &cl) {
    cl.phead=NULL;
    cl.ptail=NULL;
}

CNODE* CreateCNode (char x) {
    CNODE* p=new CNODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
}

void cpush (CLIST &cl, CNODE* p) {
    if (cl.phead==NULL) {
        cl.phead=cl.ptail=p;
    } else {
        p->pnext=cl.phead;
        cl.phead=p;
    }
}

int cpop (CLIST &cl, char &x) {
    CNODE *p;
    if (cl.phead !=NULL) {
        x = cl.phead->data;
        p = cl.phead;
        cl.phead = cl.phead->pnext;
        if (cl.phead == NULL)
            cl.ptail = NULL;
        delete p;
        return 1; 
    }
    return 0;
} 

void EnQueue (CLIST &cl, CNODE* p) {
    if (cl.phead==NULL) {
        cl.phead=cl.ptail=p;
    } else {
        cl.ptail->pnext=p;
        cl.ptail=p;
    }
}

int DeQueue (CLIST &cl, char &x) {
    CNODE* p;
    if (cl.phead!=NULL) {
        x=cl.phead->data;
        p=cl.phead;
        cl.phead=cl.phead->pnext;
        if (cl.phead==NULL) {
            cl.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void ChuyenChuoiSangInHoa (string &x) {
    int n=x.length();
    for (int i=0; i<n; i++) {
        if (x[i]>=97&&x[i]<=122) {
            x[i]-=32;
        }
    }
}

bool Palindromes (string x) {  //Palindromes
    ChuyenChuoiSangInHoa(x);
    CLIST stack;
    CLIST queue;
    CreateCList(stack);
    CreateCList(queue);
    int n=x.length();
    for (int i=0; i<n; i++) {
        cpush(stack,CreateCNode(x[i]));
        EnQueue(queue,CreateCNode(x[i]));
    }
    for (int i=0; i<n; i++) {
        char c,d;
        cpop(stack,c);
        DeQueue(queue,d);
        if (c!=d) { //Kiểm tra nếu có bất kỳ cặp kí tự nào khác nhau thì return false
            return false;
        }
    }
    return true;
}

int main () {
    string a="Able was I ere I saw Elba";
    if (Palindromes(a)) {
        cout <<"\nChuoi tren la chuoi Palindrome";
    } else {
        cout <<"\nChuoi tren khong la chuoi Palindrome";
    }
    system("pause");
    system("cls");
    return 0;
}