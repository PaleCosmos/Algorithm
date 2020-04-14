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

int main()
{
    int N, i, j, v;

    do
    {
        cout << "100 이하의 자연수를 입력해주십시오." << endl;
        cin >> N;
        v = 2 * N - 1;
    } while (N < 1 || N > 100);

    for (i = N; i > 0; i--)
    {
        for (j = 0; j < (v - (2 * i - 1)) / 2; j++)
        {
            cout << " ";
        }
        for (j = 0; j < (2 * i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = 2; i <= N; i++)
    {
        for (j = 0; j < (v - (2 * i - 1)) / 2; j++)
        {
            cout << " ";
        }
        for (j = 0; j < (2 * i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}