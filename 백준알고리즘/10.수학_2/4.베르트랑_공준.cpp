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
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n & 1 && n ^ 1)
    {
        int t = (n + 1) / 2;
        for (int i = 2; i <= t; i += 2)
        {
            if (!(n % i))
            {
                return false;
            }

            if (!(i & 1))
                i--;
        }

        return true;
    }

    return n == 2;
}

int main()
{
    int n, m, i, g;
    bool *arr;

    while (scanf("%d", &n) && n)
    {
        m = 2 * n;

        arr = new bool[m - n + 1];

        for (i = 0; i <= m - n; i++)
            arr[i] = false;

        for (i = 1; i <= sqrt(m); i++)
        {
            if (i ^ 1 && isPrime(i))
            {
                for (g = 2 * i; g <= m; g += i)
                {
                    if (g >= n)
                        arr[g - n] = true;
                }
            }
            else
            {
                if (i >= n)
                    arr[i - n] = true;
            }
        }

        g = 0;
        for (i = 1; i <= m - n; i++)
        {
            g += !arr[i];
        }
        printf("%d\n", g);
        delete[] arr;
    }

    return 0;
}