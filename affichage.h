#ifndef H_AFFICHAGE // si H_AFFICHAGE n'a pas encore été définit
#define H_AFFICHAGE // on le definit

#define nbFctTri 2
#define nbFctComp 6

// PtrFonctComp est le type des pointeurs sur fonction de comparaison
typedef int (*PtrFonctComp)(int, int);
// PtrFonctTri est le type des pointeurs sur fonction de tri
typedef int (*PtrFonctTri)(int*, int, int, PtrFonctComp);

typedef struct
{
    int nbFctChoisies;
    PtrFonctComp fonctionCompChoisie;
    PtrFonctTri *fonctionsTriChoisies;
} *PtrFoncTriComp_s;

void printTab(int *tab, int tailleTab);
int verifTabTrie(int *tab, int tailleTab, PtrFonctComp);
void printTrie(int *tab, int tailleTab, PtrFonctComp);
PtrFoncTriComp_s menu(void);

#endif /* guard */
