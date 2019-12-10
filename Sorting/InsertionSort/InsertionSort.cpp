#pragma region LICENSE
//    Copyright 2019 PaleCosmos
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
#define size 15

using namespace std;

void insertionSort(int *arr)
{
    for (int i = 1; i < size; i++)
    {
        int j;
        int key = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}

void print(int *arr, string define)
{
    cout << define << '\n';
    cout << "[";
    for (int k = 0; k < size; k++)
    {
        cout << arr[k];
        if (k != size - 1)
        {
            cout << ",";
        }
    }
    cout << "]\n";
}

int main()
{
    int arr[size]{8, 11, 2, 9, 5, 14, 0, 13, 10, 3, 6, 1, 4, 7, 12};

    print(arr, "Before");

    insertionSort(arr);

    print(arr, "\nAfter");

    return 0;
}