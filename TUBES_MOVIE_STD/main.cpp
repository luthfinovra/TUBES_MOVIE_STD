
#include "movie.h"


int main(){
    listMovie LM;
    listGenre LG;
    createlistMovie(LM);
    createlistGenre(LG);

    infotype_movie movie;

    adr_movie p_movie;
    adr_genre p_genre;

    int pilihan = menu();
    while (pilihan != 0){
        switch (pilihan){
            case 1:{
                cout << "Nama Film\t: " ; cin >> movie
            }
        }
    }

}
