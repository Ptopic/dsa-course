
#ifndef TOCKE_H
#define TOCKE_H

#define MAXLEN 20

extern int globalna_varijabla;

typedef struct {
	int x;
	int y;
	char boja;
} Tocka;

Tocka zbroji(Tocka a, Tocka b);

#endif