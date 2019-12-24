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

void insertValue(NodePtr *, string, int *);
NodePtr insert(NodePtr *, string, int *, int);
void removeValue(NodePtr *, string, int *);
NodePtr remove(NodePtr *, string, int *, bool *);

int main()
{
    NodePtr root = NULL;
    int order, deeps = 0;
    string value;

    cout << "Welcome. This is binary search tree example written in C++.\n"
         << endl;

    do
    {
        print(root, deeps);
        cout << "\n";
        managePointer(root);
        cout << "deeps : " << deeps << endl;
        cout << "1) Insert Node" << endl;
        cout << "2) Remove Node" << endl;

        cin >> order;

        cout << "\n\n"
             << endl;
        switch (order)
        {
        case 1:
            cout << "string value : ";
            cin >> value;
            insertValue(&root, value, &deeps);
            break;
        case 2:
            cout << "string value : ";
            cin >> value;
            remove(&root, value, &deeps, 0);
            break;
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

void insertValue(NodePtr *root, string value, int *deeps)
{
    insert(root, value, deeps, 0);
}

NodePtr insert(NodePtr *root, string value, int *deeps, int floor)
{
    if (*root == NULL)
    {
        *root = createNewNode(value);
    }
    else
    {
        int flag = (*root)->data.compare(value);
        if (flag < 0)
        {
            (*root)->left = insert(&((*root)->left), value, deeps, floor + 1);
        }
        else if (flag > 0)
        {
            (*root)->right = insert(&((*root)->right), value, deeps, floor + 1);
        }
        else
        {
            cout << "The value \'" << value << "\' exists.";
        }
    }

    if (*deeps < floor)
    {
        (*deeps) = floor;
    }

    return (*root);
}

void removeValue(NodePtr *root, string value, int *deeps)
{
    bool success = false;

    remove(root, value, deeps, &success);

    if (!success)
    {
        cout << "The value \'" << value << "\' doesn\'t exsist.";
    }
}
NodePtr remove(NodePtr *root, string value, int *deeps, bool *floor)
{
    //구현하기
    return NULL;
}