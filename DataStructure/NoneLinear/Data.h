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
#include <stdlib.h>

using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

typedef Node *NodePtr;

NodePtr createNewNode(string value)
{
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void managePointer(NodePtr root)
{
    string rootStr;

    if (root == NULL)
    {
        rootStr = "NULL";
    }
    else
    {
        rootStr = root->data;
    }

    cout << "Root : " << rootStr << endl;
}

void print(NodePtr root)
{
    if(root == NULL)return;

    cout << root->data;

    print(root->left);
    print(root->right);
}
