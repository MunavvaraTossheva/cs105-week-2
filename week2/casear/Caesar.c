#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(const char text[]);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
 if (argc != 2 || !only_digits(argv[1]))
 {
 printf("Usage: ./caesar key\n");
 return 1;
 }

 int key = atoi(argv[1]);

 char plaintext[255];

 printf("plaintext: ");
 scanf(" %254[^\n]", plaintext);
 printf("ciphertext: ");
 for (int i = 0; plaintext[i] != '\0'; i++)
 {
 printf("%c", rotate(plaintext[i], key));
 }

 printf("\n");

 return 0;
}

int only_digits(const char text[])
{
 if (text[0] == '\0')
 {
 return 0;
 }

 for (int i = 0; text[i] != '\0'; i++)
 {
 if (!isdigit(text[i]))
 {
 return 0;
 }
 }

 return 1;
}

char rotate(char c, int key)
{
 if (isupper(c))
 {
 return (c - 'A' + key) % 26 + 'A';
 }

 if (islower(c))
  {
 return (c - 'a' + key) % 26 + 'a';
 }

 return c;
}