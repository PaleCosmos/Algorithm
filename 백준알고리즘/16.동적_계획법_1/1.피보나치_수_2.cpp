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

long arr[91] = {
    0,
    1,
    0,
};

long fibo(int a)
{
    if (a == 0 || a == 1)
        return arr[a];

    arr[a - 1] = arr[a - 1] ? arr[a - 1] : fibo(a - 1);
    arr[a - 2] = arr[a - 2] ? arr[a - 2] : fibo(a - 2);

    return arr[a - 1] + arr[a - 2];
}

int main()
{
    int N;

    scanf("%d", &N);

    printf("%ld\n", fibo(N));

    return 0;
}
