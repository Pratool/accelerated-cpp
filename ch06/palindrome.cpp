#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

string is_not(const string& s) {
    return is_palindrome(s) ? " " : " not ";
}

int main() {
    string samp01 = "rotor";
    string samp02 = "pratool";
    cout << samp01 << " is" << is_not(samp01) << "a palindrome" << endl;
    cout << samp02 << " is" << is_not(samp02) << "a palindrome" << endl;
    return 0;
}
