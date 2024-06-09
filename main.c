#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_WORD_LENGTH 30

char stack[MAX_SIZE][MAX_WORD_LENGTH];
int top = -1;
int lastope = -1;

void push(char *word)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        strcpy(stack[top], word);
        lastope = 1;
    }
}

void pop()
{
    char item[MAX_WORD_LENGTH];
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        strcpy(item, stack[top]);
        top--;
        printf("Deleted word: %s\n", item);
        lastope = 2;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Text is empty.\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%s", stack[i]);
        }
    }
}

void undo()
{
    if (lastope == 1)
    {
        printf("Undo last entered word.\n");
        top--;
    }
    else if (lastope == 2)
    {
        printf("Undo last deleted word.\n");
        top++;
    }
    else
    {
        printf("No operation to undo.\n");
    }
}

int main()
{
    printf("Stack based Word Editor\n");
    int o;
    char word[MAX_WORD_LENGTH];
    do
    {
        printf("\nSelect your option:\n");
        printf("1. For entering a word\n");
        printf("2. For deleting the last word\n");
        printf("3. For displaying the text\n");
        printf("4. For undo last opration\n");
        printf("5. For exiting the program\n");

        scanf("%d", &o);
        getchar();
        switch (o)
        {
        case 1:
            printf("Enter text: ");
            fgets(word, sizeof(word), stdin);
            push(word);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            undo();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Enter a valid input.\n");
            break;
        }
    } while (o != 5);
    return 0;
}
