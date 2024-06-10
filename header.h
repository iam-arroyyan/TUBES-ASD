#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string.h>
using namespace std;

typedef struct ElmGames *adr_games;   // pointer to elmGames
typedef struct ElmStore *adr_store; // pointer to elmStore

struct InfoGames
{
    string idGames;
    string NamaGames;
    string GenreGames; // Horror, Adventure, Action, Romance, fight, triller,zombie
};

struct InfoStore
{
    string idStore;
    string NamaStore;
    string PlatformStore; // PS5 , PS4 , Seri Xbox X , Seri Xbox S , Xbox One , PC , Stadia
};

struct ListGames
{
    adr_games first_Games;
};

struct ListStore
{
    adr_store first_Store;
};

struct ElmGames
{
    InfoGames info;
    adr_games next_Games;   
    adr_games prev_Games;
    ListStore Store; 
};

struct ElmStore
{
    InfoStore info;
    adr_store next_Store;
    ListGames Games;
};

void createListGames(ListGames &LG);
void createListStore(ListStore &LS);
adr_games createElmGames(InfoGames info);
adr_store createElmStore(InfoStore info);
void insertStore(ListStore &LS, adr_store s);
void insertGames(ListGames &LG, adr_games g);
adr_store searchStore(ListStore LS, string idStore);
adr_games searchGames(ListGames LG, string idGames);
void addRelasi(ListGames &LG, ListStore &LS, string idGames, string idStore);
void viewGames(ListGames &LG);
void viewStore(ListStore &LS);
void deleteStore(ListStore &LS, string idStore);
void deleteGames(ListGames &LG, string idGames);
void view(ListStore &LS);
void displayStore(ListStore LS, string idStore);
void displayGames(ListGames LG, string idGames);
int countGames(adr_store store);
void findStoreWithGames(ListStore &LS, string option);

#endif