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
#include <math.h>

using namespace std;

int main()
{
    int N, s, tmp, i, j;
    int *arr;
    double avg;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        avg = 0.0;
        scanf("%d", &s);
        arr = new int[s];

        for (j = 0; j < s; j++)
        {
            scanf("%d", arr + j);
            avg += (double)arr[j];
        }

        avg /= s;

        tmp = 0;

        for (; j >= 0; j--)
        {
            if (arr[j] > avg)
            {
                tmp++;
            }
        }

        printf("%.3f%%\n", ((double)tmp / s) * 100);

        delete[] arr;
    }

    return 0;
}