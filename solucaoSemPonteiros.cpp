//Solução Sem Ponteiros
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Definição da estrutura que representa um bem
struct Bem {     
	char nome [100];
    string categoria;
    string dataAquisicao;
    double peso;
    string endereco; // Apenas para imóveis
};

// Função para salvar os bens em um arquivo de texto
void salvarBens(const vector<Bem>& bens) {
    ofstream arquivo("bensSP.txt"); // Abre o arquivo "bensSP.txt" para escrita
    // Itera sobre o vetor de bens
	for (size_t i = 0; i < bens.size(); ++i) {
        const Bem& bem = bens[i]; // Obtém uma referência ao bem atual
        arquivo << bem.nome << "," << bem.categoria << "," << bem.dataAquisicao << "," << bem.peso;
         // Se o bem for um imóvel, inclui também o endereço
		if (bem.categoria == "imovel") {
            arquivo << "," << bem.endereco;
        }
        arquivo << endl;
    }
    // Fecha o arquivo após terminar de escrever os bens
    arquivo.close();
}


int main() {
    vector<Bem> listaDeBens; // Vetor para armazenar os bens
    char opcao;

    do {
    	// Exibe o menu para o usuário
        cout << "==Bem-Vindo ao SGBUZ==\nMenu:\n";
        cout << "1. Adicionar Bem\n";
        cout << "2. Listar Bens\n";
        cout << "3. Salvar e Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
		
		//Verifca a opção escolhida pelo usuário
        if (opcao == '1') {
            Bem novoBem;
            cout << "Nome: ";
            cin.getline(novoBem.nome, 100);
            //cin >> novoBem.nome;
           /* cout << "Categoria (imovel ou movel): ";
            cin >> novoBem.categoria;
            cout << "Data de Aquisicao: ";
            cin >> novoBem.dataAquisicao;
            cout << "Peso: ";
            cin >> novoBem.peso;
            if (novoBem.categoria == "imovel") {
                cout << "Endereco: ";
                cin >> novoBem.endereco;
            }
            listaDeBens.push_back(novoBem); */ // Adiciona o novo bem à lista
        } else  if (opcao == '2') {
        	// Lista os bens armazenados
            for (int i = 0; i < listaDeBens.size(); ++i) {
                const Bem& bem = listaDeBens[i];
                cout << "Nome: " << bem.nome << ", Categoria: " << bem.categoria
                     << ", Data de Aquisicao: " << bem.dataAquisicao << ", Peso: " << bem.peso;
                // Se o bem for um imóvel, exibe também o endereço
				 if (bem.categoria == "imovel") {
                    cout << ", Endereco: " << bem.endereco;
                }
                cout << endl;
            } 
        } else if (opcao == '3') {
        	// Salva os bens no arquivo e encerra o programa
            salvarBens(listaDeBens);
            cout << "Bens salvos no arquivo 'bensSP.txt'. Saindo...\n";
        } else {
            cout << "Opção inválida!\n";
        }
    } while (opcao != '3');// Continua exibindo o menu até que o usuário escolha

    return 0;
}