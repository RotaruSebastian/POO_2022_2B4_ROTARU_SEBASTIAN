#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

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

int getSize(char s[]) {
    int i=0;
    int n=strlen(s);
    int size=1;
    while(i<n) {
        if(s[i]==' ')
            size++;
        i++;
    }
    return size;
}

void toString(char s[], int num) {
    bool negativ=0;
    if(num<0) {
        negativ=1;
        num=-num;
    }
    int i=0,n;
    char c;
    while(num) {
        s[i]=num%10+'0';
        num/=10;
        i++;
    }
    n=strlen(s);
    i=0;
    while(i<n/2) {
        c=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=c;
        i++;
    }
    char s2[50]="-";
    if(negativ) {
        strcat(s2,s);
        strcpy(s,s2);
    }
}

void funcOp(char c1, char c2, char s[]) {
    bool ok=1;
    char zero[]={'\0'};
    int n,i,j,k,p,n1,n2,n3;
    while(ok) {
        ok=0;
        n=strlen(s);
        i=1;
        while(i<n) {
            if(s[i]==c1 || s[i]==c2) {
                j=i-1;
                p=1;
                n1=0;
                n2=0;
                while((s[j]>47 && s[j]<58) || s[j]=='-') {
                    n1=n1+p*(s[j]-48);
                    p*=10;
                    j--;
                    if(s[j]=='-') {
                        n1=-n1;
                        break;
                    }
                }
                j++;
                k=i+1;
                while(s[k]>47 && s[k]<58) {
                    n2=n2*10+s[k]-48;
                    k++;
                }
                k--;
                switch(s[i]) {
                    case '*':
                        n3=n1*n2;
                        break;
                    case '/':
                        n3=n1/n2;
                        break;
                    case '+':
                        n3=n1+n2;
                        break;
                    default:
                        n3=n1-n2;
                }
                char s2[50]={'\0'};
                char s3[50]={'\0'};
                char s4[50]={'\0'};
                toString(s3,n3);
                strcpy(s4,s+k+1);
                if(j)
                    strncpy(s2,s,j);
                if(strcmp(s2,"-"))
                    strcpy(s,s2);
                else strcpy(s,zero);
                strcat(s,s3);
                strcat(s,s4);
                ok=1;
                break;
            }
            i++;
        }
    }
}

void rezOp(char s[]) {
    funcOp('*','/',s);
    funcOp('+','-',s);
    int i=0;
    int n=strlen(s);
    int num=0;
    while(i<n) {
        num=num*10+s[i]-48;
        i++;
    }
    printf("\n%s\n",s);
}

int numInt(int num) {
    int n=0;
label:
    printf("\n%d\n",num);
    while(num) {
        n+=num%10;
        num/=10;
    }
    if(n>9) {
        num=n;
        n=0;
        goto label;
    }
    return n;
}

int numString(char s[]) {
    int i=0;
    int num=0;
    int n=strlen(s);
    while(i<n) {
        num+=s[i]-48;
        i++;
    }
    num+=38;
    return numInt(num);
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

    //pb5
    /*
    char s[50];
    FILE* fp=fopen("/home/rotaru/POO-2022/input.txt","r");
    fgets(s,50,fp);
    int m1=getSize(s);
    int n1=0;
    while(s[0]!='\n') {
        n1++;
        fgets(s,50,fp);
    }
    fgets(s,50,fp);
    int m2=getSize(s);
    int n2=0;
    while(!feof(fp)) {
        n2++;
        fgets(s,50,fp);
    }
    fclose(fp);
    fp=fopen("/home/rotaru/POO-2022/input.txt","r");
    int a[n1][m1];
    int b[n2][m2];
    int c[n1][m2];
    int i=0,j=0,k=0,num=0;
    fscanf(fp,"%d", &num);
    a[0][0]=num;
    j=1;
    while(i<n1) {
        while(j<m1) {
            fscanf(fp,"%d",&num);
            a[i][j]=num;
            j++;
        }
        i++;
        j=0;
    }
    i=0;
    while(i<n2) {
        j=0;
        while(j<m2) {
            fscanf(fp,"%d",&num);
            b[i][j]=num;
            j++;
        }
        i++;
    }
    fclose(fp);
    i=0;
    while(i<n1) {
        j=0;
        while(j<m2) {
            c[i][j]=0;
            k=0;
            while(k<n2) {
                c[i][j]+=a[i][k]*b[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    i=0;
    while(i<n1) {
        j=0;
        while(j<m2) {
            printf("%d ",c[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    */

    //pb6
    /*
    FILE *fp = fopen("/home/rotaru/POO-2022/input.txt","r");
    char s[50];
    while(fgets(s,50,fp)) {
        rezOp(s);
    }
    */

    //pb7
    /*
    FILE *fp = fopen("/home/rotaru/POO-2022/input.txt","r");
    char s[150];
    int num=0;
    fgets(s,150,fp);
    while(!feof(fp)) {
        num=numString(s);
        printf("\n%d\n",num);
        fgets(s,150,fp);
    }
    */
}