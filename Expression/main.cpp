#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;


double compute(const string &expression);
double operate(double a1,char op,double a2);
double todouble(string expression,int &cpos);
int getPriority(char op);

int main(int argc,char *argv[]){
    string expression;
    cin>>expression;
    double result= compute(expression);
    cout<<result<<endl;
    return 0;
}


double compute(const string &expression){
    stack<char> OPTR; OPTR.push('#');//操作符号栈operator
    stack<double> OPND;//操作数栈operand
//    cout<<expression[1]<<endl;
    int cpos=0,len=expression.length();//cpos 字符位置
    bool is_minus=true;//是不是负号
    while (cpos<len){//当字符位置小于表达式长度的时候
        //1.判断负号
        if(expression[cpos]=='-'&&is_minus){//如果说当前的这个符号是'-'且当前负号记录为真就执行0-这个数
            OPND.push(0);//使用0来减去一个数表示负数
            OPTR.push('-');
            cpos++;
        }
        //2.判断左括号'('
        else if(expression[cpos]=='('){
            is_minus=true;//注:括号相当于是一组新的数据，需要优先计算，所以要把是否为负号置位true
            OPTR.push(expression[cpos]);//把当前表达式压入栈
            cpos++;
        }
        //3.判断右边括号
        else if(expression[cpos]==')'){//弹出括号中所有操作，保存计算值
            is_minus=false;
            cpos++;//字符串指针向后移动

            while(OPTR.top()!='('){
                double a2=OPND.top();
                OPND.pop();
                double a1=OPND.top();
                OPND.pop();
                char op=OPTR.top();
                OPTR.pop();
                double result=operate(a1,op,a2);
                OPND.push(result);//保存括号结果
            }
            OPTR.pop();//弹出左边括号
        }
        //4.判断数字并且将数字保存下来
        else if(expression[cpos]>='0'&&expression[cpos]<='9'){
            is_minus=false;
            OPND.push(todouble(expression,cpos));
        }
        //5.判断+ - * /
        else{
            //最新插入的符号的优先级小于等于符号栈top的话就将优先级高的全部弹出来计算掉,然后保存结果
            while(getPriority(expression[cpos])<=getPriority(OPTR.top())){
                double a2=OPND.top();OPND.pop();
                double a1=OPND.top();OPND.pop();
                char op=OPTR.top();OPTR.pop();

                double result=operate(a1,op,a2);
                OPND.push(result);
            }
            OPTR.push(expression[cpos]);
            cpos++;
        }
    }
    //清算栈中的数值和计算符
    while(OPTR.top()!='#'){
        double a2=OPND.top();OPND.pop();
        double a1=OPND.top();OPND.pop();
        char op=OPTR.top();OPTR.pop();

        double result=operate(a1,op,a2);
        OPND.push(result);
    }
    return OPND.top();
}

double operate(double a1,char op,double a2){
    switch(op){
        case '-':
            return a1-a2;
        case '+':
            return a1+a2;
        case '*':
            return a1*a2;
        case '/':
            return a1/a2;
    }
}

double todouble(string expression,int &cpos){//字符串转double
    int i=cpos;
    while((expression[i]>='0'&&expression[i]<='9')||expression[i]=='.') i++;//找到第二个不是数字的位置
    string sub=expression.substr(cpos,i-cpos);//截取字符串
    stringstream ss(sub);//创建字符串流
    double res;
    ss>>res;//转换为double
    cpos=i;
    return res;
}

int getPriority(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        case '#':
            return -1;
    }
}