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
    string n;
    int i, temp;
    int arr[26];
    fill_n(arr, 26, -1);

    cin >> n;

    for (i = 0; i < n.length(); i++)
    {
        temp = (int)n[i] - 'a';
        if (arr[temp] == -1)
        {
            arr[temp] = i;
        }
    }

    for (i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}