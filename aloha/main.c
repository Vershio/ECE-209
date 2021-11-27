/* ECE 209 Program 1 - Aloha Due 9/27/19
 *           Written by  Alan Zheng
 *   Program will take user input via keyboard characters to spell a Hawaiian word
 *   Using only the allowed characters, the program will print the
 *   pronunciation of the word unless a illegal character, symbols or etc. is presented
 *   The program will then output either your error or the pronunciation
 *   Legal characters are "a, e, i, o, u, p, k, h, l, m, n and ' "
 *
*/

#include <stdio.h>

int main() {
    char word[48];
    int illegal = 0;
    int na;
    int i;
    int wordlength = 0;


    scanf("%s", &word);
    for (i = 0; i < 48; i++) {
        if (word[i] == '\0') {
            wordlength = i;
            break;
        }
    }
    
    for (i = 0; i < wordlength; i++) {
        switch(word[i]){
            case 'A':
            case 'E': 
            case 'I':
            case 'O':
            case 'U':
            case 'P':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'W':
            case 'H': word[i] += 32;
            break;
        }
        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' &&
            word[i] != 'p' &&
            word[i] != 'k' && word[i] != 'l' && word[i] != 'm' && word[i] != 'n' && word[i] != 'w' &&
            word[i] != 'h' &&
            word[i] != '\'') {
            illegal = 1;
            na = i;
            break;
        }
        if (word[i] == 'p' || word[i] == 'k' || word[i] == 'l' || word[i] == 'm' || word[i] == 'n' || word[i] == 'w' || word[i] == 'h' || word[i] == '\'') {
            if (word[i + 1] == 'p' || word[i + 1] == 'k' || word[i + 1] == 'l' || word[i + 1] == 'm' ||
                word[i + 1] == 'n' || word[i + 1] == 'w' || word[i + 1] == 'h' || word[i + 1] == '\'') {
                illegal = 2;
                na = i;
                break;
            }
        }
        if (word[wordlength - 1] == 'p' || word[wordlength - 1] == 'k' || word[wordlength - 1] == 'l' || word[wordlength - 1] == 'm' || 
            word[wordlength - 1] == 'n' || word[wordlength - 1] == 'w' || word[wordlength - 1] == 'h' || word[wordlength - 1] == '\'') {
            illegal = 3;
            na = wordlength - 1;
            break;
        }
    }
    switch(illegal){
        case 1: printf("Character %c is not allowed.", word[na]);
                break;
        case 2: printf("Double consonants: %c%c.", word[na], word[na + 1]);
                break;
        case 3: printf("Consonant %c at the end of the word.", word[na]);
                break;
        default:
            for (i = 0; i < (wordlength); i++) {
                switch(word[i]){
                    case 'p':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'h':
                    case '\'': 
                        printf("%c", word[i]);
                        break;
                    case 'w':
                        if (word[i - 1] == 'i' || word[i - 1] == 'e') {
                            printf("v");
                        } else {
                            printf("%c", word[i]);
                        }
                        break;
                    case'a':
                        if (word[i + 1] == 'i' || word[i + 1] == 'e') {
                            printf("eye");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        } 
                        else if (word[i + 1] == 'o' || word[i + 1] == 'u') {
                            printf("ow");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        else {
                            printf("ah");
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        break;
                    case'e':
                        if (word[i + 1] == 'i') {
                            printf("ay");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        } 
                        else {
                            printf("eh");
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        break;
                    case'i':
                        if (word[i + 1] == 'u') {
                            printf("ew");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        else {
                            printf("ee");
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        break;
                    case'o':
                        if (word[i + 1] == 'i') {
                            printf("oy");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        } 
                        else if (word[i + 1] == 'u') {
                            printf("ow");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        } 
                        else {
                            printf("oh");
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }
                        break;
                    case'u':
                        if (word[i + 1] == 'i') {
                            printf("ooey");
                            i++;
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        } 
                        else {
                            printf("oo");
                            if (word[i + 1] != '\0' && word[i + 1] != '\'') {
                                printf("-");
                            }
                        }       
                        break;
                    default:
                }
            }
            printf("\n");
            break;
    }   
    return 0;
}