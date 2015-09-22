#ifndef IO_H
#define IO_H

/* READ BYTE - SHORT - LONG FROM I/O PORT */

unsigned char inportb(unsigned short port);
unsigned short inports(unsigned short port);
unsigned int inportl(unsigned short port);

/* WRITE BYTE - SHORT - LONG FROM I/O PORT */

void outportb(unsigned short port, unsigned char data);
void outports(unsigned short port, unsigned short data);
void outportl(unsigned short port, unsigned int data);


#endif // IO_H
