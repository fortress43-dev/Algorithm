#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int d = n/4;
    if(n%4 != 0)d++;
    
    for(int i = 0; i < d; i++){
        cout<<"long ";
    }
    cout<<"int";
    
}