#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* pleft;
    struct Node* pright;
};
typedef struct Node NODE;
typedef NODE* TREE;

void CreateTree (TREE &t)
{
    t = NULL;
}

NODE* CreateNode (int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->pleft = p->pright = NULL;
    return p;
}

int AddNode (TREE &t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            return 0;
        }
        if (x < t->data)
        {
            return AddNode (t->pleft,x);
        }
        else 
        {
            return AddNode (t->pright,x);
        }
    }
    t = CreateNode (x);
    return 1;
}

void AutoInputTree (TREE &t, int n)
{
    srand(time(0));
    for (int i = 0 ; i < n ; i++)
    {
        int x;
        x = rand () % 31;
        AddNode (t,x);
    }
}

void XuatSoChan (TREE t)
{
    if (t != NULL)
    {
        XuatSoChan (t->pleft);
        if (t->data % 2 == 0)
        {
            cout << t->data << "\t";
        }
        XuatSoChan (t->pright);
    }
}

void DemSoChan (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoChan (t->pleft, dem);
        if (t->data % 2 == 0)
        {
            dem++;
        }
        DemSoChan (t->pright, dem);
    }
}

void TongSoChan (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongSoChan (t->pleft, sum);
        if (t->data % 2 == 0)
        {
            sum += t->data;
        }
        TongSoChan (t->pright, sum);
    }
}

void XuatSoLe (TREE t)
{
    if (t != NULL)
    {
        XuatSoLe (t->pleft);
        if (t->data % 2 != 0)
        {
            cout << t->data << "\t";
        }
        XuatSoLe (t->pright);
    }
}

void DemSoLe (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoLe (t->pleft, dem);
        if (t->data % 2 != 0)
        {
            dem++;
        }
        DemSoLe (t->pright, dem);
    }
}

void TongSoLe (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongSoLe (t->pleft, sum);
        if (t->data % 2 != 0)
        {
            sum += t->data;
        }
        TongSoLe (t->pright, sum);
    }
}

bool KTSNT (int x)
{
    if (x < 2)
    {
        return false;
    }
    for (int i = 2 ; i <= sqrt (x) ; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void XuatSoNguyenTo (TREE t)
{
    if (t != NULL)
    {
        XuatSoNguyenTo (t->pleft);
        if (KTSNT(t->data))
        {
            cout << t->data << "\t";
        }
        XuatSoNguyenTo (t->pright);
    }
}

void DemSoNguyenTo (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoNguyenTo (t->pleft, dem);
        if (KTSNT(t->data))
        {
            dem++;
        }
        DemSoNguyenTo (t->pright, dem);
    }
}

void TongSoNguyenTo (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongSoNguyenTo (t->pleft, sum);
        if (KTSNT(t->data))
        {
            sum += t->data;
        }
        TongSoNguyenTo (t->pright, sum);
    }
}

bool KTSDX (int x)
{
    int sum = 0;
    int t = x;
    int r;
    while (x != 0)
    {
        r = x % 10;
        sum = sum * 10 + r;
        x = x / 10;
    }
    if (t == sum)
    {
        return true;
    }
    return false;
}

void XuatSoDoiXung (TREE t)
{
    if (t != NULL)
    {
        XuatSoDoiXung (t->pleft);
        if (KTSDX(t->data))
        {
            cout << t->data << "\t";
        }
        XuatSoDoiXung (t->pright);
    }
}

void DemSoDoiXung (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoDoiXung (t->pleft, dem);
        if (KTSDX(t->data))
        {
            dem++;
        }
        DemSoDoiXung (t->pright, dem);
    }
}

void TongSoDoiXung (TREE t, int &sum)
{
    if (t != NULL)
    {
        DemSoDoiXung (t->pleft, sum);
        if (KTSDX(t->data))
        {
            sum += t->data;
        }
        DemSoDoiXung (t->pright, sum);
    }
}

bool KTST (int x)
{
    int t = x % 10;
    x = x / 10;
    while (x != 0)
    {
        int r = x % 10;
        if (t < r)
        {
            return false;
        }
        t = r;
        x = x / 10;
    }
    return true;
}

void XuatSoTang (TREE t)
{
    if (t != NULL)
    {
        XuatSoTang (t->pleft);
        if (KTST(t->data))
        {
            cout << t->data << "\t";
        }
        XuatSoTang (t->pright);
    }
}

void DemSoTang (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoTang (t->pleft, dem);
        if (KTST(t->data))
        {
            dem++;
        }
        DemSoTang (t->pright, dem);
    }
}

void TongSoTang (TREE t, int &sum)
{
    if (t != NULL)
    {
        DemSoTang (t->pleft, sum);
        if (KTST(t->data))
        {
            sum += t->data;
        }
        DemSoTang (t->pright, sum);
    }
}

bool KTSG (int x)
{
    int t = x % 10;
    x = x / 10;
    while (x != 0)
    {
        int r = x % 10;
        if (t > r)
        {
            return false;
        }
        t = r;
        x = x / 10;
    }
    return true;
}

void XuatSoGiam (TREE t)
{
    if (t != NULL)
    {
        XuatSoGiam (t->pleft);
        if (KTSG(t->data))
        {
            cout << t->data << "\t";
        }
        XuatSoGiam (t->pright);
    }
}

void DemSoGiam (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoGiam (t->pleft, dem);
        if (KTSG(t->data))
        {
            dem++;
        }
        DemSoGiam (t->pright, dem);
    }
}

void TongSoGiam (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongSoGiam (t->pleft, sum);
        if (KTSG(t->data))
        {
            sum += t->data;
        }
        TongSoGiam (t->pright, sum);
    }
}

int Count (int n)
{
    int dem = 0;
    while (n != 0)
    {
        n /= 10;
        ++dem;
    }
    return dem;
}

bool KTSArmstrong (int x)
{
    int sum = 0;
    int t = x;
    int n = Count (x);
    while (x != 0)
    {
        int t = x % 10;
        sum += pow (t,n);
        x /= 10;
    }
    if (sum == t)
    {
        return true;
    }
    return false;
}

void XuatSoArmstrong (TREE t)
{
    if (t != NULL)
    {
        XuatSoArmstrong (t->pleft);
        if (KTSArmstrong(t->data))
        {
            cout << t->data << "\t";
        }
        XuatSoArmstrong (t->pright);
    }
}

void DemSoArmstrong (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemSoArmstrong (t->pleft, dem);
        if (KTSArmstrong(t->data))
        {
            dem++;
        }
        DemSoArmstrong (t->pright, dem);
    }
}

void TongSoArmstrong (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongSoArmstrong (t->pleft, sum);
        if (KTSArmstrong(t->data))
        {
            sum += t->data;
        }
        TongSoArmstrong (t->pright, sum);
    }
}

void XuatNodeCo1ConTrai (TREE t)
{
    if (t != NULL)
    {
        XuatNodeCo1ConTrai (t->pleft);
        if (t->pleft != NULL && t->pright == NULL)
        {
            cout << t->data << "\t";
        }
        XuatNodeCo1ConTrai (t->pright);
    }
}

void DemNodeCo1ConTrai (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemNodeCo1ConTrai (t->pleft, dem);
        if (t->pleft != NULL && t->pright == NULL)
        {
            dem++;
        }
        DemNodeCo1ConTrai (t->pright, dem);
    }
}

void TongNodeCo1ConTrai (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongNodeCo1ConTrai (t->pleft, sum);
        if (t->pleft != NULL && t->pright == NULL)
        {
            sum += t->data;
        }
        TongNodeCo1ConTrai (t->pright, sum);
    }
}

void XuatNodeCo1ConPhai (TREE t)
{
    if (t != NULL)
    {
        XuatNodeCo1ConPhai (t->pleft);
        if (t->pleft == NULL && t->pright != NULL)
        {
            cout << t->data << "\t";
        }
        XuatNodeCo1ConPhai (t->pright);
    }
}

void DemNodeCo1ConPhai (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemNodeCo1ConPhai (t->pleft, dem);
        if (t->pleft == NULL && t->pright != NULL)
        {
            dem++;
        }
        DemNodeCo1ConPhai (t->pright, dem);
    }
}

void TongNodeCo1ConPhai (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongNodeCo1ConPhai (t->pleft, sum);
        if (t->pleft == NULL && t->pright != NULL)
        {
            sum += t->data;
        }
        TongNodeCo1ConPhai (t->pright, sum);
    }
}

void XuatNodeCo2Con (TREE t)
{
    if (t != NULL)
    {
        XuatNodeCo2Con (t->pleft);
        if (t->pleft != NULL && t->pright != NULL)
        {
            cout << t->data << "\t";
        }
        XuatNodeCo2Con (t->pright);
    }
}

void DemNodeCo2Con (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemNodeCo2Con (t->pleft, dem);
        if (t->pleft != NULL && t->pright != NULL)
        {
            dem++;
        }
        DemNodeCo2Con (t->pright, dem);
    }
}

void TongNodeCo2Con (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongNodeCo2Con (t->pleft, sum);
        if (t->pleft != NULL && t->pright != NULL)
        {
            sum += t->data;
        }
        TongNodeCo2Con (t->pright, sum);
    }
}

void XuatNodeLa (TREE t)
{
    if (t != NULL)
    {
        XuatNodeLa (t->pleft);
        if (t->pleft == NULL && t->pright == NULL)
        {
            cout << t->data << "\t";
        }
        XuatNodeLa (t->pright);
    }
}

void DemNode (TREE t, int &dem)
{
    if (t != NULL)
    {
        DemNode (t->pleft, dem);
        if (t->pleft == NULL && t->pright == NULL)
        {
            dem++;
        }
        DemNode (t->pright, dem);
    }
}

void TongNodeLa (TREE t, int &sum)
{
    if (t != NULL)
    {
        TongNodeLa (t->pleft, sum);
        if (t->pleft == NULL && t->pright == NULL)
        {
            sum += t->data;
        }
        TongNodeLa (t->pright, sum);
    }
}

void XuatNodeNamOTangK (TREE t, int k)
{
    if (t != NULL)
    {
        if (k == 0)
        {
            cout << t->data << "\t";
        }
        XuatNodeNamOTangK (t->pleft,k-1);
        XuatNodeNamOTangK (t->pright,k-1);
    }
}

void XuatNodeNamTrenTangK (TREE t, int k)
{
    if (t != NULL)
    {
        for (int i = k - 1 ; i >= 0 ; i--)
        {
            XuatNodeNamOTangK (t,i);
        }
    }
}

int ChieuCao (TREE t)
{
    if (t == NULL)
    {
        return 0;
    }
    int a = ChieuCao (t->pleft);
    int b = ChieuCao (t->pright);
    if (a > b) 
    {
        return a + 1;
    }
    else
    {
        return b + 1;
    }
}

void XuatNodeNamDuoiTangK (TREE t, int k)
{
    
    if (t != NULL)
    {
        for (int i = k + 1 ; i < ChieuCao (t); i++)
        {
            XuatNodeNamOTangK (t,i);
        }
    }
}