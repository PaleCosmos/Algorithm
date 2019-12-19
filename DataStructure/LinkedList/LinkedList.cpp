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

void add(string str)
{
}

int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->data = "A";
    head->next = new Node();
    head->next->data = "B";
    print(head);

    int order;

    cout << "Welcome. This is linked list Example written in C++." << endl;

    do
    {
        cout << "1) Add At First" << endl;
        cout << "2) Add At Last" << endl;
        cout << "3) Add Between Indexes" << endl;
        cout << "4) Remove By Index" << endl;
        cout << "5) Remove By Value" << endl;

        cin >> order;

        switch (order)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;

        default:
            order = -1;
            break;
        }

    } while (order != -1);
    return 0;
}