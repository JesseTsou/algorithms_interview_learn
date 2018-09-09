#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 遍历容器，将数字存储在栈中，遇到操作符，则取出栈顶两个元素进行操作，然后将结果再压入栈中
     * 最后栈中的栈顶元素即最终的结果
     * 注意 字符串与int的转换
     */
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        stack<int> stack1;
        int num1 = 0;
        int num2 = 0;
        int res = 0;
        for (auto e:tokens){
            if (e == "+" || e == "-" || e == "*" || e == "/" ){
                if (stack1.size() < 2)
                    continue;
                num2 = stack1.top();
                stack1.pop();
                num1 = stack1.top();
                stack1.pop();
                if (e == "+")
                    res = num1 + num2;
                if (e == "-")
                    res = num1 - num2;
                if (e == "*")
                    res = num1 * num2;
                if (e == "/")
                    res = num1 / num2;
                stack1.push(res);
            } else{
                stack1.push(stoi(e));
            }
        }
        return stack1.top();
    }
};

int print(vector<string> vec)
{
    for (auto e:vec)
        cout << e << "";
    cout << endl;

    return 0;
}

int print(int val)
{
    cout << "res: " << val << endl;

    return 0;
}

int main() {
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("1");
    vec.push_back("+");
    vec.push_back("3");
    vec.push_back("*");

    print(vec);

    Solution s;
    int var = s.evalRPN(vec);
    print(var);

    return 0;
}