#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool not_url_char(char c) {
    // characters, in addition to alphanumerics, that can appear in a URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    return !(isalnum(c) ||
            find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the separator isn't at the beginning or end of the URL
        if (i != b && i + sep.size() != e) {
            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character before and after ://
            if (beg !=i && !not_url_char(i[sep.size()]))
                    return beg;
        }

        // the separator we found wasn't part of a URL advance i past ://
        i += sep.size();
    }
    return e;
}

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
            iter after = url_end(b, e);

            // remember the URL
            ret.push_back(string(b, after));

            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}

int main() {
    string test_url = "what the heck is http://www.google.com ?";
    vector<string> all_urls = find_urls(test_url);
    for (vector<string>::size_type i = 0; i != all_urls.size(); ++i)
        cout << all_urls[i] << endl;
    return 0;
}
