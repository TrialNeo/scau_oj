#include <iostream>
using namespace std;

#define WHITE_COW 1;
#define BLOCK_COW 2;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned n =0,num_white_cow = 0;
    cin >> n;


    char *cow_group = new char[n]();
    for(size_t i =0;i<n;i++){
        cin >> cow_group[i];
        if(cow_group[i] == WHITE_COW){
            num_white_cow++;
        }
    }

    //假设把前面的全部变白后面全部变黑,等下对调过来
    int *prefix_white = new char[n](); //前面全部变白的前缀
    int *prefix_black = new char[n](); //后边全部变黑的前缀 下一次做一个交换
    for(size_t i = 0;i< n;i++){


    }

    delete []cow_group;
}
