
int provjera2(int b, int* niz, int n) {
	// c3 za inicijalizaciju i
	for (int i = 0; i < n; i++) // c4 + c5
		if (niz[i] == b)        // c1
			return 1; // c2
	return 0; // c2
}

// O(n)
// M(n) = O(n)

int provjeraR(int b, int* niz, int n) {
	if (n == 0)
		return 0;
	if (niz[0] == b)
		return 1;
	return provjeraR(b, niz + 1, n - 1);
}

void main() {

}