#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

int B[1000005];

void process(char s[]){
	int j = -1, i = 0, m = strlen(s);
	B[0] = -1;
	while(i < m){
		while(j >= 0 && s[i] != s[j]) j = B[j];
		j++;
		i++;
		B[i] = j;
	}
}

int kmp(char s[], char t[]){
	int j = -1, i = 0, n = strlen(t), m = strlen(s);
	while(i < n){
		while(j >= 0 && t[i] != s[j]) j = B[j];
		i++;
		j++;
		if(j == m) return i-j;
	}
	return -1;
}

int main(){
	int i,j;
	char s[1000005], t[2000005];

	while(scanf(" %s",s), s[0] != '.'){
		strcpy(t,s);

		for(j = strlen(t), i = 0; s[i]; i++, j++)
			t[j] = s[i];
		t[j] = '\0';

		process(s);
		int ans = kmp(s,t);
		printf("%d\n", strlen(s)/ans);
	}

	return 0;
}