#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define MAX 70 //Max array size

/* This function removes the s[n] char from the s array*/
void rmChar(char s[], int n){
    int i;
    for(i = n+1; s[i]; i++, n++){
        s[n] = s[i];
    }
    s[n] = '\0';
}

/* This function returns 1(true) if a is a vocal, and returns 0(false) if it is not*/
int isVocal(char a){
    if (a == 'a' ||a == 'e' ||a == 'i' ||a == 'o' ||a == 'u'
        ||a == 'A' ||a == 'E' ||a == 'I' ||a == 'O' ||a == 'U') return 1;
    else return 0;
}

/* This function prints the content of an array*/
void dumpV(char v[]){
    int i;
    putchar('{');
    for (i=0; v[i] != '\0'; i++) printf ("%c", v[i]);
    putchar('}');
    putchar ('\n');
}

// Exercise 4
int bitsUm(unsigned int n){
    int r = 0;
    while(n > 0){
        if(n % 2 != 0)r +=1;
        n /= 2;
    }
    return r;
}

// Exercise 5
int trailingZ(unsigned int n){
    int r = 0;
    while(n > 0){
        if(n % 2 == 0)r +=1, n /= 2;
        else break;
    }
    if(n == 0)r = 32;
    return r;
}

/* This function outputs the number n in base 2 (binary)*/
void showBinary(unsigned int n){
    int size = 0, m;
	for	(m = n; m > 0; m >>= 1) size++;
	for	(size--; size >= 0; size--)
	    printf("%d", (n >> size) & 1);
    putchar('\n');
}

// Exercise 6
int qDig(unsigned int n){
    int r = 0;
    while(n > 0){
        r++;
        n /= 10;
    }
    return r;
}

// Exercise 7
char *myStrcat(char s1[], char s2[]){
    int i, size;
    for(size = 0; s1[size]; size++);
    for(i = 0; s2[i]; i++, size++){
        s1[size] = s2[i];
    }
    s1[size] = '\0';
    return s1;
}

// Exercise 8
char *myStrcpy(char *dest, char source[]){
    int i;
    for(i = 0; source[i] != '\0'; i++){
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

// Exercise 9
int myStrcmp(char s1[], char s2[]){
    int i;
    for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++){
        if(s1[i] == s2[i]);
        else break;
    }
    if(s1[i] < s2[i]) return -1;
    if(s1[i] > s2[i]) return 1;
    return 0;
}

// Exercise 10
char *myStrstr(char s1[], char s2[]){
    int i;
    for(i = 0; s1[i]; i++){
        if(s1[i] == s2[0]){
            int aux = i;
            int j;
            for(j = 0; s2[j]; j++, aux++){
                if(s1[aux] == s2[j]);
                else break;
            }
            if(s2[j] == '\0'){
                s1 = s1 + i;
                return s1;
            }
        }
    }
    if(s2[0] == '\0') return s1;
    return NULL;
}

// Exercise 11
void myStrrev(char s[]){
    int i, j;
    char aux[MAX];
    for(i = 0; s[i]; i++){
        aux[i] = s[i];
    }
    i -= 1;
    for(j = 0; i >= 0; j++, i--){
        s[j] = aux[i];
    }
    s[j] = '\0';
}

// Exercise 12
void myStrnoV(char s[]){
    int i;
    for(i = 0; s[i] != '\0';){
        if(isVocal(s[i])) rmChar(s, i);
        else i++;
    }
}

// Exercise 13
void truncW(char t[], int n){
    int i, j = 0;
    for(i = 0; t[i] != '\0'; i++){
        if(n == 0)break;
        if(t[i] == ' ') j = 0;
        else j++;
        if(j == n){
            while(t[i+1] != ' ' && t[i+1] != '\0'){
                if(t[i+1] != ' ')rmChar(t, i+1);
                else i++;
            }
        }
    }
    i = 0;
    if(n == 0)while(t[i] != '\0'){
        if(t[i] != ' ')rmChar(t, i);
        else i++;
    }
}

// Exercise 14
char charMaisfreq(char s[]){
    int i, j;
    int max = 0, maybe = 0;
    char aux = '0';
    for(i = 0; s[i] != '\0'; i++){
        for(j = 0; s[j] != '\0'; j++){
            if(s[i] == s[j]) maybe++;
        }
        if(maybe > max) max = maybe, aux = s[i];
        maybe = 0;
    }
    return aux;
}

// Exercise 15
int iguaisConsecutivos(char s[]){
    int i, max = 0, aux = 1;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == s[i+1]) aux++;
        if(aux > max) max = aux;
        if(s[i] != s[i+1]) aux = 1;
    }
    return max;
}

/* This function returns true if the value k is already in the string s*/
int pertence(char s[], int i, int j){
    for(; i < j; i++){
        if(s[i] == s[j]) return 1;
    }
    return 0;
}

// Exercise 16 
int difConsecutivos(char s[]){
    int i, j, aux, max = 0;
    for(i = 0; s[i] != '\0'; i++){
        aux = 0;
        for(j = i; s[j] != '\0'; j++){
            if(pertence(s, i, j))break;
            else aux++;
        }
        if(aux > max) max = aux;
    }
    return max;
}

// Exercise 17
int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i]; i++);
    return i;
}

// Exercise 18
int maiorSufixo (char s1 [], char s2 []) {
    int i, j, ans = -1;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++);
    while(s1[i--] == s2[j--]) ans++;
    return ans;
}

// Exercise 19
int sufPref(char s1[], char s2[]){
    int i, j, ans = 0;
    for(i = 0; s1[i]; i++){
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

// Exercise 20
int contaPal (char s[]) {
    int isWord = 0, total = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if(isWord) total++;
            isWord = 0;
        }
        else isWord = 1;
    }
    if(isWord) total++;
    return total;
}

// Exercise 21
int contaVogais(char s[]){
    int i, ans = 0;
    for(i = 0; s[i]; i++){
        if(isVocal(s[i])) ans++;
    }
    return ans;
}

// Exercise 22
int contida(char a[], char b[]){
    int i, j, ans;
    for(i = 0; a[i]; i++){
        ans = 0;
        for(j = 0; b[j]; j++){
            if(a[i] == b[j]) ans = 1;
        }
        if(!ans)break;
    }
    return ans;
}

// Exercise 23
int palindroma(char s[]){
    int i, j;
    for(i = 0; s[i]; i++);
    for(j = 0; j <= i/2; j++){
        if(s[j] != s[--i]) return 0;
    }
    return 1;
}

// Exercise 24
int remRep(char x[]){
    int i, ans = 0;
    for(i = 0; x[i];){
        if(x[i-1] == x[i]) rmChar(x, i);
        else ans++, i++;
    }
    return ans;
}

// Exercise 25
int limpaEspacos(char t[]){
    int i, ans = 0;
    for(i = 0; t[i];){
        if(t[i] == t[i+1] && t[i] == ' ') rmChar(t, i);
        else i++, ans++;
    }
    return ans;
}

// Exercise 26
void insere(int v[], int N, int x){
    int i, j;
    for(i = 0; i < N; i++){
        if(v[i] > x){
            for(j = N; j > i; j--){
                v[j] = v[j-1];
            }
            v[i] = x;
            break;
        }
        if(i == N -1) v[N] =x;
    }
}

// Exercise 27
void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while(k < na + nb) {
        if((a[i] < b[j] && i < na) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}

// Exercise 28
int crescente(int a[], int i, int j){
    while(i < j){
        if(a[i] > a[i+1]) return 0;
        i++;
    }
    return 1;
}

// Exercise 29
int retiraNeg(int v[], int N){
    int i, j;
    for(i = 0; i < N;){
        if(v[i] < 0){
            for(j = i; j < N; j++) v[j] = v[j+1];
            N--;
        }
        else i++;
    }
    return N;
}

// Exercise 30
int menosFreq (int v[], int N) {
    int i, freq = 1, freqMin = N, ans = v[0];
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq < freqMin) {
                freqMin = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq < freqMin) {
        freqMin = freq;
        ans = v[i - 1];
    }
    return ans;
}

// Exercise 31
int maisFreq(int v[], int N){
    int i, j, times, aux = 0, ans = v[0];
    for(i = 0; i < N; i++){
        times = 0;
        for(j = 0; j < N; j++){
            if(v[i] == v[j]) times++;
        }
        if(times > aux){
            aux = times;
            ans = v[i];
        }
    }
    return ans;
}

// Exercise 32
int maxCresc(int v[], int N){
    int i, ans = 1, seq = 1;
    for(i = 1; i < N; i++){
        if(v[i] >= v[i - 1]){
            seq++;
            if(seq > ans) ans = seq;
        }
        else seq = 1;
    }
    return ans;
}

// Exercise 33
int elimRep(int v[], int n){
    int i, j, pertence;
    for(i = 0; i < n;){
        pertence = 0;
        for(j = 0; j < i; j++){
            if(v[i] == v[j]) pertence = 1;
        }
        if(pertence){
            for(j = i; j < n; j++){
                v[j] = v[j+1];
            }
            n--;
        }
        else i++;
    }
    return n;
}

// Exercise 34
int elimRepOrd(int v[], int n){
    int i = 0, j;
    while(i < n){
        if(n == 1)break;
        if(v[i] == v[i+1]){
            for(j = i; j < n; j++){
                v[j] = v[j+1];
            }
            n--;
        }
        else i++;
    }
    return n;
}

// Exercise 35
int comunsOrd (int a[], int na, int b[], int nb){
   int j = 0, i = 0, ans = 0;
   while(i < na && j < nb){
       if(a[i] == b[j]){
           ans++;
           i++;
           j++;
       }
       else if(a[i] > b[j]) j++;
            else i++;
   }
   return ans;
}

// Exercise 36
int comuns(int a[], int na, int b[], int nb){
    int i, j, ans = 0;
    for(i = 0; i < na; i++){
        for(j = 0; j < nb; j++){
            if(a[i] == b[j]){
                ans++;
                break;
            }
        }
    }
    return ans;
}

// Exercise 37
int minInd(int v[], int n){
    int i, min = 0;
    for(i = 0; i < n; i++){
        if(v[i] < v[min])min = i;
    }
    return min;
}

// Exercise 38
void somasAc(int v[], int Ac[], int N){
    int i, soma = 0;
    for(i = 0; i < N; i++){
        Ac[i] = soma + v[i];
        soma += v[i];
    }
}

// Exercise 39
int triSup(int N, float m[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < i; j++){
            if(m[i][j] == 0);
            else return 0;
        }
    }
    return 1;
}

// Exercise 40
void transposta(int N, float m[N][N]){
    int i, j;
    float aux;
    for(i = 0; i < N; i++){
        for(j = 0; j < i; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

// Exercise 41
void addTo(int N, int M, int a[N][M], int b[N][M]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            a[i][j] += b[i][j];
        }
    }
}

// Exercise 42
int unionSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++){
        r[i] = v1[i] || v2[i];
    }
    return 0;
}

// Exercise 43
int intersectSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++){
        r[i] = v1[i] && v2[i];
    }
    return 0;
}

// Exercise 44
int intersectMSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++){
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    }
    return 0;
}

// Exercise 45
int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, len = 0;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
        len += r[i]; 
    }
    return len;
}

// Exercise 46
int cardinalMSet(int N, int v[N]){
    int i, length = 0;
    for(i = 0; i < N; i++) length += v[i];
    return length;
}

/* This struct is necessary for the next exercises */
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao{
    int x, y;
} Posicao;

// Exercise 47
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(mov[i] == Norte) inicial.y++;
        if(mov[i] == Sul) inicial.y--;
        if(mov[i] == Este) inicial.x++;
        if(mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}

// Exercise 48
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(final.x > inicial.x)inicial.x++, mov[i] = Este;
        else if(final.x < inicial.x)inicial.x--, mov[i] = Oeste;
        else if(final.y > inicial.y)inicial.y++, mov[i] = Norte;
        else if(final.y < inicial.y)inicial.y--, mov[i] = Sul;
        else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}

/* This function returns the distance to the origin */
int distOrigem(int x, int y){
    return(abs(x - 0) + abs(y - 0));
}

// Exercise 49
int maisCentral(Posicao pos[], int N){
    int ind = 0, i;
    int closest = distOrigem(pos[0].x, pos[0].y);
    for(i = 0; i < N; i++){
        if(distOrigem(pos[i].x, pos[i].y) < closest){
            ind = i;
            closest = distOrigem(pos[i].x, pos[i].y);
        }
    }
    return ind;
}

/* This function returns the distance between to points */
int distPontos(int x1, int y1, int x2, int y2){
    return(abs(x2 - x1) + abs(y2 - y1));
}

// Exercise 50
int vizinhos(Posicao p, Posicao pos[], int N){
    int i, r = 0;
    for(i = 0; i < N; i++){
        if(distPontos(p.x, p.y, pos[i].x, pos[i].y) == 1) r += 1;
    }
    return r;
}

int main(){
    int a = 5+5;/*
    A acrescentar no futuro (Para teste das funcoes tem sido usado o codeboard);
    */
    return 0;
}