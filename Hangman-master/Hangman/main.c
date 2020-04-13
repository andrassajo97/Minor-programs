#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void game();

int main()
{
    menu();
}

void menu()
{
    int menunum;
    printf("\n\tHangman\n\n");
    printf("1. New game\n2. Exit\nGive the number: ");
    scanf("%d",&menunum);
    while(menunum<1 || menunum>2)
    {
        printf("\nYou should choose between the 2 numbers!\n");
        scanf("%d",&menunum);
    }
    switch (menunum)
    {
    case 1 :
        game();
    case 2 :
        return 0;
    }
}

void game()
{
BEGIN:
    system("cls");
    char word[20];
    char betu;
    int a;
    int i,j,k;
    char betuk[36];
    for(i=0;i<36;i++)
    {
        betuk[i]=' ';
    }
    int talalt=0;
    char halal[]="GAME-OVER";
    char segit[20];
    printf("Give the word! ");
    scanf("%s",word);
    for(i=0; i<strlen(word); i++)
    {
        segit[i]='_';
    }
    system("cls");
    int kor=-1;
    int szamlal=0;
    int f=0;
    while(talalt != strlen(word))
    {
        a=0;
        printf("Give the letter: ");
        scanf("%c",&betu);
        scanf("%c",&betu);
        for(i=0;i<36;i++)
        {
            if(betu == betuk[i])
            {
                printf("\nThis letter is already taken, give a new one!");
                scanf("%c",&betu);
                scanf("%c",&betu);
            }
        }
        betuk[f]=betu;
        f++;
        for(i=0; i<(strlen(word)); i++)
        {
            if (word[i]==betu)
            {
                segit[i]=betu;
                talalt++;
                a++;
            }
        }
        for(j=0; j<strlen(word); j++)
        {
            printf("%c",segit[j]);
        }
        printf("\n");
        if(a==0)
        {
            kor++;
            for(k=0; k<=kor; k++)
            {
                printf("%c",halal[k]);
            }
            szamlal++;
        }
        printf("\n");
        int boolean;
        if (szamlal==(strlen(halal)))
        {
            system("cls");
            printf("\n\GAME-OVER!\n\tThe word: %s\n\n",word);
            printf("Would you like to play again? 1 - YES    2 - NO\n");
            scanf("%d",&boolean);
            while(boolean>2 || boolean<1)
            {
                printf("\nYou should choose between the 2 numbers!");
                scanf("%d",&boolean);
            }
            if (boolean==2)
            {
                system("cls");
                printf("\n\tThe game is over!\n\n");
                system("PAUSE");
                return 0;
            }
            else
            {
                goto BEGIN;
            }
        }
    }
    for(i=0;i<36;i++)
    {
        betuk[i]=' ';
    }
    int boolean;
    system("cls");
    printf("\n\tYou found out the word!\n\n");
    printf("Would you like to play again? 1 - YES    2 - NO\n");
    scanf("%d",&boolean);
    while(boolean>2 || boolean<1)
    {
        printf("\nYou should choose between the 2 numbers!");
        scanf("%d",&boolean);
    }
    if (boolean==2)
    {
        system("cls");
        printf("\n\tThe game is over!\n\n");
        system("PAUSE");
        return 0;
    }
    else
    {
        goto BEGIN;
    }
}
