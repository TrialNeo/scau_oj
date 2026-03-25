#include <iostream>
using namespace std;

int main(){
    //这还是第一个0-1背包
    unsigned n = 0;
    cin >> n;
    unsigned flags[200001] ={false};  //这里也有个坑，0<=n<=200000，一共是200001个数字
    unsigned in = 0,count = 0;

    for(size_t i =0;i<n;i++){
        cin >> in;
        if(!flags[in]){
            count ++;
            flags[in] = true;
        }
    }

    cout << count;

    return 0;
}
