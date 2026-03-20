#include <ctype.h>
#include <stdio.h>
#include <string.h>
char *encrypt(char text[], char *cipher_key) {
  static char encrypted_text[5000];
  for (int i = 0, n = strlen(text); i < n; i++) {
    if (isalpha(text[i])) {
      if (isupper(text[i])) {
        encrypted_text[i] = toupper(cipher_key[text[i] - 65]);
      } else {
        encrypted_text[i] = tolower(cipher_key[text[i] - 97]);
      }
    } else {
      encrypted_text[i] = text[i];
    }
  }
  return encrypted_text;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("%s%s %s\n", "Usage: ", argv[0], "KEY");
    return 1;
  }
  if (strlen(argv[1]) != 26) {
    printf("%s\n", "Key must contain 26 characters.");
    return 1;
  }
  for (int i = 0, n = strlen(argv[1]); i < n; i++) {
    if (!isalpha(argv[1][i])) {
      printf("%s\n", "Key should be all alphabets.");
      return 1;
    }
    for (int j = 0; j < i; j++) {
      if (toupper(argv[1][i]) == toupper(argv[1][j])) {
        printf("%s\n", "No duplicate values allowed.");
        return 1;
      }
    }
  }
  char *cipher_key = argv[1];
  char user_input[5000];
  printf("plaintext: ");
  fgets(user_input, 5000, stdin);
  printf("ciphertext: %s\n", encrypt(user_input, cipher_key));
  return 0;
}
