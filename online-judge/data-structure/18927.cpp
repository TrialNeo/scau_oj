#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    unsigned n = 0,m = 0;
    cin >> n;
    long *series = new long[n]();
    cin >> series[0];


    for(size_t i = 1;i < n;i++){
        cin >> series[i];
        series[i] += series[i-1];
    }

    cin >> m;

    long L =0,R = 0;
    for(size_t i = 0;i < m;i++){
        cin >> L;
        cin >> R;
        cout << series[R]-series[L-1] << '\n';
    }


    delete []series;
    return 0;
}
