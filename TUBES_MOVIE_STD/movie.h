#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <iostream>
#include <string.h>

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
adr_relation createElemenRelation(adr_genre p_genre);
void insertMovie(listMovie &LM, adr_movie p);
void insertGenre(listGenre &LG, adr_genre p);
void showGenre(listGenre LG);
void showMovieSelectGenre(listMovie LM, infotype_genre genre);
void showMovieGenre(listMovie LM);
adr_movie searchMovie(listMovie LM, infotype_movie x);
adr_genre searchGenre(listGenre LG, infotype_genre x);
void addGenre(listMovie &LM, listGenre &LG, infotype_genre x, adr_movie p_movie);
void addRelation(listMovie &LM, adr_movie p_movie, adr_genre p_genre);
int countMovie(listMovie LM);
int countGenre(listGenre LG);
int countMovieWGenre(listMovie LM, infotype_genre x);
infotype_genre MostGenre(listGenre LG, listMovie LM);
infotype_genre LeastGenre(listGenre LG, listMovie LM);
void deleteMovie(listMovie &LM, infotype_movie x);
void deleteAllMovie(listMovie &LM);
void deleteAllGenre(listGenre &LG);
void deleteAllRelation(adr_movie &p_movie);
void deleteGenre(listGenre &LG, infotype_genre x);
string menu();

#endif // MOVIE_H_INCLUDED
