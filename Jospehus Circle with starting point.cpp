#include<iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter starting point: ";
    cin >> k;
    int result = josephus(n, k);
    cout << "The last person standing is at position: " << result << endl;
    return 0;
}
