//
//  main.c
//  x160asm
//
//  Created by home on 21/10/2022.
//  Copyright © 2022 GITANES. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define w(x) fw(fou,(x))
#define w0 w(0)

FILE* fin;
FILE* fou;

void fw(FILE* d, int s)
{
    switch(s){
        case 0:
            fputc('0',d);
            fputc('0',d);
            fputc('0',d);
            break;
        case 1:
            fputc('0',d);
            fputc('0',d);
            fputc('1',d);
            break;
        case 2:
            fputc('0',d);
            fputc('1',d);
            fputc('0',d);
            break;
        case 3:
            fputc('0',d);
            fputc('1',d);
            fputc('1',d);
            break;
        case 4:
            fputc('1',d);
            fputc('0',d);
            fputc('0',d);
            break;
        case 5:
            fputc('1',d);
            fputc('0',d);
            fputc('1',d);
            break;
        case 6:
            fputc('1',d);
            fputc('1',d);
            fputc('0',d);
            break;
        case 7:
            fputc('1',d);
            fputc('1',d);
            fputc('1',d);
            break;
        default:
            break;
    }
    
    fputc(' ',d);
}

int main(int argc, const char * argv[]) {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    
    if (argc < 3) {
        printf("Error missing argument\n");
        exit(200);
    }
    
    fin = fopen(argv[1],"r");
    fou = fopen(argv[2],"w");
    
    while((c1 = fgetc(fin)) != EOF) {
        switch(c1) {
            case 'A':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'C':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'J':
                                fw(fou,0);
                                fw(fou,0);
                                break;
                        }
                        break;
                    case 'D':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                fw(fou,3);fw(fou,2);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'F':
                                fw(fou,3);fw(fou,2);
                                break;
                            case 'M':
                                fw(fou,3);fw(fou,1);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'I':
                                fw(fou,3);fw(fou,1);
                                break;
                            case 'S':
                                fw(fou,3);fw(fou,3);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'B':
                                fw(fou,3);fw(fou,3);
                                break;
                            case 'D':
                                fw(fou,3);fw(fou,0);
                                break;
                            case 'N':
                                fw(fou,0);fw(fou,6);
                                break;
                        }
                        break;
                    case 'O':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                fw(fou,5);fw(fou,6);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'F':
                                fw(fou,5);fw(fou,6);
                                break;
                            case 'M':
                                fw(fou,5);fw(fou,5);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'I':
                                fw(fou,5);fw(fou,5);
                                break;
                            case 'S':
                                fw(fou,5);fw(fou,7);
                                fw(fou,0);fw(fou,0);
                                break;
                            case 'B':
                                fw(fou,5);fw(fou,7);
                                break;
                            case 'D':
                                fw(fou,5);fw(fou,4);
                                break;
                        }
                        break;
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'E':
                                fw(fou,0);fw(fou,1);
                                w(0);w(5);
                                break;
                            case 'X':
                                w(0);w(1);
                                w(0);w(6);
                                break;
                        }
                        break;
                }
                break;
            case 'B':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'L':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'S':
                                w(0);w(1);
                                w(0);w(0);
                                break;
                        }
                        break;
                }
                break;
            case 'C':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'B':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w0;w(1);
                                w0;w(4);
                                break;
                        }
                        break;
                    case 'I':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'L':
                                w0;w(1);
                                w(2);w0;
                                break;
                        }
                        break;
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'A':
                                w0;w(1);
                                w(3);w0;
                                break;
                        }
                        break;
                }
                break;
            case 'D':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'R':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'J':
                                w0;w0;
                                break;
                        }
                        break;
                }
                break;
            case 'E':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'R':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'R':
                                w0;w0;
                                w0;w0;
                                break;
                        }
                        break;
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'A':
                                w0;w(1);
                                w0;w(7);
                                break;
                        }
                        break;
                    case 'X':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(7);w(5);
                                w0;w0;
                                break;
                            case 'F':
                                w(7);w(5);
                                break;
                        }
                        break;
                }
                break;
            case 'H':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'L':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'T':
                                w(7);w(7);
                                w0;w0;
                                break;
                        }
                        break;
                    case 'W':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'I':
                                w(7);w(6);
                                break;
                        }
                        break;
                }
                break;
            case 'I':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'B':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'I':
                                w(7);w(2);
                                w0;w0;
                                break;
                            case 'O':
                                w(7);w(3);
                                w0;w0;
                                break;
                        }
                        break;
                    case 'N':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'P':
                                w(7);w(2);
                                break;
                            case 'A':
                                w(7);w(6);
                                w0;w0;
                                break;
                        }
                        break;
                    case 'R':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'J':
                                w0;w0;
                                break;
                        }
                        break;
                }
                break;
            case 'J':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'P':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'I':
                                w(7);w0;
                                break;
                            case 'R':
                                w(7);w(1);
                                w0;w0;
                                break;
                        }
                        break;
                    case 'F':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'I':
                                w(7);w(1);
                                break;
                        }
                        break;
                }
                break;
            case 'L':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'D':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(2);w(2);
                                w0;w0;
                                break;
                            case 'F':
                                w(2);w(2);
                                break;
                            case 'M':
                                w(2);w(1);
                                w0;w0;
                                break;
                            case 'I':
                                w(2);w(1);
                                break;
                            case 'S':
                                w(2);w(3);
                                w0;w0;
                                break;
                            case 'B':
                                w(2);w(3);
                                break;
                            case 'D':
                                w(2);w0;
                                break;
                            case 'N':
                                w0;w(4);
                                break;
                        }
                        break;
                    case 'C':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(2);w(6);
                                w0;w0;
                                break;
                            case 'F':
                                w(2);w(6);
                                break;
                            case 'M':
                                w(2);w(5);
                                w0;w0;
                                break;
                            case 'I':
                                w(2);w(5);
                                break;
                            case 'S':
                                w(2);w(7);
                                w0;w0;
                                break;
                            case 'B':
                                w(2);w(7);
                                break;
                            case 'D':
                                w(2);w(4);
                                break;
                            case 'N':
                                w0;w(5);
                                break;
                        }
                        break;
                    case 'P':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(1);w(2);
                                w0;w0;
                                break;
                            case 'F':
                                w(1);w(2);
                                break;
                            case 'M':
                                w(1);w(1);
                                w0;w0;
                                break;
                            case 'I':
                                w(1);w(1);
                                break;
                            case 'S':
                                w(1);w(3);
                                w0;w0;
                                break;
                            case 'B':
                                w(1);w(3);
                                break;
                            case 'D':
                                w(1);w0;
                                break;
                            case 'N':
                                w0;w(2);
                                break;
                        }
                        break;
                    case 'S':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case '1':
                                w0;w(1);
                                w0;w(2);
                                break;
                            case '2':
                                w0;w(1);
                                w0;w(3);
                                break;
                            case '3':
                                w0;w(1);
                                w(1);w0;
                                break;
                            case '6':
                                w0;w(1);
                                w(1);w(1);
                                break;
                        }
                        break;
                }
                break;
            case 'M':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'U':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'T':
                                w0;w(1);
                                w(1);w(2);
                                break;
                            case 'H':
                                w0;w(1);
                                w(1);w(3);
                                break;
                        }
                        break;
                }
                break;
            case 'P':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'J':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'B':
                                w(6);w(6);
                                break;
                            case 'F':
                                w(6);w(2);
                                break;
                        }
                        break;
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'A':
                                w0;w(1);
                                w0;w(1);
                                break;
                        }
                        break;
                }
                break;
            case 'N':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'O':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'P':
                                w0;w0;
                                break;
                        }
                        break;
                    case 'Z':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'F':
                                w(6);w(1);
                                break;
                            case 'B':
                                w(6);w(5);
                                break;
                        }
                        break;
                    case 'J':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'F':
                                w(6);w(3);
                                break;
                            case 'B':
                                w(6);w(7);
                                break;
                        }
                        break;
                }
                break;
            case 'O':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'N':
                                w(7);w(4);
                                break;
                            case 'A':
                                w(7);w(6);
                                w(7);w(7);
                                break;
                        }
                        break;
                    case 'U':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'T':
                                w(7);w(3);
                                break;
                        }
                        break;
                }
                break;
            case 'R':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'S':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case '1':
                                w0;w(1);
                                w(1);w(4);
                                break;
                            case '2':
                                w0;w(1);
                                w(1);w(5);
                                break;
                        }
                        break;
                    case 'A':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(5);w(2);
                                w0;w0;
                                break;
                            case 'F':
                                w(5);w(2);
                                break;
                            case 'M':
                                w(5);w(1);
                                w0;w0;
                                break;
                            case 'I':
                                w(5);w(1);
                                break;
                            case 'S':
                                w(5);w(3);
                                w0;w0;
                                break;
                            case 'B':
                                w(5);w(3);
                                break;
                            case 'D':
                                w(5);w0;
                                break;
                        }
                        break;
                }
                break;
            case 'S':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'B':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(3);w(6);
                                w0;w0;
                                break;
                            case 'F':
                                w(3);w(6);
                                break;
                            case 'M':
                                w(3);w(5);
                                w0;w0;
                                break;
                            case 'I':
                                w(3);w(5);
                                break;
                            case 'S':
                                w(3);w(7);
                                w0;w0;
                                break;
                            case 'B':
                                w(3);w(7);
                                break;
                            case 'D':
                                w(3);w(4);
                                break;
                            case 'N':
                                w0;w(7);
                                break;
                        }
                        break;
                    case 'C':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(1);w(6);
                                w0;w0;
                                break;
                            case 'F':
                                w(1);w(6);
                                break;
                            case 'M':
                                w(1);w(5);
                                w0;w0;
                                break;
                            case 'I':
                                w(1);w(5);
                                break;
                            case 'S':
                                w(1);w(7);
                                w0;w0;
                                break;
                            case 'B':
                                w(1);w(7);
                                break;
                            case 'D':
                                w(1);w(4);
                                break;
                        }
                        break;
                    case 'L':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'S':
                            case 'J':
                                w(7);w(7);
                                break;
                        }
                        break;
                    case 'R':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(4);w(6);
                                w0;w0;
                                break;
                            case 'F':
                                w(4);w(6);
                                break;
                            case 'M':
                                w(4);w(5);
                                w0;w0;
                                break;
                            case 'I':
                                w(4);w(5);
                                break;
                            case 'S':
                                w(4);w(7);
                                w0;w0;
                                break;
                            case 'B':
                                w(4);w(7);
                                break;
                            case 'D':
                                w(4);w(4);
                                break;
                        }
                        break;
                    case 'T':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w(4);w(2);
                                w0;w0;
                                break;
                            case 'F':
                                w(4);w(2);
                                break;
                            case 'M':
                                w(4);w(1);
                                w0;w0;
                                break;
                            case 'I':
                                w(4);w(1);
                                break;
                            case 'S':
                                w(4);w(3);
                                w0;w0;
                                break;
                            case 'B':
                                w(4);w(3);
                                break;
                            case 'D':
                                w(4);w0;
                                break;
                            case 'P':
                            case 'E':
                                w0;w(1);
                                break;
                        }
                        break;
                    case 'I':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                            case 'D':
                                w0;w0;
                                break;
                        }
                        break;
                    case 'D':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w0;w0;
                                break;
                        }
                        break;
                }
                break;
            case 'Z':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'J':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'F':
                                w(6);w0;
                                break;
                            case 'B':
                                w(6);w(4);
                                break;
                        }
                        break;
                }
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                fw(fou,c1-'0');
                break;
            default:
                break;
        }
    }
    
    return 0;
}
