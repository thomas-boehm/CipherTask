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
    static int a = 0;                                                                           //a static variable used to store the user's selection
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
    static int a = 0;                                                                           //a static variable used to store the user's selection
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
/*This function has no arguments and no return value(s). This function is designed to encrypt a given text via a substituion cipher using a given key in the form of
  a rearranged alphabet (e.g. POIUYTREWQASDFGHJKLMNBVCXZ). When called from the menu, the name of the task is displayed at the top of the screen and the user is
  prompted with a request to enter the text they wish to encrypt, followed by the key. The encrypted text is then displayed back to the user. This encryption only
  changes letters, and therefore, numbers and punctuation are ignored. Additionally the program will read both lower and upper-case, however, any input text will be
  converted to upper-case, and subsequently, all output text will be in upper-case, also.*/
void task3(void) {
    int i, k;                                                                                   //'i' and 'k' are both used as counters
    char str[100];                                                                              //used to store the input string (maximum length of 100 characters)
    char key[26];                                                                               //used to store the input key as a rearranged alphabet
    char alph[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //regular alphabet
    printf("Task 3: Encryption of text via a subtitution cipher, given the text and the key.\n\n"); //a heading to inform the user which task they currently using
    printf("Enter the text you wish to encrypt.\n   Text: ");                                   //a prompt to enter text for encryption
    scanf(" %[^\n]%*c", str);                                                                   //reads the input text (including white space) and writes it to the array, 'str'
    printf("\nNow enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");  //a prompt to enter a key as a rearranged alphabet
    scanf("%s", key);                                                                           //reads input key and writes it to the array, 'key[]'
    for(i = 0; i < strlen(str); i++)   {                                                         //converts each letter of the input string and the key to a capital letter
        str[i] = toupper(str[i]);
        key[i] = toupper(key[i]);
    }  
    for(k = 0; k < strlen(str); k++)    {                                                       //for each letter of the input text                                                         
        for(i = 0; i < 26; i++) {                                                               //for each letter of the alphabet
            if(str[k] == alph[i])   {                                                           //checks if a given letter of the input text, 'str[]' matches a letter from the alphabet, 'alp[]'
                str[k] = key[i];                                                                //if so, assigns this letter to the new letter at that point in the alphabet, dictated by the input key, 'key[]'
                break;                                                                          //stops checking for that letter and moves onto the next
            }
        }
    }
    printf("\nThe encrypted text reads: %s\n\n", str);                                          //prints the encrypted message
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's selection
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
/*This function has no arguments and no return value(s). This function is designed to decrypt a given text via a substituion cipher using a given key in the form of
  a rearranged alphabet (e.g. POIUYTREWQASDFGHJKLMNBVCXZ). When called from the menu, the name of the task is displayed at the top of the screen and the user is
  prompted with a request to enter the text they wish to decrypt, followed by the key. The decrypted text is then displayed back to the user. This decryption only
  changes letters, and therefore, numbers and punctuation are ignored. Additionally the program will read both lower and upper-case, however, any input text will be
  converted to upper-case, and subsequently, all output text will be in upper-case, also.*/
void task4(void)    {
    int i, k;                                                                                   //'i' and 'k' are both used as counters
    char str[100];                                                                              //used to store the input string (maximum length of 100 characters)
    char key[26];                                                                               //used to store the input key as a rearranged alphabet
    char alph[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //regular alphabet
    printf("Task 4: Decryption of text encrypted via a subtitution cipher, given the text and the key.\n\n"); //a reminder of what this task does
    printf("Enter the text you wish to decrypt.\n   Text: ");                                   //a prompt to enter text for decryption
    scanf(" %[^\n]%*c", str);                                                                   //reads input text and assigns it to "str[]"
    printf("\nNow enter a key as a rearranged alphabet (e.g. QWERTYUIOPLKJHGFDSAZXCVBNM).\n   Key: ");    //a prompt to enter a key as a rearranged alphabet
    scanf("%s", key);                                                                           //reads input text and assigns it to "key[]"
    for(i = 0; i < strlen(str); i++)   {                                                        //converts each letter of the input string and the key to a capital letter
        str[i] = toupper(str[i]);
        key[i] = toupper(key[i]);
    } 
    for(k = 0; k < strlen(str); k++)    {                                                       //for each letter of the input text                                    
        for(i = 0; i < 26; i++) {                                                               //for each letter of the alphabet
            if(str[k] == key[i])   {                                                            //checks if a given letter of the input text, 'str[]' matches a letter from the key, 'key[]'
                str[k] = alph[i];                                                               //if so, assigns this letter to the old letter at that point in the alphabet, dictated by the alphabet string, 'alph[]'
                break;                                                                          //stops checking for that letter and moves onto the next
            }
        }
    }
    printf("\nThe decrypted text reads: %s\n\n", str);                                          //prints the decrypted message
//Option to return to the menu:
    static int a = 0;                                                                           //a static variable used to store the user's selection
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
/*This function has no arguments and no return value(s). This function is designed to decrypt a given text via a rotation cipher by an unknown amount of rotation.
  When called from the menu, the name of the task is displayed at the top of the screen and the user is prompted with a request to enter the text they wish to
  decrypt. The decrypted text is then displayed back to the user. This decryption only changes letters, and therefore, numbers and punctuation are ignored.
  Additionally the program will read both lower and upper-case, however, any input text will be converted to upper-case, and subsequently, all output text will be
  in upper-case, also.*/
void task5(void) {
    int a, b, c, d, e, f, m = 0, n;                                                             //these variables are used for counters
    char str[100];                                                                              //used to store the input text (maximum length of 100 characters)
    char sentence[100][20];                                                                     //used to store each individual word (of maximum 20 letters long) of the input sentence (of maximum 100 words long)
    char words[9976][20];                                                                       //used to store the most common words in the english dictionary
    printf("Task 5: Decryption of text encrypted via a subtitution cipher, given the text only (no key):\n\n"); //a heading to inform the user which task they are currently using
    printf("Enter the text to be decrypted.\n   Text: ");                                       //a prompt to the user to enter the text to be decrypted
    scanf(" %[^\n]%*c", str);                                                                   //reads the input text (including white space) and writes it to the array, 'str[]'
    FILE* dictionary;                                                                           //declaring the file variable to be used to refer to the file with the list of the 10 000 most common words
    dictionary = fopen("dictionary.txt", "r");                                                  //open the dictionary file for reading
	for(a = 0; a < strlen(str); a++)                                                            //converts all letters from the input text capitals
        str[a] = toupper(str[a]);
    n = SplitSentence(str, sentence);                                                           //breaks the input text into individual words, stored in 'sentence[][]'
    for(a = 0; a < 9976; a++)                                                                   //stores each word in the dictionary file into a local array, 'words[a]'
        fscanf(dictionary, "%s", words[a]);                                                                            
    for(a = 1; a < 26; a++)    {                                                                //for every possible rotation                                      
        for(b = 0; b < strlen(sentence[0]); b++) {                                              //for each individual letter of the input string                                                  
            if((int)sentence[0][b] >= 65 && (int)sentence[0][b] <= 90)   {                      //checks for upper case letters only (excludes letters and punctuation)
                if((int)sentence[0][b] + 1 > 90)                                                //checks if a rotation from 'z' to 'a' is necessary (if the new ASCII value of a character is greater than 'Z')  
                    sentence[0][b] -= 26;                                                       //converts 'Z + 1' into 'A' if necessary
                sentence[0][b]++;                                                               //rotates the letter
            }
        }
        //printf("%d. %s\n", a, sentence[0]);                                                   //prints every rotation of the string (TEMPORARY)
        for(c = 0; c < 9976; c++)   {                                                           //for every word of the imported dictionary
            if(strcasecmp(sentence[0], words[c]) == 0)  {                                       //check if the first word of the sentence matches a dictionary word
                //printf("MATCH '%s' with the word '%s'\n", sentence[0], words[c]);             //displays the word that matched (TEMPORARY)
                for(d = 0; d < strlen(sentence[1]); d++)    {                                   //if the first word matched, check if the second word matches also
                    if((int)sentence[1][d] >= 65 && (int)sentence[1][d] <= 90)  {               //checks for upper case letters only (excludes letters and punctuation)
                        if((int)sentence[1][d] + a > 90)                                        //checks if a rotation from 'z' to 'a' is necessary (if the new ASCII value of a character is greater than 'Z')
                            sentence[1][d] -= 26;                                               //converts 'Z + 1' into 'A' if necessary
                        sentence[1][d] += a;                                                    //applies the same rotation to the second word as was applied to the first word
                    }
                }
                //printf("%s\n", sentence[1]);                                                  //prints every second word (TEMPORARY)
                for(e = 0; e < 9976; e++)  {                                                    //for every word of the dictionary
                    if(strcasecmp(sentence[1], words[e]) == 0)    {                             //checks if the second word of the sentence rotated with the same amount as the first matches a dictionary word
                        //printf("SECOND MATCH with %s", words[e]);                             //displays the word that matched (TEMPORARY)
                        for(f = 0; f < strlen(str); f++)    {                                   //decrypts the entire sentence
                            if((int)str[f] >= 65 && (int)str[f] <= 90)  {                       //checks for upper-case letters (excludes numbers and punctuation)
                                if((int)str[f] + a > 90)                                        //checks if a rotation from 'z' to 'a' is necessary (if the new ASCII value of a character is greater than 'Z')
                                    str[f] -= 26;                                               //converts 'Z + 1' into 'A' if necessary
                            str[f] += a;                                                        //applies the rotation to the string, 'str[]'
                            }
                        }
                        printf("\n   Decrypted message: %s\n", str);                            //prints the decrypted message
                        break;                                                                  //stops checking for that rotation
                        break;                                                                  //stops checking for that word
                    }
                } 
            }
        }
    }
//Option to return to the menu:
    static int z = 0;                                                                           //a static variable used to store the user's selection
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