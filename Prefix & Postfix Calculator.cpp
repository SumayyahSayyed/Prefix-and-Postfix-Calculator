#include <iostream>
#include <stack> // For push & pop functions
#include <algorithm>
using namespace std;

void Welcome();
// Boolean function for Operator, Operand, Equal_High and the string conversion functions.
bool Operator(char);
bool Operand(char);
bool Equal_High(char, char);
string Postfix_Convert(string);
string Prefix_Convert(string);

int main()
{
    string infix_expression, postfix_expression, prefix_expression;
    stack<char> stack;
    char again = '\0';

    Welcome();

    do
    {
        int digit = 0, alpha = 0;
        do
        {

            if (digit != 0 && alpha != 0)
            {
                cout << endl
                     << endl;
                cout << "           ------------ The expression should have either Alphabets or Numbers ------------" << endl;
                cout << endl
                     << "                            ------------ Enter again -------------" << endl;
            }
            digit = 0;
            alpha = 0;
            cout << endl
                 << endl
                 << endl;
            cout << "Enter an INFIX Expression = ";
            cin >> infix_expression;

            for (int i = 0; i < infix_expression.length(); i++)
            {
                // check for alphabets
                if (isalpha(infix_expression[i]) != 0)
                {
                    alpha++;
                }
                // check for numbers
                if (isdigit(infix_expression[i]) != 0)
                {
                    digit++;
                }
            }

            while (infix_expression.length() < 3)
            {
                cout << endl
                     << endl;
                cout << "           ------------ The expression should have a minimum length of 3 ------------" << endl;
                cout << endl
                     << "                            ------------ Enter again -------------" << endl;
                cout << endl
                     << endl;
                cout << "Enter an INFIX Expression = ";
                cin >> infix_expression;
            }
        } while (digit != 0 && alpha != 0);

        cout << endl
             << endl
             << endl;

        cout << "\t \tConvert the Infix Expression to = " << endl
             << endl;
        cout << "\t \t \t 1. POSTFIX Expression" << endl;
        cout << "\t \t \t 2. PREFIX Expression" << endl;

        int ch;
        cout << endl
             << endl
             << "\t                                     Enter your choice = ";
        cin >> ch;
        cout << endl
             << endl;

        while (!(ch == 1 || ch == 2)) // if Choice is incorrect
        {

            cout << endl;
            cout << "                                       ------------ Wrong Input! ------------" << endl;
            cout << "                                       ------------ Enter again -------------" << endl;
            cout << endl
                 << endl
                 << "\t                                     Enter your choice = ";
            cin >> ch;
        }

        switch (ch)
        {
        case 1:
            postfix_expression = Postfix_Convert(infix_expression);
            cout << "\t \t \t \t      ----------------------------------------------" << endl;
            cout << "\t \t \t \t         INFIX Expression is = " << infix_expression << endl;
            cout << "\t \t \t \t         POSTFIX Expression is = " << postfix_expression << endl;
            cout << "\t \t \t \t      ----------------------------------------------" << endl;
            break;
        case 2:
            prefix_expression = Prefix_Convert(infix_expression);
            cout << "\t \t \t \t      ----------------------------------------------" << endl;
            cout << "\t \t \t \t         INFIX Expression is = " << infix_expression << endl;
            cout << "\t \t \t \t         PREFIX Expression is = " << prefix_expression << endl;
            cout << "\t \t \t \t      ----------------------------------------------" << endl;
            break;
        }

        again = '\0';
        cout << endl
             << endl
             << "\t \t \t \t \t     Go to Main Menu? [Y/N] = ";
        cin >> again;
        while ((again != 'y') && (again != 'Y') && (again != 'n') && (again != 'N'))
        {
            cout << endl
                 << endl
                 << "\t \t \t \t \t     Invalid Input!" << endl;
            cout << "\t \t \t \t \t     Go to Main Menu? [Y/N] = ";
            cin >> again;
        }
    } while (again == 'y' || again == 'Y');
    system("cls");
    if ((again == 'n') || (again == 'N'))
    {
        cout << endl;
        cout << "        ------------------------------------------------------------------------------------------------------" << endl;
        cout << "########################################################################################################################" << endl;
        cout << "########################################################################################################################" << endl;
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        cout << "                               ********************************************************" << endl
             << endl;
        cout << "                                                        THANK YOU!" << endl;
        cout << "                                               HOPE YOU LIKED the CALCULATOR :) " << endl
             << endl;
        cout << "                                                   COME BACK ANY TIME :)" << endl
             << endl;
        cout << "                               ********************************************************" << endl;
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        cout << "########################################################################################################################" << endl;
        cout << "########################################################################################################################" << endl;
        cout << "        ------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    return 0;
}

void Welcome() // Welcome Screen
{
    cout << endl;
    cout << "        ------------------------------------------------------------------------------------------------------" << endl;
    cout << "########################################################################################################################" << endl;
    cout << "########################################################################################################################" << endl;
    cout << endl
         << endl
         << endl;
    cout << "                               *********************************************************" << endl
         << endl
         << endl;
    cout << "                                                    WELCOME TO" << endl;
    cout << "                                        INFIX TO POSTFIX & INFIX TO PREFIX" << endl;
    cout << "                                                    CALCULATOR" << endl;
    cout << endl
         << endl;
    cout << "                               *********************************************************" << endl;
    cout << endl;
    cout << "Project made by = " << endl;
    cout << "    *Sumayyah Sayyed   " << endl;
    cout << "########################################################################################################################" << endl;
    cout << "########################################################################################################################" << endl;
    cout << "        ------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

// Operator() function to determine whether any symbol is operator.
bool Operator(char c)
{
    // If the symbol is an operator, it returns true, otherwise false.
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Operand() function is used to determine whether the character is an operand.
bool Operand(char c)
{
    // Defines the character in between A to Z. If not, it returns False.
    if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    // Defines the character in between a to z. If not, it returns False.
    else if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    // Defines the character in between 0 to 9. If not, it returns False.
    else if (c >= '0' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Precedence() function is used to define the precedence to the operator.
int Precedence(char op)
{
    // Defines the lowest precedence.
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    // exponent operator has the highest precedence.
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
// The Equal_High() function is used to check the higher or equal precedence.
bool Equal_High(char op1, char op2)
{
    int p1 = Precedence(op1);
    int p2 = Precedence(op2);
    if (p1 == p2)
    {
        if (op1 == '^')
            return false;
        return true;
    }
    else
    {
        // condition ? result1 : result2
        // If condition is true, the entire expression evaluates to result1, and otherwise to result2.
        return (p1 > p2 ? true : false);
    }
}
// Postfix_Convert() function is used to convert the infix expression to the postfix expression of the Stack.
string Postfix_Convert(string infix)
{
    stack<char> S;
    string postfix = "";
    char ch;

    S.push('(');
    infix += ')';

    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];
        if (ch == ' ')
        {
            continue;
        }
        else if (ch == '(')
        {
            S.push(ch);
        }
        else if (Operand(ch))
        {
            postfix += ch;
        }
        else if (Operator(ch))
        {
            while (!S.empty() && Equal_High(S.top(), ch))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(ch);
        }
        else if (ch == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    return postfix;
}

// Prefix_Convert() function is used to convert the infix expression to the prefix expression of the Stack.
string Prefix_Convert(string infix)
{
    /*  Reverse String
        Replace '(' with ')' and vice versa
        Get Postfix
        Reverse Postfix   */
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = Postfix_Convert(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}