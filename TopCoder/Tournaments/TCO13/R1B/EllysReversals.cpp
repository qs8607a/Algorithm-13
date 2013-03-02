// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE
int vv[55];

class EllysReversals {
public:
    int getMin(vector <string> words) {
		memset(vv, 0, sizeof(vv));
		int len = words.size();
		REP(i,len) {
			if (vv[i] == 1) continue;
			FOR(j,i+1,len-1) {
				if (vv[j] == 1) continue;
				if (isok(words[i], words[j])) {
					vv[i] = vv[j] = 1;
					break;
				}
			}
		}
        int res = 0;
		REP(i,len) {
			if (vv[i] == 0) ++res;
		}
        return res;
    }
	bool isok(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		int len = s1.length();
		if (len & 1) {
			if (s1[len - 1] != s2[len - 1]) return false;
			return isok(s1.substr(0, len - 1), s2.substr(0, len - 1));
		}
		vector<string> mm1, mm2;
		REP(i,s1.length()/2) {
			string str = s1.substr(i * 2, 2);
			sort(str.begin(), str.end());
			mm1.push_back(str);
			str = s2.substr(i * 2, 2);
			sort(str.begin(), str.end());
			mm2.push_back(str);
		}
		sort(mm1.begin(), mm1.end());
		sort(mm2.begin(), mm2.end());
		REP(i,mm1.size()) {
			if (mm1[i] != mm2[i]) return false;
		}
		return true;
	}
};
// BEGIN CUT HERE
int main() {
    {
        string wordsARRAY[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(0, theObject.getMin(words),3);
    }
    {
        string wordsARRAY[] = {"no", "zaphod", "just", "very", "improbable"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(1, theObject.getMin(words),5);
    }
    {
        string wordsARRAY[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(2, theObject.getMin(words),0);
    }
    {
        string wordsARRAY[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(3, theObject.getMin(words),1);
    }
    {
        string wordsARRAY[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
            "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
            "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
            "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
            "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(4, theObject.getMin(words),16);
    }
	{
        string wordsARRAY[] = {"topcoder", "redocpot", "topcoder", "doretopc", "cpotdoer", "harlemshake"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(3, theObject.getMin(words),2);
    }
	{
        string wordsARRAY[] = {"wendai"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(3, theObject.getMin(words),1);
    }
    return 0;
}
// END CUT HERE
