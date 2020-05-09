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
#include <algorithm>

using namespace std;

struct p
{
    string name;
    int age;
    int order;
};

bool st(p &a, p &b)
{
    return a.age != b.age ? a.age < b.age : a.order < b.order;
}

int main()
{
    int N, i = 0;
    p *arr;

    cin >> N;

    arr = new p[N];

    for (; i < N; i++)
    {
        cin >> arr[i].age >> arr[i].name;
        arr[i].order = i;
    }

    sort(arr, arr + N, st);

    for (i = 0; i < N; i++)
    {
        cout << arr[i].age << " " << arr[i].name << "\n";
    }

    delete[] arr;

    return 0;
}