#include <iostream>
using namespace std;

int Search (int n, int a[], int x) {
    for (int i=0; i<n; i++) {
        if (a[i]==x) {
            return 1;
            break;
        }
    }
    return 0;
}

int SearchViTri (int n, int a[], int x) {
    for (int i=0; i<n; i++) {
        if (a[i]==x) {
            return i;
            break;
        }
    }
    return -1;
}

int SearchAllViTri (int n, int a[], int x, int b[], int &m) {
    int j=0;
    int dem=0;
    for (int i=0; i<n; i++) {
        if (a[i]==x) {
            b[j]=i;
            j++;
            dem++;
            m++;
        }
    }
    if (dem==0) {
        return 0;
    }
    return 1;
}

int main () {
    int n;
    int m=0;
    n=9;
    int a[9]={2,2,5,3,0,6,8,5,1};
    int b[9];
    int x;
    cout <<"\nNhap x: ";
    cin>>x;
    if (Search(n,a,x)) {
        cout <<"\nx co trong mang";
    } else {
        cout <<"\nx khong co trong mang";
    }
    if (SearchViTri(n,a,x)==-1) {
        cout <<"\nx khong co trong mang";
    } else {
        cout <<"\nx nam o vi tri thu "<<SearchViTri(n,a,x);
    }
    if (SearchAllViTri(n,a,x,b,m)==0) {
        cout <<"\nx khong co trong mang";
    } else {
        cout <<"\nx nam o vi tri thu ";
        for (int i=0; i<m; i++) {
            cout <<b[i]<<" ";
        }
    }
    system("pause");
    system("cls");
    return 0;
}