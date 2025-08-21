
#include "Date.h"
using namespace date;
int main() {
    int numRows = 0;
    cin >> numRows;

    vector<vector<int>> vv(numRows);
    for (size_t i = 0; i < numRows; i++) {
        vv[i].resize(i+1, 1);
    }
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 1; j < vv[i].size()-1; j++) {
            vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
        }
    }
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}