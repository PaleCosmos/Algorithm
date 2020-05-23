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
#include <algorithm>

int srt(int *a, int *b)
{
    return a[0] < b[0];
}

int main()
{
    int N, **arr, i, j, max = 1;

    scanf("%d", &N);

    arr = new int *[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new int[2];
        scanf("%d%d", arr[i], arr[i] + 1);
    }

    std::sort(arr, arr + N, srt);

    for (i = 0; i != N; i++)
    {
        arr[i][0] = 1;
        for (j = 0; j != i; j++)
        {
            if (arr[i][1] > arr[j][1])
            {
                if (arr[i][0] <= arr[j][0])
                {
                    arr[i][0] = arr[j][0] + 1;
                    if (max < arr[i][0])
                        max = arr[i][0];
                }
            }
        }
    }

    printf("%d\n", N - max);

    for (i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}