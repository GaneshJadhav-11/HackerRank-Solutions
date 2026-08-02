#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int main() {
    int Q;
    cin >> Q;

    set<int> s;

    while (Q--) {
        int y, x;
        cin >> y >> x;

        if (y == 1) {
            s.insert(x);
        }
        else if (y == 2) {
            s.erase(x);
        }
        else {
            if (s.find(x) != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }  
    return 0;
}



