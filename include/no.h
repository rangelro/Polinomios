class No
{
private:
    int coeficiente;
    int expoente;
    No* proximo;
public:
    
    No(int coeficiente, int expoente);

    ~No();

    int getCoeficiente();
    void setCoeficiente(int valor);

    int getExpoente();
    void setExpoente(int valor);

    No* ProximoNo();
    void setProximoNo(No* no);

};
