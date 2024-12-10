#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#include "dictionary_new.h"

int readWord(FILE *fd, char *buffer)
{
	int c;
	
	do {
		c = fgetc(fd);
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

int main()
{
	FILE *fd;
	char buffer[1024];
	Dictionary dict;
				
	fd = fopen("liar1.txt", "rt");
	if(fd == NULL){
		printf("Error opening file.\n");
		return 1;
	}

	dict = create();
	while(readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		add(dict, buffer); //&
	}

	fclose(fd);

	print(dict);
    
    printf("\n\n\n\n");
    
    
//    char* rjesenje = find_longest_word(dict);
//    printf("Najduza rijec je : %s\n",rjesenje);
////    
//    int broj = number_of_strings_in_dict(dict);
//    printf("Broj stringova je : %d\n",broj);
    
//    add_on_start(dict);
    
//    add_on_end(dict);
    
//    add_before_index(dict, 3);
    
//    add_before_element(dict, "his");
    
//    remove_from_start(dict);
    
//    remove_from_enndd(dict);
    
//    remove_specific_word(dict, "his");
    
//    Dictionary okrenuta = reverse_dict(dict);
    
    printf("\n\n");

    //Dictionary novi =
//    filterDictionary(dict, filter);
    
//    remove_all_above_10chars(dict);
    
//    remove_last_3_elements(dict);
    
//    add_elements_in_lst(dict);
    
//    replace_element_in_lst(dict, 2, 5);
    
//    Dictionary novi = add_to_another_lst_longer_words(dict, 5);
    
    swap_two_elementsss(dict, 2, 6);
    
    print(dict);
    
    destroy(dict);
    return 0;
}

