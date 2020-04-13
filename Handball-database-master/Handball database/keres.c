#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

void kereses( JATEKOS *keres, CSAPAT *csapkeres )
{
    int menuszam,melyikadat;
    FILE *f;
    FILE *g;
    JATEKOS adat;
    CSAPAT csapadat;
    char kercsapnev [60];
    char kernev [30];

    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\n\n\t\tEBBEN A MENUPONTBAN AZ ADATOKRA TUD RAKERESNI,\nCSAK VALASZTANIA KELL, HOGY JATEKOS VAGY CSAPAT ADATAIRA SZERETNE RAKERESNI!\n\n");
    printf("\n\n\t\t\t 1 - JATEKOS             2 - CSAPAT\n\n");
    while (melyikadat<1 || melyikadat>2)
    {
        printf("\nCsak az 1 es a 2 menupont kozul valaszthat! ");

        scanf("%d",&melyikadat);
    }
    if (melyikadat==2)
    {
        if ( ( g=fopen( "csapatok.txt", "r+") ) == NULL )
        {
            printf("\n\nA fajlt nem lehet beolvasni!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            printf("\n\nA keresett csapat neve: \n");
            scanf("\t\t%[^\n]s",kercsapnev);
            while (!feof(g))
            {
                fscanf(g,"%d",&csapadat.sorszam);
                fscanf(g,"\t%[^\n]s",csapadat.csapnev);
                fscanf(g,"%d",&csapadat.gyozdb);
                fscanf(g,"%d",&csapadat.veszdb);
                fscanf(g,"%d",&csapadat.dontdb);
                fscanf(g,"%d",&csapadat.helyezes);
                fscanf(g,"\t%[^\n]s",csapadat.megjegyzes);

                if ( strcmp(csapadat.csapnev,kercsapnev) == 0 )
                {
                    printf("\nAZ ADATBANKBAN LEVO CSAPAT ADATAI: \n");
                    printf("\n-----------------------------------------\n");
                    printf("\n\t%d. adat",csapadat.sorszam);
                    printf("\n\tCsapat neve: %s",csapadat.csapnev);
                    printf("\n\tGyozelmek szama: %d",csapadat.gyozdb);
                    printf("\n\tVeresegek szama: %d",csapadat.veszdb);
                    printf("\n\tDontetlenek szama: %d",csapadat.dontdb);
                    printf("\n\tHelyezes a bajnoksagban: %d",csapadat.helyezes);
                    printf("\n\tMegjegyzes: %s\n",csapadat.megjegyzes);
                    printf("\n-----------------------------------------\n");
                    system("PAUSE");
                    system("cls");
                    menu(menuszam);
                    fclose(g);
                }
            }
        }
        printf( "\n\n%s nem talalhato az adatbankban!\n\n", kercsapnev);
        system( "PAUSE" );
        system( "cls" );
        menu( menuszam );
    }
    else
    {
        if ( ( f=fopen ("jatekos.txt","r+") ) == NULL )
        {
            printf("\n\nA fajlt nem lehet beolvasni!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            printf("\n\nA keresett szemely neve: \n");
            scanf("\t\t%[^\n]s",kernev);
            while (!feof(f))
            {
                fscanf(f,"%d",&adat.sorszam);
                fscanf(f,"\t%[^\n]s",adat.nev);
                fscanf(f,"\t%[^\n]s",adat.szulido);
                fscanf(f,"\t%[^\n]s",adat.csapnev);
                fscanf(f,"\t%[^\n]s",adat.poszt);
                fscanf(f,"%d",&adat.golok);
                fscanf(f,"\t%[^\n]s",adat.megjegyzes);

                if ( strcmp(adat.nev,kernev) == 0)
                {
                    printf("\nAZ ADATBANKBAN LEVO SZEMELY ADATAI: \n");
                    printf("\n-----------------------------------------\n");
                    printf("\n\t%d. adat:",adat.sorszam);
                    printf("\n\tNev: %s",adat.nev);
                    printf("\n\tSzuletesi datum: %s",adat.szulido);
                    printf("\n\tCsapat neve: %s",adat.csapnev);
                    printf("\n\tPoszt: %s",adat.poszt);
                    printf("\n\tGolok szama: %d",adat.golok);
                    printf("\n\tMegjegyzes: %s\n",adat.megjegyzes);
                    printf("\n-----------------------------------------\n");
                    system("PAUSE");
                    system("cls");
                    menu(menuszam);
                    fclose(f);
                }
            }
        }
    }
    printf( "\n\n%s nem talalhato az adatbankban!\n\n",kernev);
    system( "PAUSE" );
    system( "cls" );
    menu( menuszam );
}
