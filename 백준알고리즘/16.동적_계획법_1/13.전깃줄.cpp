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
#define max(x, y) ((x) > (y) ? (x) : (y))

// 더 알아보기@@@@@@@@
// dp 방법과 lowerbound에 대해 조사
int srt(int *a, int *b)
{
    return a[0] < b[0];
}

int main()
{
    int N, i, j, **arr, result = 0;

    scanf("%d", &N);

    arr = new int *[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new int[3];
        scanf("%d%d", &arr[i][0], &arr[i][1]);
        arr[i][2] = 0;
    }

    std::sort(arr, arr + N, srt);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i][1] > arr[j][1] && arr[i][2] <= arr[j][2])
            {
                arr[i][2] = arr[j][2] + 1;
            }
        }

        result = max(result, arr[i][2]);
    }

    printf("%d\n", result);

    for (i = 0; i < N; i++)
    {
        delete arr[i];
    }

    delete[] arr;
    return 0;
}
