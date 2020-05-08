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
#include <algorithm>

struct point
{
    int x, y;
};

bool sort(point &a, point &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main()
{
    int N, i = 0;
    point *arr;

    scanf("%d", &N);

    arr = new point[N];

    for (; i < N; i++)
    {
        scanf("%d%d", &arr[i].x, &arr[i].y);
    }

    std::sort(arr, arr + N, sort);

    for (i = 0; i < N; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    delete[] arr;

    return 0;
}