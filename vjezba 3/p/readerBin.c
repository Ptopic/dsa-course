	#include "stdio.h"
#include "readerTxt.h"
#include "readerBin.h"
#include <stdlib.h>

Objekt3D* iterateThroughTriangleBinaryFile() {

	FILE* fd = fopen("primjerbin.stl", "rb");

	int numberOfTriangles = 0;

	fseek(fd, 80, SEEK_SET);
	fread(&numberOfTriangles, sizeof(int), 1, fd);

	Objekt3D* objekt3D = (Objekt3D*) malloc(sizeof(Objekt3D));
	objekt3D->numberOfTriangles = numberOfTriangles;

	Triangle triangle;

	int tempTriangle = 0;

	objekt3D->triangles = (Triangle*)malloc(numberOfTriangles * sizeof(Triangle));

	while (tempTriangle < numberOfTriangles) {

		fread(&triangle , 50, 1, fd);

		objekt3D->triangles[tempTriangle] = triangle;

		++tempTriangle;

	}

	return objekt3D;
}

void writeObjekt3DToBinaryFile(Objekt3D* objekt3D) {
	FILE* fd = fopen("pisanjeUBinarnu.stl", "wb");

	char start[80] = { 0 };

	fwrite(&start, 80, 1, fd);

	fwrite(&objekt3D->numberOfTriangles, sizeof(int), 1, fd);

	for (int i = 0; i < objekt3D->numberOfTriangles; ++i) 
		fwrite(&objekt3D->triangles[i], 50, 1, fd);
	

	fclose(fd);

}

void writeObjekt3DToTextFile(Objekt3D* objekt3D) {
	FILE* fd = fopen("pisanjeUTextFile.stl", "w");

	char* start = "solid OpenSCAD_Model\n";

	fprintf(fd, "%s", start);

	for (int i = 0; i < objekt3D->numberOfTriangles; ++i) {

		fprintf(fd, "  facet normal %f %f %f\n", 
			objekt3D->triangles[i].normale[0],
			objekt3D->triangles[i].normale[1],
			objekt3D->triangles[i].normale[2]);

		fprintf(fd, "    outer loop\n");

		for (int topNumber = 0; topNumber < 3; ++topNumber) {
			fprintf(fd, "      vertex %f %f %f\n",
				objekt3D->triangles[i].tops[topNumber].coordinates[0],
				objekt3D->triangles[i].tops[topNumber].coordinates[1],
				objekt3D->triangles[i].tops[topNumber].coordinates[2]);
		}

		fprintf(fd, "    endloop\n");
		fprintf(fd, "  endfacet\n");
	}

	char* end = "endsolid OpenSCAD_Model\n";

	fprintf(fd, "%s", end);

	fclose(fd);

}

void printObjekt3D(Objekt3D* objekt3D) {
	for (int i = 0; i < objekt3D->numberOfTriangles; ++i)
		printTriangle(&objekt3D->triangles[i]);
}