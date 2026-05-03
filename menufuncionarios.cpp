#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <clocale>

using namespace std;

struct Funcionario {
    string prontuario;
    string nome;
    double salario;
};

vector<Funcionario> lista;

int buscarIndice(string pront) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].prontuario == pront) {
            return i;
        }
    }
    return -1;
}

void incluir() {
    string p;
    cout << "Digite o prontuário: ";
    cin >> p;

    if (buscarIndice(p) != -1) {
        cout << "Erro: Prontuário já cadastrado!" << endl;
    } else {
        Funcionario novo;
        novo.prontuario = p;

        cout << "Digite o nome: ";
        cin.ignore(); 
        getline(cin, novo.nome);

        cout << "Digite o salário: ";
        cin >> novo.salario;

        lista.push_back(novo);
        cout << "Funcionário cadastrado com sucesso!" << endl;
    }
}

void excluir() {
    string p;
    cout << "Digite o prontuário para excluir: ";
    cin >> p;

    int pos = buscarIndice(p);
    if (pos == -1) {
        cout << "Funcionário não encontrado!" << endl;
    } else {
        lista.erase(lista.begin() + pos);
        cout << "Funcionário removido!" << endl;
    }
}

void pesquisar() {
    string p;
    cout << "Digite o prontuário para pesquisa: ";
    cin >> p;

    int pos = buscarIndice(p);
    if (pos != -1) {
        cout << fixed << setprecision(2);
        cout << "\n--- Dados do Funcionário ---" << endl;
        cout << "Prontuário: " << lista[pos].prontuario << endl;
        cout << "Nome: " << lista[pos].nome << endl;
        cout << "Salário: R$ " << lista[pos].salario << endl;
    } else {
        cout << "Funcionário não encontrado!" << endl;
    }
}

void listar() {
    double somaSalarios = 0;
    cout << fixed << setprecision(2);
    cout << "\n--- Lista de Funcionários ---" << endl;

    for (int i = 0; i < (int)lista.size(); i++) {
        cout << "Prontuário: " << lista[i].prontuario 
             << " | Nome: " << lista[i].nome 
             << " | Salário: R$ " << lista[i].salario << endl;
        somaSalarios += lista[i].salario;
    }

    cout << "------------------------------" << endl;
    cout << "Total dos salários: R$ " << somaSalarios << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        cout << "\n--- MENU DE FUNCIONÁRIOS ---" << endl;
        cout << "0. Sair\n1. Incluir\n2. Excluir\n3. Pesquisar\n4. Listar" << endl;
        cout << "Escolha uma opção: ";
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1: incluir(); break;
            case 2: excluir(); break;
            case 3: pesquisar(); break;
            case 4: listar(); break;
            case 0: cout << "Saindo..." << endl; break;
            default: cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
};