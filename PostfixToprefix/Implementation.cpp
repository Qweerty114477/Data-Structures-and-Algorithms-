#include<bits/stdc++.h>
using namespace std;
string postfixtoprefix(string s){
    stack<string>st;
    int i=0;
    while(i<s.size()){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string ans=s[i]+s2+s1;
            st.push(ans);
        }
        i++;
    }
    return st.top();
}
int main(){
    string postfix = "ab+c*"; 
    
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression:  " << postfixtoprefix(postfix) << endl;
    return 0;
}