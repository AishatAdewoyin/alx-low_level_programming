#include"main.h"


/**
*print_alphabet_x10-prints10timesthealphabet,inlowercase,
*followedbyanewline
*/
voidprint_alphabet_x10(void)
{
charch;
inti;


i=0;


while(i<10)
{
ch='a';
while(ch<='z')
{
_putchar(ch);
ch++;
}
_putchar('\n');
i++;
}
}
