#include "no.h"
#include <string>

class Lista
{
private:
    No* primeiro;
public:
    Lista();
    ~Lista();

    
    No* ObterProximo(No* no);

    int ObterCoeficiente(No* no);
    int ObterExpoente(No* no);

    void AlterarNo(No* no, int coeficiente, int expoente);

    int Tamanho();

    bool Existe(No* no);

    std::string mostrarAll();

    No* Buscar(int expoente);

    void Inserir(int coeficiente, int expoente);

    void Excluir(No* no);


};  

