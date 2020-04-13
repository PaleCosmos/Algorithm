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
    int A, B, N;

    do
    {
        cout << "테스트 케이스의 수를 입력해주십시오." << endl;
        cin >> N;
    } while (N < 1);

    for (int i = 1; i <= N; i++)
    {
        cout << i << "번째 케이스" << endl;
        cin >> A >> B;

        if (A <= 0 || A >= 10 || B <= 0 || B >= 10)
        {
            i--;
            continue;
        }
        cout << (A + B) << endl;
    }

    return 0;
}