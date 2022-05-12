#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <climits>

using namespace std;

string RED = "\033[1;31m";
string GREEN = "\033[1;32m";
string BLUE = "\033[1;36m";
string END = "\033[0m";

/*
    调试输出
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v) {
    if(v.size() > 20) {
        return END +  "[hidden] data is too long" + BLUE;
    }
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
            if(typeid(x) == typeid(vector<int>)) res += "\n";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}


void debug_out() {
    cerr << END << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << BLUE << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


template <typename T>
bool compare_result(string sample_name, T &my_ans, T &answer) {
    bool equal = (my_ans == answer);
    if (!equal) {
        cerr << sample_name << ": \t" << RED << " Wrong Answer" << END << endl;
        debug(my_ans);
        debug(answer);
    } else {
        cerr << sample_name << ": \t" << GREEN << " Accepted" << END << endl;
    }
    return equal;
}