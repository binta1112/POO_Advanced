#pragma once
#include "pch.h"
#include <iostream>
#include<stdexcept>
using namespace std;
class Expression
{
private:
	string exp;
public:
	Expression(string expr);
	bool isValidExp();
    float Evaluation();
private:
    int Signe(char opt);
    int Priority(char opt);
    float Calcul(float op1, float op2, char opt);
    void Evaluate(Stack<float>* pile_oprd, Stack<char>* pile_oprt);
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

inline float Expression::Evaluation()
{
    Stack<float> stack_oprd;//pile d'operande
    Stack<char> stack_oprt;//pile d'operateur
    int dernier=0,//cette variable pour indiquer le niveau dans l'expression
        sign=1,//pour la gestion de signe des operandes
        quotient=10;
    float nbr = 0.0;
    char car;
    //if (!this->isValidExp()) throw logic_error("Expression invalide");

    for (int i = 0; i < this->exp.length(); i++)
    {
        car = this->exp[i];
        if (car == ' ') continue;//ignorer les blancs

        /*Si on rencontre un chiffre*/
        if (isdigit(car))
        {
            //si le dernier caractere etait aussi un chiffre => c'est donc la continuité
            if (dernier == 1)
            {
                                
                nbr = stack_oprd.Pop()*(float)quotient + (float)(car - '0');
            }
            else nbr = (float)(car - '0');

            nbr *= (float)sign;
            stack_oprd.Push(nbr);
            dernier = 1;//marque que le dernier caracter de l'expression est un chiffre*
            continue;
        }

        if ((car == '+') || (car == '-') || (car == '*') || (car == '/'))
        {
            /*si le dernier caractere est un operateur ou ( ou [ ou { => il s'agit d'un signe d'operande*/
            if ((dernier == 3) || (dernier == 2)) sign = this->Signe(car);
            /**/ 
            else
            {
                try
                {
                    stack_oprt.isEmpty();
                    char opt = stack_oprt.Pop();
                    
                    
                    if (Priority(opt) >= Priority(car))
                    {
                        float oprd2 = stack_oprd.Pop();
                        float oprd1 = stack_oprd.Pop();
                        nbr = Calcul(oprd1, oprd2, opt);
                        stack_oprd.Push(nbr);
                    }
                    else stack_oprt.Push(opt);
                }
                catch (const std::exception&)
                {

                }
            }
           
            stack_oprt.Push(car);
            dernier = 2;//marque que le dernier caracter de l'expression est un operateur

            continue;
        }
       
        /*si on rencontre un '(,[,{'*/
        if ((car == '(') || (car == '[') || (car == '{'))
        {
            /*si le dernier est un nombre on evalue l sous-expression precedente*/
            if (dernier == 1)
            {
                Evaluate(&stack_oprd, &stack_oprt);
                /*Si il n y pas d'operateur on considere comme un multiplication*/
                stack_oprt.Push('*');
            }
            stack_oprt.Push(car);

            dernier = 3;
            continue;
        }

        /*Si on rencontre une parenhese fermante on evalue l'expression contenue dns la parenthese*/
        if ((car == ')') || (car == '}') || (car == ']'))
        {
           
            Evaluate(&stack_oprd, &stack_oprt);
            continue;
        }
    }
    /*On evalue le reste de l'expression*/
    Evaluate(&stack_oprd, &stack_oprt);
   
    return stack_oprd.Pop();
}

inline int Expression::Signe(char opt)
{
    int sign = 1;
    if (opt == '-') sign = -1;
    return sign;
}

inline int Expression::Priority(char opt)
{
    int p = -1;
    switch (opt)
    {
    case'-': p = 1; break;
    case'+': p = 1; break;
    case'*': p = 2; break;
    case'/': p = 2; break;
    default:
        break;
    }
    return p;
}

inline float Expression::Calcul(float op1, float op2, char opt)
{
    float result = 0.0;
    switch (opt)
    {
    case '+': result = op1 + op2; break;
    case '-': result = op1 - op2; break;
    case '*': result = op1 * op2; break;
    case '/': if (op2 == 0) throw runtime_error("Erreur:Division par 0"); 
              result = op1 / op2; break;
    default:
        break;
    }
    return result;
}
/*
* Cette methode fait l'evaluation partielle en se servant d'une pile d'operande
* et d'une pile d'operateur
*/
inline void Expression::Evaluate(Stack<float>* pile_oprd, Stack<char>* pile_oprt)
 {
    float result = 0.0,oprd1,oprd2;
    char car;
    try
    {
        while (!pile_oprt->isEmpty())
        {
            car = pile_oprt->Pop();//depiler l'operateur en tete 
            if ((car == '(') || (car == '[') || (car == '{')) break;
            oprd2 = pile_oprd->Pop();
            oprd1 = pile_oprd->Pop();
            result = Calcul(oprd1, oprd2, car);
            pile_oprd->Push(result);
        }
    }
    catch (const std::runtime_error e)
    {
        
    }
    
}
