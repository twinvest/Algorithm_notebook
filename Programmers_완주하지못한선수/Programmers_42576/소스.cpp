#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<string> participant;
vector<string> completion;

string solution(vector<string> participant, vector<string> completion) 
{ 
	sort(participant.begin(), participant.end()); 
	sort(completion.begin(), completion.end()); 
	for (int i = 0; i < completion.size(); ++i) 
	{
		if (participant[i] != completion[i]) 
		{ 
			return participant[i]; 
		} 
	} 
	return participant[participant.size() - 1]; 
}
int main()
{
	participant.push_back("tw1");
	participant.push_back("tw2");
	participant.push_back("tw3");
	
	completion.push_back("tw1");
	completion.push_back("tw2");
	string ans = solution(participant, completion);
	cout << ans << endl;

}