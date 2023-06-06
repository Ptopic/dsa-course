#include "stdio.h"
#include "readerTxt.h"

void readTrianglesTxtFile() {

	FILE* fd = fopen("primjertxt.stl", "rt");

	Triangle triangle;

	skipLine(fd);

	while (1) {

		if ((fscanf(fd, "  facet normal %f %f %f", &triangle.normale[0], &triangle.normale[1], &triangle.normale[2])) == EOF)
			break;

		skipLine(fd);
		skipLine(fd);

		readTriangle(fd, &triangle);

		skipLine(fd);
		skipLine(fd);

		printTriangle(&triangle);

	}

	fclose(fd);

}


void readTriangle(FILE* fd, Triangle* triangle) {

	readTriangleTop(fd, triangle, 0);
	skipLine(fd);

	readTriangleTop(fd, triangle, 1);
	skipLine(fd);

	readTriangleTop(fd, triangle, 2);
	skipLine(fd);
}

void readTriangleTop(FILE* fd, Triangle* triangle, int topNumber) {
	fscanf(fd, "      vertex %f %f %f",
		&triangle->tops[topNumber].coordinates[0],
		&triangle->tops[topNumber].coordinates[1],
		&triangle->tops[topNumber].coordinates[2]);
}

void skipLine(FILE* fd) {

	char buffer[100];

	fgets(buffer, 99, fd);
	//printf("%s \n", buffer);
}

void printTriangle(Triangle* triangle) {
	printf("Triangle \n normale [%.2f, %.2f, %.2f]\n vertex1 [%.2f, %.2f, %.2f]\n vertex2 [%.2f, %.2f, %.2f]\n vertex3 [%.2f, %.2f, %.2f]\n",
		triangle->normale[0], triangle->normale[1], triangle->normale[2],
		triangle->tops[0].coordinates[0], triangle->tops[0].coordinates[1], triangle->tops[0].coordinates[2],
		triangle->tops[1].coordinates[0], triangle->tops[1].coordinates[1], triangle->tops[1].coordinates[2],
		triangle->tops[2].coordinates[0], triangle->tops[2].coordinates[1], triangle->tops[2].coordinates[2]);
	printf(" number : %d\n", triangle->number);
}



