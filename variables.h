#ifndef DEFIN
#define DEFIN

char ssid[] = "ssh";
char pass[] = "0712418805@Shan";

inline bool isEqual(char a[], char b[]) {
  int lenA = sizeof(a) / sizeof(char);
  int lenB = sizeof(b) / sizeof(char);
  return (memcmp(a, b, (lenA > lenB) ? lenB : lenA) == 0);
}

#endif
