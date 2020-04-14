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
    int *n = new int[3];
    int tm;

    cout << "세 정수를 입력해 주십시오." << endl;

    cin >> n[0] >> n[1] >> n[2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (n[j] > n[j + 1])
            {
                tm = n[j];
                n[j] = n[j + 1];
                n[j + 1] = tm;
            }
        }
    }

    cout << n[1] << endl;

    delete[] n;

    return 0;
}