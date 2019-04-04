/*---------------------------------------------------------------------------*/
//Header files:
#include <stdio.h>
#include <conio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
//Function prototypes:
void menu(void);                                                                                //menu selection
//Tasks:
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);
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
    static int menuInput = 0;                                                                   //user's selection
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
            case 7: exit(7);
            default: printf("Invalid entry, please try again. ");
        } 
    }   while(menuInput!=1 && menuInput!=2 && menuInput!=3 && menuInput!=4 && menuInput!=5 && menuInput!=6 && menuInput!=7);    //checks if input is valid (do while loop was not functioning)
    return;
}
/*---------------------------------------------------------------------------*/
// 1. Rotation encryption (given text & key):
void task1(void) {   
    clrscr();                                                                                   
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The encryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("Enter the text you wish to encrypt, followed by a key between 0 and 26 to determine the amount of rotation\n");  //a prompt to enter text and a key
    printf("   Text: ");
    fgets(str, 100, stdin);
    printf("%s", str);
    printf("   ");
    scanf("%d", &key);                                                                          //assigns the input text to the array "str[]"
    if(key >= 0 && key <= 26)    {
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter
            if((int)str[i] >= 97 && (int)str[i] <= 122)    {                                    //checks for lower-case letters
                if((int)str[i] + key > 122)    {                                                //checks if the letter is bigger than 'z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] += key;                                                                  //adds the value of "key" to the ASCII code of the letter
            } else if((int)str[i] >= 65 && (int)str[i] <= 90)  {                                //checks for upper-case letters
                if((int)str[i] + key > 90)    {                                                 //checks if the letter is bigger than 'Z'
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
void task2(void) {
    clrscr();                                                                                   
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The decryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("Enter the text you wish to decrypt, followed by a key between 0 and 26 to determine the amount of rotation\n");  //a prompt to enter text and a key
    printf("   Text: ");
    fgets(str, 100, stdin);
    printf("%s", str);
    printf("   ");
    scanf("%d", &key);                                                                          //assigns the input text to the array "str[]"
    if(key >= 0 && key <= 26)    {
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter
            if((int)str[i] >= 97 && (int)str[i] <=122)    {                                     //checks for lower-case letters
                if((int)str[i] - key < 97)    {                                                 //checks if the letter is bigger than 'z'
                    str[i] += 26;                                                               //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] -= key;                                                                  //adds the value of "key" to the ASCII code of the letter
            } else if((int)str[i] >= 65 && (int)str[i] <= 90)  {                                //checks for upper-case letters
                if((int)str[i] - key < 65)    {                                                 //checks if the letter is bigger than 'Z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'Z + 1' into 'A'
                }
                str[i] -= key;                                                                  //adds the value of "key" to the ASCII code of the letter
            }
        }
        printf("\nThe decrypted message reads: %s\n\n", str);                                   //prints the encrypted message
    }   else    {
        task2();
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
// 3. Substitution encryption (given text & key):
void task3(void) {
    clrscr();
    int i, j, k;                                                                                   //counters
    char str[100];                                                                              //input text to be encrypted
    char key[26];                                                                               //input key for encryption
    char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; //regular alphabet
    printf("The encryption of text via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter text for encryption 
    fgets(str, 100, stdin);                                                                     //reads input text and assigns it to "str[]"
    printf("Now enter the key as a rearranged alphabet (e.g. qwertyuiopasdfghjklzxcvbnm):\n   Key: ");  //a prompt to enter the key
    scanf("%s", key);                                                                           //reads input text and assigns it to "key[]"
    for(i = 0; i <= 26; i++)    {                                                               
        for(k = 0; k < strlen(str); k++)    {
            if(str[k] == 32)   {
                str[k] == ' ';
            } else if(str[k] == alph[i])   {                                                           //checks if a given letter of the input text matches the regular alphabet, alph[]
                str[k] = key[i];                                                                //if so, assigns this letter to the new letter at that point in the alphabet, dictated by the input key
            }
        }
    }
    printf("\n%s\n\n", str);
    int a = 0;                                                                                  //option to return to main menu
    do {
        printf("Enter 1 to return to main menu: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        }
    } while(a != 1);  
    return 0;
}
/*---------------------------------------------------------------------------*/
// 4. Substitution decryption (given text & key);
void task4(void) {
    clrscr();
    printf("4");
    return 0;
}
/*---------------------------------------------------------------------------*/
// 5. Roation decryption (given only text):
void task5(void) {
    clrscr();
    printf("5");
    return 0;
}
/*---------------------------------------------------------------------------*/
// 6. Substitution decryption (give only text):
void task6(void) {
    clrscr();
    printf("6");
    return 0;
}
/*---------------------------------------------------------------------------*/
