#include "Machinesll.h"


int main(){
	cout << "Enter number of Ports that the circular line of database should have (bit wise system):  ";
	cin >> system_bits;
	number_of_Ports = static_cast<short>(pow(2, system_bits));
	cout << "\n" << number_of_Ports << endl;
	keys_tree my1;
	my1.Display();
	my1.change_key_status(2, true);
	my1.Display();
	cout<<endl<<my1.get_Port_status(2);
	cout << "update the number of ports :";
	cin >> system_bits;
	number_of_Ports = static_cast<short>(pow(2, system_bits));
	my1.Extend_the_Ports_keys_array();
	my1.Display();
	cout << "Enter number of Hubs that the system has :  ";
	cin >> number_of_Hubs;
	cout << "hello world\n";


	cout << "hello world\n";
	Machines my_test;

	my_test.creator_and_addAtEnd(1);
	my_test.creator_and_addAtEnd(2);
	my_test.creator_and_addAtEnd(3);

	Machine_node* my3 = my_test.Port_station_node_creator(4);
	my_test.addAtEnd_new_Node(my3);
	my3 = my_test.Port_station_node_creator(5);
	my_test.addAtEnd_new_Node(my3);
	my_test.Display();
	cout << endl << my_test.search(4);
	Machine_node* my2 = my_test.search(5);
	cout << my2->data;
	cout << "\nhello world";

    return 0;
}