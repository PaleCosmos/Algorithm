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
    int N, X;

    do
    {
        cout << "10000이하의 자연수 두 개를 입력해주십시오." << endl;
        cin >> N >> X;
    } while (N < 1 || N > 10000 || X < 1 || X > 10000);

    int *arr = new int[N];

    cout << N << "개의 수를 입력해주십시오." << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < X)
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    delete[] arr;

    return 0;
}