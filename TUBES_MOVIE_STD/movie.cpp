#include "movie.h"

void createlistMovie(listMovie &LM){
    first(LM) = NULL;
}

void createlistGenre(listGenre &LG){
    first(LG) = NULL;
}

adr_movie createElemenMovie(infotype_movie x){
    adr_movie p = new elemenMovie;
    info(p) = x;
    next(p) = NULL;
    return p;
}

adr_genre createElemenGenre(infotype_genre x){
    adr_genre p = new elemenGenre;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertMovie(listMovie &LM, adr_movie p){
    if(first(LM) == NULL){
        first(LM) = p;
    } else {
        next(p) = first(LM);
        first(LM) = p;
    }
}

void insertGenre(listGenre &LG, adr_genre p){
  if(first(LG) == NULL){
        first(LG) = p;
    } else {
        next(p) = first(LG);
        first(LG) = p;
    }
}
void showMovieGenre(listMovie LM){
    if(first(LM) == NULL){
        cout << "Data kosong" << endl;
    } else {
        adr_movie p = first(LM);
        while (p != NULL){
            cout << "Nama Film\t: " << info(p) << endl;
            p = next(p);
        }
    }
}

int menu(){
    int i;
    cout << "============================================================" << endl;
    cout << "MENU" << endl;
    cout << " 1. Menambahkan Film " << endl;
    cout << "Pilihan : " ; cin >> i ;
    return i;
}
