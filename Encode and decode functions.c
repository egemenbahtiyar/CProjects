#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int get_int_len (long long value){
    int l=1;
    while(value>9){ l++; value/=10; }
    return l;
}
int myPow(int n, int exp)
{
    int result = 1;
    for (; exp > 0; exp--)
        result *= n;

    return result;
}
int ReverseInteger(int n){
    int rev = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    return rev;
}
void Encode() {
    int input1;
    printf("Enter your number:");
    scanf("%d",&input1);
    long long output=0;
    long long a= myPow(10,0);

    if (input1>=10000 && input1<=99999){
        int basamak1=(input1/10000);
        int basamak2=(input1-(basamak1*10000))/1000;
        int basamak3=(input1-(basamak1*10000)-(basamak2*1000))/100;
        int basamak4=(input1-(basamak1*10000)-(basamak2*1000)-(basamak3*100))/10;
        int basamak5=(input1-(basamak1*10000)-(basamak2*1000)-(basamak3*100)-(basamak4*10))/1;

        for (int i = 0; i <=basamak5%3; i+=1) {
            output = output + a*(basamak5);
            a*=10;
        }
        for (int i = 0; i <=basamak4%3; i+=1) {
            output = output+ a*(basamak4);
            a*=10;
        }
        for (int i = 0; i <=basamak3%3; i+=1) {
            output = output+ a*(basamak3);
            a*=10;
        }
        for (int i = 0; i <=basamak2%3; i+=1) {
            output = output+ a*(basamak2);
            a*=10;
        }
        for (int i = 0; i <=basamak1%3; i+=1) {
            output = output+ a*(basamak1);
            a*=10;
        }
        printf("%lld",output);
    }
    else if (input1<10000 && input1>=1000){
        int basamak1=(input1/1000);
        int basamak2=(input1-(basamak1*1000))/100;
        int basamak3=(input1-(basamak1*1000)-(basamak2*100))/10;
        int basamak4=(input1-(basamak1*1000)-(basamak2*100)-(basamak3*10))/1;

        for (int i = 0; i <=basamak4%3; i+=1) {
            output = output+ a*(basamak4);
            a*=10;
        }
        for (int i = 0; i <=basamak3%3; i+=1) {
            output = output+ a*(basamak3);
            a*=10;
        }
        for (int i = 0; i <=basamak2%3; i+=1) {
            output = output+ a*(basamak2);
            a*=10;
        }
        for (int i = 0; i <=basamak1%3; i+=1) {
            output = output+ a*(basamak1);
            a*=10;
        }
        printf("%lld",output);
    }
    else if (input1<1000 && input1>=100){
        int basamak1=(input1/100);
        int basamak2=(input1-(basamak1*100))/10;
        int basamak3=(input1-(basamak1*100)-(basamak2*10))/1;
        for (int i = 0; i <=basamak3%3; i+=1) {
            output = output+ a*(basamak3);
            a*=10;
        }
        for (int i = 0; i <=basamak2%3; i+=1) {
            output = output+ a*(basamak2);
            a*=10;
        }
        for (int i = 0; i <=basamak1%3; i+=1) {
            output = output+ a*(basamak1);
            a*=10;
        }
        printf("%lld",output);
    }
    else if (input1<100 && input1>=10){
        int basamak1=(input1/10);
        int basamak2=(input1-(basamak1*10))/1;
        for (int i = 0; i <=basamak2%3; i+=1) {
            output = output+ a*(basamak2);
            a*=10;
        }
        for (int i = 0; i <=basamak1%3; i+=1) {
            output = output+ a*(basamak1);
            a*=10;
        }
        printf("%lld",output);
    }
    else if (input1<10 && input1>0){
        int basamak2=(input1/1);
        for (int i = 0; i <=basamak2%3; i+=1) {
            output = output+ a*(basamak2);
            a*=10;
        }
        printf("%lld",output);
    }
    else{
        printf("EROR");
    }
}
void Decode(){
    long long input1;
    printf("Enter your number:");
    scanf("%lld",&input1);
    int ham = get_int_len(input1);
    long long a= myPow(10,ham-1);
    int err=0;
    int number1=0;
    int n=0;

    while (err==0){
        for (int j = 0; j < ham; ham-=1) {
            if (input1>=1 && a==1 && (input1/a)%3!=0){
                err+=1;
            }
            else if ((input1/a)%3==1 && (input1-((input1/a)*a))/(a/10)==input1/a){
                number1+=myPow(10,n)*(input1/a);
                n+=1;
                input1=input1-(input1/a)*a-(input1/a)*a/10;
                a/=100;
                ham-=1;
            }
            else if ((input1/a)%3==0){
                if (input1/a == 0){
                    n+=1;
                    input1=input1-(input1/a)*a;
                    a/=10;
                } else{
                    number1+=myPow(10,n)*(input1/a);
                    n+=1;
                    input1=input1-(input1/a)*a;
                    a/=10;
                }
            }
            else if ((input1/a)%3==2 && (input1-((input1/a)*a))/(a/10)==input1/a &&((input1-((input1/a)*a)-((input1-((input1/a)*a))/(a/10))*(a/10))/(a/100))==input1/a){
                number1+=myPow(10,n)*(input1/a);
                n+=1;
                input1=input1-(input1/a)*a-(input1/a)*a/10-(input1/a)*a/100;
                a/=1000;
                ham-=2;
            }
            else{
                err+=1;
            }
        }
        if (err==0 && get_int_len(number1)==n){
            printf("%d",ReverseInteger(number1));
            err+=1;
        }
        else if(err==0 && get_int_len(number1)!=n){
            printf("%d%d",ReverseInteger(number1),0);
            err+=1;
        }
        else{
            printf("Eror");
            break;
        }
    }
}
int main() {
    printf("Program name: MyRepo3\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("This program created for showing Encode and decode functions process.\n");
    printf("Make a selection by using the letters E, D and Q from the menu. Then enter the number for encoding or decoding process.\n\n");

    char input;
    do{
        printf("=== Menu ===\n");
        printf("1. For Encode press e letter.\n");
        printf("2. For Decode press d letter.\n");
        printf("3. For Exit press q letter.\n");
        printf("Enter your choice:");
        scanf(" %c", &input);
        switch(tolower(input))
        {
            case 'e' :
                Encode();
                exit(1);
            case 'd':
                Decode();
                exit(1);
            case 'q':
                printf("Exiting the program..\n");
                exit(1);
            default:
                printf("Please enter valid choice\n");
        }

    }while(input!='q');

    return 0;
}

