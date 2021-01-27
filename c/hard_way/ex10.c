#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  
  if (argc < 2) {
    printf("Error! You need at least one argument.\n");
    return 1;
  }

  char letter;
  for (int j = 1; j < argc; j++) {
    printf("\n--- %s:\n", argv[j]);
    for (int i = 0; (letter = argv[j][i]) != '\0'; i++) {
      if (isupper(letter)) {
        letter = tolower(letter);
      }

      switch (letter) {
        case 'a':
          printf("%d: 'A'\n", i);
          break;

        case 'e':
          printf("%d: 'E'\n", i);
          break;

        case 'i':
          printf("%d: 'I'\n", i);
          break;

        case 'o':
          printf("%d: 'O'\n", i);
          break;

        case 'u':
          printf("%d: 'U'\n", i);
          break;

        case 'y':
          printf("%d: 'Y'\n", i);
          break;

        default:
          printf("%d: %c is not a vowel\n", i, letter);
      }
    }
  }

  return 0;
}

