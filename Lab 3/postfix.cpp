#include<iostream>
#include <string>
#include<stack>
using namespace std;

class Parse
{
public:

    double item;
    void enterSentinel(string *a)
    {
        (*a)[(*a).length()] = ')';
    }

    int isOperand(char operand)
    {
        if (operand >= 0x0030 && operand <= 0x0039)   
        {
            return 1;
        }
        else if (operand == ' ')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    double postToConvert(string pre)
    {
        enterSentinel(&pre);
        stack<double> s;

        int flagPost = 0;
        double x, y, resultant;

        for (int i = 0; pre[i] != ')'; i++)
        {
            int answer = isOperand(pre[i]);
            if (answer == 1)
            {
                item = pre[i] - '0'; 
                s.push(item);
            }
            else if (answer == 0)
            {
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();

                switch (pre[i])
                {
                case '+':
                    resultant = y + x;
                    break;
                case '-':
                    resultant = y - x;
                    break;
                case '*':
                    resultant = y * x;
                    break;
                case '/':
                    resultant = y / x;
                    break;
                default:
                    cout << "Sorry, " << pre[i] << " is not an operator.\n";
                    flagPost = 1;
                }
                if (flagPost == 1)
                    break;
                item = resultant;
                s.push(item);
            }
        }
        if (flagPost == 0)
        {
            double returnRes = s.top();
            return returnRes;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Parse parseVar;
    string str;
    cout << "Enter an expression: ";
    getline(cin, str);

    double answer = parseVar.postToConvert(str);
    cout << "Resultant: " << answer << endl;

}