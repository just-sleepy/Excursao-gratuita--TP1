#include <string.h>
#include <stdexcept>
#include <iostream>

#include "curses.h"
#include "dominios.h"
#include "interface.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"

using namespace std;

int main()
{

    // Instancia as controladoras de apresentaçăo.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoConta *cntrApresentacaoConta;
    IApresentacaoExcursao *cntrApresentacaoExcursao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrApresentacaoExcursao = new CntrApresentacaoExcursao();

    // Instancia as controladoras de serviço.

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoConta *cntrServicoConta;
    IServicoExcursao *cntrServicoExcursao;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoConta = new CntrServicoConta();
    cntrServicoExcursao = new CntrServicoExcursao();

    // Interliga as controladoras de apresentação às de serviço.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoConta(cntrApresentacaoConta);
    cntrApresentacaoControle->setCntrApresentacaoExcursao(cntrApresentacaoExcursao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);

    cntrApresentacaoConta->setCntrServicoConta(cntrServicoConta);
    cntrApresentacaoConta->setCntrServicoExcursao(cntrServicoExcursao);

    cntrApresentacaoExcursao->setCntrServicoExcursao(cntrServicoExcursao);

    initscr();                                                                      // Inicia curses.
    cntrApresentacaoControle->executar();                                           // Solicita serviço apresentacao.
    endwin();                                                                       // Finaliza curses.

    return 0;
}
