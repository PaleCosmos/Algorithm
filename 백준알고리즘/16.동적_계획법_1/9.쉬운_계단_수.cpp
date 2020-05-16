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
#define uint unsigned long long
#define mv 1000000000

int main()
{
    uint pr[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int i, N;
    uint **arr, sum = 0;

    scanf("%d", &N);

    arr = new uint *[N];

    for (i = 1; i < N; i++)
    {
        arr[i] = new uint[10];
    }

    arr[0] = pr;

    for (i = 0; i < N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (i)
            {
                arr[i][j] = ((j > 0 ? arr[i - 1][j - 1] : 0) + (j < 9 ? arr[i - 1][j + 1] : 0)) % mv;
            }

            if (i == N - 1)
            {
                sum += arr[i][j];
                sum %= mv;
            }
        }
    }

    printf("%llu\n", sum);

    for (i = 1; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
