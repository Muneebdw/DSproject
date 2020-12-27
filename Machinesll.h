#include "Keystree.h"
#include "AVL.h"
struct machine_node
{
	keys_tree HT;
    int info;
    struct machine_node *next;
    string filepath;
    MyDS AVLT;
}*last;
 

class Machines
{private:
int machine_count=1;
    public:
        void create_machine(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_machines(int value);
        void search_machine(int value);
        string search_all(int key);
        string search_all2(int key);
        string delete_key(int key);
		machine_node* get_machine(int value);
        void display_machines();
        void update();
        void sort();
        
        Machines()
        {
            last = NULL;           
        }
};

void Machines::create_machine(int value)
{
	
    struct machine_node *temp;
    temp = new(struct machine_node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
	//Updates no of ports in each new machine added
		keys_tree T1;
		last->HT = T1;
    //creates file
        last->filepath = "./Machinesres/m" +to_string(machine_count) + "Data.txt";
        std::ofstream outfile (last->filepath);
        outfile.close();
        machine_count++;
}

void Machines::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create a machine list."<<endl;
        return;
    }
    struct machine_node *temp;
    temp = new(struct machine_node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}
 

void Machines::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create a machine list."<<endl;
        return;
    }
    struct machine_node *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<"Machines in the list"<<endl;
            return;
        }
    }
    temp = new(struct machine_node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;
    if (s == last)
    { 
        last=temp;
    }
}

void Machines::delete_machines(int value)
{
    struct machine_node *temp, *s;
    s = last->next;
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value)  
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {
      
        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Machine "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }

    if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    cout<<"Machine "<<value<<" not found in the Machine list"<<endl;
}
 

void Machines::search_machine(int value)
{
    struct machine_node *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)    
        {
            cout<<"Machine "<<value; 
            cout<<" found at position "<<counter<<endl;
            return;
        }
        s = s->next;
    }
    if (s->info == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Machine "<<value<<" not found in the Machines list"<<endl;
}
machine_node* Machines::get_machine(int value)
{
    struct machine_node *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)    
        {
            //cout<<"Machine "<<value; 
            //cout<<" found at position "<<counter<<endl;
            return s;
        }
        s = s->next;
    }
    if (s->info == value)    
    {
        counter++;
		return s;             
    }
    cout<<"Machine "<<value<<" not found in Machines list"<<endl;
	return NULL;
}
void Machines::display_machines()
{
    struct machine_node *s;
    if (last == NULL)
    {
        cout<<"No Machines Present"<<endl;
        return;
    }
    s = last->next;
    cout<<"Machines "<<endl;
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}
 

void Machines::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        cout<<"No machines present"<<endl;
        return;
    }
    cout<<"Enter the machine ID";
    cin>>pos;
    cout<<"Enter the new Machine ID";
    cin>>value;
    struct machine_node *s;
    s = last->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == last)
        {
            cout<<"There are less than "<<pos<<" Machines.";
            cout<<endl;
            return;
        }
        s = s->next;
    }
    s->info = value;  
    cout<<"machine_node Updated"<<endl;
} 

void Machines::sort()
{
    struct machine_node *s, *ptr;
    int temp;
    if (last == NULL) 
    {
        cout<<"No machines present to sort"<<endl;
        return;
    }
    s = last->next;
    while (s != last)
    {
        ptr = s->next;
        while (ptr != last->next)
        {
            if (ptr != last->next)
            {
                if (s->info > ptr->info)
                {
                    temp = s->info;
                    s->info = ptr->info;
                    ptr->info = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;    
        }
        s = s->next;         
    }
}

string Machines::search_all(int key){
bool found;
string tf,dt="";
int mkey;

for(int i=1;i<machine_count;i++){
    machine_node* t = this->get_machine(i);
    tf=t->HT.get(key);
    if(tf!=""){
    found=true;
    mkey = machine_count;
    dt = tf;
    }
}
if(found==true){
//cout <<"Key found at machine # " << mkey<<endl;
return dt;
}
else{
    cout <<"Key doesnt exist anywhere" << endl;
}
    return "";
}

string Machines::search_all2(int key){
bool found;
string tf,dt="";
int mkey;

for(int i=1;i<machine_count;i++){
    machine_node* t = this->get_machine(i);
    tf=t->HT.get(key);
    if(tf!=""){
    found=true;
    mkey = machine_count;
    dt = tf;
    }
}
if(found==true){
return dt;
}
else{
    cout <<"Key doesnt exist anywhere" << endl;
}
    return "";
}

string Machines::delete_key(int key){
bool found=false;
string tf,dt="";
int mkey;
tf = "";
tf= this->search_all2(key);
cout <<"Value at deleted key : " << tf << endl;
tf = "";

for(int i=1;i<machine_count;i++){bool temp;
    machine_node* t = this->get_machine(i);
    t->AVLT.search(t->HT.get(key));
    temp=t->HT.deletekey(key);
    tf=tf+ "Machine " + to_string(i) +" -->";
    if(temp==true){
        found = temp;
        dt = tf;
        dt = dt + "Key found";
        temp = false;
        mkey = i;
        cout <<"UPDATED AVL TREE :: ";
        t->AVLT.printPreOrder();
        cout << endl;
    }
}
if(found==true){
    cout <<"Request PATH : ";
    return dt;
}
else
{
    return "Key not found";
}

}
