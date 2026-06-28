#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    int ans;
    if(ch=='^') ans=3;
    else if(ch=='*'||ch=='/') ans=2;
    else if(ch=='+'||ch=='-') ans=1;
    else return -1;
    return ans;
}
string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    int i=0;
    string ans="";
        stack<int>st;
    while(i<s.size()){
        
        if(isalnum(s[i])){
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
        else {
            while(!st.empty()&&((precedence(s[i])<precedence(st.top()))||(precedence(s[i])==precedence(st.top())&&s[i]!='^'))){
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string exp1 = "A+B*C";
    cout << "Infix:  " << exp1 << endl;
    cout << "Prefix: " << infixToPrefix(exp1) << "\n" << endl; 
    // Output: +A*BC

    // Example 2: Complex expression with parentheses and exponents
    string exp2 = "((a+b)*(c-d)/(e+f^g)-h)*(i+j/(k-l*m))^(n-o+p)";
    cout << "Infix:  " << exp2 << endl;
    cout << "Prefix: " << infixToPrefix(exp2) << endl;
    return 0;
}