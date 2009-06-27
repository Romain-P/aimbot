
#ifndef mergesort_h
#define mergesort_h


namespace Algorithms
{
	static void mergeSort(T a[], int n)
	{
		int i, j, k;
		T tmp;

		/* For small arrays, insertion sort is much faster */
		if (n < 64) {
			for (i = 1; i < n; i++) {
				tmp = a[i];
				for (j = i-1; j >= 0 && tmp < a[j]; j--) a[j+1] = a[j];
				a[j+1] = tmp;
			}
			return;
		}

		int f = n / 2;

		mergeSort(a, f);
		mergeSort(a+f, n-f);

		/* Merge */
		T *s = new T[n];

		for (i = 0, j = f, k = 0; i < f && j < n;)
			s[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

			while (i < f)
				s[k++] = a[i++];
			while (j < n)
				s[k++] = a[j++];

			for (i = 0; i < n; i++)
				a[i] = s[i];
			delete[] s;
	}

}


#endif
