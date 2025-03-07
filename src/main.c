#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Push(Stack* stack, int data)
{
    stack->data[stack->top] = data;
    stack->top++;
}

int Pop(Stack* stack)
{
    stack->top--;
    int data = stack->data[stack->top];
    return data;
}
int Top(Stack* stack) { return stack->data[stack->top - 1]; }
void PushD(StackD* stack, double data)
{
    stack->data[stack->top] = data;
    stack->top++;
}
double PopD(StackD* stack)
{
    stack->top--;
    double data = stack->data[stack->top];
    return data;
}
double TopD(StackD* stack) { return stack->data[stack->top - 1]; }

int ResultD(Tuple** tuple)
{
    int i = 0;
    StackD* stack = (StackD*)malloc(sizeof(StackD));
    stack->top = 0;
    while (tuple[i]->type != 2) {
        if (tuple[i]->type == 0) {
            PushD(stack, tuple[i]->number);
        } else {
            switch (tuple[i]->operation) {
            case Add: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double right = PopD(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double left = PopD(stack);
                double temp = left + right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                PushD(stack, temp);
                break;
            }
            case Sub: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double right = PopD(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double left = PopD(stack);
                double temp = left - right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                PushD(stack, temp);
                break;
            }

            case Mult: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double right = PopD(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double left = PopD(stack);
                double temp = left * right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                PushD(stack, temp);
                break;
            }
            case Div: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double right = PopD(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                double left = PopD(stack);
                if (left * left < 0.0004 * 0.0004) {
                    printf("UB:Divider too small. README for help");
                    return -1;
                }
                double temp = left / right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                PushD(stack, temp);
                break;
            }
            default:
                break;
            }
        }
        i++;
    }
    if (stack->top > 1) {
        printf("Wrong input");
        return -1;
    }
    printf("%.4f", stack->data[0]);
    free(stack);
    return 0;
}
int Result(Tuple** tuple)
{
    int i = 0;
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = 0;
    while (tuple[i]->type != 2) {
        if (tuple[i]->type == 0) {
            Push(stack, tuple[i]->number);
        } else {
            switch (tuple[i]->operation) {
            case Add: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int right = Pop(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int left = Pop(stack);
                int temp = left + right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                Push(stack, temp);
                break;
            }
            case Sub: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int right = Pop(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int left = Pop(stack);
                int temp = left - right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                Push(stack, temp);
                break;
            }

            case Mult: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int right = Pop(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int left = Pop(stack);
                int temp = left * right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                Push(stack, temp);
                break;
            }
            case Div: {
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int right = Pop(stack);
                if (stack->top == 0) {
                    printf("Wrong input");
                    return -1;
                }
                int left = Pop(stack);
                if (left * left < 0.0004 * 0.0004) {
                    printf("UB:Divider too small. README for help");
                    return -1;
                }
                int temp = left / right;
                if (temp > 2000000000 || temp < -2000000000) {
                    printf("UB:Big number in operation. README for help");
                    return -1;
                }
                Push(stack, temp);
                break;
            }
            default:
                break;
            }
        }
        i++;
    }
    if (stack->top > 1) {
        printf("Wrong input");
        return -1;
    }
    printf("%d", stack->data[0]);
    free(stack);
    return 0;
}
Tuple* tuple[MAXSIZE];
Tuple** PRN(char* string)
{
    char c;
    int j = 0;
    //= (Tuple**)malloc(sizeof(Tuple*) * MAXSIZE);
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = 0;
    int number = 0;
    int isNum = 0;
    int isSign = 1;
    for (int i = 0; i < MAXSIZE; i++) {
        if (sizeof(stack) > MAXSIZE) {
            printf("UB: input more than 1KB. README for help");
            return NULL;
        }
        // printf("NEW\n");
        c = string[i];
        // printf("%c", c);
        if (c == EOF) //ИСПРАВИТЬ НА EOF
        {
            if (isSign == 1) {
                printf("Wrong input");
                return NULL;
            }
            if (isNum != 0) {
                Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                newTuple->type = 0;
                newTuple->number = number;
                tuple[j] = newTuple;
                j++;

                number = 0;
                isNum = 0;
                isSign = 0;
            }

            while (stack->top > 0) {
                int r = Pop(stack);
                if (r == OB) {
                    printf("Wrong input");
                    return NULL;
                }
                Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                newTuple->type = 1;
                newTuple->operation = (enum Lexem)r;
                tuple[j] = newTuple;
                j++;
            }
            Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
            newTuple->type = 2;
            newTuple->operation = END;
            tuple[j] = newTuple;
            j++;
            return tuple;
        }

        if (c >= '0' && c <= '9') {
            number = number * 10 + (c - 48);
            isNum = 1;
            isSign = 0;
        } else {
            if (isNum != 0) {
                if (number > 2000000000) {
                    printf("UB:Number too big. README file for help");
                }
                Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                newTuple->type = 0;
                newTuple->number = number;
                tuple[j] = newTuple;
                j++;

                number = 0;
                isNum = 0;
                isSign = 0;
            }

            switch (c) {
            case '+': {
                if (isSign == 1) {
                    printf("Wrong input");
                    return NULL;
                }
                while (Top(stack) == Add || Top(stack) == Sub || Top(stack) == Mult || Top(stack) == Div) {
                    enum Lexem op = (Lexem)Pop(stack);
                    Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                    newTuple->type = 1;
                    newTuple->operation = op;
                    tuple[j] = newTuple;
                    j++;
                }
                isSign = 1;
                Push(stack, Add);
                break;
            }
            case '-': {
                if (isSign == 1) {
                    printf("Wrong input");
                    return NULL;
                }
                while (Top(stack) == Add || Top(stack) == Sub || Top(stack) == Mult || Top(stack) == Div) {
                    enum Lexem op = (Lexem)Pop(stack);
                    Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                    newTuple->type = 1;
                    newTuple->operation = op;
                    tuple[j] = newTuple;
                    j++;
                }
                isSign = 1;
                Push(stack, Sub);
                break;
            }
            case '*': {
                if (isSign == 1) {
                    printf("Wrong input");
                    return NULL;
                }
                while (Top(stack) == Div || Top(stack) == Mult) {
                    enum Lexem op = (Lexem)Pop(stack);
                    Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                    newTuple->type = 1;
                    newTuple->operation = op;
                    tuple[j] = newTuple;
                    j++;
                }
                isSign = 1;
                Push(stack, Mult);
                break;
            }
            case '/': {
                if (isSign == 1) {
                    printf("Wrong input");
                    return NULL;
                }
                while (Top(stack) == Div || Top(stack) == Mult) {
                    enum Lexem op = (Lexem)Pop(stack);
                    Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                    newTuple->type = 1;
                    newTuple->operation = op;
                    tuple[j] = newTuple;
                    j++;
                }
                isSign = 1;
                Push(stack, Div);
                break;
            }
            case '(': {
                Push(stack, OB);
                int j = i + 1;
                while (1) {
                    if (string[j] == ' ' || string[j] == '\r' || string[j] == '\n' || string[j] == '\t' || string[j] == '\f' || string[j] == '\v')
                        j += 1;
                    else if (string[j] == ')') {
                        printf("Wrong input");
                        return NULL;
                    } else
                        break;
                }
                break;
            }
            case ')': {
                while (1) {
                    if (stack->top == 0) {
                        printf("Wrong input");
                        return NULL;
                    }
                    int r = Pop(stack);

                    if (r == OB)
                        break;

                    Tuple* newTuple = (Tuple*)malloc(sizeof(Tuple));
                    newTuple->type = 1;
                    newTuple->operation = (enum Lexem)r;
                    tuple[j] = newTuple;
                    j++;
                }
                break;
            }
            case '\r':
                break;
            case '\n':
                break;
            case '\t':
                break;
            case '\f':
                break;
            case '\v':
                break;
            case ' ':
                break;
            default: {
                printf("%d %c", i, c);
                printf("Undefined symbol");
                return NULL;
            } break;
            }
        }
    }
    return NULL;
}
#ifndef GTEST
int main(int argc, char** argv)
{
    int flag = 0;
    if (argc == 2) {
        char* a = "--float";
        for (int i = 0; i < 7; i++)
            if (a[i] != argv[1][i]) {
                printf("I dont know this flag");
                return -1;
            }
        flag = 1;
    }
    char string[MAXSIZE];
    int i = 0;
    char c;
    while ((c = getchar()) != EOF) {
        string[i] = c;
        i++;
    }
    string[i] = EOF;
    Tuple** input = PRN(string);
    if (input == NULL)
        return -1;
    int a = -1;

    if (flag == 0)
        a = Result(input);
    else
        a = ResultD(input);
    if (a != 0)
        return -1;
    return 0;
}
#endif