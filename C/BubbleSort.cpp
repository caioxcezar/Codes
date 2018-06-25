#include <iostream>
#include <vector>
using namespace std;
vector<int> bubbleSort(vector<int> vetor){
  int aux;
    for(int i = 0; i < vetor.size();i++)
      for(int j = 0; j < vetor.size()-1;j++){
        if(vetor[j]>vetor[j+1]){
          aux = vetor[j];
          vetor[j] = vetor[j+1];
          vetor[j+1] = aux;
      }
    }
  return vetor;
}
int main(){
  int x=1;
  vector<int> vetor;
  while(x!=0){
    cout << "Digite um numero (zero sai): ";
    cin >> x;
    vetor.push_back(x);
  }
  vector<int> bubbled = bubbleSort(vetor);
  bubbleSort(vetor);
  for (int i = 0; i < bubbled.size();i++)
    cout << bubbled[i] << ' ';
  return 0;
}
