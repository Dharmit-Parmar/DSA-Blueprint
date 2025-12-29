#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
class Stack
{
    vector<char> elements;
    string result;

public:
    void push(char a)
    {
        elements.push_back(a);
    }
    char pop()
    {
        if (elements.empty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        char topElement = elements.back();
        elements.pop_back();
        return topElement;
    }
    char top()
    {
        if (elements.empty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return elements.back();
    }

    int isPara(char c)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            return 1;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            return 2;
        }
        return 0;
    }

    int ismatch(char a, char b)
    {
        if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    string InfixToPostfix(string s)
    {
        for (char c : s)
        {
            if (isPara(c) == 1)
            {
                push(c);
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                result += c;
            }
            else if (isPara(c) == 2)
            {
                while (!elements.empty() && !ismatch(top(), c))
                {
                    result += top();
                    pop();
                }
                if (!elements.empty())
                {
                    pop();
                }
            }
            else
            {
                while (!elements.empty() && prec(c) <= prec(top()))
                {
                    result += top();
                    pop();
                }
                push(c);
            }
        }
        while (!elements.empty())
        {
            result += top();
            pop();
        }
        return result;
    }

    int evaluatePostfix(string s )
    {
        elements.clear();
        for (char c :s)
        {
            if(isdigit(c)){
                push(c-'0');
            }
            else{
                int val1 = top() ; pop();
                int val2 = top() ; pop();
                switch (c) {
                    case '+': push(val2 + val1); break;
                    case '-': push(val2 - val1); break; 
                    case '*': push(val2 * val1); break;
                    case '/': push(val2 / val1); break;
                    case '^': push(pow(val2, val1)); break;
                }
            }
        }
        return top();
    }
};

int main()
{
    Stack s;
    string c;
    string c2;
    cout << "give the niumber you want to calculate " << endl;
    cin >> c;
    c2 = s.InfixToPostfix(c);
    cout << c2 << endl;
    cout << s.evaluatePostfix(c2);


    return 0;
}