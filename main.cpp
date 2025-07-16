#include <iostream>
#include <vector>
using namespace std;

int get_element(const int v[], int idx)
{
    return v[idx];
}
// 配列の要素商を求める
int *element_wise_quotient(int *a, int *b)
{
    int *ans = new int[sizeof(a)];
    // aの要素数よりbの要素数が少ないとインデックス超過
    for (size_t i = 0; i < sizeof(a); i++)
    {
        ans[i] = a[i] / b[i];
    }
    return ans;
}

int main()
{
    int data[6];
    int data_small[4];

    for (int i = 0; i < sizeof(data); i++)
    {
        data[i] = i; // 配列の要素:0,1,2,...,5
    }
    for (int i = 0; i < sizeof(data_small); i++)
    {
        data_small[i] = (sizeof(data_small) - i); // ベクトルの要素:6,5,...,3
    }

    int a = data[0];
    int b = data[1];
    cout << "b/a= " << b / a << endl;
    data[0] = 6 / 0;

    int idx = sizeof(data) + 3;
    cout << "Out of range element: " << get_element(data, idx) << endl;
    cout << "Out of range element: " << data[9] << endl;

    cout << "element wise quotient: " << element_wise_quotient(data, data_small) << endl;
    cout << "element wise quotient: " << data[5] / data_small[5] << endl;

    return 0;
}
