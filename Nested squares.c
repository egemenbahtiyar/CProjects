#include <stdio.h>
int main()
{
    printf("Program name: MyRepo2\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("This program shows to create two nested squares using loops.\n");
    printf("For the program to run enter the outer number, inner number and margin value.The first two numbers must be odd numbers. \n");


    int outer,inner,margin;
    printf("Please enter number of outer square's width:");
    scanf("%d",&outer);
    printf("Please enter number of inner square's width:");
    scanf("%d",&inner);
    if (outer%2==1 && inner%2==1)
    {
        if (outer>inner){
            printf("Please enter margin:");
            scanf("%d",&margin);
            printf("%s","The shape is");
            if(margin>0){
                for (int i = 0; i < margin; ++i) {
                    printf("\n");
                }
                int star =42;
                for (int i = 0; i < margin*2; ++i) {
                    printf(" ");

                }
                for (int i = 0; i < outer; ++i)
                {
                    for (int j = 0; j < outer; ++j)
                    {
                        if (i>=(outer-inner)/2 && i<inner+(outer-inner)/2  && j>=(outer-inner)/2  && j<inner+(outer-inner)/2)
                        {
                            printf("  ");
                        }
                        else
                        {
                            printf("%c ",star);
                        }
                    }
                    printf("\n");
                    for (int j = 0; j < margin*2-1; ++j) {
                        printf(" ");
                    }
                    printf(" ");

                }
                for (int i = 0; i < margin-1; ++i) {
                    printf("\n");
                }

            }
            else if (margin==0) {
                int star =42;
                for (int i = 0; i < outer; ++i) {
                    for (int j = 0; j < outer; ++j) {
                        if (i >= (outer - inner) / 2 && i < inner + (outer - inner) / 2 && j >= (outer - inner) / 2 &&
                            j < inner + (outer - inner) / 2) {
                            printf("  ");
                        } else {
                            printf("%c ", star);
                        }
                    }
                    if (i!=outer-1){
                        printf("\n");
                    }

                }

            }

        }
        else{
            printf("!\nMake sure outer width must be greater than inner width.");
        }

    }
    else{
        printf("!\nMake sure that both numbers must be odd numbers.");
    }

    return 0;
}