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
    int A;
    string result;

    do
    {
        cout << "점수를 입력해주세요.";
        cin >> A;
    } while (A < 0 || A > 100);

    if (A <= 100 && A >= 90)
    {
        result = "A";
    }
    else if (A <= 89 && A >= 80)
    {
        result = "B";
    }
    else if (A <= 79 && A >= 70)
    {
        result = "C";
    }
    else if (A <= 69 && A >= 60)
    {
        result = "D";
    }
    else
    {
        result = "F";
    }

    cout << result << endl;

    return 0;
}