#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

int menu (int szam)
{
    int menuszam;
    JATEKOS adat[500];
    CSAPAT csapadat[500];

    printf("\n\t\t**********************************************");
    printf("\n\t\t*                                            *");
    printf("\n\t\t* KEZILABDA ADATBANK A 2016/2017-ES SZEZONRA *\t\t");
    printf("\n\t\t*                                            *");
    printf("\n\t\t**********************************************\n\n");
    printf("\n\t\t\t1. UJ ADAT FELVETELE\n");
    printf("\n\t\t\t2. OSSZES ADAT MEGTEKINTESE\n");
    printf("\n\t\t\t3. KERESES NEV ALAPJAN\n");
    printf("\n\t\t\t4. ADAT MODOSITASA\n");
    printf("\n\t\t\t5. TABELLA\n");
    printf("\n\t\t\t6. GOLLOVOLISTA\n");
    printf("\n\t\t\t7. NEVJEGY\n");
    printf("\n\t\t\t8. KILEPES\n");
    printf("\n\t\t\tA VALASZTOTT MENUPONT SZAMA: ");
    scanf("\t\t\t%d",&szam);
    switch(szam)
    {
    case 1 :
        system("cls");
        ir();
        break;
    case 2 :
        system("cls");
        olvas(adat,csapadat);
        break;
    case 3 :
        system("cls");
        kereses(adat, csapadat);
        break;
    case 4 :
        system("cls");
        modositas(adat, csapadat);
        break;
    case 5 :
        system("cls");
        tabella(csapadat);
        break;
    case 6 :
        system("cls");
        gollovolista(adat);
        break;
    case 7 :
        system("cls");
        nevjegy();
        break;
    case 8 :
        exit(-1);
        break;
    default :
        printf("\n\t\t\tNincs ilyen menupont!\n\n");
        system("PAUSE");
        system("cls");
        menu(menuszam);
    }

}
