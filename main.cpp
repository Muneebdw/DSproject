#include "Machinesll.h"


int main(){

int nmachiness,key,m_id;
string dt;
cout <<"Enter number of machines you want" << endl;
cin >> nmachiness;
cout << "Enter number of bits you want for each machine" << endl;
cin >> system_bits;
number_of_Ports = static_cast<short>(pow(2, system_bits));
Machines L;
for(int i=i+1;i<nmachiness+1;i++){
	L.create_machine(i);
}

L.display_machines();
cout <<"In which machine would you like to insert a key" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);

cout <<"Enter key" << endl;
cin >> key;
cout <<"Enter value" << endl;
cin >> dt;
m->HT.insertin(key,dt);

m->HT.Displayactive();
cout << m->HT.get(3);

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