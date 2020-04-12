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
    int A, B;

    do
    {
        cout << "10보다 작은 자연수 두 개를 입력해주세요.";
        cin >> A >> B;
    } while (A <= 0 || A >= 10 || B <= 0 || B >= 10);

    cout << (A * B) << endl;

    return 0;
}