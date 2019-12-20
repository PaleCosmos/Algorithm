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

void addAtFirst(NodePtr *, string, int *);
void addAtLast(NodePtr *, string, int *);
void addAfterIndexAt(NodePtr *, string, int, int *);
void removeByIndexAt(NodePtr *, int, int *);
void removeByValue(NodePtr *, string, int *);
void sort(NodePtr *);

int main()
{
    Node *head = NULL;
    int order, at, size = 0;
    string value;

    cout << "Welcome. This is linked list example written in C++.\n"
         << endl;

    do
    {
        print(head);
        cout << "size : " << size << endl;
        cout << "1) Add At First" << endl;
        cout << "2) Add At Last" << endl;
        cout << "3) Add after index at..." << endl;
        cout << "4) Remove By Index" << endl;
        cout << "5) Remove By Value" << endl;
        cout << "6) Sort" << endl;

        cin >> order;

        switch (order)
        {
            cout << "\n\n"
                 << endl;
        case 1:
            cout << "string value : ";
            cin >> value;
            addAtFirst(&head, value, &size);
            break;
        case 2:
            cout << "string value : ";
            cin >> value;
            addAtLast(&head, value, &size);
            break;
        case 3:
            cout << "string value : ";
            cin >> value;
            cout << "order : ";
            cin >> order;
            addAfterIndexAt(&head, value, order, &size);
            break;
        case 4:
            cout << "order : ";
            cin >> order;
            removeByIndexAt(&head, order, &size);
            break;
        case 5:
            cout << "string value : ";
            cin >> value;
            removeByValue(&head, value, &size);
            break;
        case 6:
            sort(&head);
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

// I used a double pointer to move the head position.
void addAtFirst(NodePtr *head, string value, int *size)
{
    NodePtr temp = createNewNode(value);

    // Same as *head != NULL
    if ((*size) != 0)
    {
        temp->next = *head;
    }

    *head = temp;

    (*size)++;
}

// I used a double pointer to move the head position.
void addAtLast(NodePtr *head, string value, int *size)
{
    NodePtr newHead = *head;
    NodePtr temp = createNewNode(value);

    // Same as *head == NULL
    if (*size == 0)
    {
        *head = temp;
    }
    else
    {
        while (newHead->next != NULL)
        {
            newHead = newHead->next;
        }
        newHead->next = temp;
    }

    (*size)++;
}

// I used a double pointer to move the head position.
void addAfterIndexAt(NodePtr *head, string value, int order, int *size)
{
    if ((*size) <= order || order < 0)
    {
        cout << "\n[Error] Invalid Index";
        return;
    }

    NodePtr newHead = *head;
    NodePtr temp = createNewNode(value);

    if (order == (*size) - 1)
    {
        if (order == 0)
        {
            *head = temp;
        }
        else
        {
            while (newHead->next != NULL)
            {
                newHead = newHead->next;
            }
            newHead->next = temp;
        }
    }
    else
    {
        for (int i = 0; i < order; i++, newHead = newHead->next)
            ;
        Node *temp2 = newHead->next;
        newHead->next = temp;
        temp->next = temp2;
    }

    (*size)++;
}

// I used a double pointer to move the head position.
void removeByIndexAt(NodePtr *head, int order, int *size)
{
    if ((*size) <= order || order < 0)
    {
        cout << "\n[Error] Invalid Index.";
        return;
    }

    NodePtr newHead = *head;
    NodePtr temp = NULL;

    for (int i = 0; i < (*size); i++,temp = newHead, newHead = newHead->next);

    (*size)--;
}

// I used a double pointer to move the head position.
void removeByValue(NodePtr *head, string value, int *size)
{
    // I'll do it tomorrow ~
    (*size)--;
}

// I used a double pointer to move the head position.
void sort(NodePtr *head)
{
    // Simply, I'll use bubble sort.
}