#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define max 5
typedef struct list
{
    int data;
    struct list *next;
} node_type;
node_type *ptr[max], *root[max], *temp[max];
class Dictionary
{
public:
    int index;
    Dictionary();
    void insert(int);
    void search(int);
    void delete_ele(int);
    void display(int);
};
Dictionary::Dictionary()
{
    index = -1;
    for (int i = 0; i < max; i++)
    {
        root[i] = NULL;
        ptr[i] = NULL;
        temp[i] = NULL;
    }
}
void Dictionary::insert(int key)
{
    index = int(key % max);
    ptr[index] = (node_type *)malloc(sizeof(node_type));
    ptr[index]->data = key;
    ptr[index]->next = NULL;
    if (root[index] == NULL)
    {
        root[index] = ptr[index];
        root[index]->next = NULL;
        temp[index] = ptr[index];
    }
    else
    {
        temp[index] = root[index];
        while (temp[index]->next != NULL)
            temp[index] = temp[index]->next;
        temp[index]->next = ptr[index];
    }
}
void Dictionary::search(int key)
{
    int flag = 0;
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index] != NULL)
    {
        if (temp[index]->data == key)
        {
            cout << "\nSearch key is found!!";
            flag = 1;
            break;
        }
        else
            temp[index] = temp[index]->next;
    }
    if (flag == 0)
        cout << "\nsearch key not found.......";
}
void Dictionary::delete_ele(int key)
{
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index]->data != key && temp[index] != NULL)
    {
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }
    ptr[index]->next = temp[index]->next;
    cout << "\n"
         << temp[index]->data << " has been deleted.";
    temp[index]->data = -1;
    temp[index] = NULL;
    free(temp[index]);
}
void Dictionary::display(int n)
{
    for (int i = 1; i <= n; i++)
    {
        while (root[i] != NULL)
        {
            cout << "level" << i << "contents are" << root[i]->data << "\t ";
            root[i] = root[i]->next;
        }
    }
}
int main()
{
    int val, ch, n, num;
    char c;
    Dictionary d;
    do
    {
        cout << "\nMENU:\n1.Create";
        cout << "\n2.Search for a value\n3.Display\n4.Exit\n";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the number of elements to be inserted:";
            cin >> n;
            cout << "\nEnter the elements to be inserted:";
            for (int i = 0; i < n; i++)
            {
                cin >> num;
                d.insert(num);
            }
            break;
        case 2:
            cout << "\nEnter the element to be searched:";
            cin >> n;
            d.search(n);
        case 3:
            d.display(n);
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "\nInvalid Choice.";
        }
        cout << "\nEnter anything to Continue:";

    } while (1);
    getch();

    return 0;
}
