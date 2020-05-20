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
#define max(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int N, i, j;
    uint **arr, *p, *q, l, maximum = 0;

    scanf("%d", &N);
    arr = new uint *[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new uint[3];
        scanf("%u", &arr[i][0]);
        arr[i][1] = 1;
        arr[i][2] = 1;
    }

    for (i = 1; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i][0] > arr[j][0])
                arr[i][1] = max(arr[i][1], arr[j][1] + 1);
        }
        for (j = N - 1; j > N - i; j--)
        {
            if (arr[N - i][0] > arr[j][0])
                arr[N - i][2] = max(arr[N - i][2], arr[j][2] + 1);
        }
    }

    for (i = 0; i < N; i++)
        maximum = max(maximum, arr[i][1] + arr[i][2]);

    printf("%u\n", maximum - 1);

    for (i = 0; i < N; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}
