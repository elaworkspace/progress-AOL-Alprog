//program for encrpyt words with Caesar Cipher
//shift by 1
#include <stdio.h>
#include <string.h>
void caesarCipher(char* text, int key) {
	int i = 0;
	int cipherValue;
	char cipher;
	
	while (text[i] != '\0' && strlen(text) > i) {
		cipherValue = ((int)text[i] - 97 + key) % 26 + 97;
		cipher = (char)(cipherValue);
		
		printf("%c", cipher);
		i++;
	}
	puts("");
}

int main() {
	int key;
	printf("What is the shift key? ");
	scanf("%d", &key); getchar();
	
	char text[101];
	printf("Enter the word to encrpyt : ");
	scanf("%s", text);
	printf("The ciphered text is ");
	
	caesarCipher(text, key);
	return 0;
}
