#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

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
int Result(Tuple **tuple) {
  int i = 0;
  Stack *stack = malloc(sizeof(Stack));
  stack->top = 0;
  while (tuple[i]->type != 2) {
    if (tuple[i]->type == 0) {
      // atoi
      // int temp = tuple[i] - 48;
      Push(stack, tuple[i]->number);
    } else {
      switch (tuple[i]->operation) {
      case Add: {
        int right = Pop(stack);
        int left = Pop(stack);
        int temp = left + right;
        Push(stack, temp);
        break;
      }
      case Sub: {
        int right = Pop(stack);
        int left = Pop(stack);
        int temp = left - right;
        Push(stack, temp);
        break;
      }

      case Mult: {
        int right = Pop(stack);
        int left = Pop(stack);
        int temp = left * right;
        Push(stack, temp);
        break;
      }
      case Div: {
        int right = Pop(stack);
        int left = Pop(stack);
        int temp = left / right;
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
}
Tuple *tuple[MAXSIZE];
Tuple **PRN() {
  char c;
  int j = 0;
  //= (Tuple**)malloc(sizeof(Tuple*) * MAXSIZE);
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = 0;
  int number = 0;
  for (int i = 0; i < MAXSIZE; i++) {
    // printf("NEW\n");
    c = getchar();
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
        Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
        newTuple->type = 0;
        newTuple->number = number;
        tuple[j] = newTuple;
        j++;

        number = 0;
      }

      switch (c) {
      case '+': {
        while (Top(stack) == Add || Top(stack) == Sub) {
          enum Lexem op = Pop(stack);
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
        while (Top(stack) == Add || Top(stack) == Sub) {
          enum Lexem op = Pop(stack);
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
          enum Lexem op = Pop(stack);
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
          enum Lexem op = Pop(stack);
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
      default:
        break;
      }
    }
  }
}

int main() {
  Tuple **input = PRN();
  Result(input);
  // for (int i = 0; i < MAXSIZE; i++)
  //{
  //	free(input[i]);
  // }
}
int main1() {
  //Считываем инфу
  // const int MAXSIZE = 128;
  char c;
  // char* tuple = malloc(sizeof(char) * MAXSIZE);
  // int* lexems = malloc(sizeof(int) * MAXSIZE);
  // int* stack = malloc(sizeof(int) * MAXSIZE);
  char string[MAXSIZE];
  int lexems[MAXSIZE];
  float stack[MAXSIZE];
  for (int i = 0; i < MAXSIZE; i++) {
    stack[i] = 0;
  }
  int numI = 0;
  int lexemI = 0;

  //Создаем порядок действий
  short *order[MAXSIZE];
  int i = 0;
  int ordI = 0;
  while (lexems[i] != END) {

    i++;
  }

  return 0;
}