#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* pnext;
    struct Node* ppre;
};
typedef struct Node NODE;

struct List {
    NODE* phead;
    NODE* ptail;
};
typedef struct List LIST;

void CreateList (List &l) {
    l.phead=NULL;
    l.ptail=NULL;
}

NODE* CreateNode (int x) {
    NODE* p=new NODE;
    if (p==NULL ) {
        return NULL;
    } else {
        p->data=x;
        p->pnext=NULL;
        p->ppre=NULL;
    }
    return p;
}

void AddHead (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        p->pnext=l.phead;
        l.phead->ppre=p;
        l.phead=p;
    }
}

void AddTail (LIST &l, NODE* p) {
    if (l.phead==NULL) {
        l.phead=l.ptail=p;
    } else {
        l.ptail->pnext=p;
        p->ppre=l.ptail;
        l.ptail=p;
    }
}

void AddAfterQ (LIST &l, NODE* tam, NODE* q) {
    NODE* p=q->pnext;
    if (q!=NULL) {
        tam->ppre=q;
        tam->pnext=p;
        q->pnext=tam;
        if (p!=NULL) {
            p->ppre=tam;
        } else {
            if (q==l.ptail) {
                l.ptail=tam;
            }
        }
    } else {
        AddHead(l,tam);
    }
}

void AddBeforeQ (LIST &l, NODE* tam, NODE* q) {
    NODE* p=q->ppre;
    if (q!=NULL) {
        tam->pnext=q;
        q->ppre=tam;
        tam->ppre=p;
        if (p!=NULL) {
            p->pnext=tam;
        } else {
            if (q==l.phead) {
                l.phead=tam;
            }
        }
    } else {
        AddTail(l,tam);
    }
}

void Nhap(int n, LIST &l) {
    for (int i=0; i<n; i++) {
        int x;
        cout <<"\nNhap data: ";
        cin>>x;
        AddTail(l,CreateNode(x));
    }
}

void DuyetList (LIST l) {
    for (NODE* k=l.ptail; k!=NULL; k=k->ppre) {
        cout <<k->data<<"\t";
    }
}

void LietKeNode (LIST l, int x) {
    for (NODE*k=l.phead; k!=NULL; k=k->pnext) {
        if (k->data>x) {
            cout <<k->data<<"\t";
        }
    }
}

void ThemSau (LIST &l, NODE* x) {
    for (NODE*k=l.phead; k!=NULL; k=k->pnext) {
        if (x->data>k->data) {
            AddAfterQ(l,x,k);
        }
    }
}

void ThemTruoc (LIST &l, NODE* x) {
    for (NODE*k=l.phead; k!=NULL; k=k->pnext) {
        if (x->data<k->data) {
            AddBeforeQ(l,x,k);
        }
    }
}

int RemoveHead (LIST &l) {
    if (l.phead!=NULL) {
        NODE* p=l.phead;
        l.phead=l.phead->pnext;
        l.phead->ppre=NULL;
        if (l.phead==NULL) {
            l.ptail=NULL;
        }        
        delete p;
        return 1;
    }
    return 0;
}

int RemoveTail (LIST &l) {
    if (l.phead!=NULL) {
        NODE* p=l.ptail;
        l.ptail=l.ptail->ppre;
        l.ptail->pnext=NULL;
        if (l.ptail==NULL) {
            l.phead=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void PrintList (LIST l) {
    for (NODE* k=l.phead; k!=NULL; k=k->pnext) {
        cout <<k->data<<"\t";
    }
}

int main () {
    LIST l;
    CreateList(l);
    int n;
    cout <<"\nNhap so node: ";
    cin>>n;
    Nhap(n,l);
    cout <<"\n\t\tDuyet list tu node cuoi den node dau\n";
    DuyetList(l);
    int x;
    cout <<"\nNhap X: ";
    cin>>x;
    cout <<"\nCac node co info lon hon X la: ";
    LietKeNode(l,x);
    int a;
    cout <<"\nNhap data node can them: ";
    cin>>a;
    NODE* b=CreateNode(a);
    ThemSau(l,b);
    cout <<"\n\t\tC1\n";
    PrintList(l);
    cout <<"\nNhap data node can them: ";
    cin>>a;
    b=CreateNode(a);
    ThemTruoc(l,b);
    cout <<"\n\t\tC2\n";
    PrintList(l);
    return 0;
}