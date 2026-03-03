#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *cipher(char *text, int key) {
  while (key > 26) {
    key -= 26;
  }
  int text_len = strlen(text);
  static char cipher_text[5000];
  for (int i = 0; i < text_len; i++) {
    if (isalpha(text[i])) {
      if (isupper(text[i])) {
        if ((text[i] + key) > 90) {
          cipher_text[i] = (text[i] + key) - 26;
        } else {
          cipher_text[i] = text[i] + key;
        }
      } else {
        if ((text[i] + key) > 122) {
          cipher_text[i] = (text[i] + key) - 26;
        } else {
          cipher_text[i] = text[i] + key;
        }
      }
    } else {
      cipher_text[i] = text[i];
    }
  }
  return cipher_text;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("%s", "Usage: ./caesar key");
    return 1;
  }
  int key_len = strlen(argv[1]);
  for (int i = 0; i < key_len; i++) {
    if (!isdigit(argv[1][i])) {
      printf("%s", "Usage: ./caesar key");
      return 1;
    }
  }
  char plaintext[5000];
  int key = atoi(argv[1]);
  printf("%s", "plaintext:  ");
  fgets(plaintext, sizeof(plaintext), stdin);
  plaintext[strcspn(plaintext, "\n")] = '\0';
  printf("ciphertext: %s\n", cipher(plaintext, key));
  return 0;
};
