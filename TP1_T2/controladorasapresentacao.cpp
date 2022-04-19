#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos das classes controladoras da camada de apresentaçăo.


//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo controle.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Acessar sistema.";
    char texto3[]="b - Cadastrar usuario.";
    char texto4[]="c - Acessar dados sobre excursoes.";
    char texto5[]="d - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleçăo de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="a - Selecionar servicos de conta.";
    char texto8[]="b - Selecionar servicos relacionados a excursoes.";
    char texto9[]="c - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.

        noecho();
        campo = getch();                                                                   // Leitura do campo de entrada e conversăo de ASCII.
        echo();

        switch(campo){
            case 'a': if(cntrApresentacaoAutenticacao->autenticar(&email)){                         // Solicita autenticaçăo.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleçăo de serviço.

                            clear();                                                            // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleçăo de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversăo de ASCII.
                            echo();

                            switch(campo){
                                case 'a': cntrApresentacaoConta->executar(email);                 // Solicita serviço de pessoal.
                                        break;
                                case 'b': cntrApresentacaoExcursao->executar(email);     // Solicita serviço de produto financeiro.
                                        break;
                                case 'c': apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 'b': cntrApresentacaoConta->cadastrar();
                    break;
            case 'c': cntrApresentacaoExcursao->executar();
                    break;
            case 'd': apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo autenticaçăo.

bool CntrApresentacaoAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticaçăo.

    char texto1[]="Digite o e-mail: ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Senha senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autenticaçăo.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lę valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // Lę valor do campo.

        try{
            email->setValor(string(campo1));                                                      // Atribui valor ao Email.
            senha.setValor(string(campo2));                                                     // Atribui Valor ŕ senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceçăo devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lę caracter digitado.
            echo();
        }
    }
    return (cntr->autenticar(*email, senha));                                                     // Solicita serviço de autenticaçăo.
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo pessoal.

void CntrApresentacaoConta::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleçăo de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Editar dados da conta.";
    char texto3[]="b - Descadastrar conta.";
    char texto4[]="c - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selaçăo de serviço.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversăo de ASCII.
        echo();

        switch(campo){
            case 'a': editar(email);
                    break;
            case 'b': descadastrar(email);
                    break;
            case 'c': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoConta::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            : ";
    char texto3[] ="E-mail          : ";
    char texto4[] ="Senha           : ";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Email email;
    Senha senha;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lę valor do campo.
    try{
        nome.setValor(string(campo1));
        email.setValor(string(campo2));
        senha.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 10,coluna/4,"%s",texto5);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);

    // Cadastra usuário e conta.

    if(cntrServicoConta->cadastrarUsuario(usuario))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto6);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto7);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoConta::editar(Email email){

    // Mensagens a serem apresentadas na tela de edição de dados de conta.

    char texto1[] ="Preencha os seguintes campos com as novas informacoes: ";
    char texto2[] ="Nome            : ";
    char texto3[] ="Senha           : ";
    char texto4[]="Dados em formato incorreto. Digite algo.";
    char texto5[]="Sucesso na mudanca dos dados. Digite algo.";
    char texto6[]="Falha na mudanca dos dados. Digite algo.";

    char campo1[80], campo2[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nomeNovo;
    Senha senhaNova;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de edição.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lę valor do campo.

    try{
        nomeNovo.setValor(string(campo1));
        senhaNova.setValor(string(campo2));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 8,coluna/4,"%s",exp.what());
        mvprintw(linha/4 + 10,coluna/4,"%s",texto4);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuarioAlterado;

    usuarioAlterado.setEmail(email);
    usuarioAlterado.setNome(nomeNovo);
    usuarioAlterado.setSenha(senhaNova);

    // Edita usuário.

    if(cntrServicoConta->editarUsuario(usuarioAlterado))
    {
        mvprintw(linha/4 + 16,coluna/4,"%s",texto5);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 16,coluna/4,"%s",texto6);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoConta::descadastrar(Email email){

    // Mensagens a serem apresentadas na tela de edição de descadastramento de conta.

    char texto1[]="Sucesso no descadastramento de usuario. Digite algo.";
    char texto2[]="Falha no descadastramento de usuario. Digite algo.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);

    // Descadastra usuário.

    if(cntrServicoConta->descadastrarUsuario(email))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto1);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto2);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar(){

    // Mensagens a serem apresentadas na tela simplificada de serviços relacionados à excursões para usuários não autenticados.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Listar excursoes.";
    char texto3[]="b - Consultar excursoes.";
    char texto4[]="c - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela simplificada de excursões.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.

        noecho();
        campo = getch()-48;                                                                        // Leitura do campo de entrada.
        echo();

        switch(campo){
            case 'a': listarExcursao();
                    break;
            case 'b': consultarExcursao();
                    break;
            case 'c': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar(Email email){

    // Mensagens a serem apresentadas tela completa de serviços relacionados a excursões.

    char texto1[] ="Selecione um dos servicos : ";

    char texto2[] ="a - Listar excursoes.";
    char texto3[] ="b - Consultar excursoes.";
    char texto4[] ="c - Cadastrar excursao.";
    char texto5[] ="d - Editar excursao.";
    char texto6[] ="e - Descadastrar excursao.";

    char texto7[] ="f - Consultar avaliacao.";
    char texto8[] ="g - Cadastrar avaliacao.";
    char texto9[] ="h - Listar avaliação.";
    char texto10[] = "i - Descadastrar avaliacao feita.";

    char texto11[] ="j - Consultar sessao.";
    char texto12[] ="k - Cadastrar sessao.";
    char texto13[] ="l - Listar sessao.";
    char texto14[] = "m - Descadastrar sessao.";

    char texto15[] ="n - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de imóveis.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/6,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/6 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 16,coluna/4,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 18,coluna/4,"%s",texto10);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 20,coluna/4,"%s",texto11);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 22,coluna/4,"%s",texto12);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 24,coluna/4,"%s",texto13);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 26,coluna/4,"%s",texto14);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 28,coluna/4,"%s",texto15);                                           // Imprime nome do campo.

        noecho();
        campo = getch();                                                                         // Leitura do campo de entrada.
        echo();

        switch(campo){
            case 'a': listarExcursao();
                    break;
            case 'b': consultarExcursao();
                    break;
            case 'c': cadastrarExcursao(email);
                    break;
            case 'd': editarExcursao(email);
                    break;
            case 'e': descadastrarExcursao(email);
                    break;
            case 'f': consultarAvaliacao(email);
                    break;
            case 'g': cadastrarAvaliacao(email);
                    break;
            case 'h': listarAvaliacao(email);
                    break;
            case 'i': descadastrarAvaliacao(email);
                    break;
            case 'j': consultarSessao(email);
                    break;
            case 'k': cadastrarSessao(email);
                    break;
            case 'l': listarSessao(email);
                    break;
            case 'm': descadastrarSessao(email);
                    break;
            case 'n': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::cadastrarExcursao(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de excursões.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Titulo                               : ";
    char texto3[] ="Nota                                 : ";
    char texto4[] ="Cidade                               : ";
    char texto5[] ="Duração                              : ";
    char texto6[] ="Descrição                            : ";
    char texto7[] ="Endereço                             : ";
    char texto8[]="Dados em formato incorreto. Digite algo.";
    char texto9[]="Sucesso no cadastramento. Digite algo.";
    char texto10[]="Falha no cadastramento. Digite algo.";

    // Cria campos para entrada dos dados.
    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80];

    // Instancia os domínios.
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.

    try{
        titulo.setValor(string(campo1));
        nota.setValor(atoi(campo2));
        cidade.setValor(string(campo3));
        duracao.setValor(atoi(campo4));
        descricao.setValor(string(campo5));
        endereco.setValor(string(campo6));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 16,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Excursao excursao;

    excursao.setTitulo(titulo);
    excursao.setNota(nota);
    excursao.setCidade(cidade);
    excursao.setDuracao(duracao);
    excursao.setDescricao(descricao);
    excursao.setEndereco(endereco);

    // Cadastra imóvel.

    if(cntr->cadastrarExcursao(excursao, email))
    {
        mvprintw(linha/4 + 16,coluna/4,"%s",texto9);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 16,coluna/4,"%s",texto10);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::consultarExcursao(){

    // Mensagens a serem apresentadas na tela de consulta a excursão.

    char texto1[] ="Digite o codigo da excursao que quer consultar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da consulta ao imovel.";
    char texto4[]="Falha na consulta do imovel. Digite algo.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    clear();

    char campo1[80];

    mvprintw(linha/4, coluna/4, "%s", texto1);                                                 // Imprime nome do campo.
    getstr(campo1);


    // Instancia os domínios.

    Codigo codigoExcursao;

    try{
        codigoExcursao.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4, "%s", texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia os domínios e entidades;

    Excursao excursaoConsultada;
    Email emailUsuario;

    // Mensagens das linhas da consulta.

    string textoCodigo, textoTitulo, textoNota, textoCidade;
    string textoDuracao, textoDescricao, textoEndereco, textoEmail;

    excursaoConsultada.setCodigo(codigoExcursao);

    //  Faz a consulta e imprime o resultado.

    if(cntr->consultarExcursao(&excursaoConsultada, &emailUsuario))
    {
        textoCodigo = "Codigo: " + excursaoConsultada.getCodigo().getValor();
        textoTitulo = "Titulo: " + excursaoConsultada.getTitulo().getValor();
        textoNota = "Nota: " + excursaoConsultada.getNota().getValor();
        textoCidade = "Cidade: " + excursaoConsultada.getCidade().getValor();
        textoDuracao = "Duracao: " + to_string(excursaoConsultada.getDuracao().getValor());
        textoDescricao = "Descricao: " + excursaoConsultada.getDescricao().getValor();
        textoEndereco = "Endereco: " + excursaoConsultada.getEndereco().getValor();
        textoEmail = "Email: " + emailUsuario.getValor();

        clear();

        mvprintw(linha/4,coluna/4,"%s",textoCodigo.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",textoTitulo.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",textoNota.c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s",textoCidade.c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s",textoDuracao.c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s",textoDescricao.c_str());
        mvprintw(linha/4 + 12,coluna/4,"%s",textoEndereco.c_str());
        mvprintw(linha/4 + 14,coluna/4,"%s",textoEmail.c_str());

        mvprintw(linha/4 + 18,coluna/4,"%s", texto3);

        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::descadastrarExcursao(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de excursão.

    char texto1[] ="Digite o codigo da excursao que quer descadastrar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Sucesso no descadastramento de imovel. Digite algo.";
    char texto4[]="Falha no descadastramento de imovel. Digite algo.";

    char campo1[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    if(cntr->descadastrarExcursao(codigo, email))
    {
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::listarExcursao(){

    // Mensagens a serem apresentadas na tela de listagem de imóveis.

    char texto1[] ="Falha na listagem de excursoes. Digite algo.";
    char texto2[] ="Digite algo para sair da listagem.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);

    clear();

    int linhaAcumulada = 0;
    int contagemExcursao = 1;

    // Instancia o texto das linhas e a lista de imóveis a ser exibida.

    string textoExcursao;
    list<Excursao> listaExcursao;

    string cabecalho = "N.     Codigo     Titulo     Nota     Cidade     Duracao     Descricao     Endereco";                   // Cabeçalho da lista.

    // Lista os Excursao cadastrados no programa.

    if(cntr->listarExcursao(&listaExcursao))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        for(list<Excursao>::iterator excursao = listaExcursao.begin(); excursao != listaExcursao.end(); excursao++){

            textoExcursao = to_string(contagemExcursao) + ":     " + excursao->getCodigo().getValor();
            textoExcursao += "          " + excursao->getTitulo().getValor();
            textoExcursao += "      " + to_string(excursao->getNota().getValor());
            textoExcursao += "          " + excursao->getCidade().getValor();
            textoExcursao += "         " + to_string(excursao->getDuracao().getValor());
            textoExcursao += "       " + excursao->getDescricao().getValor();
            textoExcursao += "       " + excursao->getEndereco().getValor();

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoExcursao.c_str());
            linhaAcumulada++;
            contagemExcursao++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto2);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}

void CntrApresentacaoExcursao::editarExcursao(Email email){

    // Mensagens a serem apresentadas na tela de edição de dados de imóvel.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Codigo                               : ";
    char texto3[] ="Titulo                               : ";
    char texto4[] ="Nota                                 : ";
    char texto5[] ="Cidade                               : ";
    char texto6[] ="Duração                              : ";
    char texto7[] ="Descrição                            : ";
    char texto8[] ="Endereço                             : ";
    char texto9[]="Dados em formato incorreto. Digite algo.";
    char texto10[]="Sucesso na edicao dos dados do imovel. Digite algo.";
    char texto11[]="Falha na edicao dos dados do imovel. Digite algo.";

    // Campos a serem preenchidos pelo usuário.

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80], campo7[80];
                               // Cria campos para entrada dos dados.
    // Instancia os domínios.

    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de edição de excursão.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.

    try{
        codigo.setValor(string(campo1));
        titulo.setValor(string(campo2));
        nota.setValor(atoi(campo3));
        cidade.setValor(string(campo4));
        duracao.setValor(atoi(campo5));
        descricao.setValor(string(campo6));
        endereco.setValor(string(campo7));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto9);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Excursao excursao;

    excursao.setCodigo(codigo);
    excursao.setTitulo(titulo);
    excursao.setNota(nota);
    excursao.setCidade(cidade);
    excursao.setDuracao(duracao);
    excursao.setDescricao(descricao);
    excursao.setEndereco(endereco);

    // Edita excursão.

    if(cntr->editarExcursao(excursao, email))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::cadastrarAvaliacao(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de avaliacao.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Codigo da excursao                   : ";
    char texto3[] ="Nota                                 : ";
    char texto4[] ="Descricao                            : ";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Nota nota;
    Descricao descricao;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento de avaliação.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.

    try{
        codigo.setValor(string(campo1));
        nota.setValor(atoi(campo2));
        descricao.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 12,coluna/4,"%s",texto5);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Avaliacao avaliacao;

    avaliacao.setNota(nota);
    avaliacao.setDescricao(descricao);

    // Cadastra avaliacao.

    if(cntr->cadastrarAvaliacao(avaliacao, email, codigo))
    {
        mvprintw(linha/4 + 12,coluna/4,"%s",texto6);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::consultarAvaliacao(Email email){

    // Mensagens a serem apresentadas na tela de consulta a avaliacao.

    char texto1[] ="Digite o codigo da avaliacao que quer consultar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da consulta da avaliacao.";
    char texto4[]="Falha na consulta da avaliacao. Digite algo.";


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    clear();

    char campo1[80];

    mvprintw(linha/4, coluna/4, "%s", texto1);                                                 // Imprime nome do campo.
    getstr(campo1);

    Codigo codigoAvaliacao;

    try{
        codigoAvaliacao.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4, "%s", texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia domínios e entidades.

    Avaliacao avaliacaoConsultada;
    Email emailProposto;
    Codigo codigoExcursao;

    // Mensagens a serem exibidas na consulta a avaliacao.

    string textoCodigo, textoNota, textoDescricao;
    string textoEmail, textoCodigoExcursao;

    avaliacaoConsultada.setCodigo(codigoAvaliacao);

    // Apresenta tela de consulta da avaliacao pedida.

    if(cntr->consultarAvaliacao(email, &avaliacaoConsultada, &emailProposto, &codigoExcursao))
    {
        textoCodigo = "Codigo: " + avaliacaoConsultada.getCodigo().getValor();
        textoNota = "Nota: " + avaliacaoConsultada.getNota().getValor();
        textoDescricao = "Descricao: " + avaliacaoConsultada.getDescricao().getValor();
        textoEmail = "Email: " + emailProposto.getValor();
        textoCodigoExcursao = "Codigo da excursao: " + codigoExcursao.getValor();

        clear();

        mvprintw(linha/4,coluna/4,"%s",textoCodigo.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",textoNota.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",textoDescricao.c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s",textoEmail.c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s",textoCodigoExcursao.c_str());

        mvprintw(linha/4 + 10,coluna/4,"%s", texto3);

        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::descadastrarAvaliacao(Email email){

    // Mensagens a serem apresentadas na tela de descadastramento de avaliacao.

    char texto1[] ="Digite o codigo da avaliacao que quer descadastrar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Sucesso no descadastramento da avaliacao. Digite algo.";
    char texto4[]="Falha no descadastramento da avaliacao. Digite algo.";

    // Cria campos para entrada dos dados.

    char campo1[80];

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de descadastramento de avaliacao.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    if(cntr->descadastrarAvaliacao(codigo, email))
    {
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::listarAvaliacao(Email email){

    // Mensagens a serem apresentadas na tela de listagem de avaliacoes.

    char texto1[] ="Falha na listagem de avaliacoes. Digite algo.";
    char texto2[] ="Digite algo para sair da listagem.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);

    clear();

    int linhaAcumulada = 0;
    int contagemAvaliacao = 1;

    // Instancia as listas de avaliacoes a serem exibidas.

    string textoAvaliacao;
    list<Avaliacao> listaAvaliacao;
    list<Codigo> listaCodigosExcusao;

    string cabecalho = "N.     Codigo     Excursao     Nota     Descricao";                        // Cabeçalho da lista de excursoes.

    // Apresenta tela de listagem de excursoes.

    if(cntr->listarAvaliacao(email, &listaAvaliacao, &listaCodigosExcusao))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        list<Codigo>::iterator codigoExcursao = listaCodigosExcusao.begin();

        for(list<Avaliacao>::iterator avaliacao = listaAvaliacao.begin(); avaliacao != listaAvaliacao.end(); avaliacao++){

            textoAvaliacao = to_string(contagemAvaliacao) + ":     " + avaliacao->getCodigo().getValor();
            textoAvaliacao += "      " + codigoExcursao->getValor();
            textoAvaliacao += "      " + avaliacao->getNota().getValor();
            textoAvaliacao += "      " + avaliacao->getDescricao().getValor();

            codigoExcursao++;

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoAvaliacao.c_str());
            linhaAcumulada++;
            contagemAvaliacao++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto2);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}


void CntrApresentacaoExcursao::cadastrarSessao(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de sessao.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Codigo da sessao                     : ";
    char texto3[] ="Data                                 : ";
    char texto4[] ="Horario                              : ";
    char texto5[] ="Idioma                               : ";
    char texto6[]="Dados em formato incorreto. Digite algo.";
    char texto7[]="Sucesso no cadastramento. Digite algo.";
    char texto8[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento de sessao.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.

    try{
        codigo.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
        idioma.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 12,coluna/4,"%s",texto6);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Sessao sessao;

    sessao.setData(data);
    sessao.setHorario(horario);
    sessao.setIdioma(idioma);

    // Cadastra sessao.

    if(cntr->cadastrarSessao(sessao, email, codigo))
    {
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 12,coluna/4,"%s",texto8);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::consultarSessao(Email email){

    // Mensagens a serem apresentadas na tela de consulta a sessao.

    char texto1[] ="Digite o codigo da sessao que quer consultar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da consulta da sessao.";
    char texto4[]="Falha na consulta da sessao. Digite algo.";


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    clear();

    char campo1[80];

    mvprintw(linha/4, coluna/4, "%s", texto1);                                                 // Imprime nome do campo.
    getstr(campo1);

    Codigo codigoSessao;

    try{
        codigoSessao.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4, "%s", texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia domínios e entidades.

    Sessao sessaoConsultada;
    Email emailProposto;
    Codigo codigoExcursao;

    // Mensagens a serem exibidas na consulta a sessao.

    string textoCodigo, textoData, textoHorario, textoIdioma;
    string textoEmail, textoCodigoExcursao;

    sessaoConsultada.setCodigo(codigoSessao);

    // Apresenta tela de consulta da sessao pedida.

    if(cntr->consultarSessao(email, &sessaoConsultada, &emailProposto, &codigoExcursao))
    {
        textoCodigo = "Codigo: " + sessaoConsultada.getCodigo().getValor();
        textoData = "Data: " + sessaoConsultada.getData().getValor();
        textoHorario = "Horario: " + sessaoConsultada.getHorario().getValor();
        textoIdioma = "Idioma: " + sessaoConsultada.getIdioma().getValor();
        textoEmail = "Email: " + emailProposto.getValor();
        textoCodigoExcursao = "Codigo da excursao: " + codigoExcursao.getValor();

        clear();

        mvprintw(linha/4,coluna/4,"%s",textoCodigo.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",textoData.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",textoHorario.c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s",textoIdioma.c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s",textoEmail.c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s",textoCodigoExcursao.c_str());

        mvprintw(linha/4 + 12,coluna/4,"%s", texto3);

        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::descadastrarSessao(Email email){

    // Mensagens a serem apresentadas na tela de descadastramento de sessao.

    char texto1[] ="Digite o codigo da sessao que quer descadastrar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Sucesso no descadastramento da sessao. Digite algo.";
    char texto4[]="Falha no descadastramento da sessao. Digite algo.";

    // Cria campos para entrada dos dados.

    char campo1[80];

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de descadastramento de avaliacao.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    if(cntr->descadastrarSessao(codigo, email))
    {
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoExcursao::listarSessao(Email email){

    // Mensagens a serem apresentadas na tela de listagem de sessoes.

    char texto1[] ="Falha na listagem de sessoes. Digite algo.";
    char texto2[] ="Digite algo para sair da listagem.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);

    clear();

    int linhaAcumulada = 0;
    int contagemSessao = 1;

    // Instancia as listas de avaliacoes a serem exibidas.

    string textoSessao;
    list<Sessao> listaSessao;
    list<Codigo> listaCodigosExcusao;

    string cabecalho = "N.     Codigo     Excursao     Data     Horario     Idioma";                        // Cabeçalho da lista de excursoes.

    // Apresenta tela de listagem de sessoes.

    if(cntr->listarSessao(email, &listaSessao, &listaCodigosExcusao))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        list<Codigo>::iterator codigoExcursao = listaCodigosExcusao.begin();

        for(list<Sessao>::iterator sessao = listaSessao.begin(); sessao != listaSessao.end(); sessao++){

            textoSessao = to_string(contagemSessao) + ":     " + sessao->getCodigo().getValor();
            textoSessao += "      " + codigoExcursao->getValor();
            textoSessao += "      " + sessao->getData().getValor();
            textoSessao += "      " + sessao->getHorario().getValor();
            textoSessao += "      " + sessao->getIdioma().getValor();


            codigoExcursao++;

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoSessao.c_str());
            linhaAcumulada++;
            contagemSessao++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto2);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}

