#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

void gollovolista(JATEKOS *adat)
{
    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *\t\t");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\t\t\t\tGOLLOVOLISTA\n\n");
    int menuszam,k,i,j,x;
    FILE *f;
    if ( ( f = fopen("jatekos.txt","r+") ) == NULL )
    {
        printf("\nA fajlt nem lehet beolvasni!\n");
        system("PAUSE");
        system("cls");
        menu(menuszam);
    }
    else
    {
        k=0;
        fscanf(f,"%d",&adat[k].sorszam);
        while(!feof(f))
        {
            fscanf(f,"\t%[^\n]s",adat[k].nev);
            fscanf(f,"\t%[^\n]s",adat[k].szulido);
            fscanf(f,"\t%[^\n]s",adat[k].csapnev);
            fscanf(f,"\t%[^\n]s",&adat[k].poszt);
            fscanf(f,"%d",&adat[k].golok);
            fscanf(f,"\t%[^\n]s",adat[k].megjegyzes);
            k++;
            fscanf(f,"%d",&adat[k].sorszam);
        }
        fclose(f);
        int segit[k+1];
        for(i=0; i<k+1; i++)
        {
            segit[i]=adat[i].sorszam;
        }
        for (i=0; i<k; i++)
        {
            for (j=i+1; j<k; j++)
            {
                if ( (adat[segit[i]].golok) < (adat[segit[j]].golok) )
                {
                    x = segit[i];
                    segit[i] = segit[j];
                    segit[j] = x;
                }
            }
        }
        for(i=0; i<k+1; i++)
        {
            printf("\n| %d.hely | %s | %d - gol |\n",i+1,adat[segit[i]].nev,adat[segit[i]].golok);
        }
    }
    system("\nPAUSE");
    system("cls");
    menu(menuszam);

}
