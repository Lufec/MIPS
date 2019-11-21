#ifndef MUX_H
#define MUX_H


class mux
{
    int entrada1;
    int entrada2;
    int saida;
    bool chave;
public:
    mux();
    void set(int ent1, int ent2, bool dec);
    void execute();
    int getSaida();
};

#endif // MUX_H
