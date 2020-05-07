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
#include <stdio.h>

int *arr, *tmp;

void mergeSort(int left, int right)
{
    if (left != right)
    {
        int mid = (left + right) >> 1;
        int m;
        int i = left;
        int j = mid + 1;
        int k = left;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
                tmp[k++] = arr[j++];
            }
        }

        if (i > mid)
        {
            for (m = j; m <= right; m++)
                tmp[k++] = arr[m];
        }
        else
        {
            for (m = i; m <= mid; m++)
                tmp[k++] = arr[m];
        }

        for (m = left; m <= right; m++)
            arr[m] = tmp[m];
    }
}

// O(n*log(n))로 풀기
int main()
{
    int N, i = 0;

    scanf("%d", &N);
    arr = new int[N];
    tmp = new int[N];

    for (; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    mergeSort(0, N - 1);

    for (i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    delete[] arr;
    delete[] tmp;

    return 0;
}