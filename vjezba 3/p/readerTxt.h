typedef struct {
	float coordinates[3];
} TriangleTop;

typedef struct {
	float normale[3];
	TriangleTop tops[3];
	unsigned short number;
} Triangle;

void readTrianglesTxtFile();

void readTriangle(FILE* fd, Triangle* triangle);

void readTriangleTop(FILE* fd, Triangle* triangle, int topNumber);

void printTriangle(Triangle* triangle);

void skipLine(FILE* fd);
