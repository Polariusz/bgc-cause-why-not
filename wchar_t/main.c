#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

int is_nul_wcs(wchar_t *wcstream, int range)
{
    for(int i = 0; i < range; i++) {
	if(wcstream[i] == '\0') {
	    return 0;
	}
    }
    return 1;
}

int is_nul_mbs(char *bstream, int range)
{
    for(int i = 0; i < range; i++) {
	if(bstream[i] == '\0') {
	    return 0;
	}
    }
    return 1;
}

int main(void)
{
    setlocale(LC_ALL, ""); // sets the locale

    wchar_t *wide_text = L"Hello, €€ Money.";
    wchar_t wide_char = L'P';

    if (printf("%ls %lc\n", wide_text, wide_char) < 0) {
	printf("big f: locale is not set or something else happened. dunno\n");
    }

    printf("sizeof wchar_t is: %ld\n", sizeof(wchar_t));

    wchar_t *choco_wide = L"Dark Chocolate: 2,99€";
    char *choco_multi = "Dark Chocolate: 2,99€";

    char *choco_multi_from_wide = malloc(23);
    wcstombs(choco_multi_from_wide, choco_wide, 23);
    printf("wcstombs: %s\n", choco_multi_from_wide);

    if (is_nul_mbs(choco_multi_from_wide, 32) == 0) {
	printf("mbs: nul is there.\n");
    } else {
	printf("mbs: nul is not there.\n");
    }

    wchar_t *choco_wide_from_multi = malloc(21);
    mbstowcs(choco_wide_from_multi, choco_multi, 21);
    printf("mbstowcs: %ls\n", choco_wide_from_multi);

    if (is_nul_wcs(choco_wide_from_multi, 32) == 0) {
	printf("wcs: nul is there.\n");
    } else {
	printf("wcs: nul is not there.\n");
    }
    
    return 0;
}
