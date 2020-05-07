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
#include <cmath>
#define size 4000
#define sizeOfArray 8001

int main()
{
    int N, i = 0, sum = 0, max = -size, min = size, v = 0, l = size + 1;

    scanf("%d", &N);
    int *arr = new int[N];
    int tmp[sizeOfArray] = {
        0,
    };

    for (; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    std::sort(arr, arr + N);

    for (i = 0; i < N; i++)
    {
        sum += arr[i];
        tmp[arr[i] + size]++;

        if (arr[i] >= max)
            max = arr[i];
        if (arr[i] <= min)
            min = arr[i];
    }
    printf("%d\n", (int)round((double)sum / N));
    printf("%d\n", arr[N >> 1]);
    sum = 0;
    for (i = 0; i < sizeOfArray; i++)
    {
        if (tmp[i] > v)
        {
            v = tmp[i];
        }
    }

    for (i = 0; i < N; i++)
    {
        if (tmp[arr[i] + size] == v && l != arr[i])
        {
            l = arr[i];
            sum++;
        }

        if (sum == 2)
            break;
    }

    printf("%d\n", l);
    printf("%d\n", max - min);

    delete[] arr;

    return 0;
}