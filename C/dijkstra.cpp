#include <iostream>
#include <vector>
#include <string>
struct no{
    string 
};

void escreverGrade(std::vector<std::vector<int>> grade, int tamanho){
    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho;j++)
            std::cout << grade[i][j] << " ";
        std::cout << "\n";
    }
}

int main(){
    using namespace std;
    int tamanho, valor;
    cout << "Algoritimo de dijkstra\n\nDigitem a quantidade de lugares: ";
    cin >> tamanho;
    vector<vector<int>> grade;
    for(int i=0; i<tamanho; i++){
        vector<int> linha;
        cout << "local " << i+1 << "\n";
        for(int j=0; j<tamanho;j++){
            if(i == j){
                linha.push_back(0);
            }else{
                cout << "Distancia para o local " << j+1 << " (0 para lugar nao conexos): ";
                cin >> valor;
                linha.push_back(valor);
            }
        }
        grade.push_back(linha);
        cout << endl;
    }
    escreverGrade(grade, tamanho);
    return 0;
}