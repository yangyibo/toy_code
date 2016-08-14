#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
void pop_cal();
int p_Rank(char);
stack<char> opr_stk;
stack<double> num_stk;
 
int main(){
    string in_str;
    int i=0;
    bool num_flag=0;
    double x=0;
    cout<<"Please input the expression string:"<<endl;
    cin>>in_str;
    for(i=0;i<in_str.size();i++){
        if((in_str[i]>='0')&&(in_str[i]<='9')){
            x=x*10+in_str[i]-'0';
            num_flag=1;
            if(i==in_str.size()-1)
                num_stk.push(x);
        }
        else{
            if(x){
                num_stk.push(x);
                x=0;
                num_flag=0;
            }
            if(opr_stk.empty())
                opr_stk.push(in_str[i]);
            else if(in_str[i]=='(')
                opr_stk.push(in_str[i]);
            else if(in_str[i]==')')
            {
                while(opr_stk.top()!='(')
                    pop_cal();                
                opr_stk.pop();
            }
            else if(p_Rank(in_str[i])<=p_Rank(opr_stk.top()))
            {
                pop_cal();
                opr_stk.push(in_str[i]);
            }
            else{
                opr_stk.push(in_str[i]);
            }
        }
    }
    while(!opr_stk.empty())
        pop_cal();
    double res=num_stk.top();
    cout<<res<<endl;
}
 
void pop_cal()
{
    char op=opr_stk.top();
    double a,b,res;
    b=num_stk.top();
    num_stk.pop();
    a=num_stk.top();
    num_stk.pop();
    switch(op)
    {
        case '+':
            res=a+b;
            break;
        case '-':
            res=a-b;
            break;
        case '*':
            res=a*b;
            break;
        case '/':
            res=a/b;
            break;
        default:
            break;
    }
    num_stk.push(res);
    opr_stk.pop();
}
 
int p_Rank(char x)
{
    if(x=='(')
        return 0;
    else if(x=='+')
        return 1;
    else if(x=='-')
        return 2;
    else if(x=='*')
        return 3;
    else if(x=='/')
        return 4;
}