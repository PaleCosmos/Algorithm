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

void move(int n, int s, int e)
{
    if (n ^ 1)
    {
        int j = 6 - s - e;
        move(n - 1, s, j);
        printf("%d %d\n", s, e);
        move(n - 1, j, e);
    }
    else
    {
        printf("%d %d\n", s, e);
    }
}

int main()
{
    int N;

    scanf("%d", &N);

    printf("%d\n", (1 << N) - 1);

    move(N, 1, 3);

    return 0;
}