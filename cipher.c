/*This code is designed to complete six unique tasks involving encryption and decrpytion of text using rotation and substitution ciphers. The code beings by
offering the user a menu from which they can select the task they wish to complete. Once a task has been completed, the program will offer the user to return to
the main menu, where they can then choose to execute the same or a different task. Additionally, the user can choose to quit the program from the menu. Each task
is a seperate function, which the menu will call when the user requests. This program takes the user's input from the standard input and outputs to the standard
output.*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Header files:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>                                                                              //used for converting lower-case letters to upper-case using 'toupper()'
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
/*The program begins in main, where the menu function is called immediately.*/
int main()  {
    menu();                                                                                     //the menu is called
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Function definitions: 
//Menu:
/*The menu function consists of a list of possible selections being displayed to the user, followed by a request to choose a selection. This function has no
  arguments and no return value. This function is specifically designed as gateway to access the tasks that this program is designed to execute. The selection
  process is achieved via a 'switch' statement, where the user's input (a number corresponding to the task number they wish to access) is read, and the
  corresponding task (function) is called. If anything other than 1 to 7 is input, the function will restart and inform the user of an invalid entry.*/
void menu(void) {
    static int menuInput = 0;                                                                   //a variable to store  the user's selection
    do  {                                                                                       //a 'do while' loop is used to execute the menu once, and then repeat it if the input selection is invalid
        printf("Enter the number that corresponds to the program you wish to access: \n\n");    //a prompt to the user to input a selection that corresponds to the task they wish to access
        printf("   1. Encryption of a message with a rotation cipher, given the text and the key.\n");  //the seven possible selections that the user can choose
        printf("   2. Decryption of a message encrypted with a rotation cipher, given text and the key.\n");
        printf("   3. Encryption of a message with a substitution cipher, given text and the key.\n");
        printf("   4. Decryption of a message encrypted with a substitution cipher, given the text and the key.\n");
        printf("   5. Decryption of a message encrypted with a rotation cipher, given the text only (no key).\n");
        printf("   6. Decryption of a message encrypted with a substitution cipher, given the text only (no key).\n");
        printf("   7. Exit.\n\nSelection: ");
        scanf("%d", &menuInput);                                                                //writes the user's input into the variable, 'menuInput'
        switch(menuInput)   {                                                                   //reads the 'menuInput' and calls the corresponding function
            case 1: task1();                                                                    //the seven possible functions to execute:
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
            default: printf("Invalid entry, please try again. ");                                //if the input is invalid, the function will restart and the user will be prompted to try again
        } 
    }   while(menuInput!=1 && menuInput!=2 && menuInput!=3 && menuInput!=4 && menuInput!=5 && menuInput!=6 && menuInput!=7);    //checks if input is valid
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 1. Rotation encryption (given text & key):
/*This function has no arguments and no return value(s). This function is designed to encrypt a given text via a rotation cipher by a given amount of rotation.
  When called from the menu, the name of the task is displayed at the top of the screen and the user is prompted with a request to enter the text they wish to
  encrypt, followed by the amount of rotation required to do so. The encrypted text is then displayed back to the user. This encryption only changes letters, and
  therefore, numbers and punctuation are ignored. Additionally the program will read both lower and upper-case, however, any input text will be converted to upper-
  case, and subsequently, all output text will be in upper-case, also.*/
void task1(void) {                                                                                     
    int i, key;                                                                                 //'i' is a counter (index), 'key' is the amount of rotation
    char str[100];                                                                              //used to store the input string, which can have a maximum character length of 100
    printf("Task 1: Encryption of text via a rotation cipher, given the text and the key:\n\n");//a heading to inform the user which task they are currently using
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter the text to be encrypted
    scanf(" %[^\n]%*c", str);                                                                   //this code reads input text (including white space) and writes it into 'str[]'
    printf("Now enter a key between 0 and 26 to determine the amount of rotation.\n   Key: ");  //a prompt to enter a key to determine the amount of rotation
    scanf("%d", &key);                                                                          //assigns the input key to the variable 'key'
    if(key >= 0 && key < 26)    {                                                               //checks if the key is valid (between 0 and 26)
        for(i = 0; i < strlen(str); i++)   {                                                    //for every letter of the string
            if((int)str[i] >= 97 && (int)str[i] <= 122)    {                                    //checks for lower-case letters
                if((int)str[i] + key > 122)    {                                                //checks if the letter is greater than the ASCII value for 'z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'z + 1' into 'a'
                }
                str[i] = str[i] + key - 32;                                                     //adds the value of "key" to the ASCII code of the letter and converts lower-case letters to upper-case
            } else if((int)str[i] >= 65 && (int)str[i] <= 90)  {                                //checks for upper-case letters
                if((int)str[i] + key > 90)    {                                                 //checks if the letter is greater than the ASCII value for 'Z'
                    str[i] -= 26;                                                               //subtracts 26 to turn 'Z + 1' into 'A'
                }
                str[i] += key;                                                                  //adds the value of "key" to the ASCII code of the letter
            }
        }
        printf("\nThe encrypted message reads: %s\n\n", str);                                   //prints the encrypted message
    }   else    {                                                                               //if the key is invalid, the function is called again (restarts)
        task1();
        }
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &a);                                                                            //writes the input selection to the static variable, 'a'
    if(a == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
    return;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// 2. Rotation decryption (given text & key):
/*This function has no arguments and no return value(s). This function is designed to decrypt a given text via a rotation cipher by a given amount of rotation.
  When called from the menu, the name of the task is displayed at the top of the screen and the user is prompted with a request to enter the text they wish to
  decrypt, followed by the amount of rotation required to do so. The decrypted text is then displayed back to the user. This decryption only changes letters, and
  therefore, numbers and punctuation are ignored. Additionally the program will read both lower and upper-case, however, any input text will be converted to upper-
  case, and subsequently, all output text will be in upper-case, also.*/
void task2(void) {                                                                                  
    int i, key;                                                                                 //"i" is a counter (index), "key" is the amount of rotation
    char str[100];                                                                              ////used to store the input string, which can have a maximum character length of 100
    printf("Task 2: Decryption of text encrypted via a rotation cipher, given the text and the key:\n\n");    //a heading to inform the reader which task they are currently using
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to the user to enter the text to be decrypted
    scanf(" %[^\n]%*c", str);                                                                   //reads input text (including white space) and writes it into the array, 'str[]'
    printf("\nNow enter a key between 0 and 26 to determine the amount of rotation\n   Key: "); //a prompt to the user to input a key to determine the amount of rotation
    scanf("%d", &key);                                                                          //assigns the input key to the variable, 'key'
    if(key >= 0 && key < 26)    {                                                               //checks if the key is valid (between 0 and 26)
        for(i = 0; i < strlen(str); i++)   {                                                    //for every letter of the string
            if((int)str[i] >= 97 && (int)str[i] <=122)    {                                     //checks for lower-case letters
                if((int)str[i] - key < 97)    {                                                 //checks if the letter is less than the ASCII value for 'a'
                    str[i] += 26;                                                               //subtracts 26 to turn 'a - 1' into 'z'
                }
                str[i] = str[i] - key - 32;                                                     //adds the value of "key" to the ASCII code of the letter and converts the letter to upper-case
            } else if((int)str[i] >= 65 && (int)str[i] <= 90)  {                                //checks for upper-case letters
                if((int)str[i] - key < 65)    {                                                 //checks if the letter is less than the ASCII value for 'A'
                    str[i] += 26;                                                               //subtracts 26 to turn 'A - 1' into 'Z'
                }
                str[i] -= key;                                                                  //adds the value of "key" to the ASCII code of the letter
            }
        }
        printf("\nThe decrypted message reads: %s\n\n", str);                                   //prints the encrypted message
    }   else    {                                                                               //if the key is invalid, the function is called again (restarts)
        task2();
        }
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &a);                                                                            //writes the input selection to the static variable, 'a'
    if(a == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
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
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &a);                                                                            //writes the input selection to the static variable, 'a'
    if(a == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
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
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &a);                                                                            //writes the input selection to the static variable, 'a'
    if(a == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
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
//Option to return to the menu:
    static int z = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &z);                                                                            //writes the input selection to the static variable, 'z'
    if(z == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
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
//Option to return to the menu:
    static int z = 0;                                                                           //a static variable used to store the user's 
    printf("Enter 1 to return to the main menu or enter anything else to exit the program.\n   Selction: ");    //a prompt to the user to make a choice to return to the menu or to quit the program
    scanf("%d", &z);                                                                            //writes the input selection to the static variable, 'z'
    if(z == 1)  {                                                                               //checks if the input was '1'
        menu();                                                                                 //calls the menu function
    } else  {
        exit(0);                                                                                //quits the program if anything other than '1' is input
    } 
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