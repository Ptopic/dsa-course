
// T(n) = c -> O(1)
int provjera(int b, int* niz, int n) {
	if (niz[0] > 0)
		return 1;
	else
		return 0;
}

// T(n) = c1 + n * c2 -> O(n)
int provjera2(int b, int* niz, int n) {
	// c3 za inicijalizaciju i
	for (int i = 0; i < n; i++) // c4 + c5
		if (niz[i] == b)        // c1
			return 1; // c2
	return 0; // c2
}

// T(n) = c + c*n * (c + c*n) = c1 + c2*n + c3*n*n -> O(n^2)
// c1 + c2*n + c3*n*n  <= C*n*n
// M(n) = c
int provjera6(int* niz, int n) {
	// da li su svi brojevi u nizu jednistveni
	// c
	for (int i = 0; i < n; i++) { // c*n 
		// c
		for (int j = 0; j < n; j++) { // c*n
			if (niz[i] == niz[j] && i != j) // c
				return 0; 
		}
	}
	return 1; // c
}
// T(n) = c*n*n/2
// O(n^2) = O(f(n))
int provjera3(int* niz, int n) {
	// da li su svi brojevi u nizu jednistveni
	// c
	for (int i = 0; i < n; i++) { // c*n 
		// c
		for (int j = i+1; j < n; j++) { // c*n
			if (niz[i] == niz[j]) // c
				return 0;
		}
	}
	return 1; // c
}


// T(n) = c + n * (c + O(n) ) = O(n) * O(n) = O(n*n)

int provjera4(int* niz, int n) {
	// da li su svi brojevi u nizu jednistveni
	// c
	for (int i = 0; i < n; i++) { // c*n 
		// c
		if (provjera(niz[i], niz + i + 1, n - i)) {
				return 0;
		}
	}
	return 1; // c
}

// T(n) = -> O(logN)
int b_provjera5(int b, int* niz, int n) {
	int l = 0;
	int r = n;
	while (r <= l) {
		int c = (l + r) / 2;
		if (niz[c] > b) {
			r = c - 1;
		}
		else if (niz[c] < b) {
			l = c + 1;
		}
		else
			return 1;
	}
	return 0;
}


