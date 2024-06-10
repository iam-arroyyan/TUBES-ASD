/*Judul : Data Game Store
Deskripsi : implementasikan multi linked-list yang memodelkan data 
Game Store dan Games beserta relasi keduanya. Suatu Game Store bisa Menjual beberapa games. Dan suatu games bisa dijual oleh 2 Game Store.
Fungsionalitas :
a. Penambahan data Game Store.	
b. Penambahan data Games.
c. Penentuan relasi Game Store dan games yang dijual(dan sebalikknya).
d. Menghapus data Game Store.
e. Manghapus data Games.
f. Menampilkan data keseluruhan Game Store beserta data Games yang dijualnya.
g. Menampilkan data Games yang dijual oleh Game Store tertentu.
h. Menampilkan data Game Store yang Menjual Games tertentu.
i. Menampilkan data Game Store yang paling banyak Menjual Games dan yang paling sedikit Menjual Games. */

// RAPIIN OUTPUT

#include "header.h"
#include "source.cpp"

int main(){
    ListGames LG;
    ListStore LS;

    createListGames(LG);
    createListStore(LS);

    int pilihan;
    awal:
    do
    {
        system("Color 0A");  
        cout << endl << "----------------------------";
        cout << endl << "      Main Menu   ";
        cout << endl << "----------------------------" << endl;
        viewStore(LS);
        cout << endl;
        viewGames(LG);
        cout << endl << "----------------------------" << endl;
        cout << "1. Add Store" << endl;
        cout << "2. Add Game" << endl;
        cout << "3. Relationships Between Game Stores and Games" << endl;
        cout << "4. Delete Store" << endl;
        cout << "5. Delete Game" << endl;
        cout << "6. Display All Game Stores and the Games" << endl;
        cout << "7. Display Games sold by certain Game Stores" << endl;
        cout << "8. Display Store Selling Specific Game" << endl;
        cout << "9. Displays Store With The Most And Least Games" << endl;
        cout << "10. Quit" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter Options : ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            InfoStore is;
            cout << "Insert ID Game Store : ";
            cin >> is.idStore;
            cout << "Insert Name Game Store : ";
            cin >> is.NamaStore;
            cout << "Insert Platform Game Store : ";
            cin >> is.PlatformStore;
            adr_store s = createElmStore(is);
            insertStore(LS, s);
            system("pause");
            system("cls");
        }
        else if (pilihan == 2)
        {
            InfoGames ig;
            cout << "Insert ID Games : ";
            cin >> ig.idGames;
            cout << "Insert Name Games : ";
            cin >> ig.NamaGames;
            cout << "Insert Genre Games : ";
            cin >> ig.GenreGames;
            adr_games g = createElmGames(ig);
            insertGames(LG, g);
            system("pause");
            system("cls");
        }
        else if (pilihan == 3)
        {
            string idStore, idGames;
            cout << "Insert ID Game Store : ";
            cin >> idStore;
            cout << "Insert ID Games : ";
            cin >> idGames;
            addRelasi(LG,LS,idGames,idStore);
            system("pause");
            system("cls");
        }
        else if (pilihan == 4)
        {
            cout << "======== CAUTION ========" << endl;
            cout << "Be careful, all store data will be deleted, press 0 to return" << endl;
            string idStore;
            cout << "Enter The Game Store ID You Want To Delete : ";
            cin >> idStore;
            if (idStore == "0")
            {
                goto awal;
            }
            else
            {
                deleteStore(LS, idStore);
            }
            system("pause");
            system("cls");
        }
        else if (pilihan == 5)
        {
            cout << "======== CAUTION ========" << endl;
            cout << "Be careful, all store data will be deleted, press 0 to return" << endl;
            string idGames;
            cout << "Enter The Games ID You Want To Delete : ";
            cin >> idGames;
            if (idGames == "0")
            {
                goto awal;
            }
            else
            {
                deleteGames(LG, idGames);
            }
            system("pause");
            system("cls");
        }
        else if (pilihan == 6)
        {
            view(LS);
            system("pause");
            system("cls");
        }
        else if (pilihan == 7)
        {
            string idStore;
            cout << "Enter The Store ID You Want To Display The Game : ";
            cin >> idStore;
            displayStore(LS, idStore);
            system("pause");
            system("cls");
        }
        else if (pilihan == 8) 
        {
            string idGames;
            cout << "Enter The Game ID You Want To Display In The Store : ";
            cin >> idGames;
            displayGames(LG, idGames);
            system("pause");
            system("cls");
        }
        
        else if (pilihan == 9)
        {
            atas:
            int pilihan_show;
            cout << "1. Most Selling Games\n";
            cout << "2. least Selling Games\n";
            cout << "Enter Options : ";
            cin >> pilihan_show;
            if (pilihan_show == 1)
            {
                findStoreWithGames(LS, "terbesar");
            }
            else if (pilihan_show == 2)
            {
                findStoreWithGames(LS, "terkecil");
            }
            else
            {
                cout << "Wrong Choice!" << endl;
                goto atas;
            }
            system("pause");
            system("cls");
        }
    } while (pilihan != 10);
    return 0;
}
