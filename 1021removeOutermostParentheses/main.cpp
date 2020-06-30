#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        //当遍历到'('时flag + 1, 遍历到')'时，flag - 1，则当flag == 0时，是有效括号字符串
        //当flag > 1时，即夹在最外层（）中间的字符串
        int flag = 0;
        for (int i = 0; i < S.size(); i ++){
            if (S[i] == '('){
                flag ++;
            }
            if (flag > 1){
                res += S[i];
            }
            if (S[i] == ')'){
                flag --;
            }
        }
        return res;
    }

    string removeOuterParentheses1(string S) {
        stack<char> s;
        string res;
        int left = 0, right = 1;
	//当栈为空时，'('与')'数量相等，且为有效括号字符串，排除最外层括号，即可得到中间的字符串
        for (int i = 0; i < S.size(); i ++){
            if (S[i] == '('){
                s.push(S[i]);
            }else{
                s.pop();
            }
            if (s.empty()){
                left = left + 1;
                right = i - 1;
                res += S.substr(left, right - left + 1);
                if (i + 1 < S.size()){
                    left = i + 1;
                }
            }
        }
        return res;
    }
};
