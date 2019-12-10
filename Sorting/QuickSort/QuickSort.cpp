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

int partition(int *, int, int);
void conqurer(int *, int, int);

void quickSort(int *arr)
{
    conqurer(arr, 0, size - 1);
}

int main()
{
    int* arr = arrData;

    print(arr, "Before");

    quickSort(arr);

    print(arr, "\nAfter");

    return 0;
}

int partition(int *arr, int left, int right)
{
    int temp;
    int low = left;
    int high = right + 1;
    int pivot = arr[left];

    do
    {
        do
        {
            low++;
        } while (low <= right && arr[low] < pivot);

        do
        {
            high--;
        } while (high >= left && arr[high] > pivot);

        if (low < high)
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }

    } while (low < high);

    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;

    return high;
}

void conqurer(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);

        conqurer(arr, left, pivot - 1);
        conqurer(arr, pivot + 1, right);
    }
}