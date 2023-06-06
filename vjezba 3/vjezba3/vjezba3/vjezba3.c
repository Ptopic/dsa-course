#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Potrebno je definirati strukturu Trokut koja će predstavljati jedan trokut sa normalom i sa dodatnim unsigned short brojem(boja trokuta), 
//ukupno 50 byte - ova.



typedef struct {
	float coordinates[3];
} Vrh;

typedef struct {
	float normale[3];
	Vrh vrhovi[3];
	unsigned short broj;
} Trokut;

// Definirati dodatnu strukturu Objekt3D koja će sadržati 
// niz trokuta i njihov broj.

typedef struct {
	Trokut* trokuti;
	unsigned int brojTrokuta;
}Objekt3D;

// ---------- Funkcije ----------

// Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D  strukturu




// Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku




// Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku




// Funkciju koja briše Objekt3D strukturu


Objekt3D* readBin() {
	FILE* fd = fopen("primjerbin.stl", "rb");

	int brojTrokuta;
	fseek(fd, 80, SEEK_SET);
	fread(&brojTrokuta, sizeof(unsigned int), 1, fd);
	printf("broj trokuta %d \n", brojTrokuta);

	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	objekt->brojTrokuta = brojTrokuta;
	Trokut t;
	objekt->trokuti = (Trokut*)malloc(sizeof(Trokut) * brojTrokuta);

	int indexTrokuta = 0;

	while (indexTrokuta < brojTrokuta) {
		fread(&t, 50, 1, fd);
		objekt->trokuti[indexTrokuta] = t;
		indexTrokuta++;
	}

	fclose(fd);
	return objekt;
}


Objekt3D writeBin(Objekt3D* objekt) {
	FILE* fd = fopen("test.stl", "wb");

	char start[80] = { 0 };

	fwrite(&start, 80, 1, fd);

	fwrite(&objekt->brojTrokuta, sizeof(int), 1, fd);

	for (int i = 0; i < objekt->brojTrokuta; i++) {
		fwrite(&objekt->trokuti[i], 50, 1, fd);
	}

	fclose(fd);
}

Objekt3D writeText(Objekt3D* objekt) {
	FILE* fd = fopen("testtext.stl", "w");

	char* start = "solid OpenSCAD_Model\n";

	fprintf(fd, "%s", start);

	for (int i = 0; i < objekt->brojTrokuta; ++i) {

		//fprintf(fd, "  facet normal %f %f %f\n",
		//	//->triangles[i].normale[0],
		//	//->triangles[i].normale[1],
		//	//->triangles[i].normale[2]);
			

		fprintf(fd, "    outer loop\n");

		//for (int topNumber = 0; topNumber < 3; ++topNumber) {
		//	fprintf(fd, "      vertex %f %f %f\n",
		//		//->triangles[i].tops[topNumber].coordinates[0],
		//		//->triangles[i].tops[topNumber].coordinates[1],
		//		//->triangles[i].tops[topNumber].coordinates[2]);
		//		
		//}

		fprintf(fd, "    endloop\n");
		fprintf(fd, "  endfacet\n");
	}

	char* end = "endsolid OpenSCAD_Model\n";

	fprintf(fd, "%s", end);

	fclose(fd);
}

int main() {
	Objekt3D* objekt = readBin();

	writeBin(objekt);
	writeText(objekt);
	return 0;
}