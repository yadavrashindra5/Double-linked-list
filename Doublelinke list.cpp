/*This a double linked list code 
you can insert data at begin of node , last of node as well as before and after of a given node 
you can also view data using print( ) function 
*/

#include<iostream>
using namespace std;
class Node{
Node *prev;//this represent the pointer to previous node
int Data;
Node *Next;//This represent the pointer to next node 
public:
    void insert_at_first(int x);//Function for insert data at first node
    void insert_at_last(int x);//Function for insert data at last node
    void print();
    void insert_after_given_node(int x,int y);//Function for insert data after given node
    void insert_before_given_node(int x,int y);//Function for insert data before given node
    void delete_last_node();
    void delete_first_node();
    void delete_node_after_given_node(int x);
    void delete_node_before_given_node(int x);

};
Node *Head=NULL;
void Node::insert_at_first(int x)
{
    Node *New_Node=new Node();
    New_Node->Data=x;
    New_Node->prev=NULL;
    Node *temp=Head;
    if(Head==NULL)
    {
        Head=New_Node;
    }
    else{
        New_Node->Next=temp;
        temp->prev=New_Node;
        Head=New_Node;

    }

}
void Node::insert_after_given_node(int x,int y)
{

    Node*New_Node=new Node();
    New_Node->Data=x;
    Node *ptr=Head;
    while(ptr->Data!=y)
    {
        ptr=ptr->Next;
    }
    Node*temp=ptr->Next;
    ptr->Next=New_Node;
    New_Node->prev=ptr;
    New_Node->Next=temp;

}



void Node::print()
{
Node*ptr=Head;
while(ptr!=NULL)
{
    cout<<ptr->Data<<"\n";
    ptr=ptr->Next;
}

}
void Node::insert_at_last(int x)
{

    Node *New_Node=new Node();
    Node*temp=Head;
    New_Node->Data=x;
    New_Node->Next=NULL;
    if(Head==NULL)
    {
        Head=New_Node;
    }
    else{

        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=New_Node;
        New_Node->prev=temp;

    }

}

void Node::insert_before_given_node(int x,int y)
{

    Node *New_Node=new Node();
    New_Node->Data=x;
    Node *ptr=Head;
    while(ptr->Data!=y)
    {
        ptr=ptr->Next;

    }
    Node *temp=ptr->prev;
    New_Node->prev=temp;
    New_Node->Next=ptr;
    temp->Next=New_Node;



}

void Node::delete_node_before_given_node(int x)
{   Node *ptr=Head;
    if(Head==NULL)
    {
        cout<<"Under flow\n";
    }
    else{
        while(ptr->Data!=x)
        {
            ptr=ptr->Next;
        }
        if (ptr->prev==NULL)
        {
            cout<<"No Node is available before This Node\n";
        }
        else if(ptr->prev->prev==NULL)
        {
            Head=ptr;
            ptr->prev=NULL;
        }
        else{


            ptr->prev->prev->Next=ptr;
            ptr->prev=ptr->prev->prev;
        }


    }


}



void Node::delete_node_after_given_node(int x)
{
    Node *ptr=Head;
    if(Head==NULL)
    {
        cout<<"Under flow\n";
    }
    else {
        while(ptr->Data!=x)
        {
            ptr=ptr->Next;
        }
        if(ptr->Next->Next==NULL)
        {
            ptr->Next=NULL;
        }
        else{
        ptr->Next=ptr->Next->Next;
        ptr->Next->prev=ptr;
        }
    }


}


void Node::delete_last_node()
{
Node*ptr=Head;
if(Head==NULL)
{
    cout<<"under flow\n";
}
else if(Head->Next==NULL)
{
    Head=NULL;
}
else{

    while(ptr->Next!=NULL)
    {
        ptr=ptr->Next;
    }
    ptr->prev->Next=NULL;
}


}
void Node::delete_first_node()
{
    if(Head==NULL)
    {
        cout<<"Under Flow\n";

    }
    else if(Head->Next==NULL)
    {
        Head=NULL;
    }
    else{

        Head->Next->prev=NULL;
        Head=Head->Next;
    }
}







int main()//This is the main function from where function begin 
{

    Node n;
    n.insert_at_first(11);
    n.insert_at_last(12);
    n.insert_at_last(13);
    n.insert_at_last(14);
    n.insert_at_last(15);
    n.insert_after_given_node(12,11);
    n.print();
    cout<<"\n";
    n.insert_before_given_node(9,15);
    n.print();

}
