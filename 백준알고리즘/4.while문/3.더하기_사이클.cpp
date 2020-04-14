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
    int N, M, P, Q, i = 0;

    do
    {
        cout << "0 이상 99 이하의 정수를 입력해 주십시오." << endl;
        cin >> N;
        M = N;
    } while (N < 0 || N > 99);

    do
    {
        P = M / 10;
        Q = M - 10 * P;

        M = 10 * Q + (P + Q) % 10;

        i++;
    } while (M != N);

    cout << i << endl;

    return 0;
}