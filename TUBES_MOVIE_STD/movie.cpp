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

adr_movie searchMovie(listMovie LM, infotype_movie x){
    adr_movie p = first(LM);
    while(p!=NULL){
        if(info(p)==x){
            return p;
        }
        p = next(p);
    }
    return p;
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
            cout << info(p);
            if(next(p)!=NULL){
                cout << ", ";
            }
            p = next(p);
        }
        cout << endl;
    }
}

void showMovieSelectGenre(listMovie LM, infotype_genre genre){
    adr_movie p = first(LM);
    adr_relation q;
    int i = 1;
    while (p != NULL){
        q = child(p);
        while(q!=NULL){
                if(info(info(q))==genre){
                    cout << i << ". " << info(p) << endl;
                    i++;
                    break;
                }
                q = next(q);
        }
            p = next(p);
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
            cout << "Nama Film: " << info(p) << ", Genre: ";
            q = child(p);
            while(q!=NULL){
                cout << info(info(q));
                if(next(q)!=NULL){
                    cout << ", ";
                }
                q = next(q);
            }
            p = next(p);
            cout << endl;
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

int countMovie(listMovie LM){
    int i = 0;
    adr_movie p = first(LM);
    while(p != NULL){
        i++;
        p = next(p);
    }
    return i;
}

int countGenre(listGenre LG){
    int i = 0;
    adr_genre p = first(LG);
    while(p != NULL){
        i++;
        p = next(p);
    }
    return i;
}

int countMovieWGenre(listMovie LM, infotype_genre x){
    int i = 0;
    adr_movie p_movie = first(LM);
    adr_relation p_relation = NULL;
    while(p_movie!=NULL){
        p_relation = child(p_movie);
        while(p_relation!=NULL){
            if(info(info(p_relation))==x){
                i++;
                break;
            }else{
                p_relation = next(p_relation);
            }
        }
        p_movie = next(p_movie);
    }
    return i;
}

infotype_genre MostGenre(listGenre LG, listMovie LM){
    int i = 0, maks = 0;
    infotype_genre genre_maks = "";
    adr_genre p_genre = first(LG);
    while(p_genre !=NULL){
        i = countMovieWGenre(LM, info(p_genre));
        if(i > maks){
            maks = i;
            genre_maks = info(p_genre);
        }
        p_genre = next(p_genre);
    }
    return genre_maks;
}

infotype_genre LeastGenre(listGenre LG, listMovie LM){
    int i = 0, minimum = -1;
    infotype_genre genre_min = "";
    adr_genre p_genre = first(LG);
    while(p_genre !=NULL){
        i = countMovieWGenre(LM, info(p_genre));
        if(i < minimum){
            minimum = i;
            genre_min = info(p_genre);
        }else if(minimum == -1){
            minimum = i;
            genre_min = info(p_genre);
        }
        p_genre = next(p_genre);
    }
    return genre_min;
}


void deleteMovie(listMovie &LM, infotype_movie x){
    adr_movie p_movie = searchMovie(LM, x);
    if(p_movie == NULL){
        cout << "Film Tidak Ditemukan!!" << endl;
    }else{
        deleteAllRelation(p_movie);
        if(p_movie == first(LM)){
            first(LM) = next(p_movie);
            delete p_movie;
        }else{
            adr_movie prev_movie = first(LM);
            while(next(prev_movie)!=p_movie){
                prev_movie = next(prev_movie);
            }
            next(prev_movie) = next(p_movie);
            delete p_movie;
        }
    }
}

void deleteAllRelation(adr_movie &p_movie){
    adr_relation p_relation;
    while(child(p_movie)!=NULL){
        p_relation = child(p_movie);
        child(p_movie) = next(p_relation);
        delete p_relation;
    }
}

void deleteGenre(listGenre &LG, infotype_genre x){
    adr_genre p_genre = first(LG), prev = first(LG);
    while(info(p_genre)!=x){
        prev = p_genre;
        p_genre = next(p_genre);
    }
    if(p_genre == first(LG)){
        first(LG) = next(p_genre);
        delete p_genre;
    }else{
        next(prev) = next(p_genre);
        delete p_genre;
    }
}

void deleteAllMovie(listMovie &LM){
    adr_movie p_movie = first(LM);
    while(p_movie!=NULL){
        deleteMovie(LM, info(p_movie));
        p_movie = first(LM);
    }
}

void deleteAllGenre(listGenre &LG){
    adr_genre p_genre = first(LG);
    while(p_genre!=NULL){
        deleteGenre(LG, info(p_genre));
        p_genre = first(LG);
    }
}

string menu(){
    string i;
    cout << "===========================================================" << endl;
    cout << "                 TUGAS BESAR STRUKTUR DATA                 " << endl;
    cout << " Kelas : IF-45-12     Kelompok : VGA    Linked List Tipe C " << endl;
    cout << "===========================================================" << endl;
    cout << "                      ANGGOTA KELOMPOK                     " << endl;
    cout << "               1. Adiandra Haikal(1301213200)              " << endl;
    cout << "                 2. Luthfi Novra(1301213454)               " << endl;
    cout << "===========================================================" << endl;
    cout << "                       DATABASE FILM                       " << endl;
    cout << "===========================================================" << endl;
    cout << "MENU" << endl;
    cout << "1. Menambahkan Film dan Genre" << endl;
    cout << "2. Mencari Film" << endl;
    cout << "3. Menampilkan Seluruh Film dan Genre" << endl;
    cout << "4. Menampilkan Film dengan Genre Tertentu" << endl;
    cout << "5. Menampilkan total Film dan Genre" << endl;
    cout << "6. Menampilkan Genre dengan film terdaftar terbanyak" << endl;
    cout << "7. Menampilkan Genre dengan film terdaftar paling sedikit" << endl;
    cout << "8. Menghapus Data Film" << endl;
    cout << "9. Menghapus Seluruh Film" << endl;
    cout << "0. Exit" << endl;
    cout << "===========================================================" << endl;
    cout << "Pilihan : " ; cin >> i ;
    return i;
}
