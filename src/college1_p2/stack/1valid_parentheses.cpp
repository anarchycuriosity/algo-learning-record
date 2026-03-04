/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
给定字符串 s 仅包含字符 '（'， '）'， '{'， '}'， '[' 和 ']''，判断输入字符串是否有效。

An input string is valid if:
输入字符串有效，满足以下条件：

Open brackets must be closed by the same type of brackets.
开放括号必须用同一种括号闭合。
Open brackets must be closed in the correct order.
开放括号必须按正确顺序关闭。
Every close bracket has a corresponding open bracket of the same type.
每个闭括号都有对应的同类型开括号。
 

Example 1:  示例1：

Input: s = "()"
Input：s = “（）”

Output: true
输出：true

Example 2:  示例2：

Input: s = "()[]{}"
Input：s = “（）[]{}”

Output: true
输出：true

Example 3:  示例3：

Input: s = "(]"
Input：s = “（]”

Output: false
输出： 错误

Example 4:  示例4：

Input: s = "([])"
Input：s = “（[]）”

Output: true
输出：true

Example 5:  示例5：

Input: s = "([)]"
Input：s = “（[）]”

Output: false
输出： 错误
*/
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        
    }
};