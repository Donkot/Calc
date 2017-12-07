#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int *p;
int *tos;
int *bos;
void push(int i);
int pop(void);
int main(void)
{
  int a, b;
  char s[80];
  p = (int *) malloc(MAX*sizeof(int));
  if(!p) {
    printf("Error allocating memory\n");
    exit(1);
  }
  tos = p;
  bos = p + MAX-1;
  printf("Calculator with four actions\n");
  printf("Press 'q' to quit\n");
  do {
    printf(": ");
    gets(s);
    switch(*s) {
      case '+':
        a = pop();
        b = pop();
        printf("%d\n", a+b);
        push(a+b);
        break;
      case '-':
        a = pop();
        b = pop();
        printf("%d\n", b-a);
        push(b-a);
        break;
      case '*':
        a = pop();
        b = pop();
        printf("%d\n", b*a);
        push(b*a);
        break;
      case '/':
        a = pop();
        b = pop();
        if(a==0) {
          printf("Division by 0.\n");
          break;
        }
        printf("%d\n", b/a);
        push(b/a);
        break;
      case '.':
        a = pop();
        push(a);
        printf("The current value on top of the stack: %d\n", a);
        break;
      default:
        push(atoi(s));
    }
  } while(*s != 'q');

  return 0;
}
void push(int i)
{
  if(p > bos) {
    printf("Stack full\n");
    return;
  }
  *p = i;
  p++;
}
int pop(void)
{
  p--;
  if(p < tos) {
    printf("Stack is empty\n");
    return 0;
  }
  return *p;
}
