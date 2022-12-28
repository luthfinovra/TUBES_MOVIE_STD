#include "movie.h"

int main(){
    listMovie LM;
    listGenre LG;
    createlistMovie(LM);
    createlistGenre(LG);

    infotype_movie movie;
    infotype_genre genre;
    int n, i;
    string dummy;

    adr_movie p_movie;
    adr_genre p_genre;

    int pilihan = menu();
    while (pilihan != 0){
        cin.ignore();
        if(pilihan == 1){
            cout << "Banyak Film yang akan ditambahkan : "; cin >> n;
            cin.ignore();
            i = 0;
            while(i<n){
                cout << "Film " << i+1 << endl;
                cout << "Nama Film: " ; getline(cin, movie, '\n');
                p_movie = createElemenMovie(movie);
                insertMovie(LM, p_movie);
                cout << "Genre: "; getline(cin, genre, '\n');
                addGenre(LM, LG, genre, p_movie);
                i++;
            }
            cout << "Data Film telah ditambahkan!" << endl;
        }else if(pilihan == 2){
            showMovieGenre(LM);
        }else if(pilihan == 3){
            showGenre(LG);
        }else{
            cout << "Input Tidak Valid!" << endl;
        }
        getline(cin, dummy);
        system("CLS");
        pilihan = menu();
    }

}
