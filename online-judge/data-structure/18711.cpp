#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);


    unsigned n = 0;
    cin >> n;
    char * buffer = new char[n]();

    //还是经典的0-1背包，不管了反正没有限制空间复杂度。
    bool flags[255] = {false};
    char in = 0;



    for(size_t i = 0;i<n;i++){
        cin >> in;
        flags[in] = true;
    }

    for(size_t i = 0;i<255;i++){
        if(flags[i]){
            cout << (char)i;
        }
    }
    cout << endl;
    delete []buffer;
    return 0;
}
