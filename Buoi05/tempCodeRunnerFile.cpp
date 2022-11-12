#include <iostream>
#include <string.h>
using namespace std;

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

void CreateSTList (STLIST &stl) {
    stl.phead=stl.ptail=NULL;
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

void EnstQueue (STLIST &stl, STNODE* p) {
    if (stl.phead==NULL) {
        stl.phead=stl.ptail=p;
    } else {
        stl.ptail->pnext=p;
        stl.ptail=p;
    }
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

int isEmpty (STLIST stl) {
    if (stl.phead==NULL) {
        return 1;
    }
    return 0;
}

char GetTen (string x) { //Lấy kí tự đầu tiên của tên
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

void Demerging (STLIST stl) {  //Demerging (tổ chức cấu trúc quản lý nhân sự giống trong slide): sắp xếp giới tính Nu - Nam và họ tên
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
            if (GetTen(i->data.ten)>GetTen(j->data.ten)) { //Sắp xếp nhân sự, tên tăng dần theo alphabet
                NHANSU t;
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
    for (STNODE* i=NAM.phead; i!=NAM.ptail; i=i->pnext) {
        for (STNODE* j=i->pnext; j!=NULL; j=j->pnext) {
            if (GetTen(i->data.ten)>GetTen(j->data.ten)) { //Sắp xếp nhân sự, tên tăng dần theo alphabet
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