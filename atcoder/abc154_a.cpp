#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	int c,d;
	cin>>c>>d;
	string f;
	cin>>f;
	if(f == a) c--;
	else d--;
	cout<<c<<" "<<d<<endl;
	return 0;
}
