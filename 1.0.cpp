#include <iostream>

void nabor(int k, int* a_k, int** a_i, int* n, int n_size, int& sum){
    for(int i = 0 ; i < n[k]; ++i){
        a_k[k] = i;
	int fl = 0;
        for(int j = 0; j < k; ++j){
	    if(a_k[j] == a_k[k]){
	        fl = 1;
	    }
	}
	if(fl == 1){
	    continue;
	}
	if(k == n_size - 1){
            int sum2 = 1;
	    for(int l = 0; l < n_size; ++l){
	        sum2 *= a_i[l][a_k[l]];
	    }
	    sum += sum2;
	    if(i != n[k] - 1){
	        fl = 2;
		continue;
	    }
	    return;
	}
	nabor(k + 1, a_k, a_i, n, n_size, sum);
    }
}

int main(){
    int max = 0;
    int  n_size = 0;
    int* n = new int[0];
    while(std::cin.peek() != '\n'){
	    int num = 0;
	    std::cin >> num; 
	    if(num > max){
	        max = num;
	    }
	    int* n1 = new int[n_size + 1];
	    for(int i = 0; i < n_size; ++i){
	        n1[i]=n[i];
	    }
	    n_size++;
	    int* n2 = n;
	    n = n1;
            delete n2;
	    n[n_size - 1] = num;
	    
    }
    int** a_i = new int*[n_size];  //Указатели на начала массивов
    for(int i = 0; i < n_size; ++i){
	int* a = new int[n[i]]; // сами массивы
	a_i[i] = a;
        for(int j = 0; j < n[i]; ++j){
	    std::cin >> a[j];
	}
    }
    int* a_k = new int[n_size]; // Массив из различных выбранных индексов
    int sum = 0;
    nabor(0, a_k, a_i, n, n_size, sum);
    std::cout << sum;
}
