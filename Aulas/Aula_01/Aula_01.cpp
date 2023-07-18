#include <iostream>
#include <string>
using namespace std;
 
//IMPLEMENTE AS FUNCOES
// EXERCICIO 1
double calculaPrecoDoMes(int tipoDoPlano, bool primeiroMes) {
    double preco; 
    switch (tipoDoPlano){
        case 1:
            if(primeiroMes){ 
                return  22.9*0.5;
            }else{
                return  22.9;
            }
        case 2: 
            if(primeiroMes){
                return 25.3*0.5;
            }else{
                return 25.3;
            }
        case 3:
            if(primeiroMes){
                return 30*0.5;
            }else{
                return 30;
            }
    }
 
}
 
// EXERCICIO 2
 
bool maisMinutosDeFilme(int duracoes[], bool ehFilme[], int quantidade) {
    int i,j, FilmeDuracao, SerieDuracao;
 
    for(i=0;i<quantidade; i++){
        if(ehFilme[i] == 1){
            FilmeDuracao += duracoes[i];
        }else{
            FilmeDuracao += duracoes[i];
        }
    }
    if(FilmeDuracao < SerieDuracao){
        return false;
    }else{
        return true;
    }
}
 
 
// EXERCICIO 3
 
double similaridade(string filmes1[], int quantidade1, string filmes2[], int quantidade2){
    int i,j,NumFilIguais=0, total= 0;
 
    total = quantidade1 + quantidade2;
 
    for (i = 0; i < quantidade1; i++){
        for(j = 0; j < quantidade2; j++){
            if(filmes1[i] == filmes2[j]){
                NumFilIguais += 1;
                total --;   
            }
        }
        
    }
   // printf("NumFilIguais: %d, total:%d", NumFilIguais, total);
 
    return 100*NumFilIguais/total;
    
 
}
/*
int main(){
    cout << calculaPrecoDoMes(1,0);
}
*/
/*
int main() {
    int duracoes[] = {100, 50, 60};
    bool ehFilme[] = {true, false, false};
    int quantidade = 3;
    cout << maisMinutosDeFilme(duracoes,ehFilme,quantidade);
    return 0;
}*/
/*
int main() {
 
    string filmes1[] =  {"Matrix", "Bastardos Inglorios", "Smurfs", "Homem-Aranha"}; 
    int quantidade1 = 4;
    string filmes2[] =  {"Divertidamente", "Smurfs", "Homem-Aranha"}; 
    int quantidade2 = 3;
    
    cout << similaridade(filmes1,quantidade1,filmes2,quantidade2);
    return 0;
}
*/