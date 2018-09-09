#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /*
     * 时间复杂度O(n)
     * 使用栈来存储左括号，遇到右括号则与栈顶元素（即最后入栈的左括号）对比。
     * 若匹配则弹出最后入栈的左括号
     * 最后匹配完，若是有效的括号，则栈为空
     */
    bool isValid(string s) {
        if (s.empty())
            return true;
        if (s.size() % 2 == 1)
            return false;

        stack<char> stack1;
        for (auto e:s){
            if (e == '(' || e == '{' || e == '[')
                stack1.push(e);
            else{
                if (stack1.empty())
                    return false;
                if (e == ')' && stack1.top() != '(')
                    return false;
                if (e == '}' && stack1.top() != '{')
                    return false;
                if (e == ']' && stack1.top() != '[')
                    return false;
                stack1.pop();
            }
        }

        if (stack1.size())
            return false;

        return true;
    }
};

int print(string str)
{
    cout << str << endl;

    return 0;
}

int main() {
    //string str = "()[]{}";
    string str = "(]";
    print(str);

    Solution s;
    if (s.isValid(str))
        print("is valid");
    else
        print("is not valid");

    return 0;
}