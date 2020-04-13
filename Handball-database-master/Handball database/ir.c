#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

int ir ( void )
{
    FILE *f;
    FILE *g;
    int i,db,menuszam;
    JATEKOS adat;
    CSAPAT csapadat;
    int boolean;
    int adatboolean;

    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\n\n\tFIGYELEM!!! UJ ADATOK FELVETELE ESETEN AZ EDDIGIEK TORLODNI FOGNAK!!!\n\n");
    printf("\n\n\t\tBIZTOS BENNE, HOGY UJ ADATOKAT AKAR FELVENNI?\n\n");
    printf("\n\n\t\t\t1 - IGEN             2 - NEM\n");
    while(boolean<1 || boolean>2)
    {
        printf("\nCsak az 1 es a 2 menupont kozul valaszthat! ");
        scanf("%d",&boolean);
    }
    if (boolean==2)
    {
        system("cls");
        menu(menuszam);
    }
    else
    {
        printf("\n\n\t\tJATEKOST VAGY CSAPATOT SZERETNE BEVINNI AZ ADATBANKBA?\n\n");
        printf("\n\n\t\t\t1 - JATEKOS             2 - CSAPAT\n\n");
        scanf("%d",&adatboolean);
        while(adatboolean<1 || adatboolean>2)
        {
            printf("\nCsak az 1 es a 2 menupont kozul valaszthat! ");
            scanf("%d",&adatboolean);
        }
        if (adatboolean==2)
        {
            printf("\nHany adatot szeretne felvenni? ");
            scanf("\t%d",&db);
            while (db<1 || db>1000)
            {
                if (db<1)
                {
                    system("cls");
                    printf("\n\tLegalabb egy adatot meg kell adnia! ");
                    scanf("\t%d",&db);
                }
                else if (db>1000)
                {
                    system("cls");
                    printf("\n\tCsak kevesebb adatot lehet megadni mint 1000, kerem adjon meg ujat! ");
                    scanf("\t%d",&db);
                }
            }

            g=fopen("csapatok.txt", "w+");
            if (g==0)
            {
                printf("\n\tA fajlt nem lehet beolvasni!\n");
                system("PAUSE");
                system("cls");
                menu(menuszam);
            }
            else
            {
                for(i=0; i<=db-1; i++)
                {
                    csapadat.sorszam=i;

                    system("cls");
                    printf("\n\t%d. adat\n",i+1);
                    printf("\n\tCsapatnev: ");
                    scanf("\t%[^\n]s",csapadat.csapnev);
                    printf("\n\tGyozelmek szama: ");
                    scanf("\t%d",&csapadat.gyozdb);
                    printf("\n\tVeresegek szama: ");
                    scanf("\t%d",&csapadat.veszdb);
                    printf("\n\tDontetlenek szama: ");
                    scanf("\t%d",&csapadat.dontdb);
                    printf("\n\tHelyezes a bajnoksagban: ");
                    scanf("\t%d",&csapadat.helyezes);
                    printf("\n\tMegjegyzes: ");
                    scanf("\t%[^\n]s",csapadat.megjegyzes);

                    fprintf(g,"%d\n",csapadat.sorszam+1);
                    fprintf(g,"%s\n",csapadat.csapnev);
                    fprintf(g,"%d\n",csapadat.gyozdb);
                    fprintf(g,"%d\n",csapadat.veszdb);
                    fprintf(g,"%d\n",csapadat.dontdb);
                    fprintf(g,"%d\n",csapadat.helyezes);
                    fprintf(g,"%s\n",csapadat.megjegyzes);
                }
                fclose(g);
            }
            printf("\n\n\tAZ ADATHOZZAADAS MEGTORTENT!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            printf("\nHany adatot szeretne felvenni? ");
            scanf("\t%d",&db);
            while (db<1 || db>1000)
            {
                if (db<1)
                {
                    system("cls");
                    printf("\n\tLegalabb egy adatot meg kell adnia! ");
                    scanf("\t%d",&db);
                }
                else if (db>1000)
                {
                    system("cls");
                    printf("\n\tCsak kevesebb adatot lehet megadni mint 1000, kerem adjon meg ujat! ");
                    scanf("\t%d",&db);
                }
            }

            f=fopen("jatekos.txt", "w+");
            if (f==0)
            {
                printf("\n\tA fajlt nem lehet beolvasni!\n");
                system("PAUSE");
                system("cls");
                menu(menuszam);
            }
            else
            {
                for(i=0; i<=db-1; i++)
                {
                    adat.sorszam=i;

                    system("cls");
                    printf("\n\t%d. adat\n",i+1);
                    printf("\n\tNev: ");
                    scanf("\t%[^\n]s",adat.nev);
                    printf("\n\tSzuletesi ido: ");
                    scanf("\t%[^\n]s",adat.szulido);
                    printf("\n\tCsapat nev: ");
                    scanf("\t%[^\n]s",adat.csapnev);
                    printf("\n\tPoszt: ");
                    scanf("\t%[^\n]s",adat.poszt);
                    printf("\n\tGolok szama: ");
                    scanf("\t%d",&adat.golok);
                    printf("\n\tMegjegyzes: ");
                    scanf("\t%[^\n]s",adat.megjegyzes);

                    fprintf(f,"%d\n",adat.sorszam+1);
                    fprintf(f,"%s\n",adat.nev);
                    fprintf(f,"%s\n",adat.szulido);
                    fprintf(f,"%s\n",adat.csapnev);
                    fprintf(f,"%s\n",adat.poszt);
                    fprintf(f,"%d\n",adat.golok);
                    fprintf(f,"%s\n",adat.megjegyzes);
                }
                fclose(f);
            }
            printf("\n\n\tAZ ADATHOZZAADAS MEGTORTENT!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
    }
}
