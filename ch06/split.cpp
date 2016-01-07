#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy the characters in [i, j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }

    return ret;
}

int main() {
    string input = "mary had a little lamb";
    vector<string> split_str = split(input);
    for (vector<string>::size_type i = 0; i != split_str.size(); ++i)
        cout << split_str[i] << endl;
    return 0;
}
