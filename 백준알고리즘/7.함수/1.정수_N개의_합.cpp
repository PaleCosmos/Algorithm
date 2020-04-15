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
#include <vector>

//////answer
long long sum(std::vector<int> &a)
{
    long long s = 0;

    for (int i = 0; i < a.size(); i++)
    {
        s += a[i];
    }

    return s;
}
////////

int main()
{
    std::vector<int> x;
    x.push_back(1);
    x.push_back(3);
    x.push_back(5);

    std::cout << sum(x) << std::endl;

    return 0;
}