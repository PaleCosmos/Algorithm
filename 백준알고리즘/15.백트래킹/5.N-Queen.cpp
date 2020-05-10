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

int N, tr, fr, count = 0;
int *bt;

bool isValid(int f)
{
    tr = bt[f];

    for (int i = 0; i < f; i++)
    {
        fr = bt[i];

        if (tr == fr || ((fr > tr ? fr - tr : tr - fr) == f - i))
            return false;
    }

    return true;
}

void backTracking(int f)
{
    if (f == N)
    {
        count++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            bt[f] = i;
            if (isValid(f))
            {
                backTracking(f + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    bt = new int[N];

    backTracking(0);

    printf("%d\n", count);

    delete[] bt;

    return 0;
}