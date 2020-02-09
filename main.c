#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void) {

  size_t n = 0;
  char c;
  FILE *fileHnd;

  char tmp[3];
  char out[5000];
  char *buff = "5452434531303031";
  
  int buffLen = strlen(buff);
  buffLen = buffLen%2 == 0 ? buffLen : buffLen + 1;

  for (int i = buffLen - 2; i >= 0; i = i - 2 )
  {
    sprintf (tmp, "%.*s", 2, buff + i);
    strncat (out, tmp, 2);
  }

  //printf("%s\n", out);
  

  fileHnd = fopen("test", "wb");
  if (fileHnd != NULL)
  {
    unsigned long x = strtoul(out, 0, 16);
    fwrite(&x, sizeof(x), 1, fileHnd);
  }
  fclose(fileHnd);

  fileHnd = fopen("test", "rb");
  if (fileHnd != NULL) 
  {
    while ((c = fgetc(fileHnd)) != EOF)
    {
      printf("%#02x - %c\n", c, c);
    }
  }
  
  fclose(fileHnd);
}