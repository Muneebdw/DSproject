#include "Machinesll.h"


int main(){
system_bits = 4;
number_of_Ports = static_cast<short>(pow(2, system_bits));
Machines L;
L.create_machine(5);
L.create_machine(7);
L.create_machine(8);
L.create_machine(9);
L.display_machines();
machine_node* m = L.get_machine(5);
m->HT.Display();
	

    return 0;
}



	/*cout << "Enter number of Ports that the circular line of database should have (bit wise system):  ";
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
	cout << "hello world\n";*/