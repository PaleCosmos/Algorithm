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

char **c;

void parse(int n, int row, int col, bool t)
{
    if (n == 1)
    {
        c[row][col] = t ? '*' : ' ';
        return;
    }

    int div = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            parse(n / 3, row + div * i, col + div * j, t && (i != 1 || j != 1));
        }
    }
}

int main()
{
    int i, N;

    scanf("%d", &N);

    c = new char *[N];

    for (i = 0; i < N; i++)
        c[i] = new char[N];

    parse(N, 0, 0, true);

    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < N; k++)
        {
            printf("%c", c[j][k]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++)
        delete[] c[i];

    delete[] c;
    return 0;
}