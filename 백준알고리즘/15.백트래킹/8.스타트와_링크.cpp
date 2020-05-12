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

int N, *A, *B, half;
bool *checker, sc = true;
int df = __INT_MAX__;
int **arr;

void backTracking(int f)
{
    int i, j;
    int *cA = A;

    if (f == half)
    {
        int **cach = arr;
        int *cB = B;
        int pA = 0, pB = 0;

        for (i = 0; i < N; i++)
        {
            if (!checker[i])
            {
                B[pB] = i;
                pB++;
            }
        }

        pB = 0;

        for (i = 0; i < half - 1; i++)
        {
            for (j = i + 1; j < half; j++)
            {
                pA += cach[cA[i]][cA[j]] + cach[cA[j]][cA[i]];
                pB += cach[cB[i]][cB[j]] + cach[cB[j]][cB[i]];
            }
        }

        int df_ = pA > pB ? pA - pB : pB - pA;

        if (df > df_)
            df = df_;

        if (df == 0)
            sc = false;
    }
    else
    {
        int A_ = cA[f];

        bool *ch = checker;

        for (i = !f ? 0 : cA[f - 1]; sc && i < N; i++)
        {
            if (!ch[i])
            {
                cA[f] = i;
                ch[i] = true;
                backTracking(f + 1);
                ch[i] = false;
            }
        }

        cA[f] = A_;
    }
}

int main()
{
    int i, j;

    scanf("%d", &N);
    half = N >> 1;
    arr = new int *[N];
    A = new int[half];
    B = new int[half];
    checker = new bool[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = new int[N];
        checker[i] = 0;
        for (j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    backTracking(0);

    printf("%d", df);

    for (i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
    delete[] A;
    delete[] B;
    delete[] checker;

    return 0;
}
