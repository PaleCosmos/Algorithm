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
#define UNDERSIZE -9999

using namespace std;

int self(int *arr, int c)
{
    int sum = 0;
    for (int i = 1; i <= c; i++)
    {
        int region = i - 1;

        if (i < 100)
        {
            if (i < 10)
            {
                arr[region] = 0;
            }
            else
            {
                arr[region] = (i % 10) - (i / 10);
            }
            sum++;
        }
        else
        {
            int temp = i / 10;
            if (arr[temp - 1] != UNDERSIZE)
            {
                if (temp % 10 + arr[temp - 1] == i % 10)
                {
                    arr[region] = arr[temp - 1];
                    sum++;
                }
                else
                {
                    arr[region] = UNDERSIZE;
                }
            }
            else
            {
                arr[region] = UNDERSIZE;
            }
        }
    }

    return sum;
}

int main()
{
    int *arr;
    int N;

    cin >> N;

    arr = new int[N];

    cout << self(arr, N) << endl;

    delete[] arr;

    return 0;
}