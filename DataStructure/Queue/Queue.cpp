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

void enqueue(NodePtr *, NodePtr *, string, int *);
void dequeue(NodePtr *, NodePtr *, int *);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int order, size = 0;
    string value;

    cout << "Welcome. This is queue example written in C++.\n"
         << endl;

    do
    {
        print(head);
        managePointer(head, tail);
        cout << "size : " << size << endl;
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;

        cin >> order;

        cout << "\n\n"
             << endl;
        switch (order)
        {
        case 1:
            cout << "string value : ";
            cin >> value;
            enqueue(&head, &tail, value, &size);
            break;
        case 2:
            dequeue(&head, &tail, &size);
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

void enqueue(NodePtr *head, NodePtr *tail, string value, int *size)
{
    NodePtr temp = createNewNode(value);

    if (*size == 0)
    {
        (*head) = temp;
        (*tail) = temp;
    }
    else
    {
        temp->next = (*head);
        (*head)->last = temp;
        (*head) = temp;
    }

    (*size)++;
}
void dequeue(NodePtr *head, NodePtr *tail, int *size)
{
    NodePtr temp = (*tail);

    if (*size == 0)
    {
        cout << "The size is 0." << endl;
        return;
    }
    else if (*size == 1)
    {
        (*tail) = NULL;
        (*head) = NULL;
    }
    else
    {
        (*tail) = (*tail)->last;
        (*tail)->next = NULL;
    }

    free(temp);

    (*size)--;
}