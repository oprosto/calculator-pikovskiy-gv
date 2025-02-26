#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*
enum Lexem {

  Add = -8,
  Sub,
  Mult,
  Div,
  OB,
  CB,
  END,
};

typedef struct {
  short type;
  union {
    int number;
    enum Lexem operation;
  };
} Tuple;
typedef struct {
  int data[MAXSIZE];
  int top;
} Stack;
*/
void Push(Stack *stack, int data) {
  stack->data[stack->top] = data;
  stack->top++;
}

int Pop(Stack *stack) {
  stack->top--;
  int data = stack->data[stack->top];
  return data;
}
int Top(Stack *stack) { return stack->data[stack->top - 1]; }
/*
typedef struct {
  double data[MAXSIZE];
  int top;
} StackD;
*/
void PushD(StackD *stack, double data) {
  stack->data[stack->top] = data;
  stack->top++;
}
double PopD(StackD *stack) {
  stack->top--;
  double data = stack->data[stack->top];
  return data;
}
double TopD(StackD *stack) { return stack->data[stack->top - 1]; }


int ResultD(Tuple **tuple) {
  int i = 0;
  StackD *stack = (StackD*)malloc(sizeof(StackD));
  stack->top = 0;
  while (tuple[i]->type != 2) {
    if (tuple[i]->type == 0) {
      PushD(stack, tuple[i]->number);
    } else {
      switch (tuple[i]->operation) {
      case Add: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double right = PopD(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double left = PopD(stack);
        double temp = left + right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        PushD(stack, temp);
        break;
      }
      case Sub: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double right = PopD(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double left = PopD(stack);
        double temp = left - right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        PushD(stack, temp);
        break;
      }

      case Mult: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double right = PopD(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double left = PopD(stack);
        double temp = left * right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        PushD(stack, temp);
        break;
      }
      case Div: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double right = PopD(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        double left = PopD(stack);
        if (left * left < 0.0004 * 0.0004)
        {
        	printf("UB:Divider too small. README for help");
        	return -1;
        }
        double temp = left / right;
        if (temp > 2000000000 || temp < -2000000000)
        {
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
  printf("%.4f", stack->data[0]);
  free(stack);
  return 0;
}

int a()
{
	return 2;
}
int a_plus_b(int a, int b)
{

		return a+b;
}



int Result(Tuple **tuple) {
  int i = 0;
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->top = 0;
  while (tuple[i]->type != 2) {
    if (tuple[i]->type == 0) {
      Push(stack, tuple[i]->number);
    } else {
      switch (tuple[i]->operation) {
      case Add: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int right = Pop(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int left = Pop(stack);
        int temp = left + right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        Push(stack, temp);
        break;
      }
      case Sub: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int right = Pop(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int left = Pop(stack);
        int temp = left - right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        Push(stack, temp);
        break;
      }

      case Mult: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int right = Pop(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int left = Pop(stack);
        int temp = left * right;
        if (temp > 2000000000 || temp < -2000000000)
        {
        	printf("UB:Big number in operation. README for help");
        	return -1;
        }
        Push(stack, temp);
        break;
      }
      case Div: {
      	if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int right = Pop(stack);
        if (stack->top == 0)
      	{
      		printf("Wrong input");
      		return -1;
      	}
        int left = Pop(stack);
        if (left * left < 0.0004 * 0.0004)
        {
        	printf("UB:Divider too small. README for help");
        	return -1;
        }
        int temp = left / right;
        if (temp > 2000000000 || temp < -2000000000)
        {
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
  printf("%d", stack->data[0]);
  free(stack);
  return 0;
}
Tuple *tuple[MAXSIZE];
Tuple **PRN(char* string) {
  char c;
  int j = 0;
  //= (Tuple**)malloc(sizeof(Tuple*) * MAXSIZE);
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = 0;
  int number = 0;
  for (int i = 0; i < MAXSIZE; i++) {
  	if (sizeof(stack) > 1024)
  	{
  		printf("UB: input more than 1KB. README for help");
  		return NULL;
  	}
    // printf("NEW\n");
    c = string[i];
    // printf("%c", c);
    if (c == EOF) //ИСПРАВИТЬ НА EOF
    {
      if (number != 0) {
        Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
        newTuple->type = 0;
        newTuple->number = number;
        tuple[j] = newTuple;
        j++;

        number = 0;
      }
      while (stack->top > 0) {
        int r = Pop(stack);
        Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
        newTuple->type = 1;
        newTuple->operation = (enum Lexem)r;
        tuple[j] = newTuple;
        j++;
      }
      Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
      newTuple->type = 2;
      newTuple->operation = END;
      tuple[j] = newTuple;
      j++;
      return tuple;
    }

    if (c >= '0' && c <= '9') {
      number = number * 10 + (c - 48);
    } else {
      if (number != 0) {
      	if (number > 2000000000)
      	{
      		printf("UB:Number too big. README file for help");
      	}
        Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
        newTuple->type = 0;
        newTuple->number = number;
        tuple[j] = newTuple;
        j++;

        number = 0;
      }

      switch (c) {
      case '+': {
        while (Top(stack) == Add || Top(stack) == Sub || Top(stack) == Mult || Top(stack) == Div) {
          enum Lexem op = (Lexem)Pop(stack);
          Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
          newTuple->type = 1;
          newTuple->operation = op;
          tuple[j] = newTuple;
          j++;
        }
        Push(stack, Add);
        break;
      }
      case '-': {
        while (Top(stack) == Add || Top(stack) == Sub || Top(stack) == Mult || Top(stack) == Div) {
          enum Lexem op = (Lexem)Pop(stack);
          Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
          newTuple->type = 1;
          newTuple->operation = op;
          tuple[j] = newTuple;
          j++;
        }
        Push(stack, Sub);
        break;
      }
      case '*': {
        while (Top(stack) == Div || Top(stack) == Mult) {
          enum Lexem op = (Lexem)Pop(stack);
          Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
          newTuple->type = 1;
          newTuple->operation = op;
          tuple[j] = newTuple;
          j++;
        }
        Push(stack, Mult);
        break;
      }
      case '/': {
        while (Top(stack) == Div || Top(stack) == Mult) {
          enum Lexem op = (Lexem)Pop(stack);
          Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
          newTuple->type = 1;
          newTuple->operation = op;
          tuple[j] = newTuple;
          j++;
        }
        Push(stack, Div);
        break;
      }
      case '(': {
        Push(stack, OB);
        break;
      }
      case ')': {
        while (1) {
        	if (stack->top == 0)
        	{
        		printf("Wrong input");
        		return NULL;
        	}
          int r = Pop(stack);
          if (r == OB)
            break;
          Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
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
      default:
      	{
      		printf("%d %c", i ,c);
      		printf("Undefined symbol");
      		return NULL;
      	}
        break;
      }
    }
  }
  return NULL;
}
#ifndef GTEST
int main(int argc, char** argv) {	
	int flag = 0;
	if (argc == 2)
	{
		char* a = "--float";
		for (int i = 0; i < 7; i++)
			if (a[i] != argv[1][i])
			{
				printf("I dont know this flag");
				return -1;
			}
		flag = 1;
	}
	char string[MAXSIZE];
	int i = 0;
	char c;
	while((c = getchar()) != EOF)
	{
		string[i] = c;
		i++;
	}
	string[i] = EOF;
  	Tuple **input = PRN(string);
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