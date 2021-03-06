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

using namespace std;

int main()
{
    int A, B, C;

    do
    {
        cout << "2이상 10000이하의 자연수 세 개를 입력해주세요.";
        cin >> A >> B >> C;
    } while (A < 2 || A > 10000 || B < 2 || B > 10000 || C < 2 || C > 10000);

    cout << ((A + B) % C) << endl;
    cout << (((A % C) + (B % C)) % C) << endl;
    cout << ((A * B) % C) << endl;
    cout << (((A % C) * (B % C)) % C) << endl;

    return 0;
}