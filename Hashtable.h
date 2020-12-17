#include <iostream>
using namespace std;
struct dt{
int k;
int val;
dt(int t1,int t2){
    this->k = t1;
    this->val = t2;
}
};

class hashtb{
private:
int size=20;
dt **data = new dt* [size];
public:
hashtb(){
    for(int i=0;i<size;i++){
        data[i]=NULL;
        
    }
}
int hashf(int t){
    return t%size;
}

      
int SearchKey(int k) {
         int h = hashf(k);
         while (data[h] != NULL && data[h]->k != k) {
            h = hashf(h + 1);
         }
         if (data[h] == NULL)
            return -1;
         else
            return data[h]->val;
}
void Insert(int k,int v) {
    int res = this->SearchKey(k);
    if(res==-1){
         int h = hashf(k);
         while (data[h] != NULL && data[h]->k != k) {
            h = hashf(h + 1);
         }
         if (data[h] != NULL)
            delete data[h];
         data[h] = new dt(k,v);}

else
{k++;
    this->Insert( k,  v);
}
}
void Remove(int k) {
         int h = hashf(k);
         int cond;
         while (data[h] != NULL && data[h]->k != k) {
            h = hashf(h + 1);
         }
         if (data[h] == NULL)
            cond= -1;
         else
            cond= data[h]->val;

            if(cond==-1){
                cout<<"No value present at the key"<<endl;
            }
            else{
                delete data[h];
                cout<<"Element deleted"<<endl;
            }
}
};