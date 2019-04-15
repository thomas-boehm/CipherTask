/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Header files:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Function prototypes:
int SplitSentence(char *base, char target[100][20]);                                            //for splitting a sentence into words
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
    printf("Task 1: Encryption of text via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
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
    printf("Task 2: Decryption of text encrypted via a rotation cipher, given the text and the key:\n\n");    //a heading to remind the reader what this task does
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to enter the text to be decrypted
    scanf(" %[^\n]%*c", str);
    printf("\nNow enter a key between 0 and 26 to determine the amount of rotation\n   Key: ");
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
    printf("Task 3: Encryption of text via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter text for encryption
    scanf(" %[^\n]%*c", str);                                                                   //reads input text and assigns it to "str[]"
    printf("\nNow enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");    //a prompt to enter a key as a rearranged alphabet
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
    printf("Task 4: Decryption of text encrypted via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to enter text for decryption
    scanf(" %[^\n]%*c", str);                                                                   //reads input text and assigns it to "str[]"
    printf("\nNow enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");    //a prompt to enter a key as a rearranged alphabet
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
    int a, b, c, d, e, f, m = 0, n;
    char str[100];                                       //input sentence to be encrypted
    char line[128];                                      //each dictionary word
    char sentence[100][20];                               //sentence broken into 100 words each with 20 characters max
    char words[9976][20];                               //the dictionary is scanned into a local 2D array
    printf("Task 5: Decryption of text encrypted via a subtitution cipher, given the text only (no key):\n\n");
    printf("Enter the text to be decrypted.\n   Text: ");
    scanf(" %[^\n]%*c", str);
    FILE* dictionary;
    dictionary = fopen("dictionary.txt", "r");
	for(a = 0; a < strlen(str); a++)                                   //changes the input text to all capitals
        str[a] = toupper(str[a]);
    n = SplitSentence(str, sentence);                                      //reads the input sentence into seperate words
    for(a = 0; a < 9976; a++)
        fscanf(dictionary, "%s", words[a]);                            //scans dictionary file and stores words inside local array                                                   
    for(a = 1; a < 26; a++)    {                                        //for every possible rotation                                      
        for(b = 0; b < strlen(sentence[0]); b++) {                                      //for each individual letter of the input string                                                  
            if((int)sentence[0][b] >= 65 && (int)sentence[0][b] <= 90)   {                                         //checks for upper case letters only
                if((int)sentence[0][b] + 1 > 90)                                                    //checks if a rotation from 'z' to 'a' is necessary  
                    sentence[0][b] -= 26;                                                       
                sentence[0][b]++;                                                                   //rotates the letter
            }
        }
        //printf("%d. %s\n", a, sentence[0]);                                                                    //prints the string (TEMP)
        for(c = 0; c < 9976; c++)   {                                                          //for every word of the imported dictionary
            if(strcasecmp(sentence[0], words[c]) == 0)  {                                           //check if the first word of the sentence matches a word
                //printf("MATCH '%s' with the word '%s'\n", sentence[0], words[c]);                 //displays which word matched with what (TEMP)
                for(d = 0; d < strlen(sentence[1]); d++)    {
                    if((int)sentence[1][d] >= 65 && (int)sentence[1][d] <= 90)  {
                        if((int)sentence[1][d] + a > 90)
                            sentence[1][d] -= 26;
                        sentence[1][d] += a;
                    }
                }
                //printf("%s\n", sentence[1]);
                for(e = 0; e < 9976; e++)  {                                               //checks second word
                    if(strcasecmp(sentence[1], words[e]) == 0)    {
                        //printf("SECOND MATCH with %s", words[e]);
                        for(f = 0; f < strlen(str); f++)    {                                   //decrypts entire sentence
                            if((int)str[f] >= 65 && (int)str[f] <= 90)  {
                                if((int)str[f] + a > 90)
                                    str[f] -= 26;
                            str[f] += a;
                            }
                        }
                        printf("\n   Decrypted message: %s\n", str);
                        break;
                        break;
                    }
                } 
            }
        }
    }
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
    int a, b, c;
    char str[100];                  //input text
    int count[26];          //keeps count of each letter
    char alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};     //alphabet
    char key[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};      //encrypted alphabet
    printf("Task 6: Decryption of a message encrypted with a substitution cipher, given the text only (no key).\n\n");
    printf("Enter the text to be decrypted.\n   Text: ");
    //EXAMPLE SENTENCE: THE OTHER DAY I WENT FOR A WALK TO THE SHOPS AND BOUGHT SOME MILK BREAD AND BUTTER WHICH I DESPERATELY NEEDED AS I RECENTLY RAN OUT OF THOSE THINGS
    //                  JDS BJDSN WQL C KSGJ XBN Q KQVF JB JDS UDBYU QGW ABMEDJ UBTS TCVF ANSQW QGW AMJJSN KDCZD C WSUYSNQJSVL GSSWSW QU C NSZSGJVL NQG BMJ BX JDBUS JDCGEU
    scanf(" %[^\n]%*c", str);
	for(a = 0; a < strlen(str); a++)                                   //changes the input text to all capitals
        str[a] = toupper(str[a]);
    for(a = 0; a < 26; a++)
        count[a] = 0;                                             //itialises the count of each word to 0
    for(a = 0; a < strlen(str); a++)    {                       //counts the frequency of each letter
        for(b = 0; b < 26; b++) {
            if(str[a] == alph[b])
                count[b]++;
        }
    }
    printf("\n");
    for(a = 0; a < 26; a++)
        printf("%d ", count[a]);                    //to see the frequency of all letters (TEMP)
    b = 0;
    for(a = 0; a < 26; a++)    {                //calculates the most frequent occuring letter
        if(b < count[a])    
            b = count[a];
    }
    for(a = 0; a < 26; a++)    {
        if(count[a] == b)                       //sets the most commonly occuring character to "E"
            key[a] = 'E';
    }
    for(a = 0; a < strlen(str); a++)    {                           //DECRYPTION                                                        
        for(c = 0; c < 26; c++) { 
            if(str[a] == key[b])   {                                                    //checks if a given letter of the input text, "str[]" matches a letter from the key, "key[]"
                str[a] = alph[b];                                                       //if so, assigns this letter to the old letter at that point in the alphabet, dictated by the alphabet string, "alph[]"
                break;
            }
        }
    }
    printf("\n%d", b);
    printf("\nThe decrypted message reads: %s\n\n", str);
    
    
    
    
    
    
    
    
    
    static int z = 0;                                                                           //option to return to main menu
    do {
        printf("Enter 1 to return to the main menu or enter anything else to exit the program:\n   Selction: ");
        scanf("%d", &z);
        if(z == 1)  {
            menu();
        } else{
            exit(0);
        }
    } while(z != 1);  
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Function for breaking a sentence up into individual words:
int SplitSentence(char *original, char sentence[100][20])    {
	int n = 0, i, j = 0;	
	for(i = 0; i < 50; i++)  {
		if((int)original[i] != 32)    {
			sentence[n][j++] = original[i];
		} else    {
			sentence[n][j++] = '\0';       
			n++;
			j = 0;
		}
		if(original[i] == '\0')   {
		    break;
	    }
	}
	return n;
}	