#include <iostream>
using namespace std;

int get_element(const int v[], size_t idx)
{
    return v[idx];
}

// 配列の要素商を求める
int *element_wise_quotient(const int *a, const int *b, size_t size)
{
    int *ans = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        if (b[i] != 0)
            ans[i] = a[i] / b[i];
        else
            ans[i] = 0; // ゼロ除算を避ける
    }
    return ans;
}

int main()
{
    const size_t data_len = 6;
    const size_t data_small_len = 4;

    int data[data_len];
    int data_small[data_small_len];

    for (size_t i = 0; i < data_len; i++)
    {
        data[i] = i; // 配列の要素:0,1,2,...,5
    }

    for (size_t i = 0; i < data_small_len; i++)
    {
        data_small[i] = static_cast<int>(data_small_len - i); // 要素:4,3,...,1
    }

    int a = data[0];
    int b = data[1];

    if (a != 0)
        cout << "b/a= " << b / a << endl;
    else
        cout << "Division by zero avoided.\n";

    // 未定義動作を回避
    data[0] = 0;

    size_t idx = data_len - 1; // 安全なインデックスに変更
    cout << "In range element: " << get_element(data, idx) << endl;

    // 範囲外アクセス削除
    // cout << "Out of range element: " << data[9] << endl;

    int *quotient = element_wise_quotient(data, data_small, data_small_len);
    cout << "element wise quotient: ";
    for (size_t i = 0; i < data_small_len; ++i)
        cout << quotient[i] << " ";
    cout << endl;

    // 範囲外アクセスを回避
    if (data_small_len > 5)
        cout << "quotient: " << data[5] / data_small[5] << endl;

    delete[] quotient;
    return 0;
}
