#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
    int ans;
    if(ch=='^') ans=3;
    else if(ch=='*'||ch=='/') ans=2;
    else if(ch=='+'||ch=='-') ans=1;
    else return -1;
    return ans;
}
string InfixToPostfix(string s){
    string ans="";
    stack<char>st;
    int i=0;
    while(i<s.size()){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&&((priority(s[i])<priority(st.top()))||(priority(s[i])==priority(st.top())&&s[i]!='^'))){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s="((a+B)*(c-D)/(e+F^g)-H)*(i+J/(k-L*m))^(N-o+P)";
    cout<<InfixToPostfix(s)<<endl;
    return 0;
}