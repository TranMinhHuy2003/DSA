#include <iostream>
using namespace std;
#define Max 100

struct Stack {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int n=10;
};
typedef struct Stack STACK;

void CreateStack (STACK &s) {
    s.n=-1;
}

bool isEmpty (STACK s) {
    if (s.n=-1) {
        return 1;
    }
    return 0;
}

bool isFull (STACK s) {
    if (s.n>=Max) {
        return 1;
    }
    return 0;
}

bool Push(STACK &s, int x) {
    if (isFull(s) == 0) {
        s.a[++s.n] = x;
        return 1;
    }
    return 0;
}

int Pop(STACK &s, int &x) {
    if (isEmpty(s) == 0) {
        x = s.a[s.n--];
        return 1;
    }
    return 0;
}

void DaoMang (STACK &s) {
    int t=s.n;
    for (int i=t+1; i>=0; i--) {
        Push(s,s.a[i]);
    }
    for (int i=t+1; i>=0; i--) {
        
    }
    for (int i=0; i<t; i++) {
        cout <<s.a[i];
    }
}

int main () {
    STACK s;
    DaoMang(s);
    system("pause");
    system("cls");
    return 0;
}