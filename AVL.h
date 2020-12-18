#include<iostream>
#include<cmath>
using namespace std;
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

struct key_Node
{
	short int key;
	bool status;
	int key_in_binary;
	key_Node* next;
};

class keys_tree
{
private:
	key_Node* head=NULL;
public:
	keys_tree()
	{
		for (int i = 0; i<number_of_Ports; i++)
		{
			if (i == 0)
			{
				key_Node* temp;
				temp = new key_Node;
				temp->key = i;
				temp->key_in_binary = convertDecimal_to_Binary(i);
				temp->next = NULL;
				temp->status = false;
				head = temp;
			}
			else
			{
				key_Node* temp;
				temp = new key_Node;
				temp->key = i;
				temp->key_in_binary = convertDecimal_to_Binary(i);
				temp->next = NULL;
				temp->status = false;
				key_Node* temp2 = head;
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
		key_Node* temp2 = head;
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
		key_Node* temp2 = head;
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
		key_Node* temp2 = head;
		while (temp2->next!= NULL)
		{
			
			temp2 = temp2->next;
		}
		short int tempreory_port_numbers = temp2->key;
		for (int i = tempreory_port_numbers + 1; i < number_of_Ports; i++)
		{
			key_Node* temp;
			temp = new key_Node;
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

		key_Node* temp2=head;
		while (temp2!= NULL)
		{
			cout << temp2->key << "  " << temp2->status <<temp2->key_in_binary<<
				endl;
			temp2 = temp2->next;
		}

	}



};

