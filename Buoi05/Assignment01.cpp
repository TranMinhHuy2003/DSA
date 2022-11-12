#include <iostream>
#include <string>
using namespace std;

struct FNode {
    float data;
    struct FNode* pnext;
};
typedef struct FNode FNODE;

struct SNode {
    string data;
    struct SNode* pnext;
};
typedef struct SNode SNODE;

struct INode {
    int data;
    struct INode* pnext;
};
typedef struct INode INODE;

struct CNode {
    char data;
    struct CNode* pnext;
};
typedef struct CNode CNODE;

struct FList {
    FNODE* phead;
    FNODE* ptail;
};
typedef struct FList FLIST;

struct SList {
    SNODE* phead;
    SNODE* ptail;
};
typedef struct SList SLIST;

struct IList {
    INODE* phead;
    INODE* ptail;
};
typedef struct IList ILIST;

struct CList {
    CNODE* phead;
    CNODE* ptail;
};
typedef struct CList CLIST;

void CreateFList (FLIST &fl) {
    fl.phead=fl.ptail=NULL;
}

void CreateSList (SLIST &sl) {
    sl.phead=sl.ptail=NULL;
}

void CreateIList (ILIST &il) {
    il.phead=il.ptail=NULL;
}

void CreateCLIst (CLIST &cl) {
    cl.phead=cl.ptail=NULL;
}

FNODE* CreateFNode (float x) {
    FNODE* p=new FNODE;
    if (p==NULL) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
    }
    return p;
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

void fpush (FLIST &fl, FNODE* p) {
    if (fl.phead==NULL) {
        fl.phead=fl.ptail=p;
    } else {
        p->pnext=fl.phead;
        fl.phead=p;
    }
}

void spush (SLIST &sl, SNODE* p) {
    if (sl.phead==NULL) {
        sl.phead=sl.ptail=p;
    } else {
        p->pnext=sl.phead;
        sl.phead=p;
    }
}

void ipush (ILIST &il, INODE* p) {
    if (il.phead==NULL) {
        il.phead=il.ptail=p;
    } else {
        p->pnext=il.phead;
        il.phead=p;
    }
}

void cpush (CLIST &cl, CNODE* p) {
    if (cl.phead==NULL) {
        cl.phead=cl.ptail=p;
    } else {
        p->pnext=cl.phead;
        cl.phead=p;
    }
}

int fpop (FLIST &fl, float &x) {
    FNODE* p;
    if (fl.phead!=NULL) {
        x=fl.phead->data;
        p=fl.phead;
        fl.phead=fl.phead->pnext;
        if (fl.phead==NULL) {
            fl.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
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

int cpop (CLIST &cl, char &x) {
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

int isEmpty (CLIST cl) {
    if (cl.phead==NULL) {
        return 1;
    }
    return 0;
}

void DaoMangSoThuc (float a[], int n) { //Đảo mảng số thực float gồm n phần tử
    FLIST stack;
    CreateFList(stack);
    for (int i=0; i<n; i++) {
        fpush(stack,CreateFNode(a[i]));
    }
    for (int i=0; i<n; i++) {
        float x;
        fpop(stack,x);
        a[i]=x;
    }
    for (int i=0; i<n; i++) {
        cout <<a[i]<<"\t";
    }
}

void DaoChuoi (string x) {
    CLIST stack;
    CreateCLIst(stack);
    int n=x.length();
    for (int i=0; i<n; i++) {
        cpush(stack,CreateCNode(x[i]));
    }
    for (int i=0; i<n; i++) {
        char c;
        cpop (stack,c);
        x[i]=c;
    }
    for (int i=0; i<n; i++) {
        cout <<x[i];
    }
}

void reverseString(string x) //Đảo chuỗi: thực hiện đảo từ trong chuỗi
{
    SLIST stack;
    CreateSList(stack);
	string s;
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

bool BracketMatching (string x) {  //Bracket Matching
    CLIST stack;
    CreateCLIst(stack);
    int length=x.length();
    for (int i=0; i<length; i++) {
        if (x[i]=='(') {
            cpush(stack,CreateCNode(x[i]));
        } else if (x[i]==')') {
            if (isEmpty(stack)==1) {
                return false;
            } else {
                char c;
                cpop(stack,c);
            }
        }
    }
    if (isEmpty(stack)==1) {
        return true;
    }
    return false;
}

bool BalancingAct (string x) {  //Balancing Act gồm những cặp ngoặc này: "()", "{}", "[]"
    CLIST stack;
    CreateCLIst(stack);
    int length=x.length();
    for (int i=0; i<length; i++) {
        if (x[i]=='('||x[i]=='['||x[i]=='{') {
            cpush(stack,CreateCNode(x[i]));
        } else if (x[i]==')'||x[i]=='}'||x[i]==']') {
            if (isEmpty(stack)==1) {
                return false;
            } else {
                char d;
                if (x[i]==')') {
                    d='(';
                } else if (x[i]=='}') {
                    d='{';
                } else if (x[i]==']') {
                    d='[';
                }
                char c;
                cpop(stack,c);
                if (c!=d) {
                    return false;
                }
            }
        }
    }
    if (isEmpty(stack)==1) {
        return true;
    }
    return false;
}

int main () {
    float a[10]={0,1,2,3,4,5,6,7,8,9};
    string b="Lan di hoc";
    string c="- b + b^2 - 4*a*c)^(0.5/ 2*a))";
    string d="[[{(({(- b + b^2) - ( 4*a*c^0.5/ 2*a)}))}]]]";
    string e="abcde";
    cout <<"\n\t\t======DAO MANG SO THUC======\n";
    DaoMangSoThuc(a,10);
    cout <<"\n\t\t======DAO TU TRONG CHUOI======\n";
    reverseString(b);
    cout <<"\n\t\t=====CHUYEN HE THAP PHAN SANG NHI PHAN=====\n";
    ChuyenDoiCoSo(8);
    cout <<"\n\t\t=======BRACKET MATCHING=======\n";
    if (BracketMatching(c)) {
        cout <<"\nTrue";
    } else {
        cout <<"\nFalse";
    }
    cout <<"\n\t\t=======BALANCING ACT=======\n";
    if (BalancingAct(d)) {
        cout <<"\nTrue";
    } else {
        cout <<"\nFalse";
    }
    cout <<"\nDAOCHUOI\n";
    DaoChuoi(e);
    system("pause");
    system("cls");
    return 0;
}