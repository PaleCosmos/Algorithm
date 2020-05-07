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
    char str[11];
    int i, len = 10;
    char tmp;
    int arr[10] = {
        0,
    };

    scanf("%s", str);

    for (i = 0; i < len; i++)
    {
        tmp = str[i];
        if (tmp >= '0' && tmp <= '9')
        {
            arr[tmp - '0']++;
        }
    }

    for (i = 9; i >= 0; i--)
    {
        for (len = 0; len < arr[i]; len++)
        {
            printf("%d", i);
        }
    }

    return 0;
}