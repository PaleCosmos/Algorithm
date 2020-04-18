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
#include <iostream>
#include <cmath>

using namespace std;

int find(int a, int b, int c)
{
    if (b >= c)
        return -1;

    return 1 + floor(a / (c - b));
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << find(a, b, c) << endl;

    return 0;
}