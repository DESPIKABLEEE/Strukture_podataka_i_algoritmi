2.
Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih cijelih brojeva (dužine N) broji (i ispisuje) koliko puta se pojavljuje broj b za svaki b od 1 do M. Algoritam se može napisati na dva načina:
      a)Niz nije sortiran. Linearno pretražujemo za svaki b.
      b)Sortiramo niz uzlazno. Brojanje za svaki idući broj b nastavljamo gdje je prethodno brojanje stalo. U vremensku složenost ulazi i vrijeme sortiranja.
      Izraziti složenost u terminima N i M. Koja je opcija bolja ako je M vrlo mali broj u odnosu na N? Koja je opcija bolja ako su N i M približno jednaki?


//  a) O(N) = N * M
//  b) O(N) = N * log(N) + N = N * log(N)


2.
Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih brojeva (dužine N) traži dva broja čija razlika daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
      a)Niz nije sortiran. Svaki broj u nizu pokušamo oduzeti od svakog od preostalih brojeva u nizu.
      b)Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je razlika brojeva na ta dva indeksa veća od 0, umanjujemo R. Ako je razlika manja od nula, uvećavamo L. Algoritam se prekida ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N/2 = N * log(N)


2.    Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N. Algoritam spaja ta dva niza u novi sortirani niz. Algoritam se može napisati na dva  načina:
a)    Kopiramo oba niza u novi niz i zatim sortiramo novi niz.
b)    Sortiramo svaki niz zasebno i zatim sa merge algoritmom konstruiramo novi sortirani niz.
Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi quicksort.


//  a) O(N) = N + N + 2N * log(2N) = N * log(N)
//  b) O(N) = N * log(N) + N * log(N) + 2N * log(2N) = N * log(N)

2.    Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u jednostruko vezanu listu. Broj pročitanih elemenata je N i ne koriste se nikakvi posebni pokazivači (npr. na kraj liste). Algoritam se može napisati na dva načina:
a)    Svaki novi element se dodaje na početak liste.
b)    Svaki novi element se dodaje na kraj liste.
Složenost izraziti u N.

//  a) O(N) = N + 1 = N
//  b) O(N) = N + N = N  -


2.    Procijeniti složenost O() algoritma koji računa operaciju za jedan skup i još N skupova dužine. Prvi skup je niz dužine M, a ostalih N skupova su nizovi dužine K. Algoritam iz prvog skupa ispisuje sve elemente koji se pojavljuju u ostalih N skupova. Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova.
b)    Sortiramo N nizova. Zatim prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova binarnom pretragom.
Složenost izraziti u N, M i K. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//  a) O(N) =  N * M * K
//  b) O(N) = N * log(K) + M * N * log(K) = M * N * log(K)


2.    Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Algoritam provjerava da se nijedan broj u nizu ne ponavlja. Algoritam se može napisati na tri  načina:
a)    Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u nizu.
b)    Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u ostatku niza.
c)    Sortiramo niz uzlazno. Zatim za svaki broj niza provjerimo da je različit od idućeg broja u nizu.
Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi mergesort.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * N = N^2
//  c) O(N) = N * log(N) + N = N * log(N)


2.    Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u nekakav niz. Za svaki pročitani element algoritam provjerava da li se element već nalazi u nizu. Broj pročitanih elemenata je N. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran i pri svakom čitanju se provjeravaju svi prethodno pročitani elementi.
b)    Niz se drži sortiran i pri svakom čitanju se novi element dodaje na odgovarajuće mjesto (pa je to mjesto potrebno osloboditi pomicanjem elemenata). Pri dodavanju se ujedno i provjeri da li se element pojavljuje u nizu.
Složenost izraziti u N.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N * N = N^2


2.    Procijeniti složenost O() algoritma koji računa operaciju za skup (niz) i niz brojeva, dužine N i M. Algoritam iz prvog niza ispisuje element koji se u drugom nizu pojavljuje najviše puta. Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj brojimo koliko puta se pojavljuje u drugom nizu.
b)    Sortiramo oba niza uzlazno. Zatim za svaki broj prvog niza brojim u drugom nizu koliko puta se pojavljuje bez vraćanja.
Složenost izraziti u N i M. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = N * M
//  b) O(N) = N * log(N) + M * log(M) + N + M = N * log(N) + M * log(M)

2.    Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N i M. Algoritam provjerava da se nijedan broj prvog niza ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Za svaki broj u prvom nizu, traži se njegovo pojavljivanje u drugom nizu.
b)    Sortira se prvi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu.
c)    Sortira se drugi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu pomoću binarne pretrage.
Složenost za svaki način izraziti u N i M tako da se vidi kako se došlo do konačnog izraza. Možete pretpostaviti da se za sortiranje koristi quicksort.

//  a) O(N) = N * M
//  b) O(N) = N * log(N) + N * M = N * log(N) + M  -
//  c) O(N) = M * log(M) + N * log(M) = (N + M) * log(M)


2.    Procijeniti vremensku složenost O() algoritma koji provjerava da li je prvi skupa podskup drugog i trećeg skupa (skupovi su predstavljeni kao nizovi brojeva). Dužina prvog niza je N, a preostala dva M. Algoritam se može napisati na dva načina:
a)    Za svaki broj u prvom nizu se provjerava da li postoji u drugom i trećem nizu.
b)    Quicksortom se sortiraju drugi i treći niz. Zatim se Za svaki broj u prvom nizu se provjerava da li postoji u drugom i trećem nizu pomoću binarne pretrage.
c)    Quicksortom sortiramo prvi niz, zatim za svaki broj u prvom nizu provjeravamo da li postoji u drugom i trećem nizu.
Složenost izraziti kroz dužine nizova N I M.

//  a) O(N) = N * M + N * M = N * M
//  b) O(N) = M * log(M) + M * log(M) + N * log(M) + N * log(M) = (M + N) * log(M)
//  c) O(N) = N * log(N) + N + M + N + M = N * log(N) + M  +/-


2.    Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih cijelih brojeva (dužine N) broji (i ispisuje) koliko puta se pojavljuje broj b za svaki b od 1 do M. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Linearno pretražujemo za svaki b.
b)    Sortiramo niz uzlazno. Brojanje za svaki idući broj b nastavljamo gdje je prethodno brojanje stalo. U vremensku složenost ulazi i vrijeme sortiranja.
Izraziti složenost u terminima N i M. Koja je opcija bolja ako je M vrlo mali broj u odnosu na N? Koja je opcija bolja ako su N i M približno jednaki?

//  a) O(N) = N * log(M)  - (M * N)
//  b) O(N) = N * log(N) + N * log(M) = N * (log(N) + log(M))


2.    Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih brojeva (dužine N) traži dva broja čija razlika daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Svaki broj u nizu pokušamo oduzeti od svakog od preostalih brojeva u nizu.
b)    Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je razlika brojeva na ta dva indeksa veća od 0, umanjujemo R. Ako je razlika manja od nula, uvećavamo L. Algoritam se prekida ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N = N * log(N) ####

2.    Procijeniti klasu složenosti O() algoritma koji u nizu dužine N traži dva broja čiji zbroj daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Svaki broj u nizu pokušamo zbrojiti sa svakim od preostalih brojeva u nizu.
b)    Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je zbroj brojeva na ta dva indeksa veći od 0, umanjujemo R. Ako je zbroj manji od nula, uvećavamo L. Algoritam se prekida ako je broj na indeksu L pozitivan, ako je broj na indeksu R negativan ili ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N = N * log(N)


2.    Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza dužine N i M sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//  a) O(N) = N * M
//  b) O(N) = M * log(M) + N * log(M) = (M + N) * log(M)
//  c) O(N) = N * log(N) + M * log(M) + N * M = N * log(N) + M * log(M)


2.    Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza jednake dužine N, sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//  a) O(N) = N * M
//  b) O(N) = M * log(M) + N * log(M) = (M + N) * log(M)
//  c) O(N) = N * log(N) + M * log(M) + N * M = N * log(N) + M * log(M)


2.    Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Svi brojevi su cijeli brojevi u rasponu [1, K]. Algoritam traži koji se broj pojavljuje najviše puta u nizu. Algoritam se može napisati na tri načina:
a)    Za svaki broj u nizu, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
b)    Sortiramo niz i brojimo koliko puta se pojavljuje svaki broj bez vraćanja.
c)    Za svaki broj od 1 do K, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
Složenost za svaki način izraziti u N i K. Možete pretpostaviti da se za sortiranje koristi quicksort.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N = N * log(N)
//  c) O(N) = N * K


2.    Procijeniti složenost O() algoritma koji računa operaciju za 3 skupa (3 niza brojeva) dužine N, M i K. Algoritam kreira novi skup tako da uzima sve element iz prvog skupa (dužine N) koji se su veći od svih elemenata u drugom skupu (dužine M), ali i manji od svih elemenata u trećem skupu (dužine K). Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjerimo da li postoji veći broj u drugom ili manji broj u trećem nizu.
b)    Pronađemo najveći i najmanji broj u drugom i trećem nizu. Nakon toga iz prvog niza uzmemo sve brojeve veće od najvećeg iz drugog niza i manje od najmanjeg iz trećeg niza.
c)    Sortiramo silazno drugi niz i uzlazno treći niz. Nakon toga iz prvog niza uzmemo sve brojeve veće od prvog broja drugog niza i manje od prvog broja trećeg niza.
Složenost izraziti u N, M i K. Možete pretpostaviti da će pretrage u (a) proći pola niza, a da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = N * M + N * K = (M + K) * N
//  b) O(N) = M + K + N
//  c) O(N) = M * log(M) + K * log(K) + N + 1 + 1 = M * log(M) + K * log(K) + N











2.
Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih cijelih brojeva (dužine N) broji (i ispisuje) koliko puta se pojavljuje broj b za svaki b od 1 do M. Algoritam se može napisati na dva načina:
      a)Niz nije sortiran. Linearno pretražujemo za svaki b.
      b)Sortiramo niz uzlazno. Brojanje za svaki idući broj b nastavljamo gdje je prethodno brojanje stalo. U vremensku složenost ulazi i vrijeme sortiranja.
      Izraziti složenost u terminima N i M. Koja je opcija bolja ako je M vrlo mali broj u odnosu na N? Koja je opcija bolja ako su N i M približno jednaki?


//  a) O(N) = N * M
//  b) O(N) = N * log(N) + M + N = N * log(N)


2.
Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih brojeva (dužine N) traži dva broja čija razlika daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
      a)Niz nije sortiran. Svaki broj u nizu pokušamo oduzeti od svakog od preostalih brojeva u nizu.
      b)Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je razlika brojeva na ta dva indeksa veća od 0, umanjujemo R. Ako je razlika manja od nula, uvećavamo L. Algoritam se prekida ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N/2 = N * log(N)


2.    Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N. Algoritam spaja ta dva niza u novi sortirani niz. Algoritam se može napisati na dva  načina:
a)    Kopiramo oba niza u novi niz i zatim sortiramo novi niz.
b)    Sortiramo svaki niz zasebno i zatim sa merge algoritmom konstruiramo novi sortirani niz.
Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi quicksort.


//  a) O(N) = N + N + 2N * log(2N) = N * log(N)
//  b) O(N) = N * log(N) + N * log(N) + 2N * log(2N) = N * log(N)

2.    Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u jednostruko vezanu listu. Broj pročitanih elemenata je N i ne koriste se nikakvi posebni pokazivači (npr. na kraj liste). Algoritam se može napisati na dva načina:
a)    Svaki novi element se dodaje na početak liste.
b)    Svaki novi element se dodaje na kraj liste.
Složenost izraziti u N.

//  a) O(N) = N + 1 = N
//  b) O(N) = N + N = N


2.    Procijeniti složenost O() algoritma koji računa operaciju za jedan skup i još N skupova dužine. Prvi skup je niz dužine M, a ostalih N skupova su nizovi dužine K. Algoritam iz prvog skupa ispisuje sve elemente koji se pojavljuju u ostalih N skupova. Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova.
b)    Sortiramo N nizova. Zatim prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova binarnom pretragom.
Složenost izraziti u N, M i K. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = M * N * K
//  b) O(N) = N * log(K) + M * N * log(K) = M * N * log(K)


2.    Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Algoritam provjerava da se nijedan broj u nizu ne ponavlja. Algoritam se može napisati na tri  načina:
a)    Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u nizu.
b)    Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u ostatku niza.
c)    Sortiramo niz uzlazno. Zatim za svaki broj niza provjerimo da je različit od idućeg broja u nizu.
Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi mergesort.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * N = N^2
//  c) O(N) = N * log(N) + N = N * log(N)


2.    Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u nekakav niz. Za svaki pročitani element algoritam provjerava da li se element već nalazi u nizu. Broj pročitanih elemenata je N. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran i pri svakom čitanju se provjeravaju svi prethodno pročitani elementi.
b)    Niz se drži sortiran i pri svakom čitanju se novi element dodaje na odgovarajuće mjesto (pa je to mjesto potrebno osloboditi pomicanjem elemenata). Pri dodavanju se ujedno i provjeri da li se element pojavljuje u nizu.
Složenost izraziti u N.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N = N * log(N)


2.    Procijeniti složenost O() algoritma koji računa operaciju za skup (niz) i niz brojeva, dužine N i M. Algoritam iz prvog niza ispisuje element koji se u drugom nizu pojavljuje najviše puta. Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj brojimo koliko puta se pojavljuje u drugom nizu.
b)    Sortiramo oba niza uzlazno. Zatim za svaki broj prvog niza brojim u drugom nizu koliko puta se pojavljuje bez vraćanja.
Složenost izraziti u N i M. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = N * M
//  b) O(N) = N * log(N) + M * log(M) + N * M = N * M

2.    Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N i M. Algoritam provjerava da se nijedan broj prvog niza ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Za svaki broj u prvom nizu, traži se njegovo pojavljivanje u drugom nizu.
b)    Sortira se prvi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu.
c)    Sortira se drugi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu pomoću binarne pretrage.
Složenost za svaki način izraziti u N i M tako da se vidi kako se došlo do konačnog izraza. Možete pretpostaviti da se za sortiranje koristi quicksort.

//  a) O(N) = N * M
//  b) O(N) = N * log(N) + N * M = N * (log(N) + M)
//  c) O(N) = M * log(M) + N * log(M) = (N + M) * log(M)


2.    Procijeniti vremensku složenost O() algoritma koji provjerava da li je prvi skupa podskup drugog i trećeg skupa (skupovi su predstavljeni kao nizovi brojeva). Dužina prvog niza je N, a preostala dva M. Algoritam se može napisati na dva načina:
a)    Za svaki broj u prvom nizu se provjerava da li postoji u drugom i trećem nizu.
b)    Quicksortom se sortiraju drugi i treći niz. Zatim se Za svaki broj u prvom nizu se provjerava da li postoji u drugom i trećem nizu pomoću binarne pretrage.
c)    Quicksortom sortiramo prvi niz, zatim za svaki broj u prvom nizu provjeravamo da li postoji u drugom i trećem nizu.
Složenost izraziti kroz dužine nizova N I M.

//  a) O(N) = N * 2M = N * M
//  b) O(N) = 2M * log(2M) + N * log(2M) = (N + M) * log(M)
//  c) O(N) = N * log(N) + N * 2M = (M + log(N)) * N


2.    Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih cijelih brojeva (dužine N) broji (i ispisuje) koliko puta se pojavljuje broj b za svaki b od 1 do M. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Linearno pretražujemo za svaki b.
b)    Sortiramo niz uzlazno. Brojanje za svaki idući broj b nastavljamo gdje je prethodno brojanje stalo. U vremensku složenost ulazi i vrijeme sortiranja.
Izraziti složenost u terminima N i M. Koja je opcija bolja ako je M vrlo mali broj u odnosu na N? Koja je opcija bolja ako su N i M približno jednaki?

//  a) O(N) = N * M
//  b) O(N) = N * log(N) + N = N * log(N)


2.    Procijeniti klasu složenosti O() algoritma koji u nizu pozitivnih brojeva (dužine N) traži dva broja čija razlika daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Svaki broj u nizu pokušamo oduzeti od svakog od preostalih brojeva u nizu.
b)    Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je razlika brojeva na ta dva indeksa veća od 0, umanjujemo R. Ako je razlika manja od nula, uvećavamo L. Algoritam se prekida ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N/2 = N * log(N)

2.    Procijeniti klasu složenosti O() algoritma koji u nizu dužine N traži dva broja čiji zbroj daje 0. Algoritam samo vraća True ili False ovisno o tome da li postoje takva dva broja u nizu. Algoritam se može napisati na dva načina:
a)    Niz nije sortiran. Svaki broj u nizu pokušamo zbrojiti sa svakim od preostalih brojeva u nizu.
b)    Niz je sortiran. Postavimo dva indeksa na početak i kraj niza (L i R). Ako je zbroj brojeva na ta dva indeksa veći od 0, umanjujemo R. Ako je zbroj manji od nula, uvećavamo L. Algoritam se prekida ako je broj na indeksu L pozitivan, ako je broj na indeksu R negativan ili ako L i R postanu jednaki.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N/2 = N * log(N)


2.    Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza dužine N i M sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//  a) O(N) = N * M
//  b) O(N) = M * log(M) + N * log(M) = log(M) * (N + M)
//  c) O(N) = N * log(N) + M * log(M) + N * M = N * log(N) + M * log(M)


2.    Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza jednake dužine N, sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N * log(N) = N * log(N)
//  c) O(N) = N * log(N) + N * log(N) + N * N = N^2


2.    Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Svi brojevi su cijeli brojevi u rasponu [1, K]. Algoritam traži koji se broj pojavljuje najviše puta u nizu. Algoritam se može napisati na tri načina:
a)    Za svaki broj u nizu, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
b)    Sortiramo niz i brojimo koliko puta se pojavljuje svaki broj bez vraćanja.
c)    Za svaki broj od 1 do K, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
Složenost za svaki način izraziti u N i K. Možete pretpostaviti da se za sortiranje koristi quicksort.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N = N * log(N)
//  c) O(N) = N * K


2.    Procijeniti složenost O() algoritma koji računa operaciju za 3 skupa (3 niza brojeva) dužine N, M i K. Algoritam kreira novi skup tako da uzima sve element iz prvog skupa (dužine N) koji se su veći od svih elemenata u drugom skupu (dužine M), ali i manji od svih elemenata u trećem skupu (dužine K). Algoritam se može napisati na dva načina:
a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjerimo da li postoji veći broj u drugom ili manji broj u trećem nizu.
b)    Pronađemo najveći i najmanji broj u drugom i trećem nizu. Nakon toga iz prvog niza uzmemo sve brojeve veće od najvećeg iz drugog niza i manje od najmanjeg iz trećeg niza.
c)    Sortiramo silazno drugi niz i uzlazno treći niz. Nakon toga iz prvog niza uzmemo sve brojeve veće od prvog broja drugog niza i manje od prvog broja trećeg niza.
Složenost izraziti u N, M i K. Možete pretpostaviti da će pretrage u (a) proći pola niza, a da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = N * M + N * K = NM + NK
//  b) O(N) = M + K + N = N + M + K
//  c) O(N) = M * log(M) + K * log(K) + N + M + K = M * log(M) + K * log(K) + N




