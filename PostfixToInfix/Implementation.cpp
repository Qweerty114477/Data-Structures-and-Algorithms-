#include<bits/stdc++.h>
using namespace std;
 string postfixtoinfix(string s){
    int i=0;
    stack<string>st;
    while(i<s.size()){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string ans="("+s2+s[i]+s1+")";
            st.push(ans);
        }
        i++;
    }
    return st.top();
 }
int main(){
    string postfix = "ab+c*";
    
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression:   " << postfixtoinfix(postfix) << endl;
    return 0;
}
