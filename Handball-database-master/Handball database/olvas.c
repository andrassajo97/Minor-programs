#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

void olvas (JATEKOS *adat, CSAPAT *csapadat)
{
    int k;
    FILE *f;
    FILE *g;
    int menuszam;
    int melyikadat;
    k=0;

    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\n\n\t\tEBBEN A MENUPONTBAN AZ OSSZES ADATOT MEGTEKINTHETI,\nCSAK VALASZTANIA KELL, HOGY JATEKOS VAGY CSAPAT ADATAIT SZERETNE MEGTEKINTENI!\n\n");
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
            printf("\nAZ ADATBANKBAN LEVO ADATOK:\n");
            printf("\n-----------------------------------------\n");
            fscanf( g,"%d",&csapadat[k].sorszam );
            /* Azert kerjuk be itt, mert e nelkul szetcsusznanak az adatok. */

            while (!feof(g))
            {
                fscanf(g,"\t%[^\n]s",csapadat[k].csapnev);
                fscanf(g,"%d",&csapadat[k].gyozdb);
                fscanf(g,"%d",&csapadat[k].veszdb);
                fscanf(g,"%d",&csapadat[k].dontdb);
                fscanf(g,"%d",&csapadat[k].helyezes);
                fscanf(g,"\t%[^\n]s",csapadat[k].megjegyzes);

                printf("\n\t%d. adat",csapadat[k].sorszam);
                printf("\n\tCsapat neve: %s",csapadat[k].csapnev);
                printf("\n\tGyozelmek szama: %d",csapadat[k].gyozdb);
                printf("\n\tVeresegek szama: %d",csapadat[k].veszdb);
                printf("\n\tDontetlenek szama: %d",csapadat[k].dontdb);
                printf("\n\tHelyezes a bajnoksagban: %d",csapadat[k].helyezes);
                printf("\n\tMegjegyzes: %s\n",csapadat[k].megjegyzes);
                printf("\n-----------------------------------------\n");
                k++;
                fscanf( g,"%d",&csapadat[k].sorszam );
                /* Azert kerjuk be itt is, mert e nelkul is szetcsusznanak az adatok. */
            }//WHILE
        }//ELSE
        fclose( g );

        system( "PAUSE" );
        system( "cls" );
        menu( menuszam );
    }//if
    else
    {
        if ( ( f=fopen( "jatekos.txt", "r+") ) == NULL)
        {
            printf("\n\nA fajlt nem lehet beolvasni!\n\n");
            system("PAUSE");
            system("cls");
            menu(menuszam);
        }
        else
        {
            printf("\nAZ ADATBANKBAN LEVO ADATOK:\n");
            printf("\n-----------------------------------------\n");
            fscanf( f,"%d",&adat[k].sorszam );
            /* Azert kerjuk be itt, mert e nelkul szetcsusznanak az adatok. */

            while (!feof(f))
            {
                fscanf(f,"\t%[^\n]s",adat[k].nev);
                fscanf(f,"\t%[^\n]s",adat[k].szulido);
                fscanf(f,"\t%[^\n]s",adat[k].csapnev);
                fscanf(f,"\t%[^\n]s",adat[k].poszt);
                fscanf(f,"%d",&adat[k].golok);
                fscanf(f,"\t%[^\n]s",adat[k].megjegyzes);

                printf("\n\t%d. adat:",adat[k].sorszam);
                printf("\n\tNev: %s",adat[k].nev);
                printf("\n\tSzuletesi datum: %s",adat[k].szulido);
                printf("\n\tCsapat neve: %s",adat[k].csapnev);
                printf("\n\tPoszt: %s",adat[k].poszt);
                printf("\n\tGolok szama: %d",adat[k].golok);
                printf("\n\tMegjegyzes: %s\n",adat[k].megjegyzes);
                printf("\n-----------------------------------------\n");
                k++;
                fscanf( f,"%d",&adat[k].sorszam );
                /* Azert kerjuk be itt is, mert e nelkul is szetcsusznanak az adatok. */
            }//WHILE
        }//ELSE
        fclose( f );

        system( "PAUSE" );
        system( "cls" );
        menu( menuszam );
    }

}
