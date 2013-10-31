#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	string s;
	map <string, bool> mapping;
	vector <string> good;

	while( cin >> s )
		mapping[s] = true;

	map <string, bool>::iterator m = mapping.begin();

	while( m != mapping.end() )
	{
		string ret = "";
		string rev = m->first;
		string s = rev;
	
		for( int i = 0; i < s.size() - 1; i++ )
		{
			ret += s[i];
			rev.erase( rev.begin() );

			if( mapping[ret] != false && mapping[rev] != false && mapping[ret + rev] != false )
			{
				if( good.size() > 0 )
				{
					if( good[good.size() - 1] != ret+rev )
						good.push_back( ret + rev );
				}
				else good.push_back( ret + rev );
			}
		}

		m++;
	}
	
	sort( good.begin(), good.end() );

	vector <string>::iterator it = good.begin();
	while( it != good.end() )
	{
		cout << *it << endl;
		it++;
	}

	return 0;
}
