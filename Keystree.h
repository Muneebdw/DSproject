#include<iostream>
#include<cmath>
#include<cstdio>
#include <string>
#include<cstdlib>
#include <sys/stat.h>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

string char_arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
short int system_bits=4;
short int number_of_Ports=1;
short int number_of_Hubs=1;

string hashfunc(int i){

string r="";
for(int i=0;i<3;i++){
r += char_arr[rand( ) % 27];}
r+= to_string(i);
r+= to_string(i%number_of_Ports);
for(int i=0;i<2;i++){
r += char_arr[rand( ) % 27];}
return r;
}

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
	string hkey;
	bool status;
	string data_in;
	int key_in_binary;
	key_Node* Left;
	key_Node* Right;
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
				temp->Left = NULL;
				temp->status = false;
				temp->hkey = hashfunc(i);
				temp->data_in="";
				head = temp;
			}
			else
			{
				key_Node* temp;
				temp = new key_Node;
				temp->key = i;
				temp->key_in_binary = convertDecimal_to_Binary(i);
				temp->Left = NULL;
				temp->status = false;
				temp->hkey = hashfunc(i);
				temp->data_in="";
				key_Node* temp2 = head;
				while (temp2->Left != NULL)
				{
					temp2 = temp2->Left;
				}
				temp2->Left = temp;


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
			temp2 = temp2->Left;
		}

	}
	string get(int key){
		
			//cout << "such key does not exist\n";
		
				key_Node* temp2 = head;

		while (temp2 != NULL)
		{
			if (temp2->key == key)
			{
				return temp2->data_in;
			}
			temp2 = temp2->Left;
		}
		return "";
	}
	bool deletekey(int key){
		
		key_Node* temp2 = head;
		while (temp2 != NULL)
		{
			if (temp2->key == key)
			{
				temp2->status=false;
				temp2->data_in="";
				return true;
			}
			temp2 = temp2->Left;
		}
					return false;

	}
	bool insertin(short int key_argument,string data)
	{bool status_argument = true;
		if (key_argument >= number_of_Ports)
		{
				key_Node* temp;
				temp = new key_Node;
				temp->key = key_argument;
				temp->key_in_binary = convertDecimal_to_Binary(key_argument);
				temp->Left = NULL;
				temp->status = true;
				temp->data_in = data;
				temp->hkey = hashfunc(key_argument);
				key_Node* temp2 = head;
				while (temp2->Left != NULL)
				{
					temp2 = temp2->Left;
				}
				temp2->Left = temp;			
				return false;
		}
		key_Node* temp2 = head;
		while (temp2 != NULL)
		{
			if (temp2->key == key_argument)
			{
				temp2->status= status_argument;
				temp2->data_in = data;
				return true;
				temp2->data_in = data;
			}
			temp2 = temp2->Left;
		}
	}
	void Extend_the_Ports_keys_array()
	{
		key_Node* temp2 = head;
		while (temp2->Left!= NULL)
		{
			
			temp2 = temp2->Left;
		}
		short int tempreory_port_numbers = temp2->key;
		for (int i = tempreory_port_numbers + 1; i < number_of_Ports; i++)
		{
			key_Node* temp;
			temp = new key_Node;
			temp->key = i;
			temp->key_in_binary = convertDecimal_to_Binary(i);
			temp->Left = NULL;
			temp->status = false;
			temp2->Left = temp;
			temp2=temp;
		}



	}
	void Displayall()
	{	    
			cout << "Key"<<setw(10)<<"Hash key" << setw(20)<< "status" << setw(10) << "Binary"<<setw(10) << "Data"<<endl;
		key_Node* temp2=head;
		while (temp2!= NULL)
		{  
			cout << temp2->key << setw(20)<<temp2->hkey<<setw(10) << temp2->status <<setw(10) << temp2->key_in_binary<< setw(10)<< temp2->data_in<<endl;
			temp2 = temp2->Left;
		}

	}

	void Displayactive(){
			cout << "Key"<<setw(10)<<"Hash key" << setw(20)<< "status" << setw(10) << "Binary"<<setw(10) << "Data"<<endl;
		key_Node* temp2=head;
		while (temp2!= NULL)
		{   
			if(temp2->status==true) {
			cout << temp2->key << setw(20)<<temp2->hkey<<setw(10) << temp2->status <<setw(10) << temp2->key_in_binary<< setw(10)<< temp2->data_in<<endl;
		}
					temp2 = temp2->Left;}

	}

	void writetofile(string filepath,int key , string data_in){
		std::ofstream outfile (filepath);
		outfile << key;
		key_Node* t = this->head;
	
		while(t->key==key || t->Left == NULL){
			t= t->Left;
		}
		outfile << setw(10) << t->hkey<<  setw(10)<< data_in <<"\n";
		outfile.close();

	}


};

