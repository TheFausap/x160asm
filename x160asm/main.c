//
//  main.c
//  x160asm
//
//  Created by home on 21/10/2022.
//  Copyright © 2022 GITANES. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define w(x) fw(fou,(x))
#define w0 w(0)

FILE* fin;
FILE* fou;

int neg = 0;
int org = -1;
int oorg = 0;
int len = 0;
int disp = 0;
char bl = 0;
char bl0 = 0;

int slj = 0;

void fw(FILE* d, int s)
{
    switch(s){
        case 0:
            if (neg) {
                fputc('1',d);
                fputc('1',d);
                fputc('1',d);
            } else {
                fputc('0',d);
                fputc('0',d);
                fputc('0',d);
            }
            break;
        case 1:
            if (neg) {
                fputc('1',d);
                fputc('1',d);
                fputc('0',d);
            } else {
                fputc('0',d);
                fputc('0',d);
                fputc('1',d);
            }
            break;
        case 2:
            if (neg) {
                fputc('1',d);
                fputc('0',d);
                fputc('1',d);
            } else {
                fputc('0',d);
                fputc('1',d);
                fputc('0',d);
            }
            break;
        case 3:
            if (neg) {
                fputc('1',d);
                fputc('0',d);
                fputc('0',d);
            } else {
                fputc('0',d);
                fputc('1',d);
                fputc('1',d);
            }
            break;
        case 4:
            if (neg) {
                fputc('0',d);
                fputc('1',d);
                fputc('1',d);
            } else {
                fputc('1',d);
                fputc('0',d);
                fputc('0',d);
            }
            break;
        case 5:
            if (neg) {
                fputc('0',d);
                fputc('1',d);
                fputc('0',d);
            } else {
                fputc('1',d);
                fputc('0',d);
                fputc('1',d);
            }
            break;
        case 6:
            if (neg) {
                fputc('0',d);
                fputc('0',d);
                fputc('1',d);
            } else {
                fputc('1',d);
                fputc('1',d);
                fputc('0',d);
            }
            break;
        case 7:
            if (neg) {
                fputc('0',d);
                fputc('0',d);
                fputc('0',d);
            } else {
                fputc('1',d);
                fputc('1',d);
                fputc('1',d);
            }
            break;
        default:
            break;
    }
    len += 3;
    
    fputc(' ',d);
}

void vfy(const char* f)
{
    char c;
    int d;
    int spc = 0;
    
    fin = fopen(f,"r");
    while ((c = fgetc(fin)) != EOF) {
        if ((c == '@') || (c == '#')) {
            while ((c = fgetc(fin)) != '\n') {}
        }
        else if (c == ' ') {
            if (spc > 2) {
                printf("\n");
                spc = -1;
            }
            spc++;
        }
        else if (c == '\n') {
            
        }
        else {
            d = (c - '0')*4;
            d += (fgetc(fin) - '0')*2;
            d += (fgetc(fin) - '0');
            printf("%d",d);
            d=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    int t = 0;
    
    if (argc < 4) {
        printf("Error missing argument\n");
        exit(200);
    }
    
    if (strcmp(argv[1],"v") == 0) {
        vfy(argv[3]);
        exit(0);
    }
    
    fin = fopen(argv[2],"r");
    if (fin == NULL) {
        printf("Error opening input %s\n",argv[1]);
        exit(100);
    }
    
    fou = fopen(argv[3],"w");
    if (fou == NULL) {
        printf("Error opening output %s\n",argv[2]);
        exit(110);
    }
    
    while((c1 = fgetc(fin)) != EOF) {
        switch(c1) {
            case 'A':
                c2 = fgetc(fin);
                switch(c2) {
                    case 'C':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'J':
                                w0;w0;
                                w(7);
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
                                w(5);
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
                                w(3);
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
                                w0;
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
                            case 'U':
                                w0;w(1);
                                w(4);
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
                            case 'N':
                                w0;w(3);
                                break;
                        }
                        break;
                    case 'J':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'S':
                                w(7);w(7);
                                break;
                        }
                        break;
                    case 'L':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'S':
                                w(7);w(7);
                                w0;
                                break;
                            case 'J':
                                w(7);w(7);
                                slj = 1;
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
                            case 'J':
                                w0;w0;
                                w(1);
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
                                w0;w(1);
                                w(5);
                            case 'E':
                                w0;w(1);
                                w(6);
                                break;
                        }
                        break;
                    case 'I':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w0;w0;
                                w(2);
                                break;
                            case 'D':
                                w0;w0;
                                w(6);
                                break;
                        }
                        break;
                    case 'D':
                        c3 = fgetc(fin);
                        switch(c3) {
                            case 'C':
                                w0;w0;
                                w(4);
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
                if (slj) {
                    fw(fou,c1-'0');
                    w0;
                    slj = 0;
                } else {
                    fw(fou,c1-'0');
                }
                break;
            case '-':
                neg=1;
                break;
            case '\n':
                neg=0;
                break;
            case '#':
                t = 0;
                bl = fgetc(fin);
                fgetc(fin);
                for(int i=3;i>=0;i--) {
                    t += (fgetc(fin)-'0')*pow(8,i);
                }
                
                if (org == -1) {
                    org = t;
                    bl0 = bl;
                    fputc('#',fou);fputc(bl,fou);
                    fputc(',',fou);
                    fprintf(fou,"%04o",t);
                    fputc('\n',fou);
                } else {
                    if (bl == bl0) {
                        disp = t-(org+len/12);
                        printf("words: %o\tdisp: %o\n",len/12,disp);
                        for(int i=0;i<disp;i++) {
                            w0;w0;w0;w0;
                        }
                        org = t;
                    } else {
                        fputc('\n',fou);
                        fputc('#',fou);fputc(bl,fou);
                        fputc(',',fou);
                        fprintf(fou,"%04o",t);
                        fputc('\n',fou);
                        oorg = (org+len/12) + 1;
                    }
                }
                break;
            case '@':
                t = 0;
                for(int i=3;i>=0;i--) {
                    t += (fgetc(fin)-'0')*pow(8,i);
                }
                fprintf(fou,"@%04o\n",t);
                break;
            default:
                break;
        }
    }
    
    printf("%d (I+D) words used\n",len/12);
    
    return 0;
}
