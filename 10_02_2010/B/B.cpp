#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

string get( int i, int j, string s )
{
	string ret = "";

	while( i <= j )
	{
		ret += s[i];
		i++;
	}

	return ret;
}

int main()
{
	string s;
	while( getline( cin, s ) )
	{
		istringstream iss( s );
		string val, s = "";
		while( iss >> val )
			s += val;

		map <int, vector <string> > strs;
		map <string, int> counts;

		for( int i = 0; i < s.size(); i++ )
			for( int j = 0; j < s.size(); j++ )
			{
				string t = get( i, j, s );
				if( t != ""  && t != s )
				{
					strs[t.size()].push_back( t );
					counts[t]++;
				}
			}

		map <int, int> freq;
		map <int, vector <string> >::iterator si = strs.begin();
		string maxs;
		int max_l;

		while( si != strs.end() )
		{
			vector <string>::iterator i = strs[si->first].begin();
			max_l = 0;

			while( i != strs[si->first].end() )
			{
				max_l = max( max_l, counts[*i] );
				i++;
			}

			if( max_l > 1 ) cout << max_l << endl;
			si++;
		}
		cout << endl;

	}

	return 0;
}
