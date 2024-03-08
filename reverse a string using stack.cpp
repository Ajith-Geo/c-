#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str;
    string word;
    stack<string> stk;
    getline(cin,str);

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]!=' ')
        {
            word += str[i];
            if(i == str.length()-1)
            {
                stk.push(word);
                word.clear();
            }
        } 
        else
        {
            stk.push(word);
            word.clear();
        }
    }

    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}
