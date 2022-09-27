#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int add(int num1, int num2);

float multiply(float num1, float num2);

void reverse(char *str);

int compare(char *str1, char *str2);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error: Usage: lab1 [debug | no-debug]\n");
    }
    else if(strcmp(argv[1],"debug") == 0 || strcmp(argv[1], "no-debug") == 0) {
    
        if(strcmp(argv[1],"debug") == 0)
            printf("Running Lab 1 on Debug Mode\n");
        else
            printf("Running Lab 1 on No-Debug Mode\n");
            
        while(true) {
            printf("\n=========MENU=========\n1. Add 2 numbers\n2. Multiply 2 numbers\n3. Reverse a string\n4. Compare two words\n5. Exit\n\n>");
            int action;
            scanf("%d", &action);
            getchar();
            
            //for debug mode
            if(strcmp(argv[1], "debug") == 0)
            	fprintf(stderr, "\nUser Input: \"%d\"\n\n", action);

            switch(action) {
                case 1 :
                   // perform add function 
                    int i,j;
                    printf("First number: ");
                    scanf("%d", &i);
                    
		    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%d\"\n\n", i);

                    printf("Second number: ");    
                    scanf("%d", &j);
                    
                    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%d\"\n\n", j);

                    printf("The result is equal to %d\n", add(i,j));
                    break;
                    
                case 2 :
                    //perform multiply function
                    float a,b;
                    printf("First number: ");
                    scanf("%f", &a);
                    getchar();
                    
                    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%f\"\n\n", a);

                    printf("Second number: ");
                    scanf("%f", &b);
                    getchar();
			
		    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%f\"\n\n", b);

                    printf("\n");
                    printf("The result is equal to %f\n", multiply(a,b));
                    break;
                case 3 :
                    //perform reverse string function
                    char *str = malloc(sizeof(char) * 100);

                    printf("Enter your string: ");
                    scanf("%s", str);
                    getchar();
                    
                    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%s\"\n\n", str);

                    reverse(str);

                    free(str);
                    break;
                case 4 :
                    //perform compare string function
                    char strls[100];

                    printf("Enter two strings: ");
                    fgets(strls, 100, stdin);
                    
		    //for debug mode
                    if(strcmp(argv[1],"debug") == 0)
                        fprintf(stderr, "\nUser Input: \"%s\"\n\n", strls);   

                    strls[strlen(strls)-1] = '\0';
                    
                    char *stringOne;
                    char *stringTwo;

                    stringOne = strtok(strls, " ");                    
                    stringTwo = strtok(NULL, " ");

                    int result = compare(stringOne, stringTwo);

                    if(result == 1) {
                        printf("The strings are not the same!\n");
                    }
                    else {
                        printf("The strings are the same!\n");
                    }

                    break;
                case 5 :
                    //exit out of the program
                    printf("User exited the program\n");
                    exit(0);
                default:
                    //invalid commands
                    printf("\nError: Invalid Command\n");
                    break;
            }
        }  
    }
    else {
        fprintf(stderr,"Error: Usage: lab1 [debug | no-debug]\n");
        exit(1);
    }
}

int add(int num1, int num2) {
    return num1 + num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

void reverse(char *str) {
    //code
    int size = 100;
    char *ptr = &str[size-1];
    for(int i = 0; i < size; i++) {
        if(ptr == "\n") {
            continue;
        }
        else {
            printf("%c", *ptr);
        }
        ptr--;
    } 
    printf("\n");
}   

int compare(char *str1, char *str2) {
    //code
    while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    if(*str1 == *str2) {
        return 0;
    }
    else {
        return 1;
    }
}
