#include "AVL.h"


struct  Machine_node
{

	int data;
	//pointer to the next node
	Machine_node* next;


};

class Machines
{
private:
	Machine_node* head;
public:
	Machines()
	{
		head = NULL;
	}
	Machine_node* Port_station_node_creator(int data_argument);
	void creator_and_addAtEnd(int data_argument);
	Machine_node* getLastNode();
	Machine_node* search(int x);
	void addAtEnd_new_Node(Machine_node* n);
	void Display()
	{
		/*if(head==NULL)
		{
			cout<<"\nempty\n";
		}
		else
		{
		 Machine_node* temp=head;
		 Machine_node* temp2=temp->next;
		 if(temp2==temp)
		 {
			cout<<temp->data;
		 }
		 else
		 {

		   while(temp2!=temp)
			{
				cout<<temp->data<<endl;
				temp2=temp2->next;
				}
		}*/
		Machine_node* temp = head;
		cout << temp->data;
		temp = temp->next;
		cout << temp->data;
		temp = temp->next;
		cout << temp->data;
		temp = temp->next;
		cout << temp->data;
		temp = temp->next;
		cout << temp->data;
		temp = temp->next;
		cout << temp->data;

	}

};

Machine_node* Machines::search(int x)
{
	Machine_node* ptr = head;
	if (ptr->data == x)
	{
		return head;
	}
	else
	{

		Machine_node* ptr2 = head->next;
		while (ptr2->next != head)
		{
			if (ptr2->data == x)
			{
				return ptr2;

			}
			//until we reach the end or we find a Node with data x, we keep moving
			ptr2 = ptr2->next;

		}
		if (ptr2->data == x)
		{
			return ptr2;
		}
		else
			return NULL;
	}
}
Machine_node* Machines::Port_station_node_creator(int data_argument)
{
	Machine_node* temp = new 	Machine_node;
	temp->data = data_argument;
	return temp;

}
void Machines::addAtEnd_new_Node(Machine_node* n)
{
	//If list is empty
	if (head == NULL) {
		//making the new Node as Head
		head = n;
		//making the next pointer of the new Node as Null
		n->next = head;
	}
	else
	{
		//getting the last node
		Machine_node* last = getLastNode();
		last->next = n;
		//making the next pointer of new node point to head
		n->next = head;
	}
}
void Machines::creator_and_addAtEnd(int data_argument)
{
	Machine_node* temp = new Machine_node;
	temp->data = data_argument;
	//If list is empty
	if (head == NULL) {
		//making the new Node as Head
		head = temp;
		//making the next pointer of the new Node as Null
		temp->next = head;
	}
	else
	{
		//getting the last node
		Machine_node* last = getLastNode();
		last->next = temp;
		//making the next pointer of new node point to head
		temp->next = head;
	}

}

Machine_node* Machines::getLastNode()
{

	if (head == NULL)
	{
		return NULL;
	}
	if (head == head->next)
	{
		return head;
	}
	else
	{

		Machine_node* temp = head;
		Machine_node* temp2 = head->next;
		while (temp2->next != temp)
		{
			temp2 = temp2->next;
		}
		return temp2;
	}
}