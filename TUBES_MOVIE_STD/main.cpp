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
    adr_relation p_relation;

    int pilihan = menu();
    while (pilihan != 0){
        cin.ignore();
        if(pilihan == 1){
            // poin(a)(d)
            //menambahkan film(parent) sekaligus dengan genrenya(child)
            cout << "Banyak Film yang akan ditambahkan : "; cin >> n;
            cin.ignore();
            i = 0;
            while(i<n){
                cout << "Film " << i+1 << endl;
                cout << "Nama Film: " ; getline(cin, movie, '\n');
                p_movie = createElemenMovie(movie);
                insertMovie(LM, p_movie);
                cout << "Masukkan genre film (input '0' untuk berhenti masukkan genre)" << endl;
                cout << "Genre: "; getline(cin, genre, '\n');
                while(genre!="0"){
                    addGenre(LM, LG, genre, p_movie);
                    cout << "Genre: "; getline(cin, genre, '\n');
                }
                i++;
            }
            cout << "Data Film telah ditambahkan!" << endl;
        }else if(pilihan == 2){
            //poin (b)
            //mencari film dengan judul tertentu dan tampilkan film tersebut dan genrenya
            cout << endl << "Masukkan judul film yang akan dicari: "; getline(cin, movie, '\n');
            p_movie = searchMovie(LM, movie);
            if(p_movie == NULL){
                cout << "Film dengan judul tersebut tidak ditemukan!" << endl;
            }else{
                cout << "Ditemukan film dengan judul tersebut:" << endl;
                p_relation = child(p_movie);
                cout << "Film: " << info(p_movie) << " Genre: ";
                if(p_relation == NULL){
                    cout << "Tidak terdaftar ke genre manapun" << endl;
                }else{
                    while(p_relation!=NULL){
                        cout << info(info(p_relation));
                        if(next(p_relation)!=NULL){
                            cout << " , ";
                        }
                        p_relation = next(p_relation);
                    }
                }
            }
        }else if(pilihan == 3){
            //poin(c)
            //menampilkan seluruh film dan genre dari masing-masing film
            showMovieGenre(LM);
        }else if(pilihan == 4){
            //poin(b)poin(c)
            //menampilkan seluruh genre yang terdaftar, dan minta user untuk memilih genre
            // kemudian tampilkan seluruh judul film dengan genre tersebut
            showGenre(LG);
            if(first(LG)!=NULL){
                cout << "Pilih genre film: "; getline(cin, genre, '\n');
                cout << "Daftar Film dengan genre " << genre << ":" << endl;
                showMovieSelectGenre(LM, genre);
            }
        }else if(pilihan == 5){
            //poin (f)
            //menampilkan total film dan genre yang terdaftar
            cout << "Total film yang terdaftar sebanyak: " << countMovie(LM) << " Film" << endl;
            cout << "Total Genre yang terdaftar sebanyak: " << countGenre(LG) << " Genre" << endl;
        }else if(pilihan == 6){
            // poin (g)
            //menampilkan genre dengann film terbanyak, dan tampilkan film dengan genre tersebut
            genre = MostGenre(LG, LM);
            if(genre == ""){
                cout << "Tidak ada genre terdaftar!!" << endl;
            }else{
                cout << "Genre dengan film terbanyak yaitu Genre " << genre << endl;
                cout << "Dengan Film sebanyak " << countMovieWGenre(LM, genre)<< " sebagai berikut:"<<endl;
                showMovieSelectGenre(LM, genre);
            }
        }else if(pilihan == 7){
            // poin (h)
            //menampilkan genre dengan film paling sedikit, dan tampilkan film dengan genre tersebut
            genre = LeastGenre(LG, LM);
            if(genre == ""){
                cout << "Tidak ada genre terdaftar!!" << endl;
            }else{
                cout << "Genre dengan film Paling sedikit yaitu Genre " << genre << endl;
                cout << "Dengan Film sebanyak " << countMovieWGenre(LM, genre)<< " sebagai berikut:"<<endl;
                showMovieSelectGenre(LM, genre);
            }
        }else if(pilihan == 8){
            //poin (e)
            //hapus suatu film, kemudian hapus seluruh relasinya
            //kemudian cek apakah suatu genre tidak ditunjuk oleh satupun film
            //jika ada, maka juga hapus genre yang tidak ada ditunjuk satupun film tersebut
        }else{
            cout << "Input Tidak Valid!" << endl;
        }
        getline(cin, dummy);
        system("CLS");
        pilihan = menu();
    }

}
