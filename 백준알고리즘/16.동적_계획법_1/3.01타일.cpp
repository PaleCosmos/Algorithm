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
#define m 15746

int main()
{
    int N;
    int *arr;

    scanf("%d", &N);

    arr = new int[N];
    arr[0] = 1;
    arr[1] = 2;

    for (int i = 2; i < N; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % m;
    }

    printf("%d\n", arr[N - 1]);

    delete[] arr;

    return 0;
}
