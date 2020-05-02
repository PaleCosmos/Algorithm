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
    int **a;
    int N, r, i, j;

    scanf("%d", &N);

    a = new int *[N];

    for (i = 0; i < N; i++)
    {
        a[i] = new int[2];
        scanf("%d%d", &a[i][0], &a[i][1]);
    }

    for (i = 0; i < N; i++)
    {
        r = 1;
        for (j = 0; j < N; j++)
        {
            if (a[j][0] > a[i][0] && a[j][1] > a[i][1])
            {
                r++;
            }
        }
        printf("%d ", r);
    }
    printf("\n");

    for (i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}