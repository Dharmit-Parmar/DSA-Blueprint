#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
    char para[30];
    char index = -1;

public:
    void push(char a)
    {
        if (index == 30)
        {
            cout << "stack is overflow" << endl;
            return;
        }
        para[++index] = a;
    }

    char pop()
    {
        if (index < 0)
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        return para[--index];
    }
    char top()
    {
        return para[index];
    }

    int check_para(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (ispara(s[i]) == 1)
            {
                cout << "is pushed" << s[i] << endl;

                push(s[i]);
                continue;
            }
            else if (ispara(s[i]) == 2)
            {
                if (ismatch(top(), s[i]) == 1)
                {
                    cout << "is popped" << top() << endl;

                    cout << "is poped " << pop() << endl;
                    continue;
                }
                else
                {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "invalid" << endl;
                return 0;
            }
        }
        return 1;
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
    int ispara(char a)
    {
        if (a == '(' || a == '{' || a == '[')
        {
            return 1;
        }
        else if (a == ')' || a == '}' || a == ']')
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Stack s;
    cout << (s.check_para("({[(]})")) << endl;
    cout << (s.check_para("({[]})")) << endl;

    return 0;
}
