#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
class Expression
{
private:
	string exp;
public:
	Expression(string expr);
	bool isValidExp();
};

Expression::Expression(string expr) :exp(expr)
{}

inline bool Expression::isValidExp()
{
    int not_in_stck = 0, last = 0;
    bool esp = false;
    Stack<char>Mapile;
    for (int i = 0; i < this->exp.length(); i++)
    {
        if (this->exp[i] == ' ')
        {
            esp = true;
            continue;
        }
        /*********************************************************/

        if (isdigit(this->exp[i]))
        {
            if ((last == 1 || last == 4) && esp)  return false;
            not_in_stck = last = 1;
            esp = false;
            continue;
        }
        /*********************************************************/

        if (this->exp[i] == '*' || this->exp[i] == '/')
        {
            if (last != 1 && last != 4) return false;
            not_in_stck = last = 2;
            esp = false;
            continue;
        }
        /*********************************************************/

        if (this->exp[i] == '+' || this->exp[i] == '-')
        {
            not_in_stck = last = 2;
            esp = false;
            continue;
        }
        /*********************************************************/
        if (this->exp[i] == '(' || this->exp[i] == '[' || this->exp[i] == '{')
        {
            Mapile.Push(this->exp[i]);
            last = 3;
            esp = false;
            continue;
        }
        /*********************************************************/


        if (this->exp[i] == ')' || this->exp[i] == ']' || this->exp[i] == '}')
        {
            try
            {
                Mapile.isEmpty();
                char car = Mapile.Pop();
                last = 4;
                esp = false;
                if ((car - this->exp[i]) > 3 || (car - this->exp[i]) < -3) return false;
            }
            catch (underflow_error e)
            {
                return false;
            }

            continue;
        }

    }
    if (not_in_stck == 2) return false;
    try
    {
        Mapile.isEmpty();
        return false;
    }
    catch (underflow_error e)
    {
        return true;
    }
    return true;
}
