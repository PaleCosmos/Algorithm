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

unsigned long long arr[100] = {
    1,
    1,
    1,
};

int main()
{
    int N, max = 3;
    int t;

    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", &t);

        if (t > max)
        {
            for (int i = max; i < t; i++)
            {
                arr[i] = arr[i - 2] + arr[i - 3];
            }

            max = t;
        }

        printf("%llu\n", arr[t - 1]);
    }

    return 0;
}
