void print_subjects(subjects sub[], int no_of_records) {
	int i = 0;
	while (i < no_of_records) {
		printf("%s ", sub[i].subject_name);
		printf("%d ", sub[i].no_of_credits);
		printf("%d\n", sub[i].semester);
		i++;
	}	
	return;
}

void print_grades(grades grd[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%f ", grd[i].lower[j]);
		}
		printf("\n");
	}
	return;
}

void print_marks(marks mrk[], int no_of_students, int no_of_subjects) {
	for (int i = 0; i < no_of_students; i++) {
		printf("%ld ", mrk[i].mis);
		for (int j = 0; j < no_of_subjects; j++) {
			printf("%lf ", mrk[i].mark[j]);
		}
		printf("\n");
	}
	return;
}