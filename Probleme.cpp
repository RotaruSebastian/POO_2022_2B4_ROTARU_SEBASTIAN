#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char a[]="abcdefghijklmnopqrstuvwxyz";

int toNumber(char c1, char c2) {
    return c2-48+(c1-48)*10;
}

int rezRad(int nb, int num) {
    int i=1;
    while(i*(i+num)<=nb)
        i++;
    return i-1;
}

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
    //aproximativ corecta, ultimele zecimale sunt gresite
    //probabil am gresit ceva la variabila "adaos" intrucat nu stiu algoritmul, dar nu pot sa zic sigur
    /*
    char s[25];
    scanf("%s",s);
    int n=strlen(s);
    int i=0;
    while(i<n) {
        if(s[i]<48 || s[i]>57)
            strcpy(s+i,s+i+1);
        i++;
    }
    char s2[26];
    s2[0]='\0';
    if(strlen(s)%2)
    {
        strcat(s2,"0");
        strcat(s2,s);
    } else strcpy(s2,s);
    while(strlen(s2)<20)
        strcat(s2,"0");
    int rez[]={0,0,0,0,0,0,0,0,0,0};

    i=0;
    long int adaos=0;
    long int adaosvechi=0;
    long int number=0;
    long int x=0;
    long int segment=0;
    while(i<21) {
        segment=toNumber(s2[0],s2[1]);
        strcpy(s2,s2+2);

        number=(number-x*(x+adaosvechi))*100+segment;
        x=0;
        while((x+1)*(x+adaos+1)<=number) {
            x++;
        }
        rez[i/2]=x;
        i+=2;

        adaosvechi=adaos;
        adaos=adaos*10+adaos%100+20;
    }

    i=0,n=10;
    printf("\n");
    while(i<n){
        printf("%d",rez[i]);
        i++;
    }
    printf("\n");
    */
}