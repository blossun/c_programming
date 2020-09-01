int main() {
	int sum=0, fbnc1=1, fbnc2=1, fbnc3;
	for (;;) {
		fbnc3 = fbnc1 + fbnc2;
		if (fbnc3 > 1000000) {
			break;
		}
		fbnc1 = fbnc2;
		fbnc2 = fbnc3;
		if (fbnc3 % 2 == 0) {
			sum = sum +fbnc3;
		}
	}
	printf("%d", sum);
	return 0;
}