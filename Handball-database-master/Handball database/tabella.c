#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

void tabella(CSAPAT *csapadat)
{
    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *\t\t");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\t\t\t\tTABELLA\n\n");
    int menuszam,k,i,j,x;
    FILE *g;
    if ( ( g = fopen("csapatok.txt","r+") ) == NULL )
    {
        printf("\nA fajlt nem lehet beolvasni!\n");
        system("PAUSE");
        system("cls");
        menu(menuszam);
    }
    else
    {
        k=0;
        fscanf(g,"%d",&csapadat[k].sorszam);
        while(!feof(g))
        {
            fscanf(g,"\t%[^\n]s",csapadat[k].csapnev);
            fscanf(g,"%d",&csapadat[k].gyozdb);
            fscanf(g,"%d",&csapadat[k].veszdb);
            fscanf(g,"%d",&csapadat[k].dontdb);
            fscanf(g,"%d",&csapadat[k].helyezes);
            fscanf(g,"\t%[^\n]s",csapadat[k].megjegyzes);
            k++;
            fscanf(g,"%d",&csapadat[k].sorszam);
        }
        fclose(g);
        int segit[k+1];
        for(i=0;i<k+1;i++)
        {
            segit[i]=csapadat[i].helyezes;
        }
        for (i=0; i<k; i++)
        {
            for (j=i+1; j<k; j++)
            {
                if ( (segit[i]) > (segit[j]) )
                {
                    x = segit[i];
                    segit[i] = segit[j];
                    segit[j] = x;
                }
            }
        }
        for(i=0;i<k+1;i++)
        {
            printf("\n |%d.hely | %s | %d - M | %d - GY | %d - D | %d - V | %d - Pt |\n",i+1,csapadat[segit[i]].csapnev,csapadat[segit[i]].gyozdb+csapadat[segit[i]].dontdb+csapadat[segit[i]].veszdb,csapadat[segit[i]].gyozdb,csapadat[segit[i]].dontdb,csapadat[segit[i]].veszdb,((csapadat[segit[i]].gyozdb)*2)+csapadat[segit[i]].dontdb);
        }
    }
    system("\nPAUSE");
    system("cls");
    menu(menuszam);
}
