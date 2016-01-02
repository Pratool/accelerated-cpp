#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string x;
    vector<string> words;
    cout << "Enter words separated by spaces (EOF to stop):\n";
    while (cin >> x)
        words.push_back(x);
    cout << words.size() << endl;
    int num_unique = 0;
    for (int i = 0; i < words.size(); i++) {
        bool is_unique = true;
        for (int j = i+1; j < words.size(); j++) {
            if (words[i] == words[j]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique)
            num_unique++;
    }

    cout << endl << num_unique << endl;

    return 0;
}
