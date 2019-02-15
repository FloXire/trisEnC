// trie les éléments d'un tableau du plus grand au plus petit
int triCroissant(int elmt1, int elmt2)
{
    return (elmt1 < elmt2);
}

// trie les éléments d'un tableau du plus petit au plus grand
int triDecroissant(int elmt1, int elmt2)
{
    return (elmt1 > elmt2);
}

// cette fonction place les nombres pairs en premier puis les nombres impairs, tout en les triant dans l'ordre croissant
int triPairCroissant(int elmt1, int elmt2)
{
    if ((elmt1%2 == 0) && (elmt2%2 == 1)) return 1;
    else if ((elmt1%2 == 1) && (elmt2%2 == 0)) return 0;
    else if (elmt1 < elmt2) return 1;
    else return 0;
}

// cette fonction place les nombres pairs en premier puis les nombres impairs, tout en les triant dans l'ordre décroissant
int triPairDecroissant(int elmt1, int elmt2)
{
    if ((elmt1%2 == 0) && (elmt2%2 == 1)) return 1;
    else if ((elmt1%2 == 1) && (elmt2%2 == 0)) return 0;
    else if (elmt1 > elmt2) return 1;
    else return 0;
}

// cette fonction place les nombres impairs en premier puis les nombres pairs, tout en les triant dans l'ordre croissant
int triImpairCroissant(int elmt1, int elmt2)
{
    if ((elmt1%2 == 0) && (elmt2%2 == 1)) return 0;
    else if ((elmt1%2 == 1) && (elmt2%2 == 0)) return 1;
    else if (elmt1 < elmt2) return 1;
    else return 0;
}

// cette fonction place les nombres impairs en premier puis les nombres pairs, tout en les triant dans l'ordre décroissant
int triImpairDecroissant(int elmt1, int elmt2)
{
    if ((elmt1%2 == 0) && (elmt2%2 == 1)) return 0;
    else if ((elmt1%2 == 1) && (elmt2%2 == 0)) return 1;
    else if (elmt1 > elmt2) return 1;
    else return 0;
}
