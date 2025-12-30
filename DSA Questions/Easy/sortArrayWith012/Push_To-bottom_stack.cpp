#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Stack
{
    vector<int>stk;
    public:
    void push(int a)
    {
        stk.push_back(a);
    }
    int pop()
    {
        if(!stk.empty())
        {

            int a = stk[stk.size() -1];
            stk.pop_back();
            return a;
        }
        return -1;
    }

    void pushToBottom(int a)
    {
        if(stk.empty())
        {
            stk.push_back(a);
            return;
        }
        int temp = pop();
        pushToBottom(a);
        push(temp);
    }
    void display()
    {
        for(int i=0;i<stk.size();i++)
        {
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pushToBottom(0);
    s.display();

    return 0;
}
