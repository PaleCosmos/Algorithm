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

void addAtFirst(NodePtr *, NodePtr *, string, int *);
void addAtLast(NodePtr *, NodePtr *, string, int *);
void addAfterIndexAt(NodePtr *, NodePtr *, string, int, int *);
void removeByIndexAt(NodePtr *, NodePtr *, int, int *);
void removeByValueAtAll(NodePtr *, NodePtr *, string, int *);
void removeByValueAtFirst(NodePtr *, NodePtr *, string, int *);
void removeByValueAtLast(NodePtr *, NodePtr *, string, int *);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int order, at, size = 0;
    string value;

    cout << "Welcome. This is linked list example written in C++.\n"
         << endl;

    do
    {
        print(head);
        managePointer(head, tail);
        cout << "size : " << size << endl;
        cout << "1) Add at first" << endl;
        cout << "2) Add at last" << endl;
        cout << "3) Add after index at..." << endl;
        cout << "4) Remove by index" << endl;
        cout << "5) Remove by value at all" << endl;
        cout << "6) Remove by value at first" << endl;
        cout << "7) Remove by value at last" << endl;

        cin >> order;

        cout << "\n\n"
             << endl;
        switch (order)
        {
        case 1:
            cout << "string value : ";
            cin >> value;
            addAtFirst(&head, &tail, value, &size);
            break;
        case 2:
            cout << "string value : ";
            cin >> value;
            addAtLast(&head, &tail, value, &size);
            break;
        case 3:
            cout << "string value : ";
            cin >> value;
            cout << "position : ";
            cin >> at;
            addAfterIndexAt(&head, &tail, value, at, &size);
            break;
        case 4:
            cout << "position : ";
            cin >> at;
            removeByIndexAt(&head, &tail, at, &size);
            break;
        case 5:
            cout << "string value : ";
            cin >> value;
            removeByValueAtAll(&head, &tail, value, &size);
            break;
        case 6:
            cout << "string value : ";
            cin >> value;
            removeByValueAtFirst(&head, &tail, value, &size);
            break;
        case 7:
            cout << "string value : ";
            cin >> value;
            removeByValueAtLast(&head, &tail, value, &size);
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

// I used a double pointer to move the head position.
void addAtFirst(NodePtr *head, NodePtr *tail, string value, int *size)
{
    NodePtr temp = createNewNode(value);

    // Same as *head != NULL
    if ((*size) != 0)
    {
        (*head)->last = temp;
        temp->next = *head;
    }
    else
    {
        *tail = temp;
    }

    *head = temp;

    (*size)++;
}

// I used a double pointer to move the head position.
void addAtLast(NodePtr *head, NodePtr *tail, string value, int *size)
{
    NodePtr newHead = *head;
    NodePtr temp = createNewNode(value);

    // Same as *head == NULL
    if (*size == 0)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        while (newHead->next != NULL)
        {
            newHead = newHead->next;
        }

        temp->last = newHead;
        newHead->next = temp;
        *tail = temp;
    }

    (*size)++;
}

// I used a double pointer to move the head position.
void addAfterIndexAt(NodePtr *head, NodePtr *tail, string value, int at, int *size)
{
    if ((*size) <= at || at < 0)
    {
        cout << "\n[Error] Invalid Index";
        return;
    }

    NodePtr newHead = *head;
    NodePtr temp = createNewNode(value);

    if (at == (*size) - 1)
    {
        if (at == 0)
        {
            *head = temp;
        }
        else
        {
            while (newHead->next != NULL)
            {
                newHead = newHead->next;
            }
            temp->last = newHead;
            newHead->next = temp;
        }
        *tail = temp;
    }
    else
    {
        for (int i = 0; i < at; i++, newHead = newHead->next)
            ;
        Node *temp2 = newHead->next;
        newHead->next = temp;
        temp->last = newHead;

        temp->next = temp2;
        temp2->last = temp;
    }

    (*size)++;
}

// I used a double pointer to move the head position.
void removeByIndexAt(NodePtr *head, NodePtr *tail, int at, int *size)
{
    if ((*size) <= at || at < 0)
    {
        cout << "\n[Error] Invalid Index.";
        return;
    }

    NodePtr newHead = *head;
    NodePtr temp = NULL;

    if (at == 0)
    {
        *head = (*head)->next;
        if ((*head) != NULL)
        {
            (*head)->last = NULL;
        }
        else
        {
            (*tail) = NULL;
        }
    }
    else
    {
        if (at == (*size) - 1)
        {
            newHead = *tail;

            (*tail)->last->next = NULL;
            (*tail) = (*tail)->last;
        }
        else
        {
            for (int i = 0; i < at; i++, temp = newHead, newHead = newHead->next)
                ;
            temp->next = newHead->next;
            newHead->next->last = temp;
        }
    }

    free(newHead);

    (*size)--;
}

// I used a double pointer to move the head position.
void removeByValueAtAll(NodePtr *head, NodePtr *tail, string value, int *size)
{
    if ((*size) == 0)
    {
        cout << "\n[Error] The size is 0.";
        return;
    }

    NodePtr newHead = *head;
    int index = 0, count = 0;

    while (newHead != NULL)
    {
        string data = newHead->data;
        newHead = newHead->next;
        if (data == value)
        {
            count++;
            removeByIndexAt(head, tail, index, size);
            index--;
        }
        index++;
    }

    if (count == 0)
    {
        cout << "There is no value named \'" << value << "\'." << endl;
    }
    else if (count == 1)
    {
        cout << 1 << " item is removed." << endl;
    }
    else
    {
        cout << count << " items are removed." << endl;
    }
}

void removeByValueAtFirst(NodePtr *head, NodePtr *tail, string value, int *size)
{
    if ((*size) == 0)
    {
        cout << "\n[Error] The size is 0.";
        return;
    }

    NodePtr newHead = *head;
    int index = 0;
    bool isExist = false;

    while (newHead != NULL)
    {
        string data = newHead->data;
        newHead = newHead->next;
        if (data == value)
        {
            isExist = true;
            removeByIndexAt(head, tail, index, size);
            break;
        }
        index++;
    }

    if (!isExist)
    {
        cout << "There is no value named \'" << value << "\'." << endl;
    }
    else
    {
        cout << "The first items is removed." << endl;
    }
}

void removeByValueAtLast(NodePtr *head, NodePtr *tail, string value, int *size)
{

    if ((*size) == 0)
    {
        cout << "\n[Error] The size is 0.";
        return;
    }

    NodePtr newTail = *tail;
    int index = (*size) - 1;
    bool isExist = false;

    while (newTail != NULL)
    {
        string data = newTail->data;
        newTail = newTail->last;
        if (data == value)
        {
            isExist = true;
            removeByIndexAt(head, tail, index, size);
            break;
        }
        index--;
    }

    if (!isExist)
    {
        cout << "There is no value named \'" << value << "\'." << endl;
    }
    else
    {
        cout << "The last items is removed." << endl;
    }
}