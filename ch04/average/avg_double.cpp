#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> numbers;
    double x, tot = 0.0, el_num = 0.0;
    while (cin >> x)
        numbers.push_back(x);
    /*for (vector<double>::size_type i = 0; i != numbers.size(); ++i) {
        tot += numbers[i];
        ++el_num;
    }*/
    vector<double>::size_type i = 0;
    while (i != numbers.size())
        tot += numbers[i++];

    cout << tot/i << endl;

    return 0;
}
