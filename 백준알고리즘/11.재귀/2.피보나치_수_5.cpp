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

int *c;

int ft(int n)
{
    if (n > 1)
        c[n] = (c[n - 2] ? c[n - 2] : ft(n - 2)) + (c[n - 1] ? c[n - 1] : ft(n - 1));
    return c[n];
}

int main()
{
    int N;

    scanf("%d", &N);

    c = new int[N + 1];

    for (int i = 2; i <= N; i++)
        c[i] = 0;
    c[1] = 1;

    printf("%d\n", ft(N));

    delete[] c;

    return 0;
}