#ifndef DICTIONARY_NEW_H
#define DICTIONARY_NEW_H

typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; 
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// bri�e cijeli rje�nik
void destroy(Dictionary dict);

void filterDictionary(Dictionary indict, int (*filter)(Word *w));

int filter(Word *w);




char* find_longest_word(Dictionary dict);

int number_of_strings_in_dict(Dictionary dict);

void add_on_start(Dictionary dict);

void add_on_end(Dictionary dict);

void add_before_index(Dictionary dict, int index);

void add_before_element(Dictionary dict, char* string);

void remove_from_start(Dictionary dict);

void remove_from_enndd(Dictionary dict);

void remove_specific_word(Dictionary dict, char* string);

Dictionary reverse_dict(Dictionary dict);

void remove_all_above_10chars(Dictionary dict);

void remove_last_3_elements(Dictionary dict);

void add_elements_in_lst(Dictionary dict);

void replace_element_in_lst(Dictionary dict, int start, int end);

Dictionary add_to_another_lst_longer_words(Dictionary dict, int length);

void swap_two_elementsss(Dictionary dict, int first, int second);
#endif // DICTIONARY_NEW_H
