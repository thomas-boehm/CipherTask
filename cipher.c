/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Header files:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Terminal commands:
ls - dispaly all files in current directory
cd - current directory eg cd CipherTask changes to the "CipherTask" folder
gcc cipher.c -compile cipher.c file
./a.out - run program
*/

//Function prototypes:
int countWords(char *base, char target[100][20]);
void menu(void);                                                                                //menu selection
//Tasks:
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//MAIN (Calling the menu fuction):
int main()  {
    menu();
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Function definitions: 
//Menu
void menu(void) {
    static int menuInput = 0;                                                                   //user's selection
    do  {
        printf("Enter the number that corresponds to the program you wish to access: \n\n");
        printf("   1. Encryption of a message with a rotation cipher, given the text and the key.\n");
        printf("   2. Decryption of a message encrypted with a rotation cipher, given text and the key.\n");
        printf("   3. Encryption of a message with a substitution cipher, given text and the key.\n");
        printf("   4. Decryption of a message encrypted with a substitution cipher, given the text and the key.\n");
        printf("   5. Decryption of a message encrypted with a rotation cipher, given the text only (no key).\n");
        printf("   6. Decryption of a message encrypted with a substitution cipher, given the text only (no key).\n");
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
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 1. Rotation encryption (given text & key):
void task1(void) {                                                                                     
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The encryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter the text to be encrypted
    scanf(" %[^\n]%*c", str);
    printf("Now enter a key between 0 and 26 to determine the amount of rotation.\n   Key: ");
    scanf("%d", &key);                                                                          //assigns the input text to the array "str[]"
    if(key >= 0 && key < 26)    {
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter                                                                     //checks for a positive key
            if((int)str[i] >= 97 && (int)str[i] <= 122)    {                                    //checks for lower-case letters
                if((int)str[i] + key > 122)    {                                                //checks if the letter is bigger than 'z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] = str[i] + key - 32;                                                     //adds the value of "key" to the ASCII code of the letter
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
    static int a = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 2. Rotation decryption (given text & key):
void task2(void) {                                                                                  
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              //"str[100]" is the string of text to be encrypted of maximum length, 100
    printf("The decryption of text encrypted via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to enter the text to be decrypted
    scanf(" %[^\n]%*c", str);
    printf("Now enter a key between 0 and 26 to determine the amount of rotation\n   Key: ");
    scanf("%d", &key);                                                                          //assigns the input text to the array "str[]"
    if(key >= -25 && key <= 25)    {
        for(i = 0; i < strlen(str); i++)   {                                                    //converts each letter of the input string to the encrypted letter
            if((int)str[i] >= 97 && (int)str[i] <=122)    {                                 //checks for lower-case letters
                if((int)str[i] - key < 97)    {                                             //checks if the letter is bigger than 'z'
                    str[i] += 26;                                                           //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] = str[i] - key - 32;                                                 //adds the value of "key" to the ASCII code of the letter
            } else if((int)str[i] >= 65 && (int)str[i] <= 90)  {                            //checks for upper-case letters
                if((int)str[i] - key < 65)    {                                             //checks if the letter is bigger than 'Z'
                    str[i] += 26;                                                           //subtracts 26 to turn 'Z + 1' into 'A'
                }
                str[i] -= key;                                                              //adds the value of "key" to the ASCII code of the letter
            }
        }
        printf("\nThe decrypted message reads: %s\n\n", str);                                   //prints the encrypted message
    }   else    {
        task2();
        }
    static int a = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program:\n   Selction: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 3. Substitution encryption (given text & key):
void task3(void) {
    int i, k;                                                                                   //counters
    char str[100];                                                                              //input text to be encrypted
    char key[26];                                                                               //input key for encryption
    char alph[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //regular alphabet
    printf("The encryption of text via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter text for encryption
    scanf(" %[^\n]%*c", str);                                                                   //reads input text and assigns it to "str[]"
    printf("Now enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");    //a prompt to enter a key as a rearranged alphabet
    scanf("%s", key);                                                                           //reads input text and assigns it to "key[]"
    for(i = 0; i < strlen(str); i++)    {    
        if(str[i] >= 97 && str[i] <= 122)   {
            str[i] -= 32;
        }
    }
    for(i = 0; i < 26; i++) {                                                                   //for each individual letter of "key[]"
        if(key[i] >= 97 && key[i] <= 122)   {                                                   //checks if the letter is lower-case
            key[i] -= 32;                                                                       //changes the letter from lower to upper-case
        }
    }    
    for(k = 0; k < strlen(str); k++)    {                                                       //for each letter of the input text                                                         
        for(i = 0; i < 26; i++) {                                                               //for each letter of the alphabet
            if(str[k] == alph[i])   {                                                           //checks if a given letter of the input text matches a letter from the alphabet
                str[k] = key[i];                                                                //if so, assigns this letter to the new letter at that point in the alphabet, dictated by the input key
                break;                                                                          //stops checking for that letter and moves onto the next
            }
        }
    }
    printf("\nThe encrypted text reads: %s\n\n", str);                                          //prints the encrypted message to the console
    static int a = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program:\n   Selection: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 4. Substitution decryption (given text & key);
void task4(void)    {
    int i, k;                                                                                   //counters
    char str[100];                                                                              //input text to be decrypted
    char key[26];                                                                               //input key for decryption
    char alph[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //regular alphabet
    printf("The decryption of text encrypted via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to enter text for decryption
    scanf(" %[^\n]%*c", str);                                                                   //reads input text and assigns it to "str[]"
    printf("Now enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");    //a prompt to enter a key as a rearranged alphabet
    scanf("%s", key);                                                                           //reads input text and assigns it to "key[]"
    for(i = 0; i < strlen(str); i++)    {    
        if(str[i] >= 97 && str[i] <= 122)   {
            str[i] -= 32;
        }
    }    
    for(i = 0; i < 26; i++) {
        if(key[i] >= 97 && key[i] <= 122)   {
            key[i] -= 32;
        }
    }
    for(k = 0; k < strlen(str); k++)    {                                                               
        for(i = 0; i < 26; i++) { 
            if(str[k] == key[i])   {                                                    //checks if a given letter of the input text, "str[]" matches a letter from the key, "key[]"
                str[k] = alph[i];                                                       //if so, assigns this letter to the old letter at that point in the alphabet, dictated by the alphabet string, "alph[]"
                break;
            }
        }
    }
    printf("\nThe decrypted text reads: %s\n\n", str);
    static int a = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program:\n   Selection: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 5. Roation decryption (given only text):
void task5(void) {
    int a, b, c, d, n;
    char str[100];                                       //input sentence to be encrypted
    char line[128];                                      //each dictionary word
    char sentence[100][20];                               //sentence broken into 100 words each with 20 characters
    char words[10000][20];
    printf("The decryption of text encrypted via a subtitution cipher, given the text only (no key):\n\n");
    printf("Enter the text to be decrypted.\n   Text: ");
    scanf(" %[^\n]%*c", str);
    FILE* dictionary;
    dictionary = fopen("dictionary.txt", "r");
	for(a = 0; a < strlen(str); a++)                                   //changes the input text to all capitals
        str[a] = toupper(str[a]);
    n = countWords(str, sentence); 
    for(a = 0; a < 100; a++)
        fscanf(dictionary, "%s", words[a]);                                                     
    for(a = 0; a < 25; a++)    {                                        
        for(b = 0; b < strlen(sentence[0]); b++) {                                                        
            if((int)sentence[0][b] >= 65 && (int)sentence[0][b] <= 90)   {                                         //checks for upper case letters
                if((int)sentence[0][b] + 1 > 90)   {
                    sentence[0][b] -= 26;
                }
                sentence[0][b]++;
                printf("%s\n", sentence[0]);
                for(c = 0; c < 10000; c++)   {
                    if(strcasecmp(sentence[0], words[c]) == 0)  {
                        printf("MATCH '%s' with the word '%s'\n", sentence[0], words[c]);
                        break;
                    }
                }
            }
        }
    }

    
    
            

     
 
 
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*int i, n, m, j, b, k;                                                                            //counters
    int x = 0, y = 0, z = 0;
    char str[100];
    char line[128];
    char sentence[100][20];
    char check1[20], check2[20];
    printf("The decryption of text encrypted via a subtitution cipher, given the text only (no key):\n\n");
    printf("Enter the text to be decrypted.\n   Text: ");
    scanf(" %[^\n]%*c", str);
    FILE *dictionary;
    dictionary = fopen("dictionary.txt", "r");
	n = countWords(str, sentence);
    for(b = 0; b <= 10000; b++) {
        fscanf(dictionary, "%s", line);
        for(i = 0; i < 26; i++)    {                                                                //checks all 26 rotations 
            for(j = 0; j < strlen(sentence[0]); j++)    {
                if(sentence[0][j] >= 97 && sentence[0][j] <= 122)   {                                               //checks for lower case letters
                    if((int)sentence[0][j] + 1 > 122)   {
                        sentence[0][j] -= 26;
                    }
                    sentence[0][j]++;
                } else if(sentence[0][j] >= 65 && sentence[0][j] <= 90)   {                                         //checks for upper case letters
                            if((int)sentence[0][j] + 1 > 90)   {
                                sentence[0][j] -= 26;
                            }
                        sentence[0][j]++;
                        }
            }
        }
        sentence[0] = check1;
        sentence[1] = check2;
        if(strcasecmp(sentence[0], line) == 0) {
            printf("\nMATCH with the word: '%s'\n", line);
            for(k = 0; k < strlen(str); k++)    {
                if(str[k] >= 97 && str[k] <= 122)   {
                    if((int)str[k] + i > 122)   {
                        str[k] -= 26;
                    }
                    str[k] += i;
                    } else  if(str[k] >= 65 && str[k] <= 90)   {
                                if((int)str[k] + i > 90)   {
                                    str[k] -= 26;
                                }
                            str[k] += i;
                            break;
                            }
            }
        printf("The encrypted message reads: %s\n\n", str);
        }
    }
    */
    static int z = 0;                                                                           //option to return to main menu
    do {
        printf("\nEnter 1 to return to the main menu or enter anything else to exit the program:\n   Selction: ");
        scanf("%d", &z);
        if(z == 1)  {
            menu();
        } else  {
            exit(0);
        }
    } while(z != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 6. Substitution decryption (give only text):
void task6(void) {
    printf("6");
    static int a = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program:\n   Selction: ");
        scanf("%d", &a);
        if(a == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(a != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Function for reading words:
int countWords(char *base, char target[100][20])    {
	int n = 0, i, j = 0;	
	for(i = 0; i < 50; i++)  {
		if(base[i] != ' ')    {
			target[n][j++] = base[i];
		} else    {
			target[n][j++] = '\0';       
			n++;
			j = 0;
		}
		if(base[i] == '\0')   {
		    break;
	    }
	}
	return n;
}