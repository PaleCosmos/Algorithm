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
    int N, M, v = 0, i = 666;

    scanf("%d", &N);

    do
    {
        M = i;

        while (M)
        {
            if (M % 1000 == 666)
            {
                v++;
                break;
            }

            M /= 10;
        }

        i++;
    } while (v != N);

    printf("%d\n", i - 1);

    return 0;
}