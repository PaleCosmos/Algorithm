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

// O(n^2)로 풀기
int main()
{
    int N, i = 0, j = 0, t;
    int *arr;

    scanf("%d", &N);
    arr = new int[N];

    for (; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    delete[] arr;

    return 0;
}