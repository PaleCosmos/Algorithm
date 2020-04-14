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
    int tmp, sum = 0;

    cout << "다섯명의 점수를 입력해 주십시오." << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;

        if (tmp < 40)
            tmp = 40;

        sum += tmp;
    }

    cout << (sum / 5) << endl;
    
    return 0;
}