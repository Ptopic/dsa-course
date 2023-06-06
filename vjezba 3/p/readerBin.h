typedef struct {
	Triangle* triangles;
	unsigned int numberOfTriangles;
} Objekt3D;

void printObjekt3D(Objekt3D* objekt3D);

Objekt3D* iterateThroughTriangleBinaryFile();
void writeObjekt3DToBinaryFile(Objekt3D* objekt3D);
void writeObjekt3DToTextFile(Objekt3D* objekt3D);