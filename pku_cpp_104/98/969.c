/*
 * paiban.cpp
 *?????
 *  Created on: 2012-12-14
 *      Author: ??
 */


int main() {
	char *p;//??????
	p = (char*)malloc(100*4);
	int chang = 0, n, len;//????????n,????
	cin >> n;//??n
	cin >> p;
	cout << p;//??????????
	chang = strlen(p);//???????????
	n--;//????
	while (n > 0) {
		cin >> p;
		len = strlen(p);//???????
		chang += len + 1;//???????
		if (chang > 80) {
			cout << '\n' << p;
			chang = len;//??????????????????
		} else
			cout << ' ' << p;//????????????
		n--;//?????
	}
	return 0;
}
