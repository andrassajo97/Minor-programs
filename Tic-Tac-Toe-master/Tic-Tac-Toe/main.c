#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu();
void jatek();
void ellenor(char *tabla[],int vege);

int main()
{
    menu();
}

void menu()
{
    int boolean;
    printf("\n\tTic-Tac-Toe\n");
    printf("\n1.New game\n2.Exit\n");
    scanf("%d",&boolean);
    while(boolean>2 || boolean <1)
    {
        printf("You should choose between the 2 numbers, give a new one!\n");
        scanf("%d",&boolean);
    }
    if (boolean == 2)
    {
        system("cls");
        printf("\n\tThe game is over!\t\n");
        return 0;
    }
    else
    {
        jatek();
    }
}

jatek()
{
    char symbol;
    char jel='X';
    char jele='O';
    int mezo,mezoke;
    char tabla[3][3];
    int i,j;
    int vege=0;
    int z=1;
    int t=1;
    system("cls");
    printf("This Tic-Tac-Toe is played in 3X3, to the fields, you could refer by their row and coloumn indexes,\nfor example.: 1,2 = forst row second coloumn!\n");
    while(vege==0)
    {
        if ( z%2 == 1)
        {
            int rendben=0;
            printf("\n%d. player %d. step: ",z,t);
            scanf("%d,%d",&mezo,&mezoke);
            while ( mezo > 3 || mezoke >3)
            {
                printf("\nThe table's size is just 3X3!");
                printf("\n%d. player %d. step: ",z,t);
                scanf("%d,%d",&mezo,&mezoke);
            }
            if (t==1)
            {
                ;
            }
            else
            {
                while(rendben==0)
                {
                    for(i=0; i<3; i++)
                    {
                        for(j=0; j<3; j++)
                        {
                            if (i==mezo-1 && j==mezoke-1)
                            {
                                if ((tabla[i][j]) == ' ' )
                                {
                                    rendben++;
                                }
                                else
                                {
                                    printf("The field is already occupied, take a new one!\n");
                                    scanf("%d,%d",&mezo,&mezoke);
                                }
                            }
                        }
                    }
                }
            }
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    if ( (i == mezo-1) && (j == mezoke-1))
                    {
                        tabla[i][j]=jel;
                    }
                    else
                    {
                        if (t==1)
                        {
                            tabla[i][j]=' ';
                        }
                    }
                }
            }
            system("cls");
            printf("Current game:\n");
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    printf(" %c ",tabla[i][j]);
                }
                printf("\n");
            }
            ellenor(tabla,vege);
        }
        else
        {
            srand(time(NULL));
            int rendben=0;
            int szamlal=0;
            mezo = rand()%2+1;
            mezoke = rand()%2+1;
            while(rendben==0)
            {
                for(i=0; i<3; i++)
                {
                    for(j=0; j<3; j++)
                    {
                        if (i==mezo-1 && j==mezoke-1)
                        {
                            if ((tabla[i][j]) == ' ' )
                            {
                                rendben++;
                            }
                            else
                            {
                                mezo = rand()%2+1;
                                mezoke = rand()%2+1;
                            }
                        }
                    }
                }
            }
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    if ( (i == mezo-1) && (j == mezoke-1))
                    {
                        tabla[i][j]=jele;
                    }
                }
            }
            system("cls");
            printf("Current game:\n");
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    printf(" %c ",tabla[i][j]);
                }
                printf("\n");
            }
            ellenor(tabla,vege);
        }
        if ( z==2 )
        {
            z=0;
            t++;
        }
        z++;
    }
    system("cls");
    printf("\n\t\tThe game is over!!!\n");
    system("PAUSE");
    return 0;
}

void ellenor(char *tabla[],int vege)
{
    if (tabla[0][0]=='O')
    {
        if (tabla[0][0]==tabla[0][1] && tabla[0][1]==tabla[0][2])
        {
            vege++;
        }
        else if (tabla[0][0]==tabla[1][0] && tabla[1][0]==tabla[2][0])
        {
            vege++;
        }
        else if (tabla[0][0]==tabla[1][1] && tabla[1][1]==tabla[2][2])
        {
            vege++;
        }
    }
    else if (tabla[1][0]=='O')
    {
        if (tabla[1][0]==tabla[1][1] && tabla[1][1]==tabla[1][2])
        {
            vege++;
        }
        else if (tabla[1][0]==tabla[0][0] && tabla[0][0]==tabla[2][0])
        {
            vege++;
        }
        else if (tabla[1][0]==tabla[2][0] && tabla[2][0]==tabla[0][0])
        {
            vege++;
        }
    }
    else if (tabla[2][0]=='O')
    {
        if (tabla[2][0]==tabla[2][1] && tabla[2][1]==tabla[2][2])
        {
            vege++;
        }
        else if (tabla[2][0]==tabla[1][1] && tabla[1][1]==tabla[0][2])
        {
            vege++;
        }
    }
    else if (tabla[0][1]=='O')
    {
        if (tabla[0][1]==tabla[1][1] && tabla[1][1]==tabla[2][1])
        {
            vege++;
        }
    }
    else if (tabla[0][2]=='O')
    {
        if (tabla[0][2]==tabla[1][2] && tabla[1][2]==tabla[2][2])
        {
            vege++;
        }
    }
    if (tabla[0][0]=='X')
    {
        if (tabla[0][0]==tabla[0][1] && tabla[0][1]==tabla[0][2])
        {
            vege++;
        }
        else if (tabla[0][0]==tabla[1][0] && tabla[1][0]==tabla[2][0])
        {
            vege++;
        }
        else if (tabla[0][0]==tabla[1][1] && tabla[1][1]==tabla[2][2])
        {
            vege++;
        }
    }
    else if (tabla[1][0]=='X')
    {
        if (tabla[1][0]==tabla[1][1] && tabla[1][1]==tabla[1][2])
        {
            vege++;
        }
    }
    else if (tabla[2][0]=='X')
    {
        if (tabla[2][0]==tabla[2][1] && tabla[2][1]==tabla[2][2])
        {
            vege++;
        }
        else if (tabla[2][0]==tabla[1][1] && tabla[1][1]==tabla[0][2])
        {
            vege++;
        }
    }
    else if (tabla[0][1]=='X')
    {
        if (tabla[0][1]==tabla[1][1] && tabla[1][1]==tabla[2][1])
        {
            vege++;
        }
    }
    else if (tabla[0][2]=='X')
    {
        if (tabla[0][2]==tabla[1][2] && tabla[1][2]==tabla[2][2])
        {
            vege++;
        }
    }
    return vege;
}
