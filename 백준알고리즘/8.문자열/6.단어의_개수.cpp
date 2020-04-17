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

#define SIZE 1000000
using namespace std;

int main()
{
    char temp[SIZE];
    int length, z;

    cin.getline(temp, SIZE);

    z = temp[0] != ' ';

    for (length = 0; temp[length] != '\0'; length++)
    {
        z += temp[length] == ' ';
    }

    z -= temp[length - 1] == ' ';

    cout << z << endl;

    return 0;
}