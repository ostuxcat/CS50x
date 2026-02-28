#include <ctype.h>
#include <stdio.h>
#include <string.h>
int scrabble(char p1[], char p2[]) {
  int p1_score = 0, p2_score = 0;
  const int point_table[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int p1len = strlen(p1);
  int p2len = strlen(p2);
  for (int i = 0; i < p1len; i++) {
    char p1lower = tolower(p1[i]);
    p1_score += point_table[p1lower - 97];
  }
  for (int i = 0; i < p2len; i++) {
    char p2lower = tolower(p2[i]);
    p2_score += point_table[p2lower - 97];
  }
  if (p1_score > p2_score) {
    printf("%s\n", "Player 1 wins!");
  } else if (p1_score < p2_score) {
    printf("%s\n", "Player 2 wins!");
  } else {
    printf("%s\n", "Tie!");
  }
  return 0;
}
int main(void) {
  char p1[30], p2[30];
  printf("%s", "Player 1: ");
  scanf("%s", p1);
  printf("%s", "Player 2: ");
  scanf("%s", p2);
  scrabble(p1, p2);
  return 0;
}
