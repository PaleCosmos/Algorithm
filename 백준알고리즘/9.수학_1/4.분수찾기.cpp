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

string find(int N)
{
    int i = 1, sum = 1;

    while (sum < N)
    {
        sum += ++i;
    }

    int g = N - 1 - (i - 1) * i / 2;

    if (i % 2)
    {
        return to_string(i - g) + "/" + to_string(1 + g);
    }
    else
    {
        return to_string(1 + g) + "/" + to_string(i - g);
    }
}

int main()
{
    int N;

    cin >> N;

    cout << find(N) << endl;

    return 0;
}