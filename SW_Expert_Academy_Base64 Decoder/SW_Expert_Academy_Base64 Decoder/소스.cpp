#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int buffer[24];
	string s = "Life itself is a quotation.";
	for (int i = 0; i < s.size(); ++i)
	{
		int index = 0;
		char tmp = s[i];
		
		while (tmp != 0)
		{
			if (tmp % 2 == 0)
			{
				buffer[index++] = 0;
				tmp /= 2;
			}
			else 
			{
				buffer[index++] = 1;
				tmp /= 2;
			}		
		}

	}
}