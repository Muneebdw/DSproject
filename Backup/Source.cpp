#include<iostream>
#include<cmath>
using namespace std;
//888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 8888888888888888888888888888
short int system_bits;
short int number_of_Ports;
short int number_of_Hubs;

int convertDecimal_to_Binary(int n)
{
	int binaryNumber = 0;
	int  remainder, i = 1, step = 1;
	while (n != 0)
	{
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder* i;
		i *= 10;
	}
	return binaryNumber;
}

struct Node_Ports_keys_array
{
	short int key;
	bool status;
	int key_in_binary;
	Node_Ports_keys_array* next;
};

class Ports_keys_array
{
private:
	Node_Ports_keys_array* head=NULL;
public:
	Ports_keys_array()
	{
		for (int i = 0; i<number_of_Ports; i++)
		{
			if (i == 0)
			{
				Node_Ports_keys_array* temp;
				temp = new Node_Ports_keys_array;
				temp->key = i;
				temp->key_in_binary = convertDecimal_to_Binary(i);
				temp->next = NULL;
				temp->status = false;
				head = temp;
			}
			else
			{
				Node_Ports_keys_array* temp;
				temp = new Node_Ports_keys_array;
				temp->key = i;
				temp->key_in_binary = convertDecimal_to_Binary(i);
				temp->next = NULL;
				temp->status = false;
				Node_Ports_keys_array* temp2 = head;
				while (temp2->next != NULL)
				{
					temp2 = temp2->next;
				}
				temp2->next = temp;

			}





		}
	}
	bool get_Port_status(short int key_argument)
	{
		if (key_argument>= number_of_Ports)
		{
			cout << "such key does not exist\n";
			return false;
		}
		Node_Ports_keys_array* temp2 = head;
		while (temp2 != NULL)
		{
			if (temp2->key == key_argument)
			{
				return temp2->status;
			}
			temp2 = temp2->next;
		}

	}
	bool change_key_status(short int key_argument,bool status_argument)
	{
		if (key_argument >= number_of_Ports)
		{
			cout << "such key does not exist............\n";
			return false;
		}
		Node_Ports_keys_array* temp2 = head;
		while (temp2 != NULL)
		{
			if (temp2->key == key_argument)
			{
				temp2->status= status_argument;
				cout << "\nchanged sucefully.............\n";
				return true;
			}
			temp2 = temp2->next;
		}
	}
	void Extend_the_Ports_keys_array()
	{
		Node_Ports_keys_array* temp2 = head;
		while (temp2->next!= NULL)
		{
			
			temp2 = temp2->next;
		}
		short int tempreory_port_numbers = temp2->key;
		for (int i = tempreory_port_numbers + 1; i < number_of_Ports; i++)
		{
			Node_Ports_keys_array* temp;
			temp = new Node_Ports_keys_array;
			temp->key = i;
			temp->key_in_binary = convertDecimal_to_Binary(i);
			temp->next = NULL;
			temp->status = false;
			temp2->next = temp;
			temp2=temp;
		}



	}
	void Display()
	{

		Node_Ports_keys_array* temp2=head;
		while (temp2!= NULL)
		{
			cout << temp2->key << "  " << temp2->status <<temp2->key_in_binary<<
				endl;
			temp2 = temp2->next;
		}

	}



};





//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888 my circular port station 888888888888888888my circular port station 888888888888888888 my circular port station
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
struct  Node_of_Port_station
{

	int data;
	//pointer to the next node
	Node_of_Port_station* next;


};

class circular_port_station
{
private:
	Node_of_Port_station* head;
public:
	circular_port_station()
	{
		head = NULL;
	}
	Node_of_Port_station* Port_station_node_creator(int data_argument);
	void creator_and_addAtEnd(int data_argument);
	Node_of_Port_station* getLastNode();
	Node_of_Port_station* search(int x);
	void addAtEnd_new_Node(Node_of_Port_station* n);
	void Display()
	{
		/*if(head==NULL)
		{
			cout<<"\nempty\n";
		}
		else
		{
		 Node_of_Port_station* temp=head;
		 Node_of_Port_station* temp2=temp->next;
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
		Node_of_Port_station* temp = head;
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

Node_of_Port_station* circular_port_station::search(int x)
{
	Node_of_Port_station* ptr = head;
	if (ptr->data == x)
	{
		return head;
	}
	else
	{

		Node_of_Port_station* ptr2 = head->next;
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
Node_of_Port_station* circular_port_station::Port_station_node_creator(int data_argument)
{
	Node_of_Port_station* temp = new 	Node_of_Port_station;
	temp->data = data_argument;
	return temp;

}
void circular_port_station::addAtEnd_new_Node(Node_of_Port_station* n)
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
		Node_of_Port_station* last = getLastNode();
		last->next = n;
		//making the next pointer of new node point to head
		n->next = head;
	}
}
void circular_port_station::creator_and_addAtEnd(int data_argument)
{
	Node_of_Port_station* temp = new Node_of_Port_station;
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
		Node_of_Port_station* last = getLastNode();
		last->next = temp;
		//making the next pointer of new node point to head
		temp->next = head;
	}

}

Node_of_Port_station* circular_port_station::getLastNode()
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

		Node_of_Port_station* temp = head;
		Node_of_Port_station* temp2 = head->next;
		while (temp2->next != temp)
		{
			temp2 = temp2->next;
		}
		return temp2;
	}
}


int main()
{
	cout << "Enter number of Ports that the circular line of database should have (bit wise system):  ";
	cin >> system_bits;
	number_of_Ports = static_cast<short>(pow(2, system_bits));
	cout << "\n" << number_of_Ports << endl;
	Ports_keys_array my1;
	my1.Display();
	//my1.change_key_status(2, true);
	//my1.Display();
	//cout<<endl<<my1.get_Port_status(2);
	cout << "update the number of ports :";
	cin >> system_bits;
	number_of_Ports = static_cast<short>(pow(2, system_bits));
	my1.Extend_the_Ports_keys_array();
	my1.Display();
	cout << "Enter number of Hubs that the system has :  ";
	cin >> number_of_Hubs;
	cout << "hello world\n";


	//8888888888888888888888888888888888888888888888888888888888888888888888888888
	cout << "hello world\n";
	circular_port_station my_test;

	my_test.creator_and_addAtEnd(1);
	my_test.creator_and_addAtEnd(2);
	my_test.creator_and_addAtEnd(3);

	Node_of_Port_station* my3 = my_test.Port_station_node_creator(4);
	my_test.addAtEnd_new_Node(my3);
	my3 = my_test.Port_station_node_creator(5);
	my_test.addAtEnd_new_Node(my3);
	my_test.Display();
	cout << endl << my_test.search(4);
	Node_of_Port_station* my2 = my_test.search(5);
	cout << my2->data;
	cout << "\nhello world";

}