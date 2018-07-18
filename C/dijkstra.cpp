#include <iostream>
#include <vector>
#include <string>
#define INF 9999

using namespace std;

typedef vector<vector<int>> grid;

void escreverGrade(grid grade, int tamanho){
    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho;j++)
        if(grade[i][j] == INF)
            cout << "∞" << " ";
        else
            cout << grade[i][j] << " ";
        cout << "\n";
    }
}

void dijkstra(grid grade, int tamanho){
    //grid final
    grid aux;
    for(int i = 0; i < tamanho; i++)
    {
        int soma = 0;
        //array com os nos ja inspecionados.
        int lock[tamanho] = {-1};
        //capturando a primeira linha para editar.
        vector<int> linha = grade[i];
        for(int j = 0; j < tamanho; j++){

        }
    }
    escreverGrade(grade, tamanho);
    
}

int main(){
    int tamanho, valor;
    cout << "Algoritimo de dijkstra\n\nDigitem a quantidade de lugares: ";
    cin >> tamanho;
    grid grade;
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
    escreverGrade(grade, tamanho);
    //dijkstra(grade, tamanho);
    return 0;
}