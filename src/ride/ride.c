/*
ID: prstcsn1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <string.h>

int converte(char*);

int main(int argc, char* argv[]) {
  FILE* fin = fopen("ride.in", "r");
  FILE* fout = fopen("ride.out", "w");
  char group[7], comet[7];
  fscanf(fin, "%s", group);
  fscanf(fin, "%s", comet);
  if (converte(group) == converte(comet)) {
    fprintf(fout, "GO\n");
  } else {
    fprintf(fout, "STAY\n");
  }
  return 0;
}

int converte(char* s) {
  int result = 1;
  char* i = s;
  for (; *i; ++i) {
    result *= (*i - 'A' + 1);
  }
  return result % 47;
}

