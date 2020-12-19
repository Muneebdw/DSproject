#include <time.h>
#include <iostream>
using namespace std;
#include <string>

string char_arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int number_of_Ports = 16;
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



int main(){
    srand(time(NULL));  

for(int i=0;i<10;i++){
   cout <<  hashfunc(i)<<endl;
}

return 0;

}