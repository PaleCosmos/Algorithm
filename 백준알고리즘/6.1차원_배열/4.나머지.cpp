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

//입출력 시간 단축을 위해 C의 입출력 함수를 사용했다.
int main()
{
    int length, i, max = 0;
    double avg = 0.0;
    int *arr;

    scanf("%d", &length);

    arr = new int[length];

    for (i = 0; i < length; i++)
    {
        scanf("%d", arr + i);
        if (arr[i] > max)
            max = arr[i];
    }

    for (i = 0; i < length; i++)
    {
        avg += ((double)arr[i] * 100) / (length * max);
    }

    printf("%lf\n", avg);

    delete[] arr;

    return 0;
}