#include "DHT.h"


int main() {
//TEST main
hashtb H;
H.Insert(333,5);
H.Insert(333,7);
cout << H.SearchKey(333)<<endl;
cout << H.SearchKey(334) << endl;


    return 0;
}