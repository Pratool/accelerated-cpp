#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::size_type i = 0; i != u.size(); ++i)
        cout << i << "\tu: " << u[i] << "\tv: " << v[i] << endl;

    return 0;
}
