#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int c1, int c2) {
   int l = c1, r = c2;
   int n = s.length();

   while (l >= 0 && r <= n-1 && s[l] == s[r]) { //中心点向两侧扫描判断是否对称
		l--;
		r++;
   }
   return s.substr(l+1, r-l-1);
}

string longestPalindromeSimple(string s) {

   int n = s.length();

   if (n == 0) return "" ;
   
   string longest = s.substr(0, 1);  // a single char itself is a palindrome
  
   for ( int i = 0; i < n-1; i++) {
     string p1 = expandAroundCenter(s, i, i); //判断奇数类型，如bab；
     
	 if (p1.length() > longest.length())
       longest = p1;
     
	 string p2 = expandAroundCenter(s, i, i+1); //判断偶数类型，如cbaabc;
     
	 if (p2.length() > longest.length())
       longest = p2;
   }
   return longest;
}

int main()
{
	string str;
	while (cin >> str){
		cout << longestPalindromeSimple(str) << endl;
	
	}
	return 0;
}
