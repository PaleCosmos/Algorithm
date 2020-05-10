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
#include <stdlib.h>
#define fl(x) 3 * (int)(x / 3)

int N, count = 0;
int bt[9][9];
int bt2[81][2];

bool isValid(int floor)
{
    int *f = bt2[floor];
    int i, j;
    int sr = fl(f[0]);
    int sc = fl(f[1]);

    for (i = 0; i < 9; i++)
    {
        if ((bt[i][f[1]] == bt[f[0]][f[1]] && i != f[0]) || (bt[f[0]][i] == bt[f[0]][f[1]] && i != f[1]))
        {
            return false;
        }

        if (i >= sr && i < sr + 3)
        {
            for (j = sc; j < sc + 3; j++)
            {
                if (bt[i][j] == bt[f[0]][f[1]] && i != f[0] && j != f[1])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void backTracking(int floor)
{
    int i, j;

    if (floor == count)
    {
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                printf("%d ", bt[i][j]);
            }
            printf("\n");
        }

        exit(0);
    }
    else
    {
        int *f = bt2[floor];

        for (i = 1; i <= 9; i++)
        {
            bt[f[0]][f[1]] = i;

            if (isValid(floor))
            {
                backTracking(floor + 1);
            }
        }

        bt[f[0]][f[1]] = 0;
    }
}

int main()
{
    int j, i = 0;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &bt[i][j]);
            if (!bt[i][j])
            {
                bt2[count][0] = i;
                bt2[count++][1] = j;
            }
        }
    }

    backTracking(0);

    return 0;
}