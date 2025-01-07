#include <iostream>
#include <string>

using namespace std;
int main()
{
	string A, B, C;
	int iResult = 0, cResult = 0;

	cin >> A >> B >> C;
	
	iResult = (stoi(A) + stoi(B)) - stoi(C);
	cResult = (stoi(A + B) - stoi(C));

	cout << iResult << '\n';
	cout << cResult;

	return 0;
}