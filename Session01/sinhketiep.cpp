#include <bits/stdc++.h>

using namespace std;

void next(string s){
	int length = s.length();
	int i = length - 1;
	while(i>=0 && s[i] == '1'){
		s[i] = '0';
		i--;
	} 
	
//	Khi bit thu i chua phai bit cuoi cung 
	if( i!= -1){
		s[i] = '1';
	}
	cout << s << endl;
}


 
int main(){
	string str;
	cin >> str;
	next(str);

	return 0;
}

