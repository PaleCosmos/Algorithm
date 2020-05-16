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
#define max 0xffffffff
#define min(x, y) ((x) > (y) ? (y) : (x))

int main()
{
    int i, N;
    uint *arr, a, b, c, t;

    scanf("%d", &N);

    arr = new uint[N];
    arr[0] = 0;

    for (i = 1; i < N; i++)
    {
        t = i + 1;
        a = b = c = max;

        if (t % 3 == 0)
        {
            a = arr[t / 3 - 1];
        }

        if (t % 2 == 0)
        {
            b = arr[(t >> 1) - 1];
        }

        c = arr[i - 1];

        arr[i] = 1 + min(a, min(b, c));
    }

    printf("%d\n", arr[N - 1]);

    delete[] arr;

    return 0;
}
