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
#define uint unsigned int
#define min(x, y) ((x) > (y) ? (y) : (x))

int main()
{
    int N;
    uint **arr, *t;

    scanf("%d", &N);

    arr = new uint *[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new uint[3];
        t = arr[i];
        scanf("%u %u %u", t, t + 1, t + 2);

        if (i)
        {
            t = arr[i - 1];
            arr[i][0] += min(t[1], t[2]);
            arr[i][1] += min(t[2], t[0]);
            arr[i][2] += min(t[0], t[1]);
        }
    }

    t = arr[N - 1];

    printf("%u\n", min(min(t[0], t[1]), t[2]));

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
