#include <stdio.h>

// mystrstr() – funkcija vraća pokazivač (unutar prvog stringa) koji pokazuje na prvo pojavljivanje drugog stringa. Ako ga ne pronađe, funkcija vraća NULL
char* mystrstr(const char* haystack, const char* needle) {
    // Ako je needle prazan string, vrati haystack
    if (!*needle) {
        return (char*)haystack;
    }

    // Iteriraj kroz haystack
    for (const char* p = haystack; *p != '\0'; p++) {
        const char* p1 = p;
        const char* p2 = needle;

        // Uspoređuj znakove haystack i needle
        while (*p1 && *p2 && (*p1 == *p2)) {
            p1++;
            p2++;
        }

        // Ako smo došli do kraja needle, pronašli smo podudaranje
        if (!*p2) {
            return (char*)p;
        }
    }

    // Ako needle nije pronađen u haystack, vrati NULL
    return NULL;
}

int main() {
    char* str1 = "Hello, world!";
    char* str2 = "world";
    char* rezultat = mystrstr(str1, str2);

    if (rezultat) {
        printf("Prvo pojavljivanje: %s\n", rezultat); // Trebalo bi ispisati "world!"
    } else {
        printf("Nije pronađeno\n");
    }

    return 0;
}