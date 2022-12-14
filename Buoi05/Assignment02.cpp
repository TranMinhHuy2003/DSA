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

struct NhanSu {
    int gioitinh; //Nam: 1, Nu: 0
    string ten;
};
typedef struct NhanSu NHANSU;

struct STNode {
    NHANSU data;
    struct STNode* pnext;
};
typedef struct STNode STNODE;

struct STList {
    STNODE* phead;
    STNODE* ptail;
};
typedef struct STList STLIST;

void CreateCList (CLIST &cl) {
    cl.phead=NULL;
    cl.ptail=NULL;
}

void CreateSTList (STLIST &stl) {
    stl.phead=stl.ptail=NULL;
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

STNODE* CreateSTNode (NHANSU x) {
    STNODE* p=new STNODE;
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

void EnstQueue (STLIST &stl, STNODE* p) {
    if (stl.phead==NULL) {
        stl.phead=stl.ptail=p;
    } else {
        stl.ptail->pnext=p;
        stl.ptail=p;
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

void NhapNhanSu (NHANSU &x) {
    cin.ignore();
    cout <<"\nNhap ho va ten: ";
    getline(cin,x.ten);
    cout <<"\nNhap gioi tinh: ";
    cin>>x.gioitinh;
}

void XuatNhanSu (NHANSU x) {
    cout <<"\nHo va ten: "<<x.ten;
    if (x.gioitinh==1) {
        cout <<"\nGioi tinh: Nam";
    } else {
        cout <<"\nGioi tinh: Nu";
    }
}

int DestQueue (STLIST &stl, NHANSU &x) {
    STNODE* p;
    if (stl.phead!=NULL) {
        x=stl.phead->data;
        p=stl.phead;
        stl.phead=stl.phead->pnext;
        if (stl.phead==NULL) {
            stl.ptail=NULL;
        }
        delete p;
        return 1;
    }
    return 0;
}

void ChuyenChuoiSangInHoa (string &x) {
    int n=x.length();
    for (int i=0; i<n; i++) {
        if (x[i]>='a'&&x[i]<='z') {
            x[i]-=32;
        }
    }
}

bool Palindromes (string x) {  //Palindromes
    ChuyenChuoiSangInHoa(x);
    CLIST queue;
    CreateCList(queue);
    int n=x.length();
    for (int i=0; i<n; i++) {
        EnQueue (queue,CreateCNode(x[i]));
    }
    for (int i=n-1; i>=0; i--) {
        char c;
        DeQueue(queue,c);
        if (c!=x[i]) {
            return false;
        }
    }
    return true;
}

int isEmpty (STLIST stl) {
    if (stl.phead==NULL) {
        return 1;
    }
    return 0;
}

char GetTen (string x) {
    int n=x.length();
    int j;
    for (int i=n-1; i>=0; i--) {
        if (x[i]==' ') {
            j=i+1;
            break;
        }
    }
    return x[j];
}

void Demerging (STLIST stl) {  //Demerging (t??? ch???c c???u tr??c qu???n l?? nh??n s??? gi???ng trong slide): s???p x???p gi???i t??nh Nu - Nam v?? h??? t??n
    STLIST NU,NAM;
    CreateSTList(NU);
    CreateSTList(NAM);
    for (STNODE* k=stl.phead; k!=NULL; k=k->pnext) {
        if (k->data.gioitinh==0) {
            EnstQueue(NU,CreateSTNode(k->data));
        } else {
            EnstQueue(NAM,CreateSTNode(k->data));
        }
    }
    for (STNODE* i=NU.phead; i!=NU.ptail; i=i->pnext) {
        for (STNODE* j=i->pnext; j!=NULL; j=j->pnext) {
            if (GetTen(i->data.ten)>GetTen(j->data.ten)) {
                NHANSU t;
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
    for (STNODE* i=NAM.phead; i!=NAM.ptail; i=i->pnext) {
        for (STNODE* j=i->pnext; j!=NULL; j=j->pnext) {
            if (GetTen(i->data.ten)>GetTen(j->data.ten)) {
                NHANSU t;
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
    int dem=1;
    int dem1=1;
    cout <<"\n=====DANH SACH NHAN SU NU HO TEN TANG DAN THEO ALPHABET=====\n";
    while (NU.phead!=NULL) {
        NHANSU b;
        DestQueue(NU,b);
        cout <<"\n\t\tTHONG TIN NHAN SU THU "<<dem;
        XuatNhanSu(b);
        dem++;
    }
    cout <<"\n=====DANH SACH NHAN SU NAM HO TEN TANG DAN THEO ALPHABET=====\n";
    while (NAM.phead!=NULL) {
        NHANSU b;
        DestQueue(NAM,b);
        cout <<"\n\t\tTHONG TIN NHAN SU THU "<<dem1;
        XuatNhanSu(b);
        dem1++;
    }
}

int main () {
    string a="Able was I ere I saw Elba";
    if (Palindromes(a)) {
        cout <<"\nChuoi tren la chuoi Palindrome";
    } else {
        cout <<"\nChuoi tren khong la chuoi Palindrome";
    }
    STLIST l;
    int n;
    cout <<"\nNhap so nhan su: ";
    cin>>n;
    CreateSTList(l);
    for (int i=0; i<n; i++) {
        cout <<"\n\t\t=====NHAP NHAN SU THU "<<i+1<<"=====\n";
        NHANSU a;
        NhapNhanSu(a);
        EnstQueue(l,CreateSTNode(a));
    }
    Demerging (l);
    system("pause");
    system("cls");
    return 0;
}