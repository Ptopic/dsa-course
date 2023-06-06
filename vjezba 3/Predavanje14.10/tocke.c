
#include "tocke.h"

int globalna_varijabla;

Tocka zbroji(Tocka a, Tocka b) {
	Tocka c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}