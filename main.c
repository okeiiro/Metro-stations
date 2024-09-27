#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define TAILLE_MAX 100

typedef enum { false, true } bool;
typedef struct maillon maillon;

struct maillon
{
    char station[TAILLE_MAX];                      //La station
    bool corresp;                      //Indicateur de correspondance
    struct maillon *adr;          //adresse du prochain maillon
}*tete;

typedef maillon* Tptr;
Tptr ptr[20];






Tptr allouer(Tptr *P);
Tptr suivant(Tptr P); // s pour le maillon "station"
char*  station(Tptr P); // donne le nom de station
void aff_adr(Tptr P,Tptr q); // le chainage
//pour l'affectation de 1 ou 0 dans le champs de correspondance on l'a integr� dans les programme comme une simple affectation








void creer_lignes(int n, int j); // function to create the list
void affich_lignes(Tptr ptr[20],int MAX); // fonction qui affiche toutes les lignes du reseau de metro
void corresp_ind(Tptr ptr[20],int MAX); //fonction qui affecte
void intersection_lignes(Tptr ptr[20],int MAX);
void delete_by_position(Tptr ptr[20],int MAX);
void ajout_station(Tptr ptr[20],int MAX);
void ajout_lignes(Tptr ptr[20],int*MAX);
void ClearConsoleToColors(int ForgC, int BackC);
void welcome();



int main(void)
{


    system("cls");
    system("color 06");
    welcome();
    getch();

    int i;
    for(i=0; i<2; i++)
    { system("cls");
      printf("\n\n\n\n\n\t\t\t\t\t\t  Chargement.\n\n");
      Sleep(300);
      system("cls");
      printf("\n\n\n\n\n\t\t\t\t\t\t  Chargement..\n\n");
      Sleep(300);
      system("cls");
      printf("\n\n\n\n\n\t\t\t\t\t\t  Chargement...\n\n");
      Sleep(300);
      system("cls");
    }

    int MAX=10;
        for (int j=1; j<MAX+1;j++)//repeter pour toutes les lignes
        {
        int n= rand() % (18 + 1 - 5) + 5;
        creer_lignes(n,j);
        }
corresp_ind(ptr,MAX);

        int choice, forgc, backgc;
do
{
 printf(" ALSDD-TP1 2020/2021");
 printf("\n\n\n\t\t\t -------------------------MENU---------------------------\n\n");
 printf("\n\t\t\t1. Afficher les lignes du metro\n");
 printf("\n\t\t\t2. Afficher les stations de correspondance\n");
 printf("\n\t\t\t3. Supprimer une station\n");
 printf("\n\t\t\t4. Ajouter une station\n");
 printf("\n\t\t\t5. Ajouter une ligne\n");
  printf("\n\t\t\t6. Personnalisation\n");

 printf("\n\t\t\t0. Quitter\n");
 printf("\n\n\t\t\t ----------------------------------------------------------\n\n");
 printf("\n\tVeuillez selectionner un chiffre:\n\n");

 printf("\t> ");
 scanf("%d",&choice);


 switch (choice)
 {
   case 1: system("cls");
           affich_lignes(ptr, MAX);
           printf("\n\tAppuyez sur n'importe quelle touche pour continuer...");
           getch();
           system("cls");
            break;

   case 2: system("cls");
           corresp_ind(ptr,MAX);
           intersection_lignes(ptr,MAX);
           getch();
           system("cls");
            break;

   case 3: system("cls");
           affich_lignes(ptr,MAX);
           delete_by_position(ptr,MAX);
           getch();
           system("cls");
            break;

   case 4: system("cls");
           affich_lignes(ptr,MAX);
           ajout_station(ptr,MAX);
           getch();
           system("cls");
            break;

   case 5: system("cls");
           ajout_lignes(ptr,&MAX);
           affich_lignes(ptr,MAX);
           corresp_ind(ptr,MAX);//Ajouter le champs correspondance aux nouvelles stations
           getch();
           system("cls");
            break;

   case 6: system("cls");
           printf("\n\t\t\t     voici la palette de couleur, et c'est vous l'artiste!");
           printf("\n\t\t\t    _________________________________________________________\n");
           printf("\t\t\t   | 0: Noir                        8: Gris                 |\n");
           printf("\t\t\t   | 1: Bleu fonce                  9: Bleu                 |\n");
           printf("\t\t\t   | 2: Vert                        10: Vert fluo           |\n");
           printf("\t\t\t   | 3: Bleu-gris                   11: Turquoise           |\n");
           printf("\t\t\t   | 4: Marron                      12: Rouge               |\n");
           printf("\t\t\t   | 5: Pourpre                     13: Rose fluo           |\n");
           printf("\t\t\t   | 6: Kaki                        14: Jaune fluo          |\n");
           printf("\t\t\t   | 7: Gris clair                  15: Blanc               |\n");
           printf("\t\t\t   |________________________________________________________|\n\n");
           printf("\n\n\t Veuillez saisir le num%cro de la couleur souhaitee\n\n",130);
           printf("\tPremier plan:");
           scanf("%d",&forgc);
           printf("\n\tArri%cre plan: plan:",138);
           scanf("%d",&backgc);
           ClearConsoleToColors(forgc,backgc);
           system("cls");        //function call to change console background color
            break;

   case 0: system("cls");
           printf("\n\n\t\tAu revoir! :)\n\n");
           exit(0);

   default: Beep(300, 400);
            MessageBox(0,"Veuillez entrer un chiffre valide","Choix inexistant!",1);
            system("cls");
            break;

}


} while (choice != 0);
 return 0;
}








void creer_lignes(int n, int j)
{

   char * strA = "ligne.txt" , * strB[10], strC[50];
   itoa(j,strB,10); //Convertir l'entier j en caractere (j etant le numero de la ligne)
   int x = 5;
   strncpy(strC, strA, x);
   strC[x] = '\0';
   strcat(strC, strB);
   strcat(strC, strA + x);//inserer j(strB) apres la 4eme position de "test.txt"
    //le fichier correspondant a la ligne (j) est test(j).txt

    char ok[TAILLE_MAX]="";
    struct maillon *fnNode, *tmp;
    allouer(&tete);
    FILE* fichier = NULL;
    fichier = fopen(strC, "r");//Ouvrir le fichier

    fscanf(fichier, "%s", ok);
    aff_stat(tete,ok);
    aff_corresp(tete,false);
    aff_adr(tete,NULL); // Lier l'adresse a NIL
    tmp = tete;
    fclose(fichier);//Fermer le fichier
    ptr[j]=tete;// la case de la ligne correspondante recoit la tete de la liste



        int num=0;
        for(int i=2; i<=n; i++)
        {
        fnNode = (struct maillon *)malloc(sizeof(struct maillon));
        fichier = fopen(strC, "r");//Ouvrir le fichier
        char chaine[TAILLE_MAX] = ""; // Chaine vide de taille TAILLE_MAX
        num++;
            if (fichier != NULL)
            {
                for(int m=0; m<=num; m++)
                {
                fscanf(fichier, "%s", chaine); // On lit une station du fichier, on stocke le tout dans "chaine"
                }
            }
        fclose(fichier);//Fermer le fichier
        aff_stat(fnNode,chaine);
        aff_corresp(fnNode,false);//Initialiser corresp a faux
        aff_adr(fnNode,NULL); // links the address field of fnNode with NULL
        aff_adr(tmp,fnNode); // links previous node i.e. tmp to the fnNode
        tmp = suivant(tmp);
        }



}



void corresp_ind(Tptr ptr[20],int MAX)
{
struct maillon *head1, *head2;
int i,j;
char stat[TAILLE_MAX];

   for (j=1; j<MAX+1;j++)//parcourir toutes les cases du tableau
   {
   head1=ptr[j];
       while (head1!= NULL)//parcourir la ligne tant que la fin n'est pas atteinte
      {strcpy(stat,station(head1));//copier le nom de la station dans une variable intermediaire

            for(i=j+1; i<MAX+1;i++)//faire un autre parcourt du tableau sans passer par les lignes deja verifiees
            { head2=ptr[i];
                while (head2!= NULL)//On passe par les stations de chaque ligne
                {
                    if (strcmp(stat, station(head2) )==0)
                    //si on trouve une autre apparition de la station sauvgardee on affecte vrai au
                    //champs corresp de la premiere apparition ainsi qu'a la nouvelle
                    {
                    aff_corresp(head2,true);
                    aff_corresp(head1,true);
                    }
                head2=suivant(head2);
                }
            }

        head1=suivant(head1);
       }

    }



}

void intersection_lignes(Tptr ptr[20],int MAX)
{int k;

    printf("\n****************************************************************************************************\n");
    printf("                                 LES STATIONS DE CORRESPONDANCE\n");

    printf("****************************************************************************************************\n\n");
struct maillon *head1;
      for (k=1; k<MAX+1;k++)//Parcourir les lignes
      {head1=ptr[k];
            while (head1!= NULL)//Tant que la fin de la liste n'est pas atteinte
            {
                if (head1->corresp==true)//Si le champs corresp est vrai alors on ecrit le nom de la station
                {printf("\t>Station %s - ligne %d\n",station(head1),k);
                }

            head1=suivant(head1);//Parcourir les stations de chaque ligne
            }
      }
printf("\n\n\tAppuyez sur n'importe quelle touche pour continuer...");
}




void affich_lignes(Tptr ptr[20],int MAX)
{int k;

struct maillon *head;
    printf("\n****************************************************************************************************\n");
    printf("                                      LES LIGNES DU METRO\n");

    printf("****************************************************************************************************\n\n");


    for (k=1; k<MAX+1;k++)//k etant le numero de la ligne
    {int cpt=1;
    head=ptr[k];
    printf("\n\n\t\t      Ligne %d :\n\n",k);
        while (head!= NULL)
        {printf("      \t%d->%s\n",cpt, station(head));
         head=suivant(head);
         cpt++;//Compteur de la position de la station dans la ligne

        }
    }
}



void delete_by_position(Tptr ptr[20], int MAX)
{int k, position;
struct maillon *temp, *prev;

    printf("\n****************************************************************************************************\n");
    printf("                                      SUPPRIMER UNE STATION\n");

    printf("****************************************************************************************************\n\n");
    printf("\tLa ligne de la station %c supprimer : ",133);
    scanf("%d",&k);
     if (k>MAX)
    {
    MessageBox(0,"Veuillez entrer un ligne valide","Ligne inexistante!",1);
    return;
    };
    printf("\n\tLa position de la station a supprimer : ");
    scanf("%d",&position);
    system("cls");
    printf("\n\n\t\t\tEtes vous s%crs de vouloir supprimer cette station?",150);
    printf("\n\n\t\t\t        1/Oui.                  2/Non.");
    int rep;
    printf("\n\t> ");
    scanf("%d", &rep);
    if (rep==1)
    {temp=ptr[k];
    int i = 0;

        if (temp != NULL && position == 1)//si la position est egale a 1 on supprime la tete
        {
        ptr[k] = suivant(temp);
        free(temp);
        return;
        }

        while (temp != NULL && i < position-1)
        //tant que la fin de la liste n'est pas atteinte et la position voulue n'est pas atteinte
        {
        prev = temp;
        temp = suivant(temp);//on avance dans la ligne
        i++;//on incremente l'indice de la position courante
        }

        if (temp == NULL)
        return;

    aff_adr(prev,suivant(temp));//chainer le maillon precedent avec le suivant
    free(temp);//liberer le maillon a supprimer
    printf("\n\n\tLa station a %ct%c supprim%ce avec succ%cs.",130,130,138);
   }

printf("\n\n\tAppuyez sur n'importe quelle touche pour continuer...");

}




void ajout_station(Tptr ptr[20],int MAX)
{int k;
struct maillon *temp, *prev, *p;

    printf("\n****************************************************************************************************\n");
    printf("                                       AJOUTER UNE STATION\n");

    printf("****************************************************************************************************\n\n");
    printf("\n\tLa ligne de la station %c ajouter : ",133);
    scanf("%d",&k);
    if (k>MAX)
    {
    MessageBox(0,"Veuillez entrer un ligne valide","Ligne inexistante!",1);
    return;
    }

    temp=ptr[k];//acceder a la ligne specifiee
    while (temp != NULL )//tant que la fin de la ligne n'est pas atteinte
    {
    prev = temp;//on enregistre le Tptr precedent
    temp = suivant(temp);
    }

    if (temp == NULL)//quand on atteint NIL
    {p = (Tptr)malloc(sizeof(struct maillon));//creer un nouveau maillon(station) a la fin de la ligne
    aff_adr(prev,p);//on chaine le dernier maillon avec le maillon cree
    aff_adr(p,NULL);//on chaine le nouveau maillon a NIL
    printf("\n\tLa station a ajouter : ");
    scanf("%s",station(p));//le nouveau maillon recoit le nom de la station choisi par l'utilisateur
    }

    printf("\n\tAppuyez sur n'importe quelle touche pour continuer...");
}


void ajout_lignes(Tptr ptr[20],int*MAX)//passage par variablen!!!!!
{ int n,i;
struct maillon *q, *p, *head;
    *MAX=*MAX+1;

    printf("\n****************************************************************************************************\n");
    printf("                                        AJOUTER UNE LIGNE\n");

    printf("****************************************************************************************************\n\n");
    printf("\t\tEntrez le nombre de stations : ");
    scanf("%d",&n);//l'utilisateur precise le nombre de stations
    q = (Tptr)(malloc(sizeof(struct maillon)));//allouer un nouveau maillon (la tete)
    printf("\n\nStation %d : ", 1);
    scanf("%s",station(q));//lire la tete
    aff_corresp(q,false);//Initialiser le champs corresp a faux par defaut
    head = q;

        for (i = 1; i < n; i++) //repeter pour chaque station
            {
            allouer(&p);//Allouer un nouveau maillon
            aff_adr(p, NULL);
            printf("Station %d : ", i+1);
            scanf("%s",station(p)); //lire la station
            aff_adr(q,p);//chainer le nouveau maillon au maillon precedent
            aff_corresp(q,false);//Initialiser le champs corresp a faux par defaut
            q = p;
            }
            ptr[*MAX]=head;//On affecte la tete a la derniere case du tableau



}

void welcome()
{
    printf("\n\t\t\t    _______________________________________________________\n");
    printf("\t\t\t   |        _______     _______     _                      |\n");
    printf("\t\t\t   |       |  _____|   |  _____|   | |  %ccole nationale    |\n",130);
    printf("\t\t\t   |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t   |       |  _____|   |_____  |   | |  sup%crieure         |\n",130);
    printf("\t\t\t   |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t   |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t   |_______________________________________________________|\n\n");
    printf("\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2020/2021 \n\n\n",138,130,130);
    printf("\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t| REALISE PAR : BOUBAHA ROSA et HACINI ADEL WACIM                   |\n");
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t|        \tANNEE : 2020/2021                                   |\n");
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t|         \tSECTION : C           GROUPE: 08                    |\n");
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t|         \tTP1 : Les listes lin%caires chain%ces                 |\n",130,130);
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t|           \t       <LES LIGNES DE METRO>                        |\n");
    printf("\t\t\t|                                                                   |\n");
    printf("\t\t\t| ENCADRE PAR :Dr. KERMI ADEL                                       |\n");
    printf("\t\t\t|___________________________________________________________________|\n\n\n");


 printf("\tAppuyez sur n'importe quelle touche pour continuer..");

}



void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {0, 0};
     DWORD count;
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}






///*************************************************MACHINE ABSTRAITE **********************************************************


Tptr allouer(Tptr *P) //allocation(a majuscule) pour le maillon "station"
{
   *P = (struct maillon *)malloc(sizeof(struct maillon));
   (*P)->adr = NULL;
}
Tptr suivant(Tptr P){return(P->adr);} // s pour le maillon "station"
char*  station(Tptr P) { return(P->station);} // donne le nom de station
void aff_adr(Tptr P,Tptr q){P->adr = q;} // le chainage
//pour l'affectation de 1 ou 0 dans le champs de correspondance on l'a integre dans les programme comme une simple affectation
void aff_stat(Tptr P,char station[20]){strcpy(P->station,station);}
void aff_corresp(Tptr P,bool bol){P->corresp = bol;}
