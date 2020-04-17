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
    string temp;
    int *ap = new int[26];
    int i, ct = 0;
    char index;

    cin >> temp;

    for (i = 0; i < temp.length(); i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            ap[(int)temp[i] - 'A']++;
        }
        else if (temp[i] >= 'a' && temp[i] <= 'z')
        {
            ap[(int)temp[i] - 'a']++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (ap[i] > ct)
        {
            ct = ap[i];
            index = (char)i + 'A';
        }
        else if (ap[i] == ct)
        {
            index = '?';
        }
    }

    cout << index << endl;

    delete[] ap;
    return 0;
}