#include "Machinesll.h"
int m_id;
string path;
int nmachiness;
void displayallmachines(Machines L){
L.display_machines();
}

void removek(Machines L){
    int k;
cout <<"Enter key to delete" << endl;
cin >>k;
cout <<L.delete_key(k) << endl;
}

void printavl(Machines L){
    int m;
    cout <<"Enter machine for which you want to print AVL Tree" << endl;
cin >> m;
machine_node* mac = L.get_machine(m);
mac->AVLT.printPreOrder();
cout << endl;
}

void addnewmachine(Machines L){
int n;
cout <<"Enter machine ID to add" << endl;
cin >> n;
L.add_after(n,nmachiness);
nmachiness++;
}

void deletemachine(Machines L){
    int n;
cout <<"Enter machine ID to delete" << endl;
cin >> n ;
L.delete_machines(n);
nmachiness--;
}
void addpath(){
path = "Machine  " + to_string(m_id)+"--->Acessing HUB ---> Machines portal ---> Machine ";
}

void insertat(Machines L){
int key;
string dt;
addpath();
cout <<"In which machine would you like to insert a key" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);
path= path + to_string(m_id);
cout <<"Enter key" << endl;
cin >> key;
cout <<"Enter value" << endl;
cin >> dt;
m->HT.insertin(key,dt);
m->HT.writetofile(m->filepath,key,dt);
m->AVLT.push(dt);
cout <<" PATH FOR insertion = " << path << endl;
string chc;
cout <<"Do you wanna print AVL Tree for machine # " << m_id << " ?       Y/N ";
cin >> chc;
if(chc=="Y"||chc=="y"){
    m->AVLT.printPreOrder();
}

}


void disp_active(Machines L){
int m_id;
cout <<"In which machine would you like to show active ports" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);
m->HT.Displayactive();
}

void disp_all(Machines L){
int m_id;
cout <<"In which machine would you like to show all the ports" << endl;
cin >> m_id;
machine_node* m = L.get_machine(m_id);
m->HT.Displayall();
}

void allm_disp_active(Machines L,int n){
for(int i=1;i<n+1;i++){
cout <<"Active ports for Machine # " << i << endl;
machine_node* m = L.get_machine(i);
m->HT.Displayactive();cout << "\n";
}
}

string get(Machines L){
int key;
cout <<"Enter key to search for" << endl;
cin >> key;
string t =  L.search_all(key);
return t;
}
