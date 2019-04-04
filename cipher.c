/*---------------------------------------------------------------------------*/
//Header files:
#include <stdio.h>
#include <conio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
//Function prototypes:
void menu(void);                                                                                //menu selection
//Tasks:
int task1(void);
int task2(void);
int task3(void);
int task4(void);
int task5(void);
int task6(void);
/*---------------------------------------------------------------------------*/
//MAIN (Calling the menu fuction):
int main()  {
    menu();
    return 0;
}
/*---------------------------------------------------------------------------*/
//Function definitions: 
//Men
void menu(void) {
    static int menuInput;                                                                       //user's selection
    do  {
        clrscr();
        printf("Enter the number that corresponds to the program you wish to access: \n\n");
        printf("   1. Encryption of a message with a rotation cipher given the message text and rotation amount.\n");
        printf("   2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount.\n");
        printf("   3. Encryption of a message with a substitution cipher given message text and alphabet substitution.\n");
        printf("   4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions.\n");
        printf("   5. Decryption of a message encrypted with a rotation cipher given cipher text only.\n");
        printf("   6. Decryption of a message encrypted with a substitution cipher given cipher text only.\n");
        printf("   7. Exit.\n\nSelection: ");
        scanf("%d", &menuInput);
        switch(menuInput)   {                                                                   //calls the appropriate function depending on user selection
            case 1: task1();
            break;
            case 2: task2();
            break;
            case 3: task3();
            break;
            case 4: task4();
            break;
            case 5: task5();
            break;
            case 6: task6();
            break;
            case 7: return 0;
            default: printf("Invalid entry, please try again. ");
        } 
    }   while(menuInput!=1 && menuInput!=2 && menuInput!=3 && menuInput!=4 && menuInput!=5 && menuInput!=6 && menuInput!=7);    //checks if input is valid (do while loop was not functioning)
    return 0;
}
/*---------------------------------------------------------------------------*/
// 1. Rotation encryption (given text & key):
int task1(void) {   
    clrscr();                                                                                   
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The encryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("To begin, enter the text you wish to encrypt.\n");                                  //a prompt to enter a key
    printf("   Text: ");
    fgets(str, 100, stdin);
    scanf("");
    printf("Now enter a key between 0 and 26 to determine the amount of rotation.\n   Key: ");  //a prompt to enter the text to be encrypted
    scanf("%d", &key);                                                                          //assigns the input text to the array "str[]"
    if(key >= 0 && key <= 26)    {
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter
            if(str[i] >= 97)    {                                                               //checks for lower-case letters
                if(str[i] + key > 122 && str[i] < 123)    {                                     //checks if the letter is bigger than 'z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] += key;                                                                  //adds the value of "key" to the ASCII code of the letter
            } else if(str[i] >= 65 && str[i] <= 90)  {                                          //checks for upper-case letters
                if(str[i] + key > 90)    {                                                      //checks if the letter is bigger than 'Z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'Z + 1' into 'A'
                }
                str[i] += key;                                                                  //adds the value of "key" to the ASCII code of the letter
            }
        }
        printf("\nThe encrypted message reads: %s\n\n", str);                                   //prints the encrypted message
    }   else    {
        task1();
        }
    int a = 0;                                                                                  //option to return to main menu
    do {
        printf("Enter 1 to return to main menu: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------*/
// 2. Rotation decryption (given text & key):
int task2(void) {
    clrscr();                                                                                   //clears screen
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be decrypted of maximum length, 100
    printf("The decryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("To begin, enter a key between 0 and 26 to determine the amount of rotation.\n");    //a prompt to enter a key
    printf("   Key: ");
    scanf("%d", &key);                                                                          //assigns the input key to the variable, "key"
    if(key >= 0 && key <= 26)    {                                                              //check for an approriate key
        printf("Now enter the text to be decrypted: \n   Text: ");                              //a prompt to enter the text to be decrypted
        fgets(str, 100, stdin);                                                                 //assigns the input text to the array "str[]"
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the decrypted letter                                                                  //checks for whitespace
                if(str[i] >= 97)    {                                                           //checks for lower-case letters
                    if(str[i] - key < 97)    {                                                  //checks if the letter is smaller than 'a'
                        str[i] += 26;                                                           //adds 26 to turn 'z + 1' into 'a' if necessary
                    }
                    str[i] -= key;                                                              //adds the value of "key" to the ASCII code of the letter
                } else if(str[i] >= 65 && str[i] <= 90)  {                                      //checks for upper-case letters
                    if(str[i] - key < 65)    {                                                  //checks if the letter is smaller than 'A'
                        str[i] += 26;                                                           //adds 26 to turn 'Z + 1' into 'A' if necessary
                    }
                    str[i] -= key;                                                              //subtracts the value of "key" from the ASCII code of the letter
                }
        }
            printf("\n\nThe decrypted message reads: %s\n", str);                             //prints the decrypted message
    }   else    {
        task2();
    }
    int a;                                                                                      //sub-menu for repating the task returning to the menu
    do {
        printf("\n\nSelect an option:");    //a divider from the previous text, without using "clrscr()" function
        printf("   1. Restart task 2\n");
        printf("   2. Proceed to task 3\n");
        printf("   3. Return to menu\n\nSelection: ");
        scanf("%d", &a);
        switch(a)   {
            case 1: clrscr();
                    task2();
            case 2: menu();
            default: clrscr(); 
        }
    } while(a != 1 && a != 2);    
    return;
}
/*---------------------------------------------------------------------------*/
// 3. Substitution encryption (given text & key):
int task3(void) {
    clrscr();
    printf("3");
    return 0;
}
/*---------------------------------------------------------------------------*/
// 4. Substitution decryption (given text & key);
int task4(void) {
    clrscr();
    printf("4");
    return 0;
}
/*---------------------------------------------------------------------------*/
// 5. Roation decryption (given only text):
int task5(void) {
    clrscr();
    printf("5");
    return 0;
}
/*---------------------------------------------------------------------------*/
// 6. Substitution decryption (give only text):
int task6(void) {
    clrscr();
    printf("6");
    return 0;
}
/*---------------------------------------------------------------------------*/

/*//WHY DOES THIS WORK BUT TASK1() DOESN'T?
#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()  {
clrscr();                                                                                   
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The encryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("To begin, enter the text you wish to encrypt.\n");                                  //a prompt to enter a key
    printf("   Text: ");
    fgets(str, 100, stdin);
        printf("Now enter a ket between 0 and 26 to determine the amount of rotation.\n   Key: ");  //a prompt to enter the text to be encrypted
        scanf("%d", &key);                                                                      //assigns the input text to the array "str[]"
        if(key >= 0 && key <= 26)    {
            for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter
                if(str[i] != 32)    {                                                               //checks for whitespace
                    if(str[i] >= 97)    {                                                           //checks for lower-case letters
                        if(str[i] + key > 122)    {                                                 //checks if the letter is bigger than 'z'
                            str[i] -= 26;                                                           //subtracts 26 to turn 'z + 1' into 'a'
                        }
                        str[i] += key;                                                              //adds the value of "key" to the ASCII code of the letter
                    } else if(str[i] >= 65 && str[i] <= 90)  {                                      //checks for upper-case letters
                        if(str[i] + key > 90)    {                                                  //checks if the letter is bigger than 'Z'
                            str[i] -= 26;                                                           //subtracts 26 to turn 'Z + 1' into 'A'
                        }
                        str[i] += key;                                                              //adds the value of "key" to the ASCII code of the letter
                    }
                }    
            }
            printf("\n\nThe encrypted message reads: %s\n\n", str);                             //prints the encrypted message
        }
    return 0;
}
*/
