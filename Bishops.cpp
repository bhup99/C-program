#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int carry = 0, n;
	while(!cin.eof())
	{
		string inp;
		cin >> inp;
		if(inp.length()<1) break;
		vector<int> useInp;
		carry = 0;
		if(inp[0] == '0' && inp.size()==1)
		{
			cout << "0" << endl;
			continue;
		}
		else if(inp[0] == '1' && inp.size() == 1)
		{
			cout << "1" << endl;
			continue;
		}
		for(int i = inp.size() - 1; i >=0; i--)
		{
			n = inp[i] - '0';
			n = n*2 + carry;
			useInp.push_back(n % 10);
			carry = n / 10;
		}
		useInp.push_back(carry);
		for(int j=0; j<2; j++)
		{
			int i=0;
			if(useInp[i] == 0)	{
				while(useInp[i] == 0)	{
					useInp[i] = 9;
					i++;
				}
				useInp[i]--;
			}
			else
			{
				useInp[0]--;
			}
		}
		int i=useInp.size()-1;
		while(useInp[i] == 0 && i>0)
			i--;
		for(; i >= 0; i--)
			cout << useInp[i];
		cout << endl;
	}
	return 0;
}