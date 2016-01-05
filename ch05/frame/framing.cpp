#include <iostream>
#include <string>
#include <vector>

using namespace std;

string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen+4, '*');

    // top border
    ret.push_back(border);

    // write each interior row bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        ret.push_back("* " + v[i] + string(maxlen-v[i].size(), ' ') + " *");

    // write the bottom border
    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct a new string to hold characters from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];

        // pad to full width
        s += string(width1-s.size(), ' ');

        // copy from right-hand side, if there is one
        if (j != right.size())
            s += right[j++];

        // add s to the picture we're creating
        ret.push_back(s);
    }

    return ret;
}

vector<string> frame_grid(const vector<string>& v, int width, int height) {
    vector<string> framed_v = frame(v);
    vector<string> horz = framed_v, ret;
    for (int i = 1; i != width; i++)
        horz = hcat(horz, framed_v);
    ret = horz;
    for (int i = 1; i != height; i++)
        ret = vcat(ret, horz);
    return ret;
}

int main() {
    vector<string> s, f;
    string x;
    int width, height;
    cin >> width >> height;
    while (cin >> x)
        s.push_back(x);
    f = frame_grid(s, width, height);
    for (vector<string>::size_type i = 0; i != f.size(); ++i)
        cout << f[i] << endl;

    return 0;
}
