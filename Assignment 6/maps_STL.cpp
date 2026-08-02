#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int Q;
    cin >> Q;

    map<string, int> m;

    while (Q--) {
        int type;
        cin >> type;

        string name;
        cin >> name;

        if (type == 1) {
            int marks;
            cin >> marks;
            m[name] += marks;
        }
        else if (type == 2) {
            m.erase(name);
        }
        else if (type == 3) {
            cout << m[name] << endl;
        }
    }
   
    return 0;
}



