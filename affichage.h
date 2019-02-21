#ifndef H_AFFICHAGE // si H_AFFICHAGE n'a pas encore été définit
#define H_AFFICHAGE // on le definit

#define nbFctTri 5
#define nbFctComp 6

// PtrFonctComp est le type des pointeurs sur fonction de comparaison
typedef int (*PtrFonctComp)(int, int);
// PtrFonctTri est le type des pointeurs sur fonction de tri
typedef int (*PtrFonctTri)(int*, int, int, PtrFonctComp);

/* Structure contenant le nombre de fonctions de tri choisies, 
la fonction de comparaison et le tableau contenant les pointeurs
des fonctions de tri choisies */
typedef struct
{
    int nbFctChoisies;
    PtrFonctComp fonctionCompChoisie;
    PtrFonctTri *fonctionsTriChoisies;
} FoncTriComp_s;

typedef FoncTriComp_s *PtrFoncTriComp_s;

void printTab(int *tab, int tailleTab);
void printTrie(int *tab, int tailleTab, PtrFonctComp);
int verifTabTrie(int *tab, int tailleTab, PtrFonctComp);
PtrFoncTriComp_s menu(void);

#endif /* guard */
