#include<bits/stdc++.h>
using namespace std;
void printfirst(){
    cout << "first" << endl;
}
void first(std::function<void()> printfirst){
    printfirst();
}

int main(){
    first(&printfirst);
    return 0;
}