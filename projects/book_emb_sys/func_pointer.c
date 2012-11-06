/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Alexander Skoglund, AF Group
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the AF Group nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************/

#include <string.h>
#include <stdio.h>

 
typedef void(*functionPointerType)(void);

struct commandStruct{
	char const *name;
	functionPointerType execute;
	char const *help;
};

int add (int, int);
int subtract (int, int);
int do_math (int (*math_fn_ptr) (int, int), int, int);
int main();


void CmdVersion(void)
{
	printf("ver from func:\n");
};

void CmdTest1(void)
{
	printf("ver from test1:\n");
};

void CmdTest2(void)
{
	printf("ver from test2:\n");
};


const struct commandStruct commands[] ={
	{"add",&CmdVersion,"Print version number"},
	{"sub",&CmdTest1,"Runs test1"},
	{"do_math",&CmdTest2,"Runs test2"},
	{"",0,""}
};

int main(int argc, char* argv[])
{
	int i,j;
	void (*func)(void);

	for(i = 1; i < argc; i++)
	{
		j = 0;
		while( strlen(commands[j].name) > 0 )
		{
			if( 0 == strcmp(commands[j].name, argv[i]) )
      		{
	      		printf("%s\n",commands[j].help);
	      		func = (commands[j].execute);
	      		func();
      		}
			j++;
		}
    }
	
  	
  	return(0);

}


/*
int main()
{
  int result;

  result = do_math (add, 10, 5);
  printf ("Addition = %d.\n", result);

  result = do_math (subtract, 40, 5);
  printf ("Subtraction = %d.\n\n", result);

  return 0;
}

int add (int num1, int num2)
{
  return (num1 + num2);
}


int subtract (int num1, int num2)
{
  return (num1 - num2);
}


int do_math (int (*math_fn_ptr) (int, int), int num1, int num2)
{
  int result;

  printf ("\ndo_math here.\n");

  /* Call one of the math functions passed to us:
     either add or subtract. */
/*
  result = (*math_fn_ptr) (num1, num2);
  return result;
}

*/