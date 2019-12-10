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
#include "../Data.h"

void insertionSort(int *arr)
{
    int j, key;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}

int main()
{
    clock_t start, end;

    int *arr = arrData;

    //print(arr, "Before");

    start = clock();

    insertionSort(arr);

    end = clock();

    //print(arr, "\nAfter");

    timeStamp(start, end); // 88ms

    return 0;
}