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

using namespace std;

int reverse(int n)
{
    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;

    return 100 * c + 10 * b + a;
}

int main()
{
    int a, b;

    cin >> a >> b;

    a = reverse(a);
    b = reverse(b);

    cout << (a < b ? b : a) << endl;

    return 0;
}