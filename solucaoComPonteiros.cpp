//Solução com ponteiros
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Definição da estrutura que representa um bem
struct Bem {
    string nome;
    string categoria;
    string dataAquisicao;
    double peso;
    string endereco; // Apenas para imóveis
};

// Função para salvar os bens em um arquivo de texto
void salvarBens(const vector<Bem*>& bens) {
    // Abre o arquivo "bensCP.txt" para escrita
    ofstream arquivo("bensCP.txt");
    // Itera sobre o vetor de ponteiros para bens
    for (int i = 0; i < bens.size(); ++i) {
        // Obtém uma referência ao bem apontado pelo ponteiro atual
        const Bem& bem = *(bens[i]);
        // Escreve os detalhes do bem no arquivo
        arquivo << bem.nome << "," << bem.categoria << "," << bem.dataAquisicao << "," << bem.peso;
        // Se o bem for um imóvel, inclui também o endereço
        if (bem.categoria == "imovel") {
            arquivo << "," << bem.endereco;
        }
        arquivo << endl; // Nova linha para o próximo bem
    }
    // Fecha o arquivo após terminar de escrever os bens
    arquivo.close();
}

int main() {
    vector<Bem*> listaDeBens; // Vetor para armazenar ponteiros para os bens
    char opcao; // Variável para armazenar a opção escolhida pelo usuário

    do {
        // Exibe o menu para o usuário
        cout << "==Bem-Vindo ao SGBUZ==\nMenu:\n";
        cout << "1. Adicionar Bem\n";
        cout << "2. Listar Bens\n";
        cout << "3. Salvar e Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        // Verifica a opção escolhida pelo usuário
        if (opcao == '1') {
            // Adiciona um novo bem à lista
            Bem* novoBem = new Bem; // Aloca dinamicamente um novo objeto Bem
            cout << "Nome: ";
            cin >> novoBem->nome;
            cout << "Categoria (imovel ou movel): ";
            cin >> novoBem->categoria;
            cout << "Data de Aquisicao: ";
            cin >> novoBem->dataAquisicao;
            cout << "Peso: ";
            cin >> novoBem->peso;
            // Se o bem for um imóvel, solicita também o endereço
            if (novoBem->categoria == "imovel") {
                cout << "Endereco: ";
                cin >> novoBem->endereco;
            }
            listaDeBens.push_back(novoBem); // Adiciona o ponteiro para o novo bem à lista
        } else if (opcao == '2') {
            // Lista os bens armazenados
            for (int i = 0; i < listaDeBens.size(); ++i) {
                const Bem& bem = *(listaDeBens[i]);
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
            cout << "Bens salvos no arquivo 'bensCP.txt'. Saindo...\n";
            // Libera a memória alocada dinamicamente para os bens
            for (int i = 0; i < listaDeBens.size(); ++i) {
                delete listaDeBens[i];
            }
            listaDeBens.clear(); // Limpa o vetor
        } else {
            // Mensagem de opção inválida se o usuário escolher uma opção inválida
            cout << "Opção inválida!\n";
        }
    } while (opcao != '3'); // Continua exibindo o menu até que o usuário escolha sair

    return 0;
}
