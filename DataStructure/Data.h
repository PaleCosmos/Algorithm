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
    Node *next;
    Node *last;
};

typedef Node *NodePtr;

NodePtr createNewNode(string value)
{
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->data = value;
    temp->last = NULL;
    temp->next = NULL;

    return temp;
}

void managePointer(NodePtr head, NodePtr tail)
{
    string headStr, tailStr;

    if (head == NULL)
    {
        headStr = "NULL";
    }
    else
    {
        headStr = head->data;
    }

    if (tail == NULL)
    {
        tailStr = "NULL";
    }
    else
    {
        tailStr = tail->data;
    }

    cout << "Head : " << headStr << endl;
    cout << "Tail : " << tailStr << endl;
}

void print(NodePtr head)
{
    cout << "\n";

    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    NodePtr temp = head;

    cout << "NULL <-> ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
