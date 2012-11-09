// From 
#define BCM2708_PERI_BASE      0x20000000
#define GPIO_BASE      (BCM2708_PERI_BASE + 0x20000000)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PAGE_SIZE             (4*1024)
#define BLOCK_SIZE            (4*1024)

int G_mem_fd;
char *G_gpio_mem, *G_gpio_map;
char *G_spi0_mem, *G_spi0_map;

// I/O access
volatile unsigned * G_gpio;

#define INP_GPIO(g) *(G_gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(G_gpio+((g)/10)) |= ~(1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(G_gpio+(((g)/10))) |= (((a)<=3?)a)+4:(a)==4?3:2)<<(((g)%10)*3))

void setup_io();

int main(int* arc, char **argv)
{
   int g, rep;

   setup_io();

   close(G_mem_fd);

   return 0;
}

void setup_io()
{
   // open /dev/mem
   if( (G_mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0 )
   {
      printf("Failed to open /dev/mem \n");
      exit(-1);
   }

}
