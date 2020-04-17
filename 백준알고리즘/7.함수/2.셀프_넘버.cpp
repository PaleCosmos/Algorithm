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
#define SIZE 10000
#include <iostream>

using namespace std;

void self(int *arr, int c)
{
    int sum = c + 1;
    int slice = c + 1;
    int module = 1;

    while ((int)slice / module > 0)
    {
        sum += (slice / module) % 10;
        module *= 10;
    }

    if (sum < SIZE)
    {
        arr[sum - 1]++;
    }

    if (c < SIZE - 1)
    {
        self(arr, c + 1);
    }
}

int main()
{
    int *arr = new int[SIZE - 1];

    self(arr, 0);

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (arr[i] == 0)
        {
            cout << (i + 1) << endl;
        }
    }

    return 0;
}