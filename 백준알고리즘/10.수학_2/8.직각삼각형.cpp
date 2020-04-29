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
    int a, b, c;

    for (; scanf("%d %d %d", &a, &b, &c) && a | b | c;)
    {
        a *= a;
        b *= b;
        c *= c;

        printf("%s\n", a + b == c || a + c == b || b + c == a ? "right" : "wrong");
    }

    return 0;
}