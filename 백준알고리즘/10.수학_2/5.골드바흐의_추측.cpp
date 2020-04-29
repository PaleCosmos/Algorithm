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
    scanf("%d", &n);
    for (int k = 0, i = scanf("%d", &m); k < n; scanf("%d", &m), k++)
    {
        arr = new bool[m];

        for (i = 0; i < m; i++)
            arr[i] = false;

        for (i = 1; i <= sqrt(m); i++)
        {
            if (i ^ 1 && isPrime(i))
            {
                for (g = 2 * i; g < m; g += i)
                {
                    arr[g - 1] = true;
                }
            }
            else
            {
                arr[i - 1] = true;
            }
        }
        for (i = m / 2; i >= 2; i--)
        {
            if (!arr[i - 1] && !arr[m - i - 1])
                break;
        }
        printf("%d %d\n", i, m - i);

        delete[] arr;
    }

    return 0;
}