#include <bits/stdc++.h>
using namespace std;
int evaluate(int a, int b, char s) // function to calculate the expression
{
    switch (s)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
    return 0;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (auto it : tokens)
    {
        if (it != "+" && it != "-" && it != "*" && it != "/")
        {
            stringstream ss(it); // converts string to int
            int number = 0;
            ss >> number;
            st.push(number);
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            stringstream sc(it);
            char op;
            sc >> op;
            int result = evaluate(b, a, op);
            st.push(result);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return st.top();
}

int main()
{
    vector<string> s = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(s);
}