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
    int N, i, j;
    char *co = new char[2];
    co[0] = '*';
    co[1] = ' ';

    do
    {
        cout << "100 이하의 자연수를 입력해주십시오." << endl;
        cin >> N;
    } while (N < 1 || N > 100);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << co[j % 2];
        }
        cout << endl;
        for (j = 0; j < N; j++)
        {
            cout << co[(j + 1) % 2];
        }
        cout << endl;
    }

    delete[] co;

    return 0;
}