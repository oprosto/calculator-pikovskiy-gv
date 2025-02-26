
#pragma once
#define MAXSIZE 1024
typedef enum Lexem {

  Add = -8,
  Sub,
  Mult,
  Div,
  OB,
  CB,
  END,
}Lexem;
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
typedef struct {
  double data[MAXSIZE];
  int top;
} StackD;

Tuple **PRN(char* string);
int Result(Tuple **tuple);
int ResultD(Tuple **tuple);
double TopD(StackD *stack);
double PopD(StackD *stack);
void PushD(StackD *stack, double data);
int Top(Stack *stack);
int Pop(Stack *stack);
void Push(Stack *stack, int data);
int a_plus_b(int a, int b);
int a();


