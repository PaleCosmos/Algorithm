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

int find()
{
    int x1, y1, r1, x2, y2, r2;
    double dist;

    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    x1 = r1 + r2;
    x2 = abs((double)r1 - r2);

    if (dist == 0 && r1 == r2)
        return -1;
    else if (dist > x1)
        return 0;
    else if (dist == x1)
        return 1;
    else if (dist < x2)
        return 0;
    else if (dist == x2)
        return 1;
    else
        return 2;

    return 0;
}

int main()
{
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", find());
    }

    return 0;
}