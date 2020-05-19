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
#define max(v) (v[0] > v[1] ? (v[0] > v[2] ? v[0] : v[2]) : (v[1] > v[2] ? v[1] : v[2]))
#define md(x) ((x) + 1) % 3

// 슬라이딩윈도우
int main()
{
    int N, i;
    int t = 2, y = 1, z = 0;
    uint arr[3][3] = {
        0,
    };

    scanf("%u", &N);

    for (i = 0; i != N; i++)
    {
        scanf("%u", &arr[t][0]);

        if (i)
        {
            arr[t][1] = arr[t][0] + max(arr[z]);
            arr[t][0] += arr[y][1];
        }
        else
        {
            arr[t][1] = arr[t][0];
        }

        arr[t][2] = max(arr[y]);

        t = md(t);
        y = md(y);
        z = md(z);
    }

    printf("%u\n", max(arr[y]));

    return 0;
}
