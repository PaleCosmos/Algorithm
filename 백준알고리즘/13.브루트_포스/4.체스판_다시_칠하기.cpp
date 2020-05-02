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
    bool **a, flag;
    char v[51];
    int N, M, i, j, x, y, r1, r2, t = 70;

    scanf("%d%d", &N, &M);

    a = new bool *[N];

    for (i = 0; i < N; i++)
    {
        a[i] = new bool[M];
        scanf("%s", v);
        for (j = 0; j < M; j++)
        {
            a[i][j] = v[j] == 'W';
        }
    }

    for (i = 0; i <= N - 8; i++)
    {
        for (j = 0; j <= M - 8; j++)
        {
            r1 = r2 = 0;
            flag = !a[i][j];
            for (x = i; x < i + 8; x++)
            {
                for (y = j; y < j + 8; y++)
                {
                    flag ^ a[x][y] ? r2++ : r1++;
                    flag = y != j + 7 ? !flag : flag;
                }
            }
            r1 = r1 > r2 ? r2 : r1;
            t = t > r1 ? r1 : t;
        }
    }

    printf("%d\n", t);

    for (i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}