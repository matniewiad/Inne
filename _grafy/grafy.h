#pragma once
#include <iostream>
#include <list>
#include <stack>
using namespace std;
//n - liczba wierzcholkow
//E - liczba krawedzi 


//***********************************
//macierz sasiedztwa - funkcje glown
//***********************************

//alokuje pamiec. Uzycie w main: int **tab = stworz_macierz_nxn(n);
int **stworz_macierz_nxn(int n);

//zwalnia pamiec
void usun_macierz_nxn(int ** tab, int n);

//wypelnia macierz 0
void zeruj_macierz_nxn(int **tab, int n);

//wyswietla macierz i 'os wspolrzednych'
void wyswietl_macierz_nxn(int **tab, int n);

//wypelnienie macierzy sasiedztwa dla grafu nieskierowanego
void wypelnij_macierz_sasiedztwa_nxn_NDG(int **tab, int n, int E);

//wypelnienie macierzy sasiedztwa dla grafu skierowanego
void wypelnij_macierz_sasiedztwa_nxn_DG(int **tab, int n, int E);

//wczytywanie macierzy sasiedztwa dla grafu skierowanego (DG) z pliku. Liczba krawedzi i wierzcholkow znana wczesniej. W pliku tylko pary krawedzi.
void wczytaj_macierz_sasiedztwa_nxn_DG_z_pliku(int**graf, string nazwa, int E);

//wczytywanie macierzy sasiedztwa dla grafu nieskierowanego (NDG) z pliku. Liczba krawedzi i wierzcholkow znana wczesniej. W pliku tylko pary krawedzi.
void wczytaj_macierz_sasiedztwa_nxn_NDG_z_pliku(int**graf, string nazwa, int E);


//*************************************
//macierz sasiedztwa - funckje poboczne
//*************************************

//przpisywanie jednego grafu do drugiego
void przepisz_nxn(int**cel, int**zrodlo, int n);

//wyswietlanie sasiadow danego wierzcholka
void wypisz_sasiadow_wierzcholka_nxn(int **tab, int n, int ktory);

//wyswietlanie wierzcholkow, dla ktorych dany wierzcholek jest sasiadem
void dla_kogo_sasiadem_nxn(int **tab, int n, int ktory);

//wyswietlanie stopni grafu nieskierowanego NDG
void stopnie_nxn_NDG(int **tab, int n);

//stopnie wchodzace grafu skierowanego
void stopnie_wchodzace_nxn(int **tab, int n);

//stopnie wychodzace grafu skierowanego
void stopnie_wychodzace_nxn(int **tab, int n);

//krawedzie dwukierunkowe w grafie skierowanym
void krawedzie_dwukierunkowe_nxn_DG(int **tab, int n);

//wierzcholki izolowane
void wierzcholki_izolowane_nxn(int **tab, int n);

//petlew grafie
void petle_nxn(int **tab, int n);


//**********************************
//**** macierz incydencji nxm ******
//**********************************

//alokuje pamiec dla macierzy incydencji mxn. Uzycie w main: int **tab = stworz_macierz_nxn(n, m);
int **stworz_macierz_nxm(int n, int m);

//zwalnianie pamieci -> takie samo jak dla nxn
void usun_macierz_nxm(int ** tab, int n);

//wypelnia macierz nxm 0
void zeruj_macierz_nxm(int **tab, int n, int m);

//wyswietla macierz nxm i 'os wspolrzednych'
void wyswietl_macierz_nxm(int **tab, int n, int m);

//wypelnienie macierzy incydencji dla grafu skierowanego
void wypelnij_macierz_incydencji_nxm_DG(int **tab, int n, int E);

//wypelnienie macierzy incydencji dla grafu nieskierowanego
void wypelnij_macierz_incydencji_nxm_NDG(int **tab, int n, int E);

//wierzcholki izolowane
void wierzcholki_izolowane_nxm(int **tab, int n, int E);


//**********************************
// lista sasiedztwa - funckje glowne
//**********************************

//alokuje pamiec. Uzycie w main: list<int> *graf = stworz_liste_sasiedztwa(n);		tworzy tablice list
list<int>* stworz_liste_sasiedztwa(int n);

//zwalnia pamiec
void usun_liste_sasiedztwa(list<int>*graf);

//wczytuje graf skierowany (DG) z pliku. Liczba krawedzi i wierzcholkow znana wczesniej. W pliku tylko pary krawedzi.
void wczytaj_liste_sasiedztwa_DG_z_pliku(list<int>*graf, string nazwa, int E);

//wczytuje graf nieskierowany (NDG) z pliku. Liczba krawedzi i wierzcholkow znana wczesniej. W pliku tylko pary krawedzi.
void wczytaj_liste_sasiedztwa_NDG_z_pliku(list<int>*graf, string nazwa, int E);

//wczytywanie listy sasiedztwa dla grafu nieskierowanego
void wypelnij_liste_sasiedztwa_NDG(list<int> *graf, int n, int E);

//wczytywanie listy sasiedztwa dla grafu skierowanego
void wypelnij_liste_sasiedztwa_DG(list<int> *graf, int n, int E);

//wyswietla liste sasiedztwa
void wyswietl_liste_sasiedztwa(list<int>*graf, int n);

//jesli wystepuja krawedzie wielokrotne to wszystkie zostana usuniete
void usun_krawedz_lista_sasiedztwa(list<int>*graf, int pocz, int konc, bool is_DG);


//************************************
// lista sasiedztwa - graf wazony
//************************************

//pair<int,int>  -> first sasiad u wierzcholka v; second - waga krawedzi v-u
list<pair<int, int>>*stworz_wazona_liste_sasiedztwa(int n);								//alokacja pamieci dla grafu wazonego w postaci listy sasiedztwa
void usun_liste_sasiedztwa(list<pair<int, int>>*graf);									//zwalnianie pamieci -||-
void wypelnij_wazona_liste_sasiedztwa_DG(list<pair<int, int>> *graf, int n, int E);		//wypelnianie grafu wazonego
void wypelnij_wazona_liste_sasiedztwa_NDG(list<pair<int, int>> *graf, int n, int E);		//wypelnianie grafu wazonego
void wyswietl_wazona_liste_sasiedztwa(list<pair<int, int>> *graf, int n);				//wyswietlanie grafu wazonego


//************************************
// lista sasiedztwa - funckje poboczne
//************************************

//przpisywanie jednego grafu do drugiego
void przepisz_liste_sasiedztwa(list<int>*cel, list<int>*zrodlo, int n);

//czysci liste sasiadow
void wyczysc_liste_sasiadow(list<int>*graf, int n);

//sortuje listy sasiadow rosnaco
void sortuj_liste_sasiedztwa(list<int>*graf, int n);

//wypisuje wierzcholki izolowane na liscie sasiedztwa
void wierzcholki_izolowane_lista_sasiedztwa(list<int>*graf, int n);

//wypisuje petle w liscie sasiedztwa
void petle_lista_sasiedztwa(list<int>*graf, int n);

//wypisuje krawedzie dwukierunkowe w liscie sasiedztwa
void krawedzie_dwukierunkowe_lista_sasiedztwa(list<int>*graf, int n);

//wypisuje stopnie w liscie sasiedztwa dla grafu NDG
void stopnie_lista_sasiedztwa_NDG(list<int>*graf, int n);

//wypisuje stopnie wychodzace w liscie sasiedztwa dla grafu DG
void stopnie_wychodzace_lista_sasiedztwa_DG(list<int>*graf, int n);

//wypisuje stopnie wchodzace w liscie sasiedztwa dla grafu DG
void stopnie_wchodzace_lista_sasiedztwa_DG(list<int>*graf, int n);

//wyswietlanie wierzcholkow, dla ktorych dany wierzcholek jest sasiadem, lista sasiedztwa
void dla_kogo_sasiadem_lista_sasiedztwa(list<int>*graf, int n);


//************************************
//************  DFS  *****************
//************************************

//funkcja ogolna, tworzy zmienne pomocnicze i wywoluje algorytm rekurencyjny. Wersja dla mecierzy sasiedztwa
void DFS_nxn(int**graf, int startowy, int n);

//algorytm rekurencyjny wywolywany w funkcji glownej DFS_nxn
void DFS_nxn_rek(int**graf, bool*visited, int startowy, int n);

//funkcja ogolna. Wersja dla listy sasiedztwa
void DFS_lista_sasiedztwa(list<int>*graf, int startowy, int n);

//algorytm rekurencyjny wywolywany w funkcji DFS_lista_sasiedztwa
void DFS_lista_sasiedztwa_rek(list<int>*graf, bool *visited, int startowy, int n);

//DFS w wersj z wykorzystaniem stosu
void DFS_stos_lista_sasiedztwa(list<int>*graf, int startowy, int n);


//************************************
//************  BFS  *****************
//************************************

//algorytm BFS dla macierzy sasiedztwa
void BFS_nxn(int **graf, int startowy, int n);

//algorytm BFS dla listy sasiedztwa
void BFS_lista_sasiedztwa(list<int>*graf, int startowy, int n);


//************************************
//****  transpozycja, kwadrat ********
//************************************

//transpozycja grafu dla macierzy sasiedztwa. Transpozycja w miejscu
void transponuj_nxn(int**graf, int n);

//transpozycja grafu dla listy sasiedztwa
void transponuj_liste_sasiedztwa(list<int>*graf, int n);

//kwadrat grafu dla macierzy sasiedztwa
void kwadrat_grafu_nxn(int**graf, int n);

//kwadrat grafu dla listy sasiedztwa
void kwadrat_grafu_lista_sasiedztwa(list<int>*graf, int n);


//************************************
//********  stopien grafu ************
//************************************

//4 wersje. Po 2 dla macierzy sasiedztwa i listy sasiedztwa oraz grafow skierowanych(DG) i nieskierowanych(NDG)
void stopien_grafu_nxn_NDG(int**graf, int n);
void stopien_grafu_lista_sasiedztwa_NDG(list<int>*graf, int n);
void stopien_grafu_nxn_DG(int**graf, int n);
void stopien_grafu_lista_sasiedztwa_DG(list<int>*graf, int n);


//************************************
//******* sciezka w grafie ***********
//************************************

//znajdowanie sciezki w grafie (niekoniecznie najkrotszej) z przejsciem DFS. Wersja dla listy sasiedztwa. Dziala dla grafow DG i NDG
void sciezka_z_przejsciem_DFS_lista_sasiedztwa_1(list<int>*graf, int startowy, int koncowy, int n);

//znajdowanie sciezki w grafie (niekoniecznie najkrotszej) z przejsciem DFS. Wersja dla macierzy sasiedztwa. Dziala dla grafow DG i NDG
void sciezka_z_przejsciem_DFS_macierz_sasiedztwa_1(int**graf, int startowy, int koncowy, int n);

//znajdowanie sciezki w grafie (niekoniecznie najkrotszej) z przejsciem DFS. Wersja dla listy sasiedztwa. Wersja rekurencjyjna oparta na stosie bez tablicy path. Dziala dla grafow DG i NDG. Wersja z lepszym wykorzystaniem pamieci.
void sciezka_z_przejsciem_DFS_lista_sasiedztwa_2(list<int>*graf, int startowy, int koncowy, int n);

//rekurencyjna funkcja DFS dla znajdywania sciezki w grafie (lista sasiedztwa)
bool DFS_sciezka_lista_sasiedztwa_rek(list<int>*graf, stack<int> *S, bool*visited, int biezacy, int koncowy);

//znajdowanie sciezki w grafie (niekoniecznie najkrotszej) z przejsciem DFS. Wersja dla macierzy sasiedztwa. Wersja rekurencjyjna oparta na stosie bez tablicy path. Dziala dla grafow DG i NDG
void sciezka_z_przejsciem_DFS_macierz_sasiedztwa_2(int**graf, int startowy, int koncowy, int n);

//rekurencyjna funkcja DFS dla znajdywania sciezki w grafie (macierz sasiedztwa)
bool DFS_sciezka_macierz_sasiedztwa_rek(int**graf, stack<int> *S, bool*visited, int biezacy, int koncowy, int n);

//najkrotsza sciezka w grafie z wykorzystaniem BFS. Wersja dla listy sasiedztwa. Dziala dla NDG i DG.
void najkrotsza_sciezka_lista_sasiedztwa(list<int>*graf, int startowy, int koncowy, int n);

//najkrotsza sciezka w grafie. Wersja dla macierzy sasiedztwa. Dziala dla NDG i DG
void najkrotsza_sciezka_macierz_sasiedztwa(int**graf, int startowy, int koncowy, int n);


//************************************
//****** drzewa rozpinajace **********
//************************************

//wyznaczanie drzewa rozpinajacego w glab dla listy sasiedztwa. czy_skierowane okresla, czy drzewo ma byc grafem skierowanym, czy nieskierowanym
void drzewo_rozpinajace_DFS_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, int startowy, int n, bool czy_skierowane);

//funkcja rekurencyjna do wyznaczania drzewa rozpinajacego dla drzewo_rozpinajace_DFS_lista_sasiedztwa
void DFS_Tree_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, bool *visited, int startowy, int n, bool czy_skierowane);

////wyznaczanie drzewa rozpinajacego w glab dla macierzy sasiedztwa. czy_skierowane okresla, czy drzewo ma byc grafem skierowanym, czy nieskierowanym
void drzewo_rozpinajace_DFS_macierz_sasiedztwa(int**graf, int**drzewo, int startowy, int n, bool czy_skierowane);

//funkcja rekurencyjna do wyznaczania drzewa rozpinajacego dla drzewo_rozpinajace_DFS_macierz_sasiedztwa
void DFS_Tree_macierz_sasiedztwa(int**graf, int**drzewo, bool *visited, int startowy, int n, bool czy_skierowane);

//wyznaczanie drzewa rozpinajacego w szerz dla listy sasiedztwa. czy_skierowane okresla, czy drzewo ma byc grafem skierowanym, czy nieskierowanym
void drzewo_rozpinajace_BFS_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, int startowy, int n, bool czy_skierowane);

//wyznaczanie drzewa rozpinajacego w szerz dla macierzy sasiedztwa. czy_skierowane okresla, czy drzewo ma byc grafem skierowanym, czy nieskierowanym
void drzewo_rozpinajace_BFS_macierz_sasiedztwa(int**graf, int**drzewo, int startowy, int n, bool czy_skierowane);


//************************************
//********* spojnosc *****************
//************************************

//badanie spojnosci grafu za pomoca DFS
bool spojnosc_lista_sasiedztwa(list<int>*graf, int startowy, int n);

//funkcja rekurencyjna DFS do badania spojnosci
void spojnosc_lista_sasiedztwa_rek(list<int>*graf, bool *visited, int startowy, int n);

//wyznaczanie skladowych spojnych w grafie. Wymaga grafu nieskierowanego
void skladowe_spojne_lista_sasiedztwa(list<int>*graf, int n);

//funkcja rekurencyjna DFS do badania skladowych spojnych
void spojne_skladowe_lista_sasiedztwa_rek(list<int>*graf, int*C, bool *visited, int startowy, int biezaca_skladowa, int n);

//znajdowanie mostow w grafie
void bridge_Tarjan_lista_sasiedztwa(list<int>*graf, int n);

//rekurencyjny odwrotny DFS dla funkcji bridge_Tarjan_lista_sasiedztwa
int DFSb_lista_sasiedztwa(list<int>*graf, int n, int v, int vf, int*D, list<pair<int, int>> *L, int &cv);		//v-wierzcholek startowy, vf-ojciec v, D-numery DFS, L-mosty(pary wierzcholek startowy i koncowy)

//znajdowanie punktow artykulacji w grafir
void punkty_artykulacji_Tarjan_lista_sasiedztwa(list<int>*graf, int n);

//rekurencyjny odwrotny DFS dla funkcji punkty_artykulacji_Tarjan_lista_sasiedztwa
int DFSap(int v, int vf, list<int>*graf, int* D, int& dv, list<int>* L);


//*************************************
//************* INNE ******************
//*************************************

//sprawdza, czy graf spojny, nieskierowany jest dwudzielny. Wersja dla listy sasiedztwa. Wykorzystuje przejscie BFS.
bool czy_dwudzielny_lista_sasiedztwa(list<int>*graf, int n);

//algorytm kojarzenia malzenstw. Wymaga tablicy bool color o rozmiarze n. False - kobieta, True - mezczyzna
void kojarzenie_malzenstw_lista_sasiedztwa(list<int>*graf, int n, bool*color);

//przygotowanie struktur danych do sorotwania topologicznego oraz wywolanie funkcji rekurencyjnej. Graf skierowany acykliczny DAG
void sortowanie_topologiczne_lista_sasiedztwa_DG(list<int>*graf, int n);

//funkcja rekurencyjna, pomocniczna dla powyzszej (wlasciwie to algorytm glowny)
bool DFS_sort_rek(list<int>*graf, int v, stack<int>*S, int*kolory);

//dodaje elementy na koniec stosu. Nie czysci stosu przed kopiowaniem
void kopiowanie_stosu_int(stack<int>*A, stack<int>*B);

//komiwojazer - brute force;   alkoacja pamieci, wywolanie funkcji glownej, rekurencyjnej
void TSP_lista_sasiedztwa(list<pair<int, int>>*graf, int n);

//algorytm glowny, rekurencja
void TSP_lista_sasiedztwa_rek(list<pair<int, int>>*graf, int n, int &v, int &v0, int &d, int &dh, stack<int>*S, stack<int>*Sh, int*visited);		//v-bierzacy, v0-startowy, d-suma wag cyklu hamiltona, dh-pomocnicza suma wag, S-stos wierzcholkow, Sh-pomocniczy stos wierzcholkow



//*************************************
//********** cyklocznosc **************
//*************************************

//sprawdzanie, czy graf spojny, nieskierowany jest cykliczny. Wersja dla macierzy sasiedztwa 
bool czy_cykliczny_lista_sasiedztwa_spojny_NDG(list<int>*graf, int n);

//sprawdzanie, czy graf niespojny, nieskierowany jest cykliczny. Wersja dla macierzy sasiedztwa
bool czy_cykliczny_lista_sasiedztwa_niespojny_NDG(list<int>*graf, int n);

//funkcja pomocniczna (wlasciwie to glowna czesc jest tutaj) do czy_cykliczny_lista_sasiedztwa_niespojny_NDG
bool czy_komponent_jest_cykliczny(list<int>*graf, int v, bool*visited);

//sprawdzanie, czy graf spojny, skierowany jest cykliczny. Wersja dla macierzy sasiedztwa 
bool czy_cykliczny_lista_sasiedztwa_spojny_DG(list<int>*graf, int n);

//funckja pomocnicza, rekurencyjna (glowna czesc algorytmu) dla czy_cykliczny_lista_sasiedztwa_spojny_DG
bool czy_graf_cykliczny_rek(list<int>*graf, int v, int*visited);

//znajdowanie cykli dla wszystkich wierzcholkow *graf nieskierowany
void cykle_lista_sasiedztwa_NDG(list<int>*graf, int n);

//pomocnicza funkcja rekurencyjna dla powyzszej
bool DFS_szukanie_cyklu_NDG_rek(list<int>*graf, int v, int w, stack<int>*S, bool*visited);

//znajdowanie cykli dla wszystkich wierzcholkow *graf skierowany
void cykle_lista_sasiedztwa_DG(list<int>*graf, int n);

//pomocnicza funkcja rekurencyjna dla powyzszej
bool DFS_szukanie_cyklu_DG_rek(list<int>*graf, int v, int w, stack<int>*S, bool*visited);


//*************************************
//********* Euler/Hamilton ************
//*************************************

//sprawdza czy graf ma sciezke albo cykl eulera i wypisuje odpowiedni komunikat
void czy_eulerowski_lista_sasiedztwa_NDG(list<int>*graf, int n);

//2 - cykl eulera, 1 - sciezka eulera, 0 - nic
int czy_eulerowski_lista_sasiedztwa_DG(list<int>*graf, int n);

//funkcja rekurencyjna, pomocnicza dla powyzszej. Przejscie dfs, sprawdzanie stopni wchodzacych i wychodzacych. zapisywanie informacji do odpowienich tablic
void DFS_czy_eulerowski_lista_sasiedztwa_DG_rek(int v, int cvn, int*VN, int*VLow, bool*VS, int*Vind, int*Voutd, int*C, stack<int>*S, list<int>*graf);

//prymitywna funkcja dzialajaca tylko, jest w grafie spojnym, nieskierowanym istnieje cykl eulera. Uzywac np. tylko wtedy, gdy funkcja czy_eulerwoski... zwroci 2
void cykl_eulera_lista_sasiedztwa_spojny_NDG(list<int>*graf, int n, int startowy);

//rekurencyjny DFS dla szukania cyklu eulera w grafie spojnym, nieskierowanym
void DFS_cykl_eulera_rek(list<int>*graf, int v, stack<int>*S);

//algorytm wypisuje wszystkie sciezki i cykle hamiltona. Zlozonosc obliczeniowa O(n!) -> dziala tylko dla nieduzych n
void cykl_lub_sciezka_hamiltona_lista_sasiedztwa(list<int>*graf, int n);

//funkcja rekurencyjna, algorytm wlasciwy szukania sciezek i cykli hamiltona
void cykl_lub_sciezka_hamiltona_lista_sasiedztwa_rek(list<int>*graf, int n, int v, bool*visited, list<int>*S);


//*************************************
//*najkrotsza sciezka w grafie wazonym*
//*************************************

//wyznacza koszty najkrotszych sciezek pomiedzy wierzcholkiem startowym, a wszystkimi pozostalymi wierzcholkami
void dijkstra_lista_sasiedztwa(list<pair<int, int>> *graf, int n, int v);			//v-wierzcholek startowy

//wyznacza koszty najkrotszych sciezek pomiedzy wierzcholkiem startowym, a wszystkimi pozostalymi wierzcholkami
//alokacja pamieci dla tablic pomocniczych; wyswietlanie wynikow
void bellman_ford_lista_sasiedztwa(list<pair<int, int>>*graf, int n, int v);

//algorytm glowny
bool bellman_ford_lista_sasiedztwa_alg(list<pair<int, int>>*graf, int n, int v, int *d, int*p); //v-startowy; d, p - n elementowe tablice

//najkrotsze sciezki pomiedzy wszystkimi parami wierzcholkow. Okropna zlozonosc O(n^3)
void floyd_warshall(list<pair<int, int>>*graf, int n);



//********************************************
//*minimalne drzewo rozpinajace - graf wazony*
//********************************************


//algorytm prima wyznaczajacy minimalne drzewo rozpinajace dla grafu wazonego
void prim_lista_sasiedztwa(list<pair<int, int>> *graf, int n);

//
void kruskal_lista_sasiedztwa(list<pair<int, int>>*graf, int n);

//podstawowe operacje na zbiorach rozlacznych reprezentowanych w postaci tablicy intow
int find_zbiory_rozlaczne(int *tab, int x);
void union_zbiory_rozlaczne(int *tab, int n, int x, int y);
void wyswietl_zbiory_rozlaczne(int *tab, int n);