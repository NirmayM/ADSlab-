#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
    int data;
    Node *npx;

    public:

    Node()
    {

    }

    Node(int x)
    {
        data=x;
        npx=NULL;
    }
    int getData()
    {

        return data;
    }
    Node* Xor(Node *x, Node *y)
    {

       return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(x)^reinterpret_cast<uintptr_t>(y));
    }

    Node* insert(Node *head,int data)
    {


      Node *newnode=new Node(data);
      if(head==NULL)
        return newnode;

      Node *prev=NULL;
      Node *curr=head;
      Node *next;

      while(curr!=NULL)
      {
        next=Xor(prev,curr->npx);
        prev=curr;
        curr=next;
      }
      prev->npx=Xor(prev->npx,newnode);
      newnode->npx=Xor(prev,NULL);

      return head;
    }

    void display()
    {

        cout<<"The elements are:\n";
        Node *curr=this;
        Node *prev=NULL;
        Node *next;

        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            next=Xor(curr->npx,prev);
            prev=curr;
            curr=next;
        }
        cout<<"\n";
    }

    Node* del(Node *head,int data)
    {

        Node *curr,*prev,*next;
        if(head->data==data)
        {
            if(head->npx==NULL)
                return NULL;
            next=Xor(head->npx,NULL);
            next->npx=Xor(next->npx,head);
            return next;
        }
        curr=head;
        prev=NULL;
        while(curr->data!=data)
        {
             next=Xor(prev,curr->npx);
             prev=curr;
             curr=next;
        }
        next=Xor(prev,curr->npx);
        prev->npx=Xor(prev->npx,curr);
        if(next!=NULL)
        {
             next->npx=Xor(next->npx,curr);
             //set new npx
             prev->npx=Xor(prev->npx,next);
             next->npx=Xor(next->npx,prev);
        }

        return head;
    }

};


int main()
{
    Node *head=new Node();
    head=head->insert(NULL,10);
    head=head->insert(head,20);
    head=head->insert(head,40);
    head=head->insert(head,50);
    head->display();
    head=head->del(head,20);
    head->display();
    head=head->del(head,10);
    head->display();
    head=head->del(head,50);
    head->display();
    return 0;
}
