#include <stdio.h>
#include <ctype.h>

int main(){
    printf("Program name: MyRepo4\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("Program counts to number of characters and words,reverse to order of words.\n");
    printf("Also Program converts first character of each word to uppercase in string.\n");
    printf("To run the program, you need to write a string expression to the input.\n");

    char str[250];
    printf("Enter your input:");
    gets(str);

    int idx = 0;                  // Length of characters finding
    int len = 0;
    while (str[idx] != '\0'){
        len++;
        idx++;
    }

    printf("%s\n",str);
    int count;                            // Words finding
    for (int i = 0;str[i] != '\0';i++)
    {
        if (str[i] == ' ' && str[i+1] != ' ')
            count++;
    }
    printf("%s %d\n","Number of Characters:", len);
    printf("Number of words: %d\n", count + 1);

    printf("%s","Reversed: ");
    int startIndex, endIndex;
    endIndex = len - 1;
    for (int i = len-1; i>=0; i--) {    // Reversed
        if (str[i]==' ' || i==0){
            if (i==0){
                startIndex=0;
            }
            else{
                startIndex=i+1;
            }
            for (int j = startIndex; j <=endIndex; ++j) {
                printf("%c",str[j]);
            }
            endIndex=i-1;
            printf(" ");
        }
    }
    printf("\n");
    printf("%s","Capitalized: ");

    for (int i = 0; i <= len - 1; ++i) {   // Capitalized
        if (str[i]==' '){
            printf(" ");
        }
        else if (str[i-1]==' '){
            printf("%c",toupper(str[i]));
        }
        else if (i==0){
            printf("%c",toupper(str[i]));
        }
        else {
            printf("%c",str[i]);
        }
    }
    printf("\n");

    return 0;
}
