#include <mips.h>

using namespace std;

int main()
{
    mux teste1;
    teste1.entradas(1,2,1);
    teste1.decisao();
    cout<<teste1.getSaida()<<endl;
    return 0;
}
