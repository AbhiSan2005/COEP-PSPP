void insert(int a[], int len, int i){
	int t;
	t = a[i];
	while(i >= 1 && a[i - 1] > t) {
		a[i] = a[i - 1];
		i--;	
	}
	a[i] = t;
	return;
}
void inssort(int a[], int len) {
	int i;
	i = 1;
	while(i < len) {
		insert(a, len, i);
		i++;
	}
	return;
}
