#pragma region LICENSE
//    Copyright 2020 PaleCosmos
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
#pragma endregion
#include <iostream>

using namespace std;

int recursive(int **arr, int k, int n)
{
    if (k == 0 || n == 1)
    {
        return n;
    }

    if (!arr[k][n])
    {
        for (int i = 1; i <= n; i++)
        {
            arr[k][n] += recursive(arr, k - 1, i);
        }
    }

    return arr[k][n];
}

int main()
{
    int T, k, n, j;
    int **arr;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> k >> n;

        arr = new int *[k + 1];

        for (j = 0; j <= k; j++)
        {
            arr[j] = new int[n + 1];
            fill_n(arr[j], n + 1, 0);
        }

        cout << recursive(arr, k, n) << endl;

        for (int g = 0; g < j; g++)
        {
            delete[] arr[g];
        }
        delete[] arr;
    }

    return 0;
}