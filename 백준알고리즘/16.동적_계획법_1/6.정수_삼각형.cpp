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
#define max(x, y) (x) < (y) ? (y) : (x)

int main()
{
    int N, i, j;
    uint **arr, *t, t1, t2, m = 0;

    scanf("%d", &N);

    arr = new uint *[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new uint[i + 1];
        t = arr[i];

        for (j = 0; j < i + 1; j++)
        {
            scanf("%u", t + j);
        }

        if (i)
        {
            t = arr[i - 1];
            for (j = 0; j < i + 1; j++)
            {
                t1 = j > 0 ? t[j - 1] : 0;
                t2 = j < i ? t[j] : 0;

                arr[i][j] += max(t1, t2);

                if (i == N - 1)
                {
                    m = (m < arr[i][j]) ? arr[i][j] : m;
                }
            }
        }
    }

    printf("%u\n", m);

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}