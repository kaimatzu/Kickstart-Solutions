#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define arr array
#define vect vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for(auto& x: a)

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template <typename T> void read(T &t) {
    cin >> t;
}

template<typename H, typename... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}

template<class A> void read(vect<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}

string to_string(vect<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) {
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

bool check(int a, int b, int c) {
    if (b - a == c - b)
        return true;
    else
        return false;
}

void solve() {
    int r0_c0, r0_c1, r0_c2;
    int r1_c0, r1_c2;
    int r2_c0, r2_c1, r2_c2;
    read(r0_c0, r0_c1, r0_c2);
    read(r1_c0, r1_c2);
    read(r2_c1, r2_c1, r2_c2);

    int count_of_valid = 0;

    if(check(r0_c0, r0_c1, r0_c2) == true) {count_of_valid++;}
    if(check(r0_c0, r1_c0, r2_c0) == true) {count_of_valid++;}
    if(check(r2_c0, r2_c1, r2_c2) == true) {count_of_valid++;}
    if(check(r0_c2, r1_c2, r2_c2) == true) {count_of_valid++;}

    int maximum = 0;
    for(int i = 0; i <= 9; i++){
        int ct = 0;
        if(check(r0_c0, i, r2_c2) == true)
            ct++;
        if(check(r0_c2, i, r2_c0) == true)
            ct++;
        if(check(r0_c1, i, r2_c1) == true)
            ct++;
        if(check(r1_c0, i, r1_c2) == true)
            ct++;

        if(ct >= maximum)
            maximum = ct;
    }
    int ans = maximum + count_of_valid;
    write(count_of_valid);
}

int main() {

    int t = 1;
    read(t);
    FOR(t) {
        write("Case #", i + 1, ": ");
        solve();
    }
}
