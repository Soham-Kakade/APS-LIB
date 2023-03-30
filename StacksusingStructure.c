#include <stdio.h>

#define MAX 5

typedef struct stack
{
    int top;
    int s[MAX];
} stack;

int push(stack *st, int item)
{
    if (st->top == MAX -1 )
    {
        printf("Stack overflow \n");
        return (0);
    }
    st->top++;
    st->s[st->top] = item;
    return (1);
}

int pop(stack *st)
{
    int item;
    if (st->top == 0)
    {
        printf("Stack is Empty \n");
        return (0);
    }
    item = st->s[st->top];
    st->top--;
    return (item);
}

void display(stack *st)
{
    for (int i = st->top; i > 0; i--)
    {
        printf("%d \n", st->s[i]);
    }
}

int main()
{
    
    stack *st;
    int choice;
    int data;
    while (1)
    {
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n");
        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Element to be Pushed \n");
            scanf("%d", &data);
            push(st, data);
            break;

        case 2:
            data = pop(st);
            printf("The popped item is %d \n", data);
            break;

        case 3:
            printf("\n");
            display(st);
            break;

        case 4:
            exit(0);
            break;

        default:
            exit(0);
            break;
        }
    }
    return (0);
}