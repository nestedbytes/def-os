#include <stdio.h>
#include <string.h>

void calculator() {
  double num1, num2, result;
  char operator;

  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  switch (operator) {
    case '+':
      result = num1 + num2;
      printf("%.1lf + %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%.1lf - %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%.1lf * %.1lf = %.1lf\n", num1, num2, result);
      break;
    case '/':
      result = num1 / num2;
      printf("%.1lf / %.1lf = %.1lf\n", num1, num2, result);
      break;
    default:
      printf("Invalid operator\n");
  }
  char exit[100];
  printf("Type exit to go back to command stage: ");
  scanf("%s",exit);
  if(strcmp(exit,"exit")==0){
    return;
  }
}

int main() {
    printf("def os 1.0.0\n");
  char input[100];

  while (1) {
    printf("Enter a command: ");
    scanf("%s", input);

    if (strcmp(input, "calc") == 0) {
      calculator();
    } else if (strcmp(input, "help") == 0) {
      printf("Commands:\n");
      printf("- calc: runs the calculator application\n");
      printf("- exit: Exits the program\n");
    } else if (strcmp(input, "exit") == 0) {
      printf("Exiting the program...\n");
      break;
    } else {
      printf("Invalid command. Type 'help' for a list of commands.\n");
    }
  }

  return 0;
}
