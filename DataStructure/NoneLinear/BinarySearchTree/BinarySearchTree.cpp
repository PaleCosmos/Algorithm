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

// 이어서하기@@@@
void insert(NodePtr *, string, int *);
NodePtr insertToTree(NodePtr *, string, int *);
void remove(NodePtr *, string, int *);
NodePtr removeFromTree(NodePtr *, string, int *);

int main()
{
    NodePtr root = NULL;
    int order, childSize = 0;
    string value;

    cout << "Welcome. This is binary search tree example written in C++.\n"
         << endl;

    do
    {
        print(root);
        managePointer(root);
        cout << "size : " << childSize << endl;
        cout << "1) A" << endl;
        cout << "2) B" << endl;

        cin >> order;

        cout << "\n\n"
             << endl;
        switch (order)
        {
        default:
            order = -1;
            break;
        }
        cout << "\n"
             << endl;
    } while (order != -1);

    cout << "Process Exit" << endl;
    return 0;
}