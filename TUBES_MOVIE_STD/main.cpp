#include "movie.h"

int main(){
    listMovie LM;
    listGenre LG;
    createlistMovie(LM);
    createlistGenre(LG);

    infotype_movie movie;
    int n;

    adr_movie p_movie;
    adr_genre p_genre;

    int pilihan = menu();
    while (pilihan != 0){
        switch (pilihan){
            case 1:
                cout << "Banyak Film yang akan ditambahkan : "; cin >> n;
                cin.ignore();
                while(n>0){
                    cout << "Nama Film\t: " ; getline(cin, movie, '\n');
                    n--;
                    p_movie = createElemenMovie(movie);
                    insertMovie(LM, p_movie);
                }
                break;
            case 2:
                showMovieGenre(LM);
                break;
            default:
                cout << "Input tidak valid!" << endl;
        }
        pilihan = menu();
    }

}
