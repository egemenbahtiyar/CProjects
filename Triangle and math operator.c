#include <stdio.h>
int main()
{
    printf("Program name: MyRepo1\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("First program creating a triangle with print formatting.Second program is that demonstrates simple math operations.\n");
    printf("For first program just run but for second program enter number,arithmetic operator,number respectively.\n\n");
    printf("*** First Program ***\n");
    int c1 =47;
    int c2 =92;
    int c3 =45;
    printf("%5c%c\n",c1,c2);
    printf("%4c%3c\n",c1,c2);
    printf("%3c%5c\n",c1,c2);
    printf("%2c%7c\n",c1,c2);
    printf("%2c%c%c%c%c%c%c%c\n",c3,c3,c3,c3,c3,c3,c3,c3);

    printf("*** Second Program ***\n");
    float number1,number2,result;
    char c;
    printf("Please enter (number+arithmetic operator+number):\n");
    scanf("%f %c %f",&number1,&c,&number2);
    if (c == '+'){
        result = number1 + number2;
        printf("%.2f+%.2f=%.2f",number1,number2,result);
    }
    else if (c=='-'){
        result = number1 - number2;
        printf("%.2f-%.2f=%.2f",number1,number2,result);
    }
    else if (c=='*'){
        result = number1 * number2;
        printf("%.2f*%.2f=%.2f",number1,number2,result);
    }
    else if (c=='/'){
        result = number1 / number2;
        printf("%.2f/%.2f=%.2f",number1,number2,result);
    }
    else{
        printf("Make sure you entered correctly.");
    }
    return 0;
}