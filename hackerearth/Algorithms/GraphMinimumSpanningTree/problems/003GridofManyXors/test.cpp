#include<iostream>
using namespace std;
struct pt{
    int x,y;
    pt(int x,int y){
        this->x=x;
        this->y = y;
    }
    friend bool operator==(pt a,pt b){
        return ((a.x == b.x) & (a.y == b.y));
    }
    friend ostream& operator<<(ostream& os,const pt &a){
        os << a.x << " " << a.y;
        return os;
    }
};
int main(){
    pt a(2, 3);
    pt b(3, 4);
    cout << (a == b) << endl;
    return 0;
}