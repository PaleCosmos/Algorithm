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
#pragma endregion3
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int A, B, C;

    do
    {
        cout << "첫 번째 좌표를 입력해 주십시오.";
        cin >> A;
        if (A > 1000 || A < -1000 || A == 0)
            continue;
        cout << "두 번째 좌표를 입력해 주십시오.";
        cin >> B;
    } while (B < -1000 || B > 1000 || B == 0);

    if (A > 0 && B > 0)
        C = 1;
    else if (A < 0 && B > 0)
        C = 2;
    else if (A < 0 && B < 0)
        C = 3;
    else
        C = 4;

    cout << C << endl;

    return 0;
}