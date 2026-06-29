#include<bits/stdc++.h>
using namespace std;
string prefixtoinfix(string s){
    int i=s.size();
    i--;
    stack<string>st;
    while(i>=0){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string ans="("+s1+s[i]+s2+")";
            st.push(ans);
        }
        i--;
    }
    return st.top();
}
int main(){
    string prefix = "*+abc"; // Equivalent to (a+b)*c
    
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression:  " << prefixtoinfix(prefix) << endl;
    return 0;
}