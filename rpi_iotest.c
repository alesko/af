// From 
#define BCM2708_PERI_BASE      0x20000000
#define GPIO_BASE      (BCM2708_PERI_BASE + 0x200000) /* GPIO controller */

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

#define GPIO_SET *(G_gpio+7)
#define GPIO_CLR *(G_gpio+10)

void setup_io();

int main(int* arc, char **argv)
{
   int g, rep;

   setup_io();

   // Set GPIO pins 7 - 11 to output
   for( g = 7; g <= 11; g++)
   {
      INP_GPIO(g);
      OUT_GPIO(g);
   }

   for(rep = 0; rep < 10; rep++)
   {
      for(g = 7; g <= 11; g++)
      {
         GPIO_SET = 1 <<g;
         sleep(1);
      }
      for(g = 7; g <= 11; g++)
      {
         GPIO_CLR = 1 <<g;
         sleep(1);
      }
   }

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

   // Allocate MAP block
   if( (G_gpio_mem = malloc(BLOCK_SIZE + (PAGE_SIZE-1))) == NULL )
   {
      printf("Allocation error\n");
      exit(-1);
   }

   // Make sure pointer is on 4k boundray
   if( (unsigned long)G_gpio_mem % PAGE_SIZE)
      G_gpio_mem += PAGE_SIZE - ( (unsigned long)G_gpio_mem % PAGE_SIZE);

   G_gpio_map = (unsigned char*)mmap((caddr_t)G_gpio_mem,
                                     BLOCK_SIZE,
                                     PROT_READ|PROT_WRITE,
                                     MAP_SHARED|MAP_FIXED,
                                     G_mem_fd,
                                     GPIO_BASE);

   if( (long)G_gpio_map < 0)
   {
      printf("mmap error %d\n", (int)G_gpio_map);
      exit(-1);
   }

   G_gpio = (volatile unsigned *)G_gpio_map;

}
