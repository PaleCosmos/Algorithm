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
#define size 10000

int arr[size] = {
    0,
};

// 카운팅정렬 이용
int main()
{
    int N, j, i = 0;

    scanf("%d", &N);

    for (; i < N; i++)
    {
        scanf("%d", &j);
        arr[j - 1]++;
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}