#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    v.erase(v.begin()+(x-1));
    int a,b;
    cin>>a>>b;
    v.erase(v.begin()+(a-1),v.begin()+(b-1));
    N=v.size();
    cout<<N<<endl;
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
