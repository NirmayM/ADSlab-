#include <bits/stdc++.h>
#include<time.h>
using namespace std;


class Node
{
public:
    int key;


    Node **forward;
    Node(int, int);
};

Node::Node(int key, int level)
{
    this->key = key;


    forward = new Node*[level+1];


    memset(forward, 0, sizeof(Node*)*(level+1));
};


class SkipList
{

    int MAXLVL;



    float P;


    int level;


    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void deleteElement(int);
    void searchElement(int);
    void displayList();
    void delay();
};

SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;


    header = new Node(-1, MAXLVL);
};


int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

Node* SkipList::createNode(int key, int level)
{
    Node *n = new Node(key, level);
    return n;
};


void SkipList::insertElement(int key)
{
    Node *current = header;


    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));


    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != NULL &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }


    current = current->forward[0];


    if (current == NULL || current->key != key)
    {

        int rlevel = randomLevel();


        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;


            level = rlevel;
        }


        Node* n = createNode(key, rlevel);


        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout << "Successfully Inserted key " << key << "\n";
    }
};

 void SkipList::deleteElement(int key)
{
    Node *current = header;


    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));


    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL  &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }


    current = current->forward[0];


    if(current != NULL and current->key == key)
    {

        for(int i=0;i<=level;i++)
        {

            if(update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }


        while(level>0 &&
              header->forward[level] == 0)
            level--;
         cout<<"Successfully deleted key "<<key<<"\n";
    }
};

void SkipList::delay()
{
    int j;
    for(int i=0;i<8000;i++)
    {
        for(int k=0;k<8000;k++)
            j=890000/34;
    }
}
void SkipList::searchElement(int key)
{
    Node *current = header;


    clock_t st,ed;
    int comp=0;
    st=clock();
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] &&
               current->forward[i]->key < key)
        {
             current = current->forward[i];
             comp++;
            delay();
        }
     }


    current = current->forward[0];
    ed=clock();

    cout<<"The time taken is "<<(double)(ed-st)/CLOCKS_PER_SEC<<"\n";
     cout<<"The comparisons are "<<comp+1<<"\n";
    if(current and current->key == key)
    {
      cout<<"Found key: "<<key<<"\n";

    }
};

void SkipList::displayList()
{
    cout<<"\n*****Skip List*****"<<"\n";
    for (int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
        {
            cout << node->key<<" ";
            node = node->forward[i];
        }
        cout << "\n";
    }
};


int main()
{

    SkipList lst(4, 0.5);

   cout<<"Insertion"<<endl;
   lst.insertElement(23);
   lst.insertElement(21);
   lst.insertElement(45);
   lst.insertElement(9);
   lst.insertElement(69);
   lst.insertElement(140);
   lst.insertElement(2);
   lst.insertElement(37);
   lst.insertElement(81);
   lst.insertElement(201);
   lst.insertElement(111);
   lst.insertElement(79);
   lst.insertElement(23);
   lst.insertElement(132);
   lst.insertElement(56);

   lst.displayList();

    cout<<"Search "<<endl;

    lst.searchElement(80);
}
