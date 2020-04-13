#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

int modositas( JATEKOS *adat, CSAPAT *csapadat)
{
    int melyik,k,menuszam,i;
    FILE *f;
    FILE *g;
    char modositando[100];
    int melyikadat;

    typedef struct ujcsapadat
    {
        char csapnev[20];
        int gyozdb;
        int veszdb;
        int dontdb;
        int helyezes;
        char megjegyzes[100];
        int sorszam;
    } UJCSAPADAT;

    UJCSAPADAT ujcsapadat;

    typedef struct ujadat
    {
        char nev[20];
        char szulido[20];
        char csapnev[30];
        char poszt[30];
        int golok;
        char megjegyzes[100];
        int sorszam;
    } UJADAT;

    UJADAT ujadat;

    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\n\n\tEBBEN A MENUPONTBAN AZ ADATOKON TUD MODOSITANI, CSAK VALASSZON,\n\tHOGY JATEKOS VAGY CSAPAT ADATAIN AKAR MODOSITANI!\n\n");
    printf("\n\n\t\t 1 - JATEKOS             2 - CSAPAT\n\n");
    scanf("%d",&melyik);
    while (melyik<1 || melyik>2)
    {
        printf("\nCsak az 1 es a 2 menupont kozul valaszthat! ");
        scanf("%d",&melyik);
    }
    if (melyik==2)
    {
        if( ( g = fopen( "csapatok.txt","r+" ) ) == NULL )
        {
            printf( "\n\nA fajlt nem lehet beolvasni!\n\n" );
            system( "PAUSE" );
            system( "cls" );
            menu( menuszam );
        }
        else
        {
            k=0;
            fscanf( g,"%d",&csapadat[k].sorszam );
            while(!feof(g))
            {
                fscanf( g,"\t%[^\n]s",csapadat[k].csapnev );
                fscanf( g,"%d",&csapadat[k].gyozdb );
                fscanf( g,"%d",&csapadat[k].veszdb );
                fscanf( g,"%d",&csapadat[k].dontdb );
                fscanf( g,"%d",&csapadat[k].helyezes );
                fscanf( g,"\t%[^\n]s",csapadat[k].megjegyzes );
                k++;
                fscanf( g,"%d",&csapadat[k].sorszam );
            }
            fclose(g);
        }
        printf("\n\nA modositando csapat neve: \n");
        scanf("\t%[^\n]s",modositando);
        for(i=0;i<=(k-1);i++)
        {
            if ( (strcmp(csapadat[i].csapnev,modositando)) == 0)
                break;
            if(i==(k-1))
            {
                printf("\n%s nem talalhato az adatbankban!\n",modositando);
                system("PAUSE");
                system("cls");
                menu(menuszam);
            }
        }
        if ( ( g = fopen("csapatok.txt","r+") ) == NULL )
        {
            printf("\n\nA fajlt nem lehet beolvasni!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            system("cls");
            i=0;
            while ( i<=(k-1))
            {
                if ( (strcmp(csapadat[i].csapnev,modositando)) == 0)
                {
                    printf("Melyik adaton szeretne valtoztatni? \n1 - CSAPATNEV \n2 - GYOZELMEK SZAMA \n3 - VERESEGEK SZAMA \n4 - DONTETLENEK SZAMA \n5 - HELYEZES A BAJNOKSAGBAN \n6 - MEGJEGYZES \n");
                    printf("Modositando adat szama: ");
                    scanf("%d",&melyikadat);
                    switch(melyikadat)
                    {
                    case 1 :
                        printf("\nJelenlegi csapatnev: %s",csapadat[i].csapnev);
                        printf("\nUj csapatnev: ");
                        scanf("\t%[^\n]s",ujcsapadat.csapnev);
                        strcpy(csapadat[i].csapnev,ujcsapadat.csapnev);
                        break;
                    case 2 :
                        printf("\nEddig a gyozelmek szama: %d",csapadat[i].gyozdb);
                        printf("\nJelenleg a gyozelmek szama: ");
                        scanf("%d",&ujcsapadat.gyozdb);
                        csapadat[i].gyozdb=ujcsapadat.gyozdb;
                        break;
                    case 3 :
                        printf("\nEddig a veresegek szama: %d",csapadat[i].veszdb);
                        printf("\nJelenleg a veresegek szama: ");
                        scanf("%d",&ujcsapadat.veszdb);
                        csapadat[i].veszdb=ujcsapadat.veszdb;
                        break;
                    case 4 :
                        printf("\nEddig a dontetlenek szama: %d",csapadat[i].dontdb);
                        printf("\nJelenleg a dontetlenek szama: ");
                        scanf("%d",&ujcsapadat.dontdb);
                        csapadat[i].dontdb=ujcsapadat.dontdb;
                        break;
                    case 5 :
                        printf("\nEddigi helyezes a bajnoksagban: %d",csapadat[i].helyezes);
                        printf("\nJelenlegi helyezes a bajnoksagban: ");
                        scanf("%d",&ujcsapadat.helyezes);
                        csapadat[i].helyezes=ujcsapadat.helyezes;
                        break;
                    case 6 :
                        printf("\nEddigi megjegyzes: %s",csapadat[i].megjegyzes);
                        printf("\nUj megjegyzes: ");
                        scanf("\t%[^\n]s",ujcsapadat.megjegyzes);
                        strcpy(csapadat[i].megjegyzes,ujcsapadat.megjegyzes);
                        break;
                    default :
                        printf("\nNincs ilyen menupont!\n");
                        system("PAUSE");
                        system("cls");
                        menu(menuszam);
                    }
                }
                i++;
            }

            for(i=0;i<k;i++)
            {
                fprintf( g,"%d\n",csapadat[i].sorszam );
                fprintf( g,"%s\n",csapadat[i].csapnev );
                fprintf( g,"%d\n",csapadat[i].gyozdb );
                fprintf( g,"%d\n",csapadat[i].veszdb );
                fprintf( g,"%d\n",csapadat[i].dontdb );
                fprintf( g,"%d\n",csapadat[i].helyezes );
                fprintf( g,"%s\n",csapadat[i].megjegyzes );
            }
            fclose(g);
            printf( "\n\nAZ ADATMODOSITAS MEGTORTENT\n\n" );
        }
        system( "PAUSE" );
        system( "cls" );
        menu( menuszam );
    }
    else
    {
        if( ( f = fopen( "jatekos.txt","r+" ) ) == NULL )
        {
            printf( "\n\nA fajlt nem lehet beolvasni!\n\n" );
            system( "PAUSE" );
            system( "cls" );
            menu( menuszam );
        }
        else
        {
            k=0;
            fscanf( f,"%d",&adat[k].sorszam );
            while(!feof(f))
            {
                fscanf( f,"\t%[^\n]s",adat[k].nev );
                fscanf( f,"\t%[^\n]s",adat[k].szulido );
                fscanf( f,"\t%[^\n]s",adat[k].csapnev );
                fscanf( f,"\t%[^\n]s",adat[k].poszt );
                fscanf( f,"%d",&adat[k].golok );
                fscanf( f,"\t%[^\n]s",adat[k].megjegyzes );
                k++;
                fscanf( f,"%d",&adat[k].sorszam );
            }
            fclose(f);
        }
        printf("\n\nA modositando szemely neve: \n");
        scanf("\t%[^\n]s",modositando);
        for(i=0;i<=(k-1);i++)
        {
            if ( (strcmp(adat[i].nev,modositando)) == 0)
                break;
            if(i==(k-1))
            {
                printf("\n%s nem talalhato az adatbankban!\n",modositando);
                system("PAUSE");
                system("cls");
                menu(menuszam);
            }
        }
        if ( ( f = fopen("jatekos.txt","r+") ) == NULL )
        {
            printf("\n\nA fajlt nem lehet beolvasni!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            system("cls");
            i=0;
            while ( i<=k-1)
            {
                if ( (strcmp(adat[i].nev,modositando)) == 0)
                {
                    printf("Melyik adaton szeretne valtoztatni? \n1 - NEV \n2 - SZULETESI DATUM \n3 - CSAPAT NEVE \n4 - POSZT \n5 - GOLOK SZAMA \n6 - MEGJEGYZES \n");
                    printf("Modositando adat szama: ");
                    scanf("%d",&melyikadat);
                    switch(melyikadat)
                    {
                    case 1 :
                        printf("\nJelenlegi nev: %s",adat[i].nev);
                        printf("\nUj nev: ");
                        scanf("\t%[^\n]s",ujadat.nev);
                        strcpy(adat[i].nev,ujadat.nev);
                        break;
                    case 2 :
                        printf("\nSzuletesi datum: %s",adat[i].szulido);
                        printf("\nUj szuletesi datum: ");
                        scanf("\t%[^\n]s",ujadat.szulido);
                        strcpy(adat[i].szulido,ujadat.szulido);
                        break;
                    case 3 :
                        printf("\nEddigi csapat neve: %s",adat[i].csapnev);
                        printf("\nUj csapat neve: ");
                        scanf("\t%[^\n]s",ujadat.csapnev);
                        strcpy(adat[i].csapnev,ujadat.csapnev);
                        break;
                    case 4 :
                        printf("\nEdddigi poszt: %s",adat[i].poszt);
                        printf("\nUj poszt: ");
                        scanf("\t%[^\n]s",ujadat.poszt);
                        strcpy(adat[i].poszt,ujadat.poszt);
                        break;
                    case 5 :
                        printf("\nEddigi golok szama: %d",adat[i].golok);
                        printf("\nJelenleg a golok szama: ");
                        scanf("%d",&ujadat.golok);
                        adat[i].golok=ujadat.golok;
                        break;
                    case 6 :
                        printf("\nEddigi megjegyzes: %s",adat[i].megjegyzes);
                        printf("\nUj megjegyzes: ");
                        scanf("\t%[^\n]s",ujadat.megjegyzes);
                        strcpy(adat[i].megjegyzes,ujadat.megjegyzes);
                        break;
                    default :
                        printf("\nNincs ilyen menupont!\n");
                        system("PAUSE");
                        system("cls");
                        menu(menuszam);
                    }
                }
                i++;
            }

            for (i=0;i<k;i++)
            {
                fprintf( f,"%d\n",adat[i].sorszam );
                fprintf( f,"%s\n",adat[i].nev );
                fprintf( f,"%s\n",adat[i].szulido );
                fprintf( f,"%s\n",adat[i].csapnev );
                fprintf( f,"%s\n",adat[i].poszt );
                fprintf( f,"%d\n",adat[i].golok );
                fprintf( f,"%s\n",adat[i].megjegyzes );
            }
            fclose(f);
            printf( "\n\nAZ ADATMODOSITAS MEGTORTENT\n\n" );
        }
        system( "PAUSE" );
        system( "cls" );
        menu( menuszam );
    }
}
