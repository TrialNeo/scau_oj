#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


bool cmp(const vector<int> &x, const vector<int> &y) { return !(x[0] > y[0] || x[0] == y[0] && x[1] > y[1]); }

int main(int argc, char const *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned m, n, i;
    cin >> m >> n >> i;
    unsigned row, col;
    vector<vector<int>> matrix;

    for (size_t j = 0; j < i; j++) {
        vector<int> item(3);
        cin >> item[0] >> item[1] >> item[2];
        swap(item[0], item[1]);
        matrix.push_back(item);
    }
    sort(matrix.begin(), matrix.end(), cmp);


    for (int j = 0; j < i; j++) {
        cout << matrix[j][0] << ' ' << matrix[j][1] << ' ' << matrix[j][2] << '\n';
    }


    return 0;
}
