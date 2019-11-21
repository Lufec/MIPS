#include <mips.h>

using namespace std;

int *converterInstr(ifstream &mipsFile){
    int *instr = new int[16];
    mipsFile.open("E:/Documentos/UFRN/Atividades/MIPS/MIPS/testar.txt");
    vector<string> linhas;      //O vetor recebe todas as linhas do arquivo
    string linhaAtual, comando;
    if(mipsFile.is_open()){
        while(getline(mipsFile, linhaAtual)){
            linhas.push_back( linhaAtual);
        }
    }
    else{
        cout << "Erro ao abrir o arquivo" << endl;
        exit(0);
    }
    for(int i=0; i<linhas.size(); i++){
        int op,rd,rs,rt,shamt,funct,imediato,endereco;
        memoria mem;
        stringstream instrucao(linhas[i]);
        instrucao >> comando; //Cada instrução lida pela linha irá para uma string comandoMIPS que selecionará a ação.
        if (comando == "add"){
            op=0;
            funct = 0x100000;
            shamt = 0;
            instrucao >> comando;
            // Passar bin de rd,rs,rt
            //combinar pra formar uma instrucao binaria
            //passar para instructionMemory

        }else if(comando == "addi"){
            op = 0x001000;
            //pegar rd,rs,imediato;
            //mesma coisa acima

        }else if(comando == "sub"){
            op = 0;
            shamt = 0;
            funct = 0x100010;
            //pegar rd,rs,rt
            //mesma coisa acima
        }
    }
    return instr;
}

int main()
{
    pc Pc;
    instructionMemory instmem;
    control Control;
    mux m1;
    registers Registers;
    signExtend SignExtend;
    mux m2;
    alucontrol AluControl;
    alu Alu;
    datamemory DataMem;
    mux m3;
    add add1;
    add add2;
    mux m4;

    MIPS mips(Pc,instmem,Control,m1,Registers,SignExtend,m2,AluControl, Alu, DataMem, m3, add1,add2,m4);
    ifstream instrucoes;
    //colocar instrucoes no mips - armazenar em vetor e jogar vetor no mips

    int *instructions = converterInstr(instrucoes);

    mips.setInstructions(instructions);

    for(int i=0;i<16;i++){ //número de instruções
        mips.executar();
    }

    cout<<"Registradores:"<<endl;
    Registers.printRegs();
    cout<<endl<<"Memória:"<<endl;
    DataMem.printDataMem();

    return 0;
}
