# include <stdio.h>

void calculate(){

    char Operator;
    float num1, num2, result;

    char* op_message = "Enter an operator of your choice";
    printf("%s\n", op_message);
    scanf("%c", &Operator);

    printf("Enter the two numbers sepetated by a space eg. 9 65 -- ");
    scanf("%f %f", &num1, &num2);

    switch(Operator){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        default:
            printf("Operator not supported\n");
            return;
   }
   printf("Calculated value = %f \n", result);
}
int main(void){   //void enshures that main is called without an argument

    printf("Welcome to The Calculator\n");
    char* op_supported = "We currently support + - * / operators only";
    printf("%s\n", op_supported);
    int cont = 1;
    char* continue_calculate = "Type 1 to use the calculator again or type 0 to exit";
    while (cont) {
        calculate();
        printf("%s\n", continue_calculate);
        scanf("%d", &cont);
    }
}
