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
#include <cstring>
#define endl '\n'
#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    int len1, len2, **arr, j, i = 0, m = 0;

    cin >> str1 >> str2;
    len1 = str1.length() + 1;
    len2 = str2.length() + 1;

    arr = new int *[len1];

    for (; i < len1; i++)
    {
        arr[i] = new int[len2];
        memset(arr[i], 0, len2);

        if (i)
        {
            for (j = 1; j < len2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                    m = m < arr[i][j] ? arr[i][j] : m;
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
    }

    cout << m << endl;

    for (i = 0; i < len1; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}