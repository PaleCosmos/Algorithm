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

int main()
{
    int N, i, j;
    uint **arr, *p, *q, max = 0;

    scanf("%d", &N);
    arr = new uint *[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new uint[2];
        p = arr[i];
        scanf("%u", &p[0]);
        p[1] = 1;

        if (i)
        {
            for (j = 0; j < i; j++)
            {
                q = arr[j];
                if (p[0] > q[0] && p[1] <= q[1])
                    p[1]++;
            }
        }
        if (max < p[1])
            max = p[1];
    }

    printf("%u\n", max);

    for (i = 0; i < N; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}
