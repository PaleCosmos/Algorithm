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
#include <stdio.h>
#define uint unsigned int
#define max(x, y) ((x) < (y) ? (y) : (x))

int main()
{
    int N;
    uint **arr, *l, v;

    scanf("%d", &N);

    arr = new uint *[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new uint[2];
        l = arr[i];

        scanf("%u", &v);

        if (i > 1)
        {
            l[0] = v + arr[i - 1][1];
            l[1] = v + max(arr[i - 2][0], arr[i - 2][1]);
        }
        else if (i == 1)
        {
            l[0] = v + arr[i - 1][0];
            l[1] = v;
        }
        else
        {
            l[0] = v;
            l[1] = 0;
        }
    }

    printf("%u\n", max(arr[N - 1][0], arr[N - 1][1]));

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
