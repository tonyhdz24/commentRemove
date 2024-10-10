#include <stdio.h>
#include <string.h>

void readFile(char prg[]);
void readLine(char line[]);

int main(int argc, char const *argv[]) {
  char test[100] = "./helloWorld.c";
  readFile(test);
  return 0;
}
void readLine(char line[]) {
  // Variable to keep track if scanner is in comment or not
  int inComment = 1;
  int outComment = 0;
  int state = outComment;

  int i, c;
  int lineLength = strlen(line);

  for (i = 0; i < lineLength; i++) {
    c = line[i];
    // check if scanner is at the end of a line
    // if (c == '\n') {
    //   printf("__ %d", i);
    // }

    // Check IF scanner has encountred a comment character //
    if (c == '/') {
      state = inComment;
      // printf("%c", c);
    }

    if (c != '/' && state == outComment) {
      printf("%c", c);
    }
  }
};

void readFile(char prg[]) {
  FILE *fptr;

  // open a file in read mode
  fptr = fopen(prg, "r");
  // Store the content of the file
  char prgString[100];
  // If the file exists
  if (fptr != NULL) {
    // Read content and print it
    while (fgets(prgString, 100, fptr)) {
      // Pass each line from the file into line reader
      readLine(prgString);
    }
  } else {
    printf("Not able to open the file.");
  }
  fclose(fptr);
}