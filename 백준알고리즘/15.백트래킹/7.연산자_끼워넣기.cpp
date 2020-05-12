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

int N, *arr, plus, minus, multiply, division;
int value;
int max = -1000000000;
int min = 1000000000;

int shorter(int, int, int &);

void backTracking(int f)
{
    int tmp = value;

    if (f == N)
    {
        if (tmp > max)
            max = tmp;
        if (tmp < min)
            min = tmp;
    }
    else
    {
        int af = arr[f];

        if (plus)
        {
            plus--;
            value += af;
            value = shorter(f, tmp, plus);
        }

        if (minus)
        {
            minus--;
            value -= af;
            value = shorter(f, tmp, minus);
        }

        if (multiply)
        {
            multiply--;
            value *= af;
            value = shorter(f, tmp, multiply);
        }

        if (division)
        {
            division--;
            value /= af;
            value = shorter(f, tmp, division);
        }
    }
}

int shorter(int f, int tmp, int &oper)
{
    backTracking(f + 1);
    oper++;
    return tmp;
}

int main()
{
    int i;

    scanf("%d", &N);

    arr = new int[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    scanf("%d %d %d %d", &plus, &minus, &multiply, &division);

    value = arr[0];
    backTracking(1);

    printf("%d\n%d\n", max, min);

    delete[] arr;

    return 0;
}
