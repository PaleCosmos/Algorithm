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
#define endl '\n'
#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, *arr, i, ans, a = 0, b = 1;

    cin >> n;

    arr = new int[2];

    for (i = 0; i < n; i++)
    {
        cin >> arr[a];

        if (i)
        {
            if (arr[b] > 0)
            {
                arr[a] = max(arr[a] + arr[b], arr[a]);
            }

            if (ans < arr[a])
            {
                ans = arr[a];
            }
        }
        else
        {
            ans = arr[a];
        }

        a = b;
        b = !a;
    }

    cout << ans << endl;

    delete[] arr;

    return 0;
}