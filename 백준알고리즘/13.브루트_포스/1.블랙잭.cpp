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

int main()
{
    int N, M, i, j, k, temp, und = 0;
    int *arr;

    scanf("%d%d", &N, &M);

    arr = new int[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    for (i = 0; i < N - 2; i++)
    {
        for (k = i + 1; k < N - 1; k++)
        {
            for (j = k + 1; j < N; j++)
            {
                temp = arr[i] + arr[k] + arr[j];
                if (temp > und && temp <= M)
                {
                    und = temp;
                    if (temp == M)
                        break;
                }
            }
        }
    }

    printf("%d\n", und);

    delete[] arr;

    return 0;
}