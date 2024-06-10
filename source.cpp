#include "header.h"

void createListGames(ListGames &LG)
{
    LG.first_Games = NULL;
}

void createListStore(ListStore &LS)
{
    LS.first_Store = NULL;
}

adr_games createElmGames(InfoGames info)
{
    adr_games g = new ElmGames;
    g->info = info;
    g->next_Games = NULL;
    g->prev_Games = NULL;
    g->Store.first_Store = NULL;
    return g;
}

adr_store createElmStore(InfoStore info)
{
    adr_store s = new ElmStore;
    s->info = info;
    s->next_Store = NULL;
    s->Games.first_Games = NULL;
    return s;
}

void insertStore(ListStore &LS, adr_store s)
{
    if (LS.first_Store == NULL)
    {
        LS.first_Store = s;
    }
    else
    {
        adr_store q = LS.first_Store;
        while (q->next_Store != NULL)
        {
            q = q->next_Store;
        }
        q->next_Store = s;
    }
}

void insertGames(ListGames &LG, adr_games g) {
    if (LG.first_Games == NULL) {
        LG.first_Games = g;
    } else {
        g->next_Games = LG.first_Games;
        LG.first_Games->prev_Games = g;
        LG.first_Games = g;
    }
}

adr_store searchStore(ListStore LS, string idStore)
{
    if (LS.first_Store == NULL)
    {
        return NULL;
    }
    else
    {
        adr_store s = LS.first_Store;
        while ((s->next_Store != NULL) && (s->info.idStore != idStore))
        {
            s = s->next_Store;
        }
        if (s->info.idStore == idStore)
        {
            return s;
        }
        else
        {
            return NULL;
        }
    }
}

adr_games searchGames(ListGames LG, string idGames)
{
    if (LG.first_Games == NULL)
    {
        return NULL;
    }
    else
    {
        adr_games g = LG.first_Games;
        while ((g->next_Games != NULL) && (g->info.idGames != idGames))
        {
            g = g->next_Games;
        }
        if (g->info.idGames == idGames)
        {
            return g;
        }
        else
        {
            return NULL;
        }
    }
}

void addRelasi(ListGames &LG, ListStore &LS, string idGames, string idStore)
{
    adr_games g = searchGames(LG, idGames);
    adr_store s = searchStore(LS, idStore);
    if ((g != NULL) && (s != NULL))
    {
        // Buat elemen baru untuk relasi game-store
        adr_store newStore = createElmStore(s->info);
        newStore->next_Store = g->Store.first_Store;
        g->Store.first_Store = newStore;

        // Buat elemen baru untuk relasi store-game
        adr_games newGame = createElmGames(g->info);
        newGame->next_Games = s->Games.first_Games;
        s->Games.first_Games = newGame;
    }
    else
    {
        cout << "Game or Store not found.\n";
    }
}


void viewGames(ListGames &LG)
{
    if (LG.first_Games == NULL)
    {
        cout << "Empty...";
    }
    else
    {
        adr_games g = LG.first_Games;
        while (g != NULL)
        {
            cout << "[ID Game : " << g->info.idGames << ", Name Game : " << g->info.NamaGames << ", Genre Game : " << g->info.GenreGames << "]";
            if (g->next_Games != NULL) {
                cout << ", ";
            }
            g = g->next_Games;
        }
    }
}

void viewStore(ListStore &LS)
{
    if (LS.first_Store == NULL)
    {
        cout << "Empty...";
    }
    else
    {
        adr_store s = LS.first_Store;
        while (s != NULL)
        {
            cout << "[ID Store : " << s->info.idStore << ", Name Store : " << s->info.NamaStore << ", Platform : " << s->info.PlatformStore << "]";
            if (s->next_Store != NULL) {
                cout << ", ";
            }
            s = s->next_Store;
        }
    }
}

void deleteStore(ListStore &LS, string idStore) {
    if (LS.first_Store == NULL) {
        cout << "The store list is empty, nothing can be deleted." << endl;
        return;
    }

    // Jika store yang akan dihapus adalah store pertama
    if (LS.first_Store->info.idStore == idStore) {
        adr_store temp = LS.first_Store;
        LS.first_Store = LS.first_Store->next_Store;
        delete temp;
        cout << "Store With ID " << idStore << " Successfully Deleted." << endl;
        return;
    }

    // Mencari store yang akan dihapus
    adr_store s = LS.first_Store;
    while (s->next_Store != NULL && s->next_Store->info.idStore != idStore) {
        s = s->next_Store;
    }

    if (s->next_Store == NULL) {
        cout << "Store With ID " << idStore << " Not Found." << endl;
        return;
    }

    // Menghapus store
    adr_store temp = s->next_Store;
    s->next_Store = s->next_Store->next_Store;
    delete temp;
    cout << "Store With ID " << idStore << " Successfully Deleted." << endl;
}

void deleteGames(ListGames &LG, string idGames) {
    if (LG.first_Games == NULL) {
        cout << "The games list is empty, nothing can be deleted." << endl;
        return;
    }

    adr_games g = LG.first_Games;

    // Mencari game yang akan dihapus
    while (g != NULL && g->info.idGames != idGames) {
        g = g->next_Games;
    }

    if (g == NULL) {
        cout << "Game With ID " << idGames << " Not Found." << endl;
        return;
    }

    // Menghapus game
    if (g == LG.first_Games) { // Game yang dihapus adalah game pertama
        LG.first_Games = g->next_Games;
        if (LG.first_Games != NULL) {
            LG.first_Games->prev_Games = NULL;
        }
    } else {
        g->prev_Games->next_Games = g->next_Games;
        if (g->next_Games != NULL) {
            g->next_Games->prev_Games = g->prev_Games;
        }
    }

    delete g;
    cout << "Game With ID " << idGames << " Successfully Deleted." << endl;
}

void view(ListStore &LS)
{
    if (LS.first_Store == NULL)
    {
        cout << "Empty...";
    }
    else
    {
        adr_store s = LS.first_Store;
        cout << "\n====================================\n";
        while (s->next_Store != NULL)
        {
            cout << "ID Store : " << s->info.idStore << ", Name Store : " << s->info.NamaStore << ", Platform : " << s->info.PlatformStore;
            viewGames(s->Games);
            cout << "\n====================================\n";
            s = s->next_Store;
        }
        cout << "ID Store : " << s->info.idStore << ", Name Store : " << s->info.NamaStore << ", Platform : " << s->info.PlatformStore;
        viewGames(s->Games);
        cout << "\n====================================\n";
    }
}

void displayStore(ListStore LS, string idStore)
{
    adr_store s = searchStore(LS, idStore);
    if (s != NULL)
    {
        cout << "List of Games in Store " << idStore << ":" << endl;
        adr_games g = s->Games.first_Games;
        while (g != NULL)
        {
            cout << "[ID Game : " << g->info.idGames << ", Name Game : " << g->info.NamaGames << ", Genre Game : " << g->info.GenreGames << "]" <<  endl;
            g = g->next_Games;
        }
    }
    else
    {
        cout << "Game Not Found." << endl;
    }
}

void displayGames(ListGames LG, string idGames) {
    adr_games g = searchGames(LG, idGames);
    if (g != NULL) {
        cout << "List of Stores That Sell Game with ID " << idGames << ":\n";
        adr_store s = g->Store.first_Store;
        if (s == NULL) {
            cout << "There are no stores selling this game.\n";
        } else {
            while (s != NULL) {
                cout << "[ID Store : " << s->info.idStore << ", Name Store : " << s->info.NamaStore << ", Platform :" << s->info.PlatformStore << "]\n";
                s = s->next_Store;
            }
        }
    } else {
        cout << "Games With ID " << idGames << " Not Found.\n";
    }
}

int countGames(adr_store store) {
    int count = 0;
    adr_games g = store->Games.first_Games;
    while (g != NULL) {
        count++;
        g = g->next_Games;
    }
    return count;
}

void findStoreWithGames(ListStore &LS, string option) {
    if (LS.first_Store == NULL) {
        cout << "The store list is empty." << endl;
        return;
    }

    adr_store store = LS.first_Store;
    adr_store targetStore = store;
    int count = countGames(store);
    int targetCount = count;

    store = store->next_Store;

    while (store != NULL) {
        count = countGames(store);
        if ((option == "terbesar" && count > targetCount) || (option == "terkecil" && count < targetCount)) {
            targetCount = count;
            targetStore = store;
        }
        store = store->next_Store;
    }

    if (option == "terbesar") {
        cout << "Stores with the Most Game Sales are: " << endl;
    } else {
        cout << "Stores with the Least Game Sales are: " << endl;
    }
    cout << "[ID Store: " << targetStore->info.idStore << ", Name Store: " << targetStore->info.NamaStore << ", Platform: " << targetStore->info.PlatformStore << ", Number of Games: " << targetCount << "]" << endl;
}