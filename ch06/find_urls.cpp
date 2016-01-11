#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through the entire input
    while (b != e) {
        // look for one or more letters followed by ://
        b = url_beg(b, e);

        // if we found it
        if (b != e) {
            // get the rest of the URL
            iter_after = url_end(b, e);

            // remember the URL
            ret.push_back(string(b, after));

            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}
