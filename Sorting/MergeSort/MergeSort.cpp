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

int temps[size];

int devide(int, int);
void conqurer(int *, int, int);
void combine(int *, int, int, int);

void mergeSort(int *arr)
{
    conqurer(arr, 0, size - 1);
}

int main()
{
    int* arr = arrData;

    print(arr, "Before");

    mergeSort(arr);

    print(arr, "\nAfter");

    return 0;
}

int devide(int left, int right)
{
    return (left + (right - left) / 2);
}

void conqurer(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = devide(left, right);

        conqurer(arr, left, mid);
        conqurer(arr, mid + 1, right);
        combine(arr, left, mid, right);
    }
}

void combine(int *arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int l;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temps[k++] = arr[i++];
        }
        else
        {
            temps[k++] = arr[j++];
        }
    }

    if (i > mid)
    {
        for (l = j; l <= right; l++)
        {
            temps[k++] = arr[l];
        }
    }
    else
    {
        for (l = i; l <= mid; l++)
        {
            temps[k++] = arr[l];
        }
    }

    for (l = left; l <= right; l++)
    {
        arr[l] = temps[l];
    }
}