#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
	if (a.length() == b.length())return a < b; //길이가 같다면 사전순
	else return a.length() < b.length();		//다른다면 짧은 순
}

string word[20000];

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> word[i];
	
	sort(word, word + N, cmp);

	for (int i = 0; i < N; i++)
	{
		if (word[i] == word[i - 1]) continue;
		cout << word[i] << "\n";
	}
}
