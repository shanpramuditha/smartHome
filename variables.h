#ifndef DEFIN
#define DEFIN


#define IRLED 14
#define RELAY 16
#define BUZZ 5

char ssid[] = "ssh";
char pass[] = "0712418805@Shan";

unsigned long ACCODES[3][5] = {
  {0x2B, 0x5C, 0x6D}, //NEC (values have to be replaced)
  {0x2B, 0x5C, 0x6D}. //SONY
  {0x2B, 0x5C, 0x6D}, //SAMSUNG
  {0x2B, 0x5C, 0x6D}, //LG
  
};

inline bool isEqual(char a[], char b[]) {

  size_t len = strlen(b);
//  int lenA = sizeof(a) / sizeof(char);
//  int lenB = sizeof(b) / sizeof(char);
//  return (memcmp(a, b, (lenA > lenB) ? lenB : lenA) == 0);
    return (strncmp (a,b,len));
}

#endif
