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
    int sum;

    cin >> temp;
    sum = temp.length();

    for (int i = 0; i < temp.length() - 1; i++)
    {
        switch (temp[i])
        {
        case 'd':
            if (i < temp.length() - 2 && temp[i + 1] == 'z' && temp[i + 2] == '=')
            {
                i += 2;
                sum -= 2;
            }
            else if (temp[i + 1] == '-')
            {
                i++;
                sum--;
            }
            break;
        case 'c':
            if ((temp[i + 1] == '=') || (temp[i + 1] == '-'))
            {
                sum--;
                i++;
            }
            break;
        case 'l':
            if (temp[i + 1] == 'j')
            {
                sum--;
                i++;
            }
            break;
        case 'n':
            if (temp[i + 1] == 'j')
            {
                sum--;
                i++;
            }
            break;
        case 's':
            if (temp[i + 1] == '=')
            {
                sum--;
                i++;
            }
            break;
        case 'z':
            if (temp[i + 1] == '=')
            {
                sum--;
                i++;
            }
            break;
        default:
            break;
        }
    }

    cout << sum << endl;

    return 0;
}