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

int max, deepth;
int bt[7];

void backTracking(int floor)
{
    if (floor == deepth)
    {
        for (int i = 0; i < deepth; i++)
        {
            printf("%d ", bt[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= max; i++)
    {
        bt[floor] = i;
        if (!floor || bt[floor - 1] < i)
        {
            backTracking(floor + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &max, &deepth);

    backTracking(0);

    return 0;
}