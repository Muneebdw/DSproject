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
//888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 8888888888888888888888888888
// 888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 
//888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 88888888888 GLOABAL VARIBLES 8888888888888888888888888888


//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

//88888888888888888888888888888888888888888888888888888888888888888888888888888888888
//888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
// AVL TREE   AVL TREE open  AVL TREE open  AVL TREE open   AVL TREE  AVL TREE open  AVL TREE open

string char_arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
short int system_bits=4;
short int number_of_Ports=1;
short int number_of_machines=1;
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

class MyDS {
private:
	struct treeNode
	{
		int key;
		treeNode* left;
		treeNode* right;
		int height;
		std::string data;
		treeNode() 
		{
			left = NULL; right = NULL; height = 0;
		};
		treeNode(const std::string& v, treeNode* l, treeNode* r, int h) { data = v; left = l;  right = r; height = h; };
	};

	treeNode* root;
	void push(const std::string& n, treeNode*& v);
	bool search(const std::string& s, treeNode*& tree);
public:
	MyDS();
	~MyDS();
	void push(const std::string& n);
	void printPreOrder() const;
	void preOrder(treeNode* pre) const;
	void clear(treeNode*& tree);
	void singleRightRotate(treeNode*& n);
	void doubleRightRotate(treeNode*& n);
	void singleLeftRotate(treeNode*& n);
	void doubleLeftRotate(treeNode*& n);
	bool search(const std::string& s);
	int avlHeight(treeNode* h);
	int max(int v1, int v2);
};
MyDS::MyDS()
{
	root = NULL;

}

MyDS::~MyDS()
{
	clear(root);
}

void MyDS::push(const std::string& n)
{
	push(n, root);
}

void MyDS::singleRightRotate(treeNode*& n)
{
	treeNode* temp;
	temp = n->right;
	n->right = temp->left;
	temp->left = n;
	n = temp;
	n->height = max(avlHeight(n->left), avlHeight(n->right)) + 1;
	temp->height = max(n->height, avlHeight(temp->right)) + 1;


}

void MyDS::singleLeftRotate(treeNode*& n)
{
	treeNode* temp;
	temp = n->left;
	n->left = temp->right;
	temp->right = n;
	n = temp;
	n->height = max(avlHeight(n->left), avlHeight(n->right)) + 1;
	temp->height = max(avlHeight(temp->left), n->height) + 1;
}

void MyDS::doubleRightRotate(treeNode*& n)
{
	singleLeftRotate(n->right);
	singleRightRotate(n);
}

void MyDS::doubleLeftRotate(treeNode*& n)
{
	singleRightRotate(n->left);
	singleLeftRotate(n);
}

int MyDS::max(int v1, int v2)
{
	return ((v1 > v2) ? v1 : v2);
}

int MyDS::avlHeight(treeNode* h)
{
	int n;
	if (h == NULL)
	{
		return -1;
	}
	else
	{
		n = h->height;
		return n;
	}

}


bool MyDS::search(const std::string& s, treeNode*& tree)
{
	if (tree == NULL)
	{
		return false;
	}
	if (s < tree->data)
	{
		return search(s, tree->left);
	}
	if (tree->data < s)
	{
		return search(s, tree->right);
	}
	return true; // We found the value.
}

bool MyDS::search(const std::string& x)
{
	if (search(x, root))
	{
		return true;
	}
	else
		return false;
}

void MyDS::clear(treeNode*& tree)
{
	if (tree != NULL)
	{
		clear(tree->left);
		clear(tree->right);
		delete tree;

	}

	tree = NULL;
}

void MyDS::push(const std::string& n, treeNode*& v)
{
	if (v == NULL)
	{
		v = new treeNode(n, NULL, NULL, 0);
	}
	else
	{
		if (n < v->data)
		{
			push(n, v->left);   // goes to left node

			if ((avlHeight(v->left) - avlHeight(v->right)) == 2)
			{
				if (n < v->left->data)
				{
					singleLeftRotate(v);
				}
				else
				{
					doubleLeftRotate(v);
				}
			}
		}
		else if (v->data < n)
		{
			push(n, v->right);  // goes to right node
			if ((avlHeight(v->right) - avlHeight(v->left)) == 2)
			{
				if (n > v->right->data)
				{
					singleRightRotate(v);
				}
				else
				{
					doubleRightRotate(v);
				}
			}
		}
		else
		{
			; // duplicate; do nothing.
		}
	}
	int a, b, c;
	a = avlHeight(v->left);
	b = avlHeight(v->right);
	c = max(a, b);
	v->height = c + 1;

}

void MyDS::printPreOrder() const
{
	preOrder(root);
}


void MyDS::preOrder(treeNode* pre) const
{
	if (pre != NULL)
	{
		std::cout << " " << pre->data << " ";
		preOrder(pre->left);
		preOrder(pre->right);
	}
}

struct Machine
{
	string machine_name;
	short machine_key = 0;
	MyDS tree;
	string file_name;
};

// AVL TREE   AVL TREE closed  AVL TREE closed AVL TREE closed   AVL TREE  AVL TREE closed AVL TREE open

//888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
struct  Node_of_Port_station
{

	int data;
	short int key;
	bool status;
	int key_in_binary;
	Node_of_Port_station* next;
	Machine* plug;



};

class circular_port_station
{
private:
	Node_of_Port_station* head;
public:
	Node_of_Port_station* Port_station_node_creator(int data_argument);
	void creator_and_addAtEnd(int data_argument);
	Node_of_Port_station* getLastNode();
	Node_of_Port_station* search(int x);
	void addAtEnd_new_Node(Node_of_Port_station* n);
	bool get_Port_status(short int key_argument);
	bool change_key_status(short int key_argument, bool status_argument);
	void set_the_number_of_ports_at_station();
	void change_the_number_of_ports_at_station();
	Node_of_Port_station* search_Node_by_key(int key_argument);
	void add_machine_to_plug(int key, string machine_name);
	bool deleteNode_by_key(int x);
	void add_machine_to_plug();
	void Display();
	void machine_Display(int key_argument);

	circular_port_station()
	{
		head = NULL;

	}
	void store_data(int key, string data)
	{
		Node_of_Port_station* temp=search_Node_by_key(key);
		temp->plug->tree.push(data);
	
    }
	void store_data_Display(int key)
	{
		Node_of_Port_station* temp = search_Node_by_key(key);
		temp->plug->tree.printPreOrder();

	}



};

//#######################################################################################################################################
//########################################################################################################################################
//####################################################################################################################################################
/*struct Machine
{
	string machine_name;
	short machine_key=0;
	MyDS tree;
	string file_name;


};
string array_machine_name[] = { "kalam","Bahrain","Madyan","tehsil","shin","matta","Buner","kabal","Mingora","sambat","acheray","khwazakhela","charbagh","odigram","shangla","dir","margozar","balogram","kozabandai","barabandai" };
short array_machine_name_flags[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
short array_machine_keys[] = { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100 };
short array_machine_keys_flags[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
*/
Machine* create_machine(int i_argument,string machine_n)
{
	Machine* temp = new Machine;
	temp->machine_key = i_argument;
	temp->machine_name =machine_n;
	
	


	/*
	code here
	temp->machine_name
	*/


	return temp;

}
Machine* create_machine(int i_argument)
{
	Machine* temp = new Machine;
	temp->machine_key = i_argument;
	char ans;
	
		temp->machine_name = hashfunc(i_argument);

	

	/*
	code here
	temp->machine_name
	*/


	return temp;

}
void circular_port_station::machine_Display(int key_argument)
{
	Node_of_Port_station* temp = search_Node_by_key(key_argument);
	if (temp->status)
	{
		cout << "\nMachine key        Machine name  \n";
		
		cout << temp->plug->machine_key <<"                 ";
		cout <<temp->plug->machine_name <<endl;
	}
	else
	{
		cout << "\nThier is no machine on this port\n";
	}


}
void circular_port_station::add_machine_to_plug()
{
	
	Node_of_Port_station* temp2 = head;
	cout << "\nAll these plugs are avalible to attach a machine : \n";
	for (int i = 0; i < number_of_Ports; i++)
	{
		if (temp2->status == false)
		{
			cout << temp2->key << " ";
		}
		temp2 = temp2->next;

	}
	cout << endl;
	short temp_key=(rand()%((number_of_Ports-1)-0+1))+0;
	Node_of_Port_station* temp3 = search_Node_by_key(temp_key);
	while (temp3->status)
	{
		temp_key = (rand() % ((number_of_Ports - 1) - 0 + 1)) + 0;
		temp3 = search_Node_by_key(temp_key);

	}
	
	temp3->status = true;
	Machine* temp1 = create_machine(temp_key);
	number_of_Hubs = number_of_Hubs + 1;
	temp3->plug = temp1;



}


void circular_port_station::add_machine_to_plug(int key,string machine_name)
{


	Node_of_Port_station* temp3 = search_Node_by_key(key);
	temp3->status = true;
	Machine* temp1 = create_machine(key,machine_name);
	number_of_Hubs = number_of_Hubs + 1;
	temp3->plug = temp1;



}
//############################################################################################
//###################################################################################################
//#####################################################################################################
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//8888888888888888888888888888888 my circular port station 888888888888888888my circular port station 888888888888888888 my circular port station
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888



void circular_port_station::Display()
{
	if (head == NULL)
	{
		cout << "\nempty\n";
	}
	else
	{
		Node_of_Port_station* temp = head;
		Node_of_Port_station* temp2 = head->next;
		if (temp2 == temp)
		{
			cout << temp->data << "  " << temp->key_in_binary << "  " << temp->status << endl;
		}
		else
		{

			temp2 = head;
			while (temp2->next != head)
			{
				cout << temp2->data << "  " << temp2->key_in_binary << "  " << temp2->status << endl;
				temp2 = temp2->next;


			}
			cout << temp2->data << "  " << temp2->key_in_binary << "  " << temp2->status << endl;
		}

	}

}
void circular_port_station::set_the_number_of_ports_at_station()
{
	for (int i = 0; i < number_of_Ports; i++)
	{
		creator_and_addAtEnd(i);
	}
}

void circular_port_station::change_the_number_of_ports_at_station()
{
	//getting the last node
	Node_of_Port_station* last = getLastNode();
	int temp_key = last->key;
	for (int i = temp_key + 1; i < number_of_Ports; i++)
	{
		creator_and_addAtEnd(i);
	}


}
bool circular_port_station::get_Port_status(short int key_argument)
{
	if (key_argument >= number_of_Ports)
	{
		cout << "such key does not exist\n";
		return false;
	}
	Node_of_Port_station* ptr = head;
	while (ptr != getLastNode())
	{
		if (ptr->key == key_argument)
		{
			return ptr->status;
		}
		ptr = ptr->next;
	}


}
bool circular_port_station::change_key_status(short int key_argument, bool status_argument)
{
	if (key_argument >= number_of_Ports)
	{
		cout << "such key does not exist............\n";
		return false;
	}

	Node_of_Port_station* ptr = head;
	while (ptr != getLastNode())
	{
		if (ptr->key == key_argument)
		{
			ptr->status = status_argument;
			return true;
		}
		ptr = ptr->next;
	}
	return false;

}
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
	temp->key = data_argument;
	temp->key_in_binary = convertDecimal_to_Binary(data_argument);
	temp->status = false;
	temp->plug = NULL;
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
Node_of_Port_station* circular_port_station::search_Node_by_key(int key_argument)
{
	if (key_argument >= number_of_Ports)
	{
		return NULL;
	}
	else
	{
		Node_of_Port_station* ptr = head;
		while (ptr->key != key_argument)
		{
			ptr = ptr->next;
		}
		return ptr;
	}



}
bool circular_port_station::deleteNode_by_key(int x)
{
	//searching the Node with data x
	Node_of_Port_station* n = search_Node_by_key(x);
	if (n == NULL)
	{
		return false;
	}
	Node_of_Port_station* ptr = NULL;
	Node_of_Port_station* ptr2 = getLastNode();

	if (head == n && head->next == head)
	{
		delete head;
		head = NULL;
		return true;
	}
	else if (head == n)
	{
		ptr = head->next;
		ptr2->next = ptr;
		delete head;
		head = ptr;
		return true;
	}
	else
	{
		ptr = head;
		while (ptr->next != n)
		{
			ptr = ptr->next;
		}
		ptr->next = n->next;
		delete n;
		return true;
	}
}


//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

int main()
{

	cout << "Enter number of Ports that the circular line of database should have (bit wise system):  ";
	cin >> system_bits;
	if (system_bits < 12)
		number_of_Ports = static_cast<short>(pow(2, system_bits));
	else
		number_of_Ports = system_bits;
    circular_port_station my_test;
	my_test.set_the_number_of_ports_at_station();
	system("CLS");
    my_test.Display();
	cout << "Enter number of machine to add : ";
	cin >> number_of_machines;
	for (int i = 0; i < number_of_machines; i++)
	{
		char choice;
		cout << "Do you want to enter machine name for machine " << i << "y/n  :  ";
		cin >> choice;
		if(choice=='y'||choice=='Y')
		{
			string temp;
			cin.ignore();
			cout << "Enter machine name : ";
			getline(cin, temp);
			my_test.add_machine_to_plug(i, temp);
		}
		else
		{
			my_test.add_machine_to_plug();
		}
		
			
			
		
	}
    
	

	
	my_test.Display();
	
	my_test.machine_Display(1);
	//my_test.store_data(1, "saad");
	cout << endl;
	//my_test.store_data_Display(1);

}
