#include <stdio.h>
#include <string.h>
#include <dirent.h>

void text_editor() {
    printf("Text Editor Command\n");
    printf("Enter the name of the file you want to open or create: ");
    char file_name[100];
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "a+"); // Open or create the file in append mode
    if (file == NULL) {
        printf("Error opening/creating file\n");
        return;
    }

    printf("Type :quitit and press enter to exit\n");
    char input[100];
    while (1) {
        printf(">> ");
        scanf("%s", input);
        if (strcmp(input, ":quitit") == 0) {
            break;
        }
        fprintf(file, "%s\n", input); // Write the input to the file
    }

    fclose(file);
}
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

void list_files() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (".")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
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
        } else if (strcmp(input, "editit") == 0) {
            text_editor();
    }
    else if (strcmp(input, "li") == 0) {
            list_files(); }
     else if (strcmp(input, "help") == 0) {
      printf("Commands:\n");
      printf("- calc: runs the calculator application\n");
      printf("- exit: Exits the program\n");
      printf("- editit: A text editor");
    } else if (strcmp(input, "exit") == 0) {
      printf("Exiting the os...\n");
      break;
    } else {
      printf("Invalid command. Type 'help' for a list of commands.\n");
    }
  }

  return 0;
}
