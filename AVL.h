#include<iostream>
#include<cmath>
#include<cstdio>
#include <string>
#include<cstdlib>
#include <sys/stat.h>
#include <iomanip>
#include <fstream>

using namespace std;


short int system_bits=4;
short int number_of_Ports=1;
short int number_of_Hubs=1;

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
	string data_in;
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
	string get(int key){
			if (key>= number_of_Ports)
		{
			//cout << "such key does not exist\n";
			return "";
		}
				key_Node* temp2 = head;

		while (temp2 != NULL)
		{
			if (temp2->key == key)
			{
				return temp2->data_in;
			}
			temp2 = temp2->next;
		}
	}

	bool insertin(short int key_argument,string data)
	{bool status_argument = true;
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
				temp2->data_in = data;
				return true;
				temp2->data_in = data;
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
	void Displayall()
	{	    
		cout << "Key"<<setw(10)<< "status" << setw(10) << "Binary"<<setw(10) << "Data"<<endl;
		key_Node* temp2=head;
		while (temp2!= NULL)
		{    std::cout << std::left;
			cout <<setw(10)<< temp2->key << setw(10) << temp2->status <<setw(10) << temp2->key_in_binary<< setw(10)<< temp2->data_in<<endl;
			temp2 = temp2->next;
		}

	}

	void Displayactive(){
			cout << "Key"<<setw(10)<< "status" << setw(10) << "Binary"<<setw(10) << "Data"<<endl;
		key_Node* temp2=head;
		while (temp2!= NULL)
		{   
			if(temp2->status==true) {std::cout << std::left;
			cout <<setw(10)<< temp2->key << setw(10) << temp2->status <<setw(10) << temp2->key_in_binary<< setw(10)<< temp2->data_in<<endl;
		}
					temp2 = temp2->next;}

	}

	void writetofile(string filepath,int key , string data_in){
		std::ofstream outfile (filepath);
		outfile << key << setw(10) << data_in <<"\n";

		outfile.close();

	}


};

