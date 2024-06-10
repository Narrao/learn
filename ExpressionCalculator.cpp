//
// Created by Cayloger on 2023/10/12.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class calculater {
private:
    string formula;  //表达式
    stack<double> num_stack;  //数字栈
    stack<char> op_stack;  //操作符栈
    char ch;  //当前字符
    map<char, int> op_priority;   //操作符优先级
public:
    calculater(string s){  //构造函数
        formula = s;
        op_priority['+'] = 1;
        op_priority['-'] = 1;
        op_priority['*'] = 2;
        op_priority['/'] = 2;
        op_priority['('] = 0;
        op_priority[')'] = 0;
        op_priority['%'] = 1;
        op_priority['='] = -1;
        op_stack.push('=');

        if(formula[formula.length()-1]!='=')
        formula += '=';

        //处理负数
        if (formula[0] == '-') {
            formula.insert(0, "0");
        }

        for (int i = 0; i < formula.length(); i++) {
            if (formula[i] == '-' && (i == 0 || formula[i - 1] == '(')) {
                formula.insert(i, "0");
            }
        }
    }

    //判断是否为操作符
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=';
    }

    //判断是否为数字
    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    //计算某一项结果
    double getResult(double a, double b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '%':
                return (int) a % (int) b;
            default:
                return a / b;
        }
    }

    //计算结果
    double calculate(){
        for (int i = 0; i < formula.length(); i++) {
            ch = formula[i];

            //读取数字并入栈
            if (isNumber(ch)) {
                double num = 0;
                bool isFloat = false;
                while (isNumber(ch)||ch=='.') {
                    if (ch == '.') {
                        isFloat = true;
                        ch = formula[++i];
                        continue;
                    }
                    if (isFloat) {
                        num += (ch - '0') / 10.0;
                    } else {
                        num = num * 10 + ch - '0';
                    }
                    ch = formula[++i];
                }
                i--;
                num_stack.push(num);
            } else if (isOperator(ch)) {    //读取操作符并计算
                if (ch == '(') {
                    op_stack.push(ch);
                } else if (ch == ')') {
                    while (op_stack.top() != '(') {
                        char op = op_stack.top();
                        op_stack.pop();
                        double b = num_stack.top();
                        num_stack.pop();
                        double a = num_stack.top();
                        num_stack.pop();
                        num_stack.push(getResult(a, b, op));
                    }
                    op_stack.pop();
                } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
                    while (op_priority[ch] <= op_priority[op_stack.top()]) {
                        char op = op_stack.top();
                        op_stack.pop();
                        double b = num_stack.top();
                        num_stack.pop();
                        double a = num_stack.top();
                        num_stack.pop();
                        num_stack.push(getResult(a, b, op));
                    }
                    op_stack.push(ch);
                } else if (ch == '=') {
                    while (op_stack.top() != '=') {
                        char op = op_stack.top();
                        op_stack.pop();
                        double b = num_stack.top();
                        num_stack.pop();
                        double a = num_stack.top();
                        num_stack.pop();
                        num_stack.push(getResult(a, b, op));
                    }
                }
            }
        }
        return num_stack.top();
    }
};

int main() {
    string s1 = "1.5+2.3*3-4/5";
    string s2 = "-1-2*(-3+4)-5*6";
    string s3 = "1+2*(3+4*(5+6*(7+8*(9+10))))";
    string s4 = "-2*2+(3+4)*5";
    calculater c1=calculater(s1);
    calculater c2=calculater(s2);
    calculater c3=calculater(s3);
    calculater c4=calculater(s4);
    cout<<s1<<"="<<c1.calculate()<<endl;
    cout<<s2<<"="<<c2.calculate()<<endl;
    cout<<s3<<"="<<c3.calculate()<<endl;
    cout<<s4<<"="<<c4.calculate()<<endl;

    system("pause");
    return 0;
}
