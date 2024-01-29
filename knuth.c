#include <stdio.h>
#include <string.h>
void computeLPS(char* pattern, int patternLength, int* lps) {
 int len = 0; 
 lps[0] = 0; 
 int i = 1;
 while (i < patternLength) {
 if (pattern[i] == pattern[len]) {
 len++;
 lps[i] = len;
 i++;
 } else {
 if (len != 0) {
 len = lps[len - 1];
 } else {
 lps[i] = 0;
 i++;
 }
 }
 }
}
void kmpSearch(char* text, char* pattern) {
 int textLength = strlen(text);
 int patternLength = strlen(pattern);
 int lps[patternLength];
 computeLPS(pattern, patternLength, lps);
 int i = 0; 
 int j = 0; 
 while (i < textLength) {
 if (pattern[j] == text[i]) {
 i++;
 j++;
 }
 if (j == patternLength) {
 printf("Pattern found at index %d\n", i - j);
 j = lps[j - 1];
 } else if (i < textLength && pattern[j] != text[i]) {
 if (j != 0) {
 j = lps[j - 1];
 } else {
 i++;
 }
 }
 }
}
int main() {
 char text[] = "AABAACAADAABAAABAA";
 char pattern[] = "AABA";
 kmpSearch(text, pattern);
 return 0;
}
