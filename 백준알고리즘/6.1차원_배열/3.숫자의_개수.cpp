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
#include <math.h>

//입출력 시간 단축을 위해 C의 입출력 함수를 사용했다.
int main()
{
    int i, temp, N = 1;
    int *arr = new int[10];

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        N *= temp;
    }

    temp = 1;

    while (N >= temp)
    {
        arr[(N / temp) % 10]++;
        temp *= 10;
    }

    for (i = 0; i <= 9; i++)
    {
        printf("%d\n", arr[i]);
    }

    delete[] arr;

    return 0;
}