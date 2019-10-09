#include <stdio.h>  // output/input/erreurs/... (printf(),scanf(),gets(),puts()...)
#include <stdlib.h> // Type conversion (chaine de c. <-> nombre)
#include <string.h> // biblio pour les chaînes des caractéres comparer/copier/chercher/...

int main()
{
    // Declaration des variables
    char dict[20][50];      // Tableau de deux dimensions
    int n;                  // n pour la taille initial de dictionaire (Tableau des mots)
    int i, j;               // Pour les boucles utilisées
    _Bool tri;              // vérification si tri ou non
    char temp[50];          // Une chaine temporaire (pour l'échange de deux chaine)
    char mot[50];           // pour l'insertion/Suppression

    // Construction de la dictionnaire
    printf("Entrer la taille de votre dictionnaire : ");
    scanf("%d",&n);
    printf("Entrer ton liste des mots :\n");
    getchar(); // pour tapez le premier dict[0] suivante // sinon (n'ajoute pas ce ligne) il va stocker rien (ligne vide)
    for(i=0; i<n; i++)
    {
        printf("-> ");
        gets(dict[i]);
    }
    /// tri du tableau (dictionnaire): Tri à bulle
    tri=1;     // 0 signifie "Vrai" // autre valeur "Faux"
    while(tri) // while(trie!=0) c'est la même chose
    {
        tri=0; // pour finir la vérification
        for(i=0; i<n-1; i++) // non accolade nécessaire car on a une seule instruction
            if(strcmp(dict[i],dict[i+1])>0) // les accolades nécessaire car on a plusieurs instruction
            {
                strcpy(temp,""); // intialization temp par rien
                strcpy(temp,dict[i]);
                strcpy(dict[i],dict[i+1]);
                strcpy(dict[i+1],temp);
                tri=1; // pour revérification
            }
    }
    // Affichage
    printf("ton liste est :\n");
    for(i=0; i<n; i++)
    {
        printf("- %s\n",dict[i]); // ou puts(dict[i]);
    }

    // Insertion d'un mot au dictionaire
    printf("ajouter une mot au dictionnaire : ");
    gets(mot);
    for(i=0; i<n; i++)
    {
        if(strcmp(dict[i],mot)>0)
        {
            for(j=n-1; j>=i; j--)
            {
                strcpy(dict[j+1],dict[j]);
            }
            strcpy(dict[i],mot);
            break;
        }
    }
    if(i==n) // le mot est de plus grand de tous les mots deja inserer
    {
        strcpy(dict[n],mot);
    }
    n++; // redimensionner ?! (on a jouté une case)
    // Affichage
    printf("ton liste est [Apres l'insertion] :\n");
    for(i=0; i<n; i++)
    {
        printf("- %s\n",dict[i]);
    }

    // Suprimer un mot
    printf("Entrer une mot pour suprimer: ");
    gets(mot);
    for(i=0; i<n; i++)
    {
        if(!strcmp(dict[i],mot)) // ou if(strcmp(dict[i],mot)==0) c'est la même chose
        {
            for(j=i; j<n-1; j++)
            {
                strcpy(temp,dict[j+1]);
                strcpy(dict[j+1],dict[j]);
                strcpy(dict[j],temp);
            }
            n--; // on suprime un mot
            // on le remplace par rien (NULL-Character)
            strcpy(dict[n],"\0"); // le mot suprimé est lecalisé a la fin de tableau
            printf("ton mot a ete suprime!\n");
            break; // la sortire de boucle, car nous trouvons le mot
        }
    }
    // Affichage
    // si le i recoi l'indice d'afin du tableau signifie que la mot pour suprimer n'existe pas
    if(i==n) printf("ton mot n'existe pas!\nton liste est :\n");
    else printf("ton liste est [Apres la Suppression] :\n");
    for(i=0; i<n; i++)
    {
        printf("- %s\n",dict[i]);
    }

    return 0;
}
