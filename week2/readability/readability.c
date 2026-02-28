#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int get_avg(char text[]) {
  int l = 0, w = 1, s = 0;
  for (int i = 0, n = strlen(text); i < n; i++) {
    if (text[i] == ' ') {
      w++;
    } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
      s++;
    } else if (isalpha(text[i])) {
      l++;
    }
  }
  return (int)round(0.0588 * l / w * 100 - 0.296 * s / w * 100 - 15.8);
}
int main() {
  char text[5000];
  printf("%s", "Text: ");
  fgets(text, sizeof(text), stdin);
  text[strcspn(text, "\n")] = '\0';
  int avg = get_avg(text);
  if (avg < 1) {
    printf("%s\n", "Before Grade 1");
  } else if (avg >= 16) {
    printf("%s\n", "Grade 16+");
  } else {
    printf("%s %d\n", "Grade", avg);
  }
  return 0;
}
