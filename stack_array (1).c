#include <stdio.h>
#include<stdlib.h> //for malloc
#include<stdbool.h>  //for bool data type


#define SIZE 5 //size of stack
typedef struct   // stack definition
{
   int top;
   int num[SIZE];   // int num[5]
 }stack;
stack *s;   // creating a stack pointer



// stack full check
bool isFull(stack *s)
{
   if (s->top == SIZE-1)
         return true;
   else
       return false;
}

// push operation
void push(stack *s, int item)
{
   if (isFull(s))
      printf("Stack full !!!!! \n");
   else
   {
      s->top++;
      s->num[s->top]=item;
   }
}

// stack empty check
bool isEmpty(stack *s)
{

    if (s->top == -1)
    {
       return true;
    }
    else
       return false;
}


//pop operation

int pop(stack *s)
{
   int item;
   if (isEmpty(s))
      printf("Stack empty !!!!! \n");
   else
   {
   	item = s->num[s->top];
   	s->top--;
   	return item;
   }
}

// display stack
void display(stack *s)
{
	int i=s->top;
       printf("\nStack is :\n");
       while(i>=0)
       {
          printf("%d \n", s->num[i]);
          i--;
       }
}

int main()
{
   int val, option;

   // stack creation
   s=(stack *) malloc(sizeof(stack));
   // check if memory has been allocated successfully
   if(s==NULL)  // memory not allocated
   {
      printf("Memory not allocated");
      exit(0);
   }
   else
      s->top=-1;
    printf("\n****Implementing a stack**** \n_____________________________________\n");
    do{
        printf("\nMenu:- \n");
        printf("\n\t 1: Push \n");
        printf("\n\t 2: Pop \n");
        printf("\n\t 3: Display \n");
        printf("\nEnter your choice:- ");
        scanf("%d",&option);
        //calling push or pop according to selection
        switch (option)
        {
            case 1:
                printf("\n Enter the value to push: ");
                scanf("%d", &val);
                push(s,val); // calling push fn
                break;
            case 2:
                printf("\n popped item is %d\n",pop(s)); // calling pop
                break;
            case 3:
                display(s); // calling stack display fn
                break;
            default:
                break;
        }
    } while(option==1||option==2||option==3);
    free(s); //releasing the allocated memory to the pointer s
}
