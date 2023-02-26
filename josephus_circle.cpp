#include <iostream>
#include <cmath>
using namespace std;

int powerof2(int n) {
    return floor(log2(n));
}

int main(){
    int n = 12;
    int josephusNo = n - pow(2, powerof2(n));
    josephusNo *= 2;
    josephusNo ++;
    cout<<"The person that remains in the end with a Josephus circle of "<<n<<" people is: "<<josephusNo<<endl;
    //cout<<pow(2, powerof2(n));
    return 0;
}
