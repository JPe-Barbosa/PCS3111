#include <iostream>
#include <string>
using namespace std;
 
// Exercicio 1
string* recomendaFilme(string nomes[], string generos[], int visualizacoes[],
                       int quantidade, string generoBuscado) {
    int i, maior = -1, verifica = 0, indice = 0;
 
    if(quantidade == 0) return NULL;
 
    for(i = 0; i < quantidade; i++){
        if (generoBuscado == generos[i]){
            verifica = 1;
            if(visualizacoes[i] > maior) {
                maior = visualizacoes[i];
                indice = i;
            }
        }
    }
    if (verifica == 0) return NULL;
    return &nomes[indice]; 
}
 
// Exercicio 2
double calcularEstatisticas(int visualizacoes[], int quantidade, int& minimo,
                            int* maximo) {
    double a;
    return a;
}
/*
int main() {
    // Teste do ex 1
    string nomes[] = {"Interestelar", "Ratatouille", "Casablanca", "O Rei Leão"};
    string generos[] = {"Sci-Fi", "f", "Animacao", "Animacao"}; 
    int visualizacoes[] = {0, 0, 780, 780};
    int quantidade = 4;
    string *maisVisualizado;
 
    maisVisualizado = recomendaFilme(nomes,generos,visualizacoes,quantidade,"f");
    cout << *maisVisualizado;
}
*/
 
/*
int main() {
    //taste do ex 2
 int visualizacoes[] = {1, 2, 3};
 int quantidade = 3;
 int minimo; 
 int maximo; // valor inicial não definido
 double media = calcularEstatisticas(visualizacoes, quantidade, &minimo, ); // veja como chamar
 // fim
}
*/