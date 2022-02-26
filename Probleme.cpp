#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char a[]="abcdefghijklmnopqrstuvwxyz";

int main()
{
    //pb1
    /*
    srand(time(NULL));
    int r=rand()%11+10;
    FILE *fp;
    while(r) {
        char fn[31]="folder\\";
        int i=7;
        while(i<30) {
            fn[i]=a[rand()%26];
            i++;
        }
        fp = fopen(fn,"w+");
        int r2=rand()%10001+10000;
        while(r2) {
            fputc(a[rand()%26],fp);
            r2--;
        }
        fclose(fp);
        r--;
    }
    */
    //pb2
    /*
    FILE *fp;
    char c;
    int n;
    fp = fopen("folder\\date.txt","r+");
    c=fgetc(fp);
    while(c!=EOF) {
        if(c==' ') {
            n++;
            if(n%2==0)
                printf("%c",'\n');
            else
                printf("%c",'\t');
        } else printf("%c",c);
        c=fgetc(fp);
    }
    */
    //pb3
    /*
    FILE *fp;
    char c;
    fp = fopen("folder\\date.txt","r+");
    c=fgetc(fp);
    int n;
    while(c!=EOF) {
        if(c<58 && c>47)
            n++;
        if(c<123 && c>96) {
            n++;
            c-=32;
        } else {
            if (c<91 && c>64) {
                n++;
                c+=32;
            }
        }
        printf("%c",c);
        c=fgetc(fp);
    }
    */
    //pb4
}