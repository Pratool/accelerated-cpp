/* 
 * Optimized version of finding the number of distinct words in a file.
 * Takes O(n) time
 */
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string x;
    std::map<std::string, int> freq;
    cout << "Enter words separated by spaces (EOF to stop):\n";
    while (cin >> x)
        freq[x]++;
    typedef std::map<std::string, int>::iterator iter;
    iter end = freq.end();
    int words = 0;
    int unique_words = 0;
    for (iter it = freq.begin(); it != end; ++it) {
        unique_words++;
        words += it->second;
    }
    cout << "words: " << words << endl;
    cout << "unique words: " << unique_words << endl;

    return 0;
}
