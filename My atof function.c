#include <stdio.h>
#include <stdlib.h>
float my_atof(char *str,char*error)
{
    error=0;                                        // String control start
    double small=1,sum=0,cont=0,cont2=0,cont3=0;
    int i=0;
    while(str[i]!='\0'){
        if (!(str[i]>='0'&&str[i]<='9'||str[i]=='+'||str[i]=='-'||str[i]=='.'||str[i]=='/'||str[i]=='*'||str[i]==' ')){
            error+=1;
            if (error>0){
                printf("Error");
                exit(1);
            }
        }
        i++;
    }
    for (int j = 0; str[j]!='\0'; ++j) {
        if (str[j]=='+'){
            cont++;
        }
        else if (str[j]=='-'){
            cont++;
        }
        else if (str[j]=='*'){
            cont++;
        }
        else if (str[j]=='/'){
            cont++;
        }
        else if (str[j]==' '){
            cont2++;
        }
        else if (str[j]=='.'){
            cont3++;
        }
    }
    if (cont>1 || cont ==0 || cont2!=2 || cont3>2){
        error+=1;
        if (error>0){
            printf("Error");
            exit(1);
        }
    }                                              // String control finish
    i=0;
    while (str[i]!=' '){
        while(str[i]>='0'&&str[i]<='9')
        {
            sum=sum*10+(str[i]-'0');
            i++;
        }
        if(str[i]=='.')
        {
            i++;
            while(str[i]>='0'&&str[i]<='9')
            {
                sum=sum*10+(str[i]-'0');
                i++;
                small*=10;
            }
        }
        sum=sum/small;
    }
    i++;
    while (str[i]!='\0'){
        if (str[i]=='+'){
            i+=2;
            double small2=1,sum2=0;
            while (str[i]>='0'&&str[i]<='9'){
                sum2=sum2*10+(str[i]-'0');
                i++;
            }
            if (str[i]=='.'){
                i++;
                while (str[i]>='0'&&str[i]<='9')
                {
                    sum2=sum2*10+(str[i]-'0');
                    i++;
                    small2*=10;
                }
            }
            sum2=sum2/small2;
            double totalsum = sum+sum2;
            printf("%.2f",totalsum);
        }
        if (str[i]=='-'){
            i+=2;
            double small2=1,sum2=0;
            while (str[i]>='0'&&str[i]<='9'){
                sum2=sum2*10+(str[i]-'0');
                i++;
            }
            if (str[i]=='.'){
                i++;
                while (str[i]>='0'&&str[i]<='9')
                {
                    sum2=sum2*10+(str[i]-'0');
                    i++;
                    small2*=10;
                }
            }
            sum2=sum2/small2;
            double totalsum = sum-sum2;
            printf("%.2f",totalsum);
        }
        if (str[i]=='*'){
            i+=2;
            double small2=1,sum2=0;
            while (str[i]>='0'&&str[i]<='9'){
                sum2=sum2*10+(str[i]-'0');
                i++;
            }
            if (str[i]=='.'){
                i++;
                while (str[i]>='0'&&str[i]<='9')
                {
                    sum2=sum2*10+(str[i]-'0');
                    i++;
                    small2*=10;
                }
            }
            sum2=sum2/small2;
            double totalsum = sum*sum2;
            printf("%.2f",totalsum);
        }
        if (str[i]=='/'){
            i+=2;
            double small2=1,sum2=0;
            while (str[i]>='0'&&str[i]<='9'){
                sum2=sum2*10+(str[i]-'0');
                i++;
            }
            if (str[i]=='.'){
                i++;
                while (str[i]>='0'&&str[i]<='9')
                {
                    sum2=sum2*10+(str[i]-'0');
                    i++;
                    small2*=10;
                }
            }
            sum2=sum2/small2;
            double totalsum = sum/sum2;
            printf("%.2f",totalsum);
        }
    }
    return 0;
}

int main()
{
    printf("Program name: MyRepo5\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("That program convert a string to float number.\n");
    printf("And the program provide to perform arithmetic operations with a float number.\n");
    printf("To run the program, you need to write a string expression to the input.\n");
    printf("This expression must be 'string number operator(+,-,*,/) string number' otherwise program gives error.\n");
    printf("Please careful about whitespace. There will be a space between string numbers and operator.\n");

    char input[250];
    char error;
    printf("Please enter input string: \n");
    gets(input);
    my_atof(input,&error);
    return 0;
}

