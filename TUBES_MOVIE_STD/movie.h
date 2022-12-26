#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child
#define first(L) ((L).first)

typedef string infotype_movie;
typedef string infotype_genre;
typedef struct elemenMovie *adr_movie;
typedef struct elemenGenre *adr_genre;
typedef struct relation *adr_relation;

struct elemenMovie{
    infotype_movie info;
    adr_relation child;
    adr_movie next;
};

struct elemenGenre{
    infotype_genre info;
    adr_genre next;

};

struct relation{
    adr_genre info;
    adr_relation next;
};

struct listMovie{
    adr_movie first;
};

struct listGenre{
    adr_genre first;
};

void createlistMovie(listMovie &LM);
void createlistGenre(listGenre &LG);
adr_movie createElemenMovie(infotype_movie x);
adr_genre createElemenGenre(infotype_genre x);
void insertMovie(listMovie &LM, adr_movie p);
void insertGenre(listGenre &LG, adr_genre p);
void showMovieGenre(listMovie LM);

#endif // MOVIE_H_INCLUDED
