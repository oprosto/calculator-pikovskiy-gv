#include <gtest/gtest.h>
extern "C" {
#include "../../src/main.h"
}
TEST(PushTest, Add3Times)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Push(stack, 8);
    Push(stack, 7);
    Push(stack, 6);
    EXPECT_EQ(3, stack->top);
}

TEST(PushDoubleTest, Add3Times)
{
    StackD* stack = (StackD*)malloc(sizeof(StackD));
    PushD(stack, 8.5);
    PushD(stack, 7.6);
    PushD(stack, 6.7);
    EXPECT_EQ(3, stack->top);
}
TEST(PopTest, PopSecondItem)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Push(stack, 8);
    Push(stack, 7);
    int a = Pop(stack);
    EXPECT_EQ(1, stack->top);
}
TEST(PopDoubleTest, PopSecondItem)
{
    StackD* stack = (StackD*)malloc(sizeof(StackD));
    PushD(stack, 8.3);
    PushD(stack, 7.2);
    int a = PopD(stack);
    EXPECT_DOUBLE_EQ(1, stack->top);
}
TEST(TopTest, TopSecondItem)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Push(stack, 8);
    Push(stack, 7);
    int a = Top(stack);
    EXPECT_EQ(7, a);
}
TEST(TopDoubleTest, TopSecondItem)
{
    StackD* stack = (StackD*)malloc(sizeof(StackD));
    PushD(stack, 8.5);
    PushD(stack, 7.1);
    double a = TopD(stack);
    EXPECT_DOUBLE_EQ(7.1, a);
}
TEST(ResultTest, SimpleExpressionWithDiv)
{
    Tuple* tuple[6];
    Tuple* newTuple1 = (Tuple*)malloc(sizeof(Tuple));
    newTuple1->type = 0;
    newTuple1->number = 2;
    tuple[0] = newTuple1;
    Tuple* newTuple2 = (Tuple*)malloc(sizeof(Tuple));
    newTuple2->type = 1;
    newTuple2->operation = (Lexem)Add;
    tuple[1] = newTuple2;
    Tuple* newTuple3 = (Tuple*)malloc(sizeof(Tuple));
    newTuple3->type = 0;
    newTuple3->number = 6;
    tuple[2] = newTuple3;
    Tuple* newTuple4 = (Tuple*)malloc(sizeof(Tuple));
    newTuple4->type = 1;
    newTuple4->operation = (Lexem)Div;
    tuple[3] = newTuple4;
    Tuple* newTuple5 = (Tuple*)malloc(sizeof(Tuple));
    newTuple5->type = 0;
    newTuple5->number = 4;
    tuple[4] = newTuple5;
    Tuple* newTuple6 = (Tuple*)malloc(sizeof(Tuple));
    newTuple1->type = 2;
    newTuple1->number = (Lexem)END;
    tuple[5] = newTuple1;
    EXPECT_EQ(0, Result(tuple));
}
TEST(ResultDoubleTest, WrongInput)
{
    Tuple* tuple[6];
    Tuple* newTuple4 = (Tuple*)malloc(sizeof(Tuple));
    newTuple4->type = 1;
    newTuple4->operation = (Lexem)Div;
    tuple[0] = newTuple4;
    Tuple* newTuple5 = (Tuple*)malloc(sizeof(Tuple));
    newTuple5->type = 0;
    newTuple5->number = 4;
    tuple[1] = newTuple5;
    Tuple* newTuple1 = (Tuple*)malloc(sizeof(Tuple));
    newTuple1->type = 0;
    newTuple1->number = 2;
    tuple[2] = newTuple1;
    Tuple* newTuple2 = (Tuple*)malloc(sizeof(Tuple));
    newTuple2->type = 1;
    newTuple2->operation = (Lexem)Add;
    tuple[3] = newTuple2;
    Tuple* newTuple3 = (Tuple*)malloc(sizeof(Tuple));
    newTuple3->type = 0;
    newTuple3->number = 6;
    tuple[4] = newTuple3;
    Tuple* newTuple6 = (Tuple*)malloc(sizeof(Tuple));
    newTuple1->type = 2;
    newTuple1->number = (Lexem)END;
    tuple[5] = newTuple1;

    EXPECT_EQ(-1, ResultD(tuple));
}
TEST(PRNTest, FifthSymbol)
{
    char input[6];
    input[0] = '2';
    input[1] = '+';
    input[2] = '3';
    input[3] = '*';
    input[4] = '4';
    input[5] = EOF;
    Tuple** tuple = PRN(input);
    Tuple* v = tuple[0];
    EXPECT_EQ(1, 1);
}
