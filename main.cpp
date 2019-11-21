#include <mips.h>
#include <bitset>
#include <map>

using namespace std;
enum memoria{
    $zero = 0,$r1 = 1,$v0 = 2, $v1 = 3, $a0=4, $a1=5, $a2=6, $a3=7,
    $t0 = 8,$t1 = 9,$t2 = 10,$t3 = 11,$t4 = 12,$t5 = 13,$t6 = 14,$t7 = 15,
    $s0 = 16,$s1 = 17,$s2 = 18,$s3 = 19,$s4 = 20,$s5 = 21,$s6 = 22,$s7 = 23,
    $t8 = 24, $t9 = 25, $k0 = 26, $k1 = 27, $gp = 28, $sp = 29, $fp = 30, $ra = 31
};


int selectAd(string end){
    if(end == "$zero"){
        return 0;
    }
    else if(end == "$r1"){
        return 1;
    }
    else if(end == "$v0"){
        return 2;
    }
    else if(end == "$v1"){
        return 3;
    }
    else if(end == "$a0"){
        return 4;
    }
    else if(end == "$a1"){
        return 5;
    }
    else if(end == "$a2"){
        return 6;
    }
    else if(end == "$a3"){
        return 7;
    }
    else if(end == "$t0"){
        return 8;
    }
    else if(end == "$t1"){
        return 9;
    }
    else if(end == "$t2"){
        return 10;
    }
    else if(end == "$t3"){
        return 11;
    }
    else if(end == "$t4"){
        return 12;
    }
    else if(end == "$t5"){
        return 13;
    }
    else if(end == "$t6"){
        return 14;
    }
    else if(end == "$t7"){
        return 15;
    }
    else if(end == "$s0"){
        return 16;
    }
    else if(end == "$s1"){
        return 17;
    }
    else if(end == "$s2"){
        return 18;
    }
    else if(end == "$s3"){
        return 19;
    }
    else if(end == "$s4"){
        return 20;
    }
    else if(end == "$s5"){
        return 21;
    }
    else if(end == "$s6"){
        return 22;
    }
    else if(end == "$s7"){
        return 23;
    }
    else if(end == "$t8"){
        return 24;
    }
    else if(end == "$t9"){
        return 25;
    }
    else if(end == "$k0"){
        return 26;
    }
    else if(end == "$k1"){
        return 27;
    }
    else if(end == "$gp"){
        return 28;
    }
    else if(end == "$sp"){
        return 29;
    }
    else if(end == "$fp"){
        return 30;
    }
    else if(end == "$ra"){
        return 31;
    }
    else{
        cout<<"erro"<<endl;
        return -1;
    }
}

int *converterInstr(ifstream& mipsFile){
    int *instr = new int[16];

    for(int i=0;i<16;i++){
        instr[i]=0;
    }

    mipsFile.open("C:/Users/lu_fe/Downloads/MIPS-master/MIPS-master/testar.txt");
    vector<string> linhas;      //O vetor recebe todas as linhas do arquivo
    string linhaAtual, comando;
    if(mipsFile){
        while(getline(mipsFile, linhaAtual)){
            linhas.push_back( linhaAtual);
        }
    }
    else{
        cout << "Erro ao abrir o arquivo" << endl;
        exit(0);
    }

    for(int i=0; i<linhas.size(); i++){
        int op,rd,rs,rt,shamt,funct,imediato,endereco; //leitura para epgar partes importantes da instrucao
        int codigo = 0;
        string rds,rss,rts;
        stringstream instrucao(linhas[i]);
        instrucao >> comando; //Cada instrução lida pela linha irá para uma string comandoMIPS que selecionará a ação.
        cout<<"comando = "<<comando<<" ";
        if (comando == "add"){
            int aux =0;
            op=0;
            funct = 0b100000;
            shamt = 0;
            instrucao>> rts >>rss>>rds;
            rt=selectAd(rts);
            rd=selectAd(rds);
            rs=selectAd(rss);
            cout<<rt<<" "<<rs<<" "<<rd<<endl;
            codigo = rs<<21;
            codigo+= (rt<<16);
            codigo+= (rd<<11);
            codigo+= funct;
            instr[i] = codigo;
            //combinar pra formar uma instrucao binaria
            //passar para instructionMemory

        }else if(comando == "addi"){
            op = 0b001000;
            instrucao >>rts >> rss >> imediato;
            rt = selectAd(rts);
            rs = selectAd(rss);
            cout<<rt<<" "<<rs<<" "<<imediato<<endl;

            codigo = op<<26;
            codigo+=(rs<<21);
            codigo+=(rt<<16);
            codigo+=imediato;
            instr[i] = codigo;
            //pegar rd,rs,imediato;
            //mesma coisa acima

        }else if(comando == "sub"){
            op = 0;
            shamt = 0;
            funct = 0b100010;
            instrucao >> rts >>rss>>rds;
            rt=selectAd(rts);
            rd=selectAd(rds);
            rs=selectAd(rss);
            cout<<rt<<" "<<rs<<" "<<rd<<endl;
            codigo = rs<<21;
            codigo+= (rt<<16);
            codigo+= (rd<<11);
            codigo+= funct;
            instr[i] = codigo;
            //pegar rd,rs,rt
            //mesma coisa acima
        }
    }
    mipsFile.close();
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

    int* instructions = converterInstr(instrucoes);

    for(int i=0;i<4;i++){
        cout<<std::bitset<32>(instructions[i])<<endl;
    }

    mips.setInstructions(instructions);


    for(int i=0;i<4;i++){ //número de instruções

        cout<<"executando instrucao "<<i<<endl;
        mips.executar();
    }

    cout<<"Registradores:"<<endl;

    Registers.printRegs();

   /* cout<<endl<<"Memoria:"<<endl;
    DataMem.printDataMem();
*/
    return 0;
}
