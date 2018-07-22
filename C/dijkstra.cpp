#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#define INF INT_MAX/2

using namespace std;

typedef vector<vector<int>> grid;
//busca a menor vertice para locomoção
int menorVertice(grid grade, int tamanho, int index){
    int aux = INF, vertice;
    for(int i = 0;i < tamanho;i++)
        if(aux > grade[index][i] && index != i){
            aux = grade[index][i];
            vertice = i;
        }
    return vertice;
}
//escreve vetor
void printLine(vector<int> x,int tamanho){
    for(int i = 0; i < tamanho; i++)
        x[i] == INF ? cout << "∞ " : cout << x[i] << " ";
    cout << endl;
}
//o algoritimo
void dijkstra(grid grade, int tamanho){
    //for para fazer o menor caminho de todos os nós
    for(int x = 0;x<tamanho;x++){
        //vetor que armazena o menor caminho de um nó
        //com valor infinito inicialmente
        vector<int> linha;
        for(int i = 0; i < tamanho; i++)
            linha.push_back(INF);
        //vetor que armazena os nos ja acessados
        //todos como falso inicialmente
        vector<bool> checked;
        for(int i = 0; i < tamanho; i++)
            checked.push_back(false);
        //soma das distancias ja percoridas
        int soma = 0;
        //index da proxima vertice a se percorrer
        int prox;
        //for vai comecar no nó x e só vai parar quando chegar em um nó ja inspecionado
        //o 'i' assume valor da proxima vertice a ser percorrida
        for(int i = x; !checked[i]; i=prox){
            //percorrer as vertices do nó atual verificando se encotra um valor menor
            for(int j = 0; j < tamanho; j++){
                if(i == j)
                    linha[j] = soma + 0;
                if(soma + grade[i][j] < linha[j])
                    linha[j] = grade[i][j] + soma;
            }
            //terminado de verificar toda a linha, marca como já inspecionada
            checked[i] = true;
            //descobre qual é a proxima vertice a se percorrer
            prox = menorVertice(grade, tamanho, i);
            //soma o valor da proxima vertice no percurso
            soma += grade[i][prox];
        }
        //imprime o nó ja inspecionado
        printLine(linha, tamanho);
    }
}

int main(){
    grid grade;
    int tamanho, valor;

    cout << "Algoritimo de dijkstra\n\nDigitem a quantidade de lugares: ";
    cin >> tamanho;
    for(int i=0; i<tamanho; i++){
        vector<int> linha;
        cout << "local " << i+1 << "\n";
        for(int j=0; j<tamanho;j++){
            if(i == j){
                linha.push_back(0);
            }else{
                cout << "Distancia para o local " << j+1 << " (0 para lugar nao conexos): ";
                cin >> valor;
                (valor == 0 ? linha.push_back(INF) : linha.push_back(valor));
            }
        }
        grade.push_back(linha);
        cout << endl;
    }

    dijkstra(grade, tamanho);
    return 0;
}