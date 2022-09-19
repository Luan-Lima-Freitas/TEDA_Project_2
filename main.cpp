#include <iostream>

using namespace std;

typedef unsigned long int t_DRE;

struct t_aluno
{
    t_DRE   DRE;
    string  nome;
    double  CR;

    void Cadastro(t_DRE pDRE, string pnome, double pCR = 0)
    {
        DRE = pDRE;
        nome = pnome;
        CR = pCR;
    }

    void Print(void)
    {
        cout << "+-------------------+" << endl;
        cout << "| Registro de Aluno |" << endl;
        cout << "+-------------------+" << endl;
        cout << "| DRE : " << DRE << endl;
        cout << "| Nome: " << nome << endl;
        cout << "| CR  : " << CR << endl;
        cout << "+-------------------+" << endl;
    }

    double operator +(t_aluno B)
    {
        return (CR + B.CR);
    }
};

class t_curso
{
    string  codigo_curso;
    string  nome_curso;
    float nota_MEC;
    t_aluno lista_de_alunos[500];
    int num_alunos;

    public:

    void cadastro(string pcodigo_curso, string pnome_curso, float pnota_MEC)
    {
        codigo_curso = pcodigo_curso;
        nome_curso = pnome_curso;
        nota_MEC = pnota_MEC;
        num_alunos = 0;
    }

    void inscricao_aluno(t_aluno aluno)
    {
        lista_de_alunos[num_alunos] = aluno;
        num_alunos++;
    }

    void print(void)
    {
        cout << "+-------------------+" << endl;
        cout << "| Registro de Curso |" << endl;
        cout << "+-------------------+" << endl;
        cout << "| Codigo : " << codigo_curso << endl;
        cout << "| Nome: " << nome_curso << endl;
        cout << "| Nota do MEC  : " << nota_MEC << endl;
        cout << "+-------------------+" << endl;
    }

    void print_alunos(void)
    {
        int i;
        for(i = 0; i < num_alunos; i++)
        {
            cout << "Aluno #" << i+1 << ": " << lista_de_alunos[i].nome << " (" << lista_de_alunos[i].DRE << ")" << endl;
        }
    }

    double operator +(t_curso B) // operador polimorfo
    {
        return nota_MEC + B.nota_MEC;
    }
};


template <class T>
double media(T a1, T a2)
{
    return (a1 + a2)/2;
}

int main()
{
    t_aluno Altair, Beltair, Celtair;
    Altair.Cadastro(111000123, "Altair da Silva", 4);
    Beltair.Cadastro(111000124, "Beltair da Silva", 5);
    Celtair.Cadastro(111000125, "Celtair da Silva", 6);

    t_curso mat_aplic;
    mat_aplic.cadastro("MAT003", "Matematica Aplicada", 8.8);
    mat_aplic.print();
    cout << "\n";

    mat_aplic.inscricao_aluno(Altair);
    mat_aplic.inscricao_aluno(Beltair);
    mat_aplic.print_alunos();
    cout << "\n";

    t_curso filosofia;
    filosofia.cadastro("FIL001", "Filosofia", 8.0);
    filosofia.print();
    cout << "\n";

    filosofia.inscricao_aluno(Celtair);
    filosofia.print_alunos();
    cout << "\n";

    cout << "Media dos cursos: " << media(mat_aplic, filosofia) << endl;

    return 0;
}
