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
#define m(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, **arr, al, bl, max = 0;
    string A, B;

    cin >> A >> B;
    al = A.length() + 1;
    bl = B.length() + 1;

    arr = new int *[al];

    for (x = 0; x < al; x++)
    {
        arr[x] = new int[bl];
        memset(arr[x], 0, bl);

        if (x)
        {
            for (y = 1; y < bl; y++)
            {
                if (A[x - 1] == B[y - 1])
                {
                    arr[x][y] = arr[x - 1][y - 1] + 1;
                }
                else
                {
                    arr[x][y] = m(arr[x - 1][y], arr[x][y - 1]);
                }

                if (arr[x][y] > max)
                    max = arr[x][y];
            }
        }
    }

    cout << max << endl;

    return 0;
}