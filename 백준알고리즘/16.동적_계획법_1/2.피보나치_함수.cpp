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
    int N, t, l = 1;
    int c[41] = {
        1,
        0,
    };

    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", &t);

        if (l <= t)
        {
            for (int i = l + 1; i <= t + 1; i++)
            {
                c[i] = c[i - 1] + c[i - 2];
            }

            l = t + 1;
        }

        printf("%d %d\n", c[t], c[t + 1]);
    }

    return 0;
}
