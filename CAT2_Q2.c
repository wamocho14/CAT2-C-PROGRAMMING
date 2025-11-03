//Hello World
/*
NAME: GRIFFIN MUTALI
REG NO: PA106/G/28744/25
*/

#include <stdio.h>

int main()
{
    float hours, wage;
    float regular_pay, overtime_pay, gross, tax, net;

    // 1. Ask user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage ($): ");
    scanf("%f", &wage);

    // 2. Calculate regular & overtime
    if (hours <= 40) {
        regular_pay   = hours * wage;
        overtime_pay  = 0;
    } else {
        regular_pay   = 40 * wage;
        overtime_pay  = (hours - 40) * wage * 1.5;
    }

    gross = regular_pay + overtime_pay;

    // 3. Calculate tax
    if (gross <= 600) {
        tax = gross * 0.15;
    } else {
        tax = 600 * 0.15 + (gross - 600) * 0.20;
    }

    net = gross - tax;

    // 4. Print results
    printf("\n=== PAY SLIP ===\n");
    printf("Gross Pay : $%.2f\n", gross);
    printf("Taxes     : $%.2f\n", tax);
    printf("Net Pay   : $%.2f\n", net);

    return 0;
}