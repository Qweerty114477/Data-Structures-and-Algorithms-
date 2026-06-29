#include<bits/stdc++.h>
using namespace std;
string prefixtopostfix(string s){
    stack<string>st;
    int i=s.size()-1;
    while(i>=0){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string ans=s1+s2+s[i];
            st.push(ans);
        }
        i--;
    }
    return st.top();
}
int main(){
    string prefix = "*+AB-CD";
    cout << "Prefix:  " << prefix << endl;
    cout << "Postfix: " << prefixtopostfix(prefix) << endl;
    return 0;
}