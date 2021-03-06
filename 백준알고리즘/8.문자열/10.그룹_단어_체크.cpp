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

bool check(string str)
{
    bool find[26] = {0};
    char temp = '\0';

    for (int g = 0; g < str.length(); g++)
    {
        if (temp != str[g])
        {
            if (find[str[g] - 'a'])
            {
                return false;
            }
            temp = str[g];
            find[temp - 'a'] = true;
        }
    }

    return true;
}

int main()
{
    string temp;
    int N, i, sum = 0;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> temp;

        sum += check(temp);
    }

    cout << sum << endl;

    return 0;
}