#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>

#define MAXN 120
//char *s =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"
const char *s = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
int main() {
	int i, len, is_mirrored, is_palindrome;
	char t, str[MAXN], temp[MAXN];
	
	//freopen("test.in", "r", stdin);
	
	while(scanf("%s", str) != EOF) {
		is_mirrored = is_palindrome = 0;
		len  = strlen(str);

		memset(temp, 0, sizeof(temp));
		for (i = 0; i < len; i++)
			temp[i] = str[len - 1 -i];
		if (strcmp(str, temp) == 0)
			is_palindrome = 1;

		for (i = 0; i < len; i++) {
			if (isdigit(str[i]))
				temp[i] = s[str[i] - '1' + 26];
			else
				temp[i] = s[str[i] - 'A'];
		}

		for (i = 0; i < len/ 2; i++) {
			t = temp[i];
			temp[i] = temp[len - 1 - i];
			temp[len - 1 - i] = t;
		}
		if (strcmp(str, temp) == 0)
			is_mirrored = 1;
		
		//printf("%d%d\n", is_palindrome, is_mirrored);	
		if (!is_palindrome && !is_mirrored)
			printf("%s -- is not a palindrome.\n\n", str);
		else if(is_palindrome && !is_mirrored)
			printf("%s -- is a regular palindrome.\n\n", str);
		else if(!is_palindrome && is_mirrored)
			printf("%s -- is a mirrored string.\n\n", str);
		else
			printf("%s -- is a mirrored palindrome.\n\n", str);
	}
	
	return 0;
}
