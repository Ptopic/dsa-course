#include <stdio.h>
#include <stdlib.h>

typedef struct _Element
{
    int broj;
    struct _Element* next;
} Element;

Element* dodajNaPocetak(int br, Element* lst)
{
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = lst;
    return novi;
}

Element* dodajNaKraj(int br, Element* lst) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = NULL;

    if (lst == NULL) {
        return novi;
    }

    // Prosetaj do kraja liste s tmp da ne minjamo staru listu

    Element* tmp = lst;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    // Stajemo na zadnjem el jer je tmp->next == NULL tjst next zadnjeg elementa je NULL
    // stavljanmo next zadnjeg elementa kao novi broj
    tmp->next = novi;
    return lst;
}

void print(Element* lst) {
    Element* tmp = lst;
    while (tmp != NULL) {
        printf("%d -> ", tmp->broj);
        tmp = tmp->next;
    }
    printf(" null\n");
}




/*

Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. 
Druga lista ima barem jedan element.

Funkcija na kraj prve liste prebacuje prvi element druge liste. (25 bodova)

*/

Element* funkc1(Element* lst, Element* lst2) {
    // Na kraj prve liste prebaci prvi element druge liste

    Element* prviEl = lst2;
    prviEl->next = NULL;

    printf("%d el", prviEl->broj);

    // Dosetaj do kraja prve liste

    while (lst->next != NULL) {
        lst = lst->next;
    }


    lst->next = prviEl;

    return lst;
}





/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i dva indeksa. 
Funkcija će obrisati sve elemente liste između ta dva indeksa. 
Indeksi su legalni i prvi je manji od drugog. (35 bodova)

*/


Element* funkc2(Element* lst, int donji, int gornji) {
    Element* tmp = lst;
    // Dosetamo do zeljenog indeksa
    for (int i = 1; i < donji; i++) {
        tmp = tmp->next;
    }

    int steps = gornji - donji;

    // Prebacujemo element steps puta
    for (int i = 0; i < steps; i++) {
        tmp->next = tmp->next->next;
    }
    tmp->next = tmp->next->next;


    return lst;
}


/*

Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. 
Druga lista ima barem jedan element. 
Funkcija na početak prve liste prebacuje zadnji element druge liste. (25 bodova)

*/


Element* funkc3(Element* lst, Element* lst2) {
    Element* zadnjiEl = lst2;

    // Dosetamo do zadnjeg elementa druge liste

    while (zadnjiEl->next != NULL) {
        zadnjiEl = zadnjiEl->next;
    }

    zadnjiEl->next = lst;

    return zadnjiEl;
}

/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan indeks. 
Funkcija će dodati novi element na tom indeksu sa brojem 0. 
Ako indeks nije legalan (vanka je dužine liste), funkcija ne čini ništa . (35 bodova)

*/

Element* funkc4(Element* lst, int index) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = 0;
    novi->next = NULL;
    
    // if(index > brEl(lst))
    //      return lst;

    Element* tmp = lst;
    for (int i = 1; i < index; i++) {
        tmp = tmp->next;
    }

    novi->next = tmp->next;
    tmp->next = novi;

    return lst;

}

/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj.
Funkcija će izbrojati koliko je elemenata liste veće od tog broja. (25 bodova)


*/

void funkc5(Element* lst, int br) {
    Element* tmp = lst;

    int count = 0;

    while (tmp != NULL) {
        if (tmp->broj > br) {
            count++;
        }
        tmp = tmp->next;
    }

    printf("%d elemenata je vece od tog broja", count);
}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati novi element sa tim brojem na sredinu liste (ili odmah nakon sredine ako je broj elemenata neparan). (35 bodova)

*/

int duzinaListe(Element* lst) {
    int count = 0;

    Element* tmp = lst;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }

    return count;
}

Element* funkc6(Element* lst, int br) {
    Element* novi = (Element*)malloc(sizeof(Element));

    novi->broj = br;
    novi->next = NULL;

    int brElListe = duzinaListe(lst);

    int index = brElListe / 2;
    

    // Ako je br elemenata paran
    if (brElListe % 2 == 0) {
        Element* tmp = lst;

        // Dosetamo do polovice

        for (int i = 1; i < index; i++) {
            tmp = tmp->next;
        }

        novi->next = tmp->next;
        tmp->next = novi;

        return lst;
    }
    // Ako je neparan
    else {
        index = index + 1;
        
        Element* tmp = lst;

        // Dosetamo do polovice

        for (int i = 1; i < index; i++) {
            tmp = tmp->next;
        }

        novi->next = tmp->next;
        tmp->next = novi;

        return lst;
    }
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li su svi elementi u listi različiti. 
Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

*/

int funkc7(Element* lst) {
    Element* tmp = lst;
    while (tmp != NULL) {
        Element* prev = tmp->next;

        while (prev != NULL) {

            if (prev->broj == tmp->broj) {
                return 0;
            }

            prev = prev->next;

        }

        tmp = tmp->next;
    }

    return 1;
}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati novi element sa tim brojem nakon najvećeg broja u listi. (35 bodova)

*/

int najveciEl(Element* lst) {
    Element* tmp = lst;

    int max = lst->broj;
    while (tmp != NULL) {
        if (tmp->broj > max) {
            max = tmp->broj;
        }
        tmp = tmp->next;
    }

    return max;
}

Element* funkc8(Element* lst, int br) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = NULL;

    Element* tmp = lst;

    int max = najveciEl(lst);

    printf("%d je najveci element \n", max);

    while (tmp->broj != max) {
        // Doestaj do max elementa i ostani na njemu
        tmp = tmp->next;
    }

    // AKo je nakon max elementa kraj 
    if (tmp->next == NULL) {
        novi->next = NULL;
        tmp->next = novi;
    }
    else {
        // Else dodaj normalno

        novi->next = tmp->next;

        tmp->next = novi;
    }

    return lst;

}

/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će provjeriti da li je lista sortirana uzlazno. (25 bodova)

*/


int funkc9(Element* lst) {
    Element* tmp = lst;

    while (tmp != NULL) {
        Element* n = tmp->next;

        while (n != NULL) {
            
            if (n->broj < tmp->broj) {
                return 0;
            }
            n = n->next;

        }

        tmp = tmp->next;
    }

    return 1;

    
}

/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati novi element na predzadnje mjesto ako lista nije prazna, ili na prvo mjesto ako je lista prazna. (35 bodova)

*/

Element* funkc10(Element* lst, int br) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = NULL;
    
    // Ako je lista prazna dodaj na prvo mjesto
    if (lst == NULL) {
        return novi;
    }

    // AKo nije prazna dodaj na predzadnje
    Element* tmp = lst;

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    novi->next = tmp->next;
    tmp->next = novi;

    return tmp;
}



/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. 
Funkcija će ispisati sve elemente liste veće od tog broja. (25 bodova)

*/

void funkc11(Element* lst, int br) {
    Element* tmp = lst;

    while (tmp != NULL) {
        if (tmp->broj > br) {
            printf("%d el je veci od broja \n", tmp->broj);
        }
        tmp = tmp->next;
    }
}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj i svi su različiti) i jedan dodatni broj. 
Funkcija će izbrisati element sa tim brojem. (35 bodova)

*/

Element* funkc12(Element* lst, int br) {
    if (lst->broj == br) {
        return lst;
    }

    Element* tmp = lst;

    while (tmp->next->broj != br) {
        tmp = tmp->next;
    }

    tmp->next = tmp->next->next;

    return lst;
    
    
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) 
i provjerava da li se svi elementi sa parnim brojem nalaze između dva elementa sa neparnim brojem. 
Prvi i zadnji element sadrži neparni broj, a primljena lista ima barem 3 elementa. 
Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

************************
*/

int funkc13(Element* lst) {
    // n -> p -> n
    
    Element* tmp = lst;
    Element* s = lst->next;
    Element* n = lst->next->next;

    while (tmp != NULL) {

        // Ako je s paran provjeri jesu tmp i n neparni ako nisu vrati 0

        if (s->broj % 2 == 0) {
            if (tmp->broj % 2 == 0 || n->broj % 2 == 0) {
                return 0;
            }
        }
        tmp = tmp->next;
        s = s->next;
        n = n->next;
    }

    return 1;
}



/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati novi element sa tim brojem prije najvećeg broja u listi. (35 bodova)

*/

Element* funkc14(Element* lst, int br) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = NULL;

    Element* tmp = lst;

    int max = najveciEl(lst);

    while (tmp->next->broj != max) {
        tmp = tmp->next;
    }

    novi->next = tmp->next;

    tmp->next = novi;

    return tmp;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će provjeriti da li se ijedan broj u listi ponavlja. (25 bodova)

*/

int funkc15(Element* lst) {
    Element* tmp = lst;

    while (tmp != NULL) {
        Element* n = tmp->next;

        while (n != NULL) {
            if (tmp->broj == n->broj) {
                return 1;
            }
            n = n->next;
        }

        tmp = tmp->next;
    }

    return 0;
}



/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). 
Funkcija će izbrisati prva tri elementa iz liste ili samo ispisati grešku ako lista ima manje od tri elementa. (35 bodova)


*/

Element* funkc16(Element* lst) {
    int brEl = duzinaListe(lst);

    if (brEl < 3) {
        printf("Lista ima manje od 3 elementa");
        return;
    }

    for (int i = 0; i < 3; i++) {
        lst = lst->next;
    }

    return lst;
}

/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će između svaka dva parna susjedna broja dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (25 bodova)

************************

*/

Element* funkc17(Element* lst) {
    Element* novi = (Element*)malloc(sizeof(Element));

    novi->broj = 0;
    novi->next = NULL;

    Element* tmp = lst;
    Element* n = lst->next;

    while (tmp != NULL && n != NULL) {
        
        printf("%d --- %d\n", tmp->broj, n->broj);

        
        if (tmp->broj % 2 == 0 && n->broj % 2 == 0) {
            novi->next = n;
            tmp->next = novi;

            //tmp = tmp->next;
            tmp = n;
            n = n->next;

            //n = n->next;
            //tmp->next = tmp->next->next;
        }
        else {
            tmp = tmp->next;
            n = n->next;
        }




    }

    return lst;
}   

/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija vraća pokazivač na zadnji element u listi koji je veći od dodatnog broja ili NULL ako se takav broj ne nalazi u listi. 
Kolika je složenost funkcije O()? (15 bodova)

*/

Element* funkc18(Element* lst, int br) {
    Element* tmp = lst;

    while (tmp != NULL) {
        if (br > tmp->broj) {
            return &tmp;
        }

        tmp = tmp->next;
    }
    return NULL;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će ispred svakog elementa sa parnim brojem dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova)

************************

*/

Element* funkc19(Element* lst) {
    Element* tmp = lst;
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = 0;
    novi->next = NULL;

    if (lst == NULL) {
        return novi;
    }

    while (tmp->next != NULL) {
        if (tmp->next->broj % 2 == 0) {
            novi->next = tmp->next;
            tmp->next = novi;
        }

        tmp = tmp->next;
    }

    return lst;
}

/*

Napisati funkciju koja prima listu i iz nje briše sve elemente sa negativnim brojem. 
Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (25 bodova)

*/

Element* funkc20(Element* lst) {
    Element* tmp = lst;

    while (tmp->next != NULL) {
        if (tmp->next->broj < 0) {
            tmp->next = tmp->next->next;
        }
        else {
            tmp = tmp->next;

        }
    }

    return lst;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će ispred svakog elementa dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova


************************

*/

Element* funkc21() {

}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će obrisati svaki element čiji je broj veći od broja u prethodnom elementu. Kolika je složenost funkcije O()? (35 bodova)

*/


Element* funkc22(Element* lst) {
    Element* tmp = lst;

    while (tmp->next != NULL) {
        if (tmp->next->broj > tmp->broj) {
            tmp->next = tmp->next->next;
        }
        else {
            tmp = tmp->next;

        }
    }

    return lst;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će izbrojati koliko je brojeva liste veće od prethodnog broja u listi. (25 bodova)

*/


int funkc24(Element* lst) {
    Element* tmp = lst;

    int count = 0;
    while (tmp->next != NULL) {
        if (tmp->next->broj > tmp->broj) {
            count++;
            tmp = tmp->next;
        }
        else {
            tmp = tmp->next;

        }
    }

    return count;
}

/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati novi element sa tim brojem ispred prvog broja u listi koji je veći od 100 (ako takav postoji). (35 bodova)

*/

Element* funkc25(Element* lst, int br) {
    Element* tmp = lst;

    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = br;
    novi->next = NULL;

    while (tmp->next->broj < 100) {
        tmp = tmp->next;
    }

    novi->next = tmp->next;
    tmp->next = novi;

    return lst;
}

/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će vratiti pokazivač na element sa najvećim brojem. (25 bodova)

*/

Element* funkc26(Element* lst) {
    int max = najveciEl(lst);

    Element * tmp = lst;
    Element* maxEl = tmp;


    while (tmp != NULL) {
        if (tmp->broj == max) {
            maxEl = tmp;
        }
        tmp = tmp->next;
    }

    return maxEl;
}


/*

Napisati funkciju koja prima vezanu listu sa barem tri elementa. 
Funkcija će izbrisati zadnja tri elementa iz liste. (35 bodova)

*/

Element* funkc27(Element* lst) {
    Element* tmp = lst;

    while (tmp->next->next->next->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = NULL;

    return lst;
}




/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija provjerava da li je lista sadrži sve brojeve od 1 do 5. 
Funkcija vraća 1 ako su svi brojevi u listi ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

*/

int funkc28(Element* lst) {
    int arr[5] = {1, 2, 3, 4, 5};

    int status = 0;

    for (int i = 0; i < 5; i++) {
        Element* tmp = lst;
        while (tmp != NULL) {
            printf("%d \n", tmp->broj);
            if (tmp->broj == arr[i]) {
                status = 1;
                break;
            }
            else {
                status = 0;
            }
            tmp = tmp->next;
            
        }

        if (status == 0) {
            break;
        }
        printf("%d status\n", status);
    }
    
    return status;
}

/*

Napisati funkciju koja prima dvije liste. 
Funkcija na početak prve liste dodaje kopije svih elemenata iz druge liste. 
Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

*/

Element* funkc29(Element* lst, Element* lst2) {
    Element* tmp = lst2;

    // Dodi do kraja druge i nalipi pocetak prve na kraj druge

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = lst;

    return lst2;
}


/*

Napisati funkciju koja dvije liste. 
Funkcija na kraj prve liste dodaje kopije svih elemenata iz druge liste. 
Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

*/

Element* funkc30(Element* lst, Element* lst2) {
    Element* tmp = lst;

    // Dodi do kraja prve i nalipi pocetak druge na kraj druge

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = lst2;

    return lst;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i dodatni broj. 
Funkcija će obrisati sve elemente koji imaju broj djeljiv sa dodatnim brojem. (25 bodova)

************************

*/

Element* funkc31(Element*lst, int br) {    
    
    
    if (lst->broj % br == 0) {
        lst = lst->next;
    }

    Element* tmp = lst;

    while (tmp != NULL) {
        printf("%d el \n", tmp->next->broj);
        if (tmp->next->broj % br == 0) {
            if (tmp->next == NULL) {
                tmp->next = NULL;
            }
            tmp->next = tmp->next->next;

        }

        tmp = tmp->next;

    }

    //if (tmp->broj % br == 0) {
    //    tmp->next = NULL;
    //}
    


    return lst;
}


/*

Napisati funkciju koja prima dvije vezane liste (svaki element sadrži broj). 
Funkcija prebacuje prvi element iz druge liste na kraj prve liste. 
Funkcija vraća (izmijenjenu) prvu listu.  (15 bodova)

*/

Element* funkc32(Element* lst, Element* lst2) {
    Element* prviEl = lst2;
    prviEl->next = NULL;

    Element* tmp = lst;

    // Dosetaj do kraja prve i dodaj prvi el
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = prviEl;

    return lst;
}




/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će ispred najvećeg broja u listi dodati novi element sa brojem 0.
Izmijenjena lista će se vratiti kao povratna vrijednost. (25 bodova)

*/

Element* funkc33(Element* lst) {
    Element* novi = (Element*)malloc(sizeof(Element));

    novi->broj = 0;
    novi->next = NULL;

    int maxEl = najveciEl(lst);

    if (lst->broj == maxEl) {
        novi->next = lst;
        return novi;
    }

    Element* tmp = lst;

    while (tmp->next->broj != maxEl) {
        tmp = tmp->next;
    }

    novi->next = tmp->next;
    tmp->next = novi;

    return lst;
}



/*

Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). 
Funkcija provjerava da li druga lista sadrži sve brojeve prve liste. 
Funkcija vraća 1 ako jesu ili 0 ako nisu. (15 bodova)

************************

*/

Element* funkc34() {

}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). 
Funkcija će obrisati prvi i zadnji element liste. (25 bodova)

*/

Element* funkc35(Element* lst) {
    lst = lst->next;

    Element* tmp = lst;

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = NULL;


    return lst;
}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). 
Funkcija vraća broj elemenata liste čiji su prethodni i iduću element manji od nula. 
Kolika je složenost funkcije O()? (20 bodova)


*/

int funkc36(Element* lst) {
    Element* p = lst;
    Element* i = lst->next;

    int count = 0;

    if (p->broj < 0 && i->broj < 0) {
        count++;

        p = p->next;
        i = i->next;
    }


    while (i != NULL) {
        if (p->broj < 0 && i->broj < 0) {
            count++;
        }
        p = p->next;
        i = i->next;
    }

    return count;
}



/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će između prva dva negativna susjedna broja dodati novi element sa brojem 0. (25 bodova)

*/

Element* funkc37(Element* lst) {
    Element* p = lst;
    Element* i = lst->next;

    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = 0;
    novi->next = NULL;

    if (p->broj < 0 && i->broj < 0) {
        novi->next = p->next;
        p->next = novi;

        i = i->next;
    }


    while (i != NULL) {
        if (p->broj < 0 && i->broj < 0) {
            novi->next = p->next;
            p->next = novi;
        }
        p = p->next;
        i = i->next;
    }

    return lst;


}






/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i dodatni broj B. 
Funkcija vraća -1 ako su svi brojevi u listi manji od broja B
, 1 ako su svi brojevi u listi veći od broja B ili 0 u svim drugim slučajevima. (15 bodova)

*/


int funkc38(Element* lst, int br) {
    Element* tmp = lst;

    int status = 0;

    while (tmp->next != NULL) {
        // -1 ako su svi brojevi manji od br

        // 1 ako svi brojevi veci od br
        if (tmp->next->broj < br) {
            status = -1;
        }
        if (tmp->next->broj > br) {
            status = 1;
        }
        tmp = tmp->next;
    }

    // U svim drugim slucajevima
    return status;

}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). 
Funkcija iz liste briše svaki drugi element. (20 bodova)

*/

Element* funkc39(Element* lst) {
    Element* tmp = lst;
    Element* n = lst->next;

    while (tmp != NULL && n != NULL) {
        tmp->next = n->next;

        tmp = tmp->next;

        if (tmp != NULL) {
            n = tmp->next;
        }
    }


    return lst;
}




/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). 
Funkcija će izbrisati polovicu liste (od centralnog elementa do kraja). (25 bodova)

*/

Element* funkc40(Element* lst) {
    int brEl = duzinaListe(lst);

    int polovina = brEl / 2;

    Element* tmp = lst;

    for (int i = 0; i < polovina; i++) {
        tmp = tmp->next;
    }

    tmp->next = NULL;

    return lst;

}





/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). 
Funkcija broji (i vraća) koliko je elemenata liste manje od oba susjedna elementa. (15 bodova)

*/

Element* funkc41() {

}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). 
Funkcija između svaka dva susjedna jednaka broja dodaje novi element s brojem 0.  
Kolika je složenost funkcije O()? (20 bodova)

*/

Element* funkc42() {

}


/*

Napisati funkciju koja prima listu (svaki element sadrži broj b) i broj B. 
Funkcija iz liste briše prvi element koji sadrži broj B. Kolika je složenost funkcije O()? (20 bodova)

*/

Element* funkc43() {

}


/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b) i broj B. 
Funkcija briše prvih B elemenata liste (ili cijelu listu ako ima manje elemenata). 
Funkcija vraća nastalu listu. Kolika je složenost funkcije O()? (20 bodova)

*/

Element* funkc44() {

}


/*

Napisati funkciju koja prima listu (svaki element sadrži broj b) i broj B. 
Funkcija dodaje na početak liste novi element sa brojem B ako B nije već u listi. 
Kolika je složenost funkcije O()? (20 bodova)

*/

Element* funkc45() {

}





/*

Napisati funkciju koja prima listu i novi element i vraća (izmijenjenu) listu. 
Funkcija dodaje novi element na kraj liste samo ako već ne postoji u listi.

*/

Element* funkc46() {

}

/*

Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). 
Funkcija provjerava da li su obje liste potpuno jednake. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

*/

Element* funkc47() {

}


/*

Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. 
Funkcija će dodati nove elemente sa tim brojem na početak i na kraj liste. (35 bodova)

*/

Element* funkc48() {

}





/*

Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). 
Funkcija vraća broj elemenata liste čiji su prethodni i idući element jednaki (brojevi su im jednaki). 
Kolika je složenost funkcije O()? (25 bodova)

*/

Element* funkc49() {

}


/*

Napisati funkciju koja prima listu i broj. 
Funkcija u listu dodaje novi element sa brojem 0 ispred svakog elementa sa pozitivnim brojem u listi. 
Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

*/

Element* funkc50() {

}


/*

Napisati funkciju koja prima listu. 
Funkcija iz liste izdvaja u zasebnu listu sve elemente sa pozitivnim brojevima. 
Funkcija vraća tu novu listu pozitivnih brojeva. 
Originalna lista mora i dalje biti ispravna vezana lista preostalih brojeva. 
Kolika je složenost funkcije O()? (35 bodova)

*/

Element* funkc51() {

}




void main()
{
    Element* lst = NULL;
    Element* lst2 = NULL;

    lst = dodajNaKraj(1, lst);
    lst = dodajNaKraj(2, lst);
    lst = dodajNaKraj(2, lst);
    lst = dodajNaKraj(3, lst);
    lst = dodajNaKraj(3, lst);
    lst = dodajNaKraj(4, lst);
    lst = dodajNaKraj(4, lst);
    lst = dodajNaKraj(3, lst);

    print(lst);


    lst2 = dodajNaKraj(1, lst2);
    lst2 = dodajNaKraj(2, lst2);
    lst2 = dodajNaKraj(3, lst2);
    lst2 = dodajNaKraj(4, lst2);
    lst2 = dodajNaKraj(5, lst2);

    print(lst2);

    //funkc1(lst, lst2);

    //printf("\n");
    //print(lst);


    //funkc2(lst, 2, 4);

    //printf("\n");
    //print(lst);


    //lst = funkc3(lst, lst2);
    //print(lst);


    /*funkc4(lst, 2);
    print(lst);*/

    //funkc5(lst, 2);

    //funkc6(lst, 9);
    //print(lst);

    //printf("%d rezultat", funkc7(lst));

    //funkc8(lst, 99);
    
    //int res = funkc9(lst);

    //printf("%d rezultat", res);

    //funkc10(lst, 100);
    //print(lst);

    //funkc11(lst, 3);

    //funkc12(lst, 5);
    //print(lst);

    //int res = funkc13(lst);

    //printf("%d rezultat", res);

    //funkc14(lst, 99);
    //print(lst);

    //printf("%d rezultat \n", funkc15(lst));

    //lst = funkc16(lst);
    //print(lst);

    lst = funkc17(lst);
    //print(lst);

    //funkc18(lst, 9);

    //funkc19(lst);
    //print(lst);

    //funkc20(lst);
    //print(lst);

    //funkc22(lst);
    //print(lst);

    //printf("%d brojeva vece od prethodnog", funkc24(lst));

    //funkc25(lst, 22);

    //funkc27(lst);

    //Element* maxEl = funkc26(lst);

    //printf("%d --- %d\n", maxEl->broj, maxEl);

    //printf("%d rezultat", funkc28(lst));

    //funkc29(lst, lst2);

    //funkc30(lst, lst2);

    //lst = funkc31(lst, 2);

    //funkc32(lst, lst2);

    //lst = funkc33(lst);

    //lst = funkc35(lst);


    //printf("%d br elemenata prethodnog i iduceg manjeg od 0 \n", funkc36(lst));

    //lst = funkc37(lst);

    //printf("%d \n", funkc38(lst, 9));

    //lst = funkc39(lst);

    //lst = funkc40(lst);

    print(lst);
}