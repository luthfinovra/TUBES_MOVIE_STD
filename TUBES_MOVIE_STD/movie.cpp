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
    child(p) = NULL;
    return p;
}

adr_genre createElemenGenre(infotype_genre x){
    adr_genre p = new elemenGenre;
    info(p) = x;
    next(p) = NULL;
    return p;
}

adr_relation createElemenRelation(adr_genre p_genre){
    adr_relation p = new relation;
    info(p) = p_genre;
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

adr_genre searchGenre(listGenre LG, infotype_genre x){
    adr_genre p = first(LG);
    while((p!=NULL)){
        if(info(p)==x){
            break;
        }
        p = next(p);
    }
    return p;
}

void insertGenre(listGenre &LG, adr_genre p){
  if(first(LG) == NULL){
        first(LG) = p;
    } else {
        next(p) = first(LG);
        first(LG) = p;
    }
}

void showGenre(listGenre LG){
    if(first(LG)==NULL){
        cout << "Genre Kosong" << endl;
    }else{
        adr_genre p = first(LG);
        cout << endl << "Daftar Genre" << endl;
        cout << "Genre : ";
        while(p != NULL){
            cout << info(p) << ", ";
            p = next(p);
        }
        cout << endl;
    }
}

void showMovieGenre(listMovie LM){
    if(first(LM) == NULL){
        cout << "Data kosong" << endl;
    } else {
        cout << endl << "Daftar Film" << endl;
        adr_movie p = first(LM);
        adr_relation q;
        while (p != NULL){
            cout << "Nama Film\t: " << info(p) << ", Genre: ";
            q = child(p);
            while(q!=NULL){
                cout << info(info(q)) << endl;
                q = next(q);
            }
            p = next(p);
        }
    }
}

void addGenre(listMovie &LM, listGenre &LG, infotype_genre x, adr_movie p_movie){
    adr_genre p_genre = searchGenre(LG, x);
    if(p_genre==NULL){
        p_genre = createElemenGenre(x);
        insertGenre(LG, p_genre);
    }
    addRelation(LM, p_movie, p_genre);
}

void addRelation(listMovie &LM, adr_movie p_movie, adr_genre p_genre){
    adr_relation p_relation = createElemenRelation(p_genre);
    next(p_relation) = child(p_movie);
    child(p_movie) = p_relation;
}

int menu(){
    int i;
    cout << "============================================================" << endl;
    cout << "MENU" << endl;
    cout << "1. Menambahkan Film" << endl;
    cout << "2. Menampilkan Film dan Genre" << endl;
    cout << "3. Menampilkan Genre" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan : " ; cin >> i ;
    return i;
}
