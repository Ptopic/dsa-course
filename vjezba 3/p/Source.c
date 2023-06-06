#include "stdio.h"
#include "readerTxt.h"
#include "readerBin.h"
#include <stdlib.h>



void main() {


	Objekt3D* objekt3D = iterateThroughTriangleBinaryFile();

	writeObjekt3DToBinaryFile(objekt3D);
	writeObjekt3DToTextFile(objekt3D);

	int aaa = 0;

	scanf("%d", &aaa);


}

