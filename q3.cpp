#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int stack(int x)  // Creating function to store stack and check the order
{
  bool areBracketsBalanced(const char* expr) {
    int len = strlen(expr);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++)  // Starting loop to check each element one by one and finding if double bracket are used or not
    {
      if (expr[i] == '(' & expr[i+1] == '(') 
   {
       return top == -1;
   }
   else if (expr[i] == '{' & expr[i+1] == '{') 
   {
       return top == -1;
   }
   else if (expr[i] == '[' & expr[i+1] == '[') 
   {
       return top == -1;
   }
   else
   {
       return top--;
   }
   }

    for (int i = 0; i < len; i++) // Creating loop to verify other bracket are used and successful run
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') 
        {
            stack[++top] = expr[i];
        } 
        else if ((expr[i] == ')' && stack[top] == '(') ||
                   (expr[i] == '}' && stack[top] == '{') ||
                   (expr[i] == ']' && stack[top] == '[')) 
                   {
            top--;
        } 
        
        else 
        {
            stack[++top] = expr[i];
        }
    }

    return top == -1;
}  
}

int add(int a, int b)
{
    return (a+b);
}



int main() {                    // Calling the functions inside main by giving user input
    const char* expr = "{()}[]";
 printf("%d\n",add(2,4));
   
    // if (areBracketsBalanced(expr)) {
    //     printf("Balanced\n");
    // } else {
    //     printf("Not Balanced\n");
    // }
    // return 0;
}