/*
 * qingkaifayigezishangerxiademokuaihuachengxuyongyuwanchengyixiarenwu.cpp
 *
 *  Created on: 2012-11-28
 *      Author: ??1200012791
 *      ????????????????????????????????????????????????????
 */
int m = 0, n = 0;//??2?????
int a[100], b[100], c[200];//??3?????
void read(void) {//???????????
	int i = 0;//??1?????
	cin >> m >> n;//??????????
	for (i = 0; i < m; i++)
		cin >> a[i];//???????
	for (i = 0; i < n; i++)
		cin >> b[i];//???????
}
void sort(void) {//???????????
	int i = 0, j = 0, temp = 0;//??3?????
	for (i = 1; i < m; i++)//?????
		for (j = 0; j < m - i; j++)
			if (a[j] > a[j + 1]) {//??????????
				temp = a[j];//??????
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	for (i = 1; i < n; i++)//?????
		for (j = 0; j < n - i; j++)
			if (b[j] > b[j + 1]) {//??????????
				temp = b[j];//??????
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
}
void combine(void) {//?????????????
	int i = 0;//??1?????
	for (i = 0; i < m; i++)
		c[i] = a[i];//?????????c?
	for (i = 0; i < n; i++)
		c[i + m] = b[i];//?????????c??a???
}
void output(void) {//???????????
	int i = 0;//??1?????
	cout << c[0];//??????
	for (i = 1; i < m + n; i++)
		cout << ' ' << c[i];//?????????
}
int main() {//???
	read();//??
	sort();//??
	combine();//??
	output();//??
	return 0;
}