#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,S,P,Q;
    int mod = 1 << 31;
    cin >> N >> S >> P >> Q;
    
    vector<int> hares(N + 1);
    hares[0] = S % mod;
    int ih = 0, it = 1, count = 0;
    
    while(it < N){
        ih += 2;
        
        if(ih <= N){
            hares[ih - 1] = (hares[ih - 2] * P + Q) % mod;
            hares[ih] = (hares[ih - 1] * P + Q) % mod;
            
            if(hares[ih] == hares[it++]){
                break;
            }
        }else{
            it = N + 1; 
            break;
        }
    }
    
    cout << it - 1;
    
    return 0;
}
