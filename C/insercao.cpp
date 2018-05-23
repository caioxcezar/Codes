#include <iostream>
int main(){
	using namespace std;
	int seguencia[] = {0,0,0,0,0,0,0,0,0,0}, numero;
	for(int i=0;i<10;i++){
		bool c = true;
		int j = 0;
		cout << "Digite o " << i+1 << " numero: ";
		cin >> numero;
		while(c&&j<=i){
			if(seguencia[j]>numero){
				for(int k=i;k>=j;k--)
					seguencia[k+1]=seguencia[k];
				seguencia[j] = numero;
				c=false;
			}
			j++;
		}
		if(c)
			seguencia[i] = numero;
		for(int i=0;i<10;i++)
			cout << seguencia[i] << " ";
	}
	for(int i=0;i<10;i++)
		cout << seguencia[i] << " ";
	return 0;
}
