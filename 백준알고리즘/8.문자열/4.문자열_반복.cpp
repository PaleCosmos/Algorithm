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
    int n, v, i, j, k;
    string temp;
    int *t;

    cin >> n;
    t = new int[n];

    for (i = 0; i < n; i++)
    {
        cin >> v >> temp;

        for (j = 0; j < temp.length(); j++)
        {
            for (k = 0; k < v; k++)
            {
                cout << temp[j];
            }
        }
        cout << endl;
    }

    delete[] t;

    return 0;
}