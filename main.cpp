#include "DHT.h"

int main(){
srand(time(NULL));  
//initialization
bool manuallyassgn=false;
int key;
machine_node* curm;
string dt,choiceof;
cout <<"Enter number of machines you want" << endl;
cin >> nmachiness;
cout << "Enter number of bits you want for each machine" << endl;
cin >> system_bits;
number_of_Ports = static_cast<short>(pow(2, system_bits));
cout <<"Do you wanna manually assign ID's to the machines?    Y/N"<<endl;
cin >> choiceof;

if(choiceof=="Y" || choiceof=="y"){
manuallyassgn= true;}
Machines L;
if(manuallyassgn==false){
for(int i=i+1;i<nmachiness+1;i++){
	L.create_machine(i);
}}
else{
	for(int i=i+1;i<nmachiness+1;i++){
		int tempint;
		cout <<"Enter Machine ID for machine # " << i<<" :: ";
		cin >> tempint;
		L.create_machine(tempint);
	}
}

L.display_machines();
//
bool menu = true;
int choice;
m_id = 1;
while(menu){
cout <<" \n \n \n Active Machine :: " << m_id<< endl;
cout <<"\t\t MENU" << endl;
cout<<"Enter Accordingly" << endl;
cout<<"1- To insert a value" << endl;
cout<<"2- To get a value" << endl;
cout<<"4- Display All ports of a machine" << endl;
cout<<"5- Display Active ports of a machine" << endl;
cout<<"6- Show all Machines Active ports" << endl;
cout<<"7- Display all machines" << endl;
cout<<"8- Add new machine" << endl;
cout<<"9- Delete a machine" << endl;
cout<<"10- To exit" << endl;
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
	disp_all(L);
	break;

	case 5:
	disp_active(L);
	break;

	case 6:
	allm_disp_active(L,nmachiness);
	break;

	case 7:
	displayallmachines(L);
	break;

	case 8:
	addnewmachine(L);
	break;

	case 9:
	deletemachine(L);
	break;

	case 10:
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