#include "Machinesll.h"

void insertat(Machines L){
int m_id, key;
string dt;
cout <<"In which machine would you like to insert a key" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);

cout <<"Enter key" << endl;
cin >> key;
cout <<"Enter value" << endl;
cin >> dt;
m->HT.insertin(key,dt);
m->HT.writetofile(m->filepath,key,dt);

}

void disp_active(Machines L){
int m_id;
cout <<"In which machine would you like to show active ports" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);
m->HT.Displayactive();
}

string get(Machines L){
int key;
cout <<"Enter key to search for" << endl;
cin >> key;
string t =  L.search_all(key);
return t;
}

int main(){
srand(time(NULL));  
//initialization
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
//
bool menu = true;
int choice;
while(menu){
cout <<"\t\t MENU" << endl;
cout<<"Enter Accordingly" << endl;
cout<<"1- To insert a value" << endl;
cout<<"2- To get a value" << endl;
cout<<"5- Display Active ports of a machine" << endl;
cout<<"9- To exit" << endl;
cout<<"--------------" << endl;
cin >> choice;
string ptemp;
switch(choice){
	case 1:
	insertat(L);
	break;

	case 2:	
	ptemp = get(L);
	cout << "Value at key = " << ptemp << endl;
	break;

	case 3:
	break;

	case 4:
	break;

	case 5:
	disp_active(L);

	break;

	case 6:
	break;

	case 9:
	menu = false;
	break;
}
}



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