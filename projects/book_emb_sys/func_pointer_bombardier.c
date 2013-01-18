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


void cmdver(void)
{
	printf("ver from func:\n");
};

void balpos(void)
{
	printf("From balpos\n");
};

void boardpos(void)
{
	printf("From boardpos\n");
};

void progbalise(void)
{
	printf("From progbalise\n");
};

void progleudata(void)
{
	printf("From progleudata\n");
};


void progcpudata(void)
{
	printf("From progcpudata\n");
};


void readbalise(void)
{
	printf("From readbalise\n");
};

void readleudata(void)
{
	printf("From readleudata\n");
};


void readcpudata(void)
{
	printf("From readcpudata\n");
};


void readmultbalise(void)
{
	printf("From readmultbalise\n");
};

void resetbalise(void)
{
	printf("From resetbalise\n");
};

void resetleudata(void)
{
	printf("From resetleudata\n");
};

void viewlogdata(void)
{
	printf("From viewlogdata\n");
};

void delbgfile(void)
{
	printf("From delbgfile\n");
};

void biterrcnt(void)
{
	printf("From biterrcnt\n");
};

void cmpbalise(void)
{
	printf("From cmpbalise\n");
};

void cmpleudata(void)
{
	printf("From cmpleudata\n");
};




/*---------------------------------------------------------------------------*/
const struct commandStruct commands[] ={
	{"ver"               ,&cmdver,        "Print version number"},
	{"baliseposition"    ,&balpos,        "Enter balise position"},
	{"boardposition"     ,&boardpos,      "Enter board position"},
	{"progbalisetgm"     ,&progbalise,    "Program balise telegram"},
	{"progleudata"       ,&progleudata,   "Program LEU data"},
	{"progcpudata"       ,&progcpudata,  "Program CPU data"},	
	{"readbalisetgm"     ,&readbalise,    "Read balise telegram"},
	{"readleudata"       ,&readleudata,   "Read LEU data"},
	{"readcpudata"       ,&readcpudata,   "Read CPU data"},
	{"readmultbalisetgm" ,&readmultbalise,"Read multiple balise telegram"},
	{"resetbalise"       ,&resetbalise,   "Reset balise"},
	{"resetleudata"      ,&resetleudata,  "Reset LEU"},	
	{"viewlogdata"       ,&viewlogdata,   "View Log Data"},
	{"delbgfile"         ,&delbgfile,     "Delete BG file"},
	{"biterrcnt"         ,&biterrcnt,     "Bit Error Rate Count"},
	{"cmpbalise"         ,&cmpbalise,     "Compare balise"},
	{"cmpleudata"        ,&cmpleudata,    "Compare LEU data"},
	{"",0,""}
};
/*_--------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	int i,j;
	void (*func)(void);

	for(i = 1; i < argc; i++){
		j = 0;
		while( strlen(commands[j].name) > 0 ){
			if( 0 == strcmp(commands[j].name, argv[i]) ){
			        printf("%s\n",commands[j].help);
	      		        func = (commands[j].execute);
	      		        func();
			}
			j++;
		}
        }	
  	return(0);

}
