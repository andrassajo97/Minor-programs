typedef struct jatekos
{
    char nev[30];
    char szulido[20];
    char csapnev[20];
    char poszt[30];
    int golok;
    char megjegyzes[100];
    int sorszam;
} JATEKOS;

typedef struct csapat
{
    char csapnev[20];
    int gyozdb;
    int veszdb;
    int dontdb;
    int helyezes;
    char megjegyzes[100];
    int sorszam;
} CSAPAT;

typedef JATEKOS tar[1000];

typedef CSAPAT tarol[1000];

extern int menu(int szam);
int ir (void);
void olvas( JATEKOS *adat, CSAPAT *csapadat );
void kereses( JATEKOS *keres, CSAPAT *csapkeres );
extern int modositas( JATEKOS *adat, CSAPAT *csapadat);
extern void tabella ( CSAPAT *csapadat );
extern void gollovolista ( JATEKOS *adat);
