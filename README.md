<h1 align="center"> Linguagens de Programação 1 <h1>
<h1 align="center"> Progamming Languages 1 <h1>
<h3 align="center"> Discord Clone - Concordo <h3>

## Projeto / Project

- #### O _projeto_ consiste na criação de um clone do Discord utilizando o terminal, sem interface gráfica e sem acesso de rede.
- #### The _project_ consists of creating a clone of Discord using the terminal without a graphical interface and without network access.

## Como rodar o projeto

Clone o projeto utilizando o git e entre no diretório:

```bash
git clone https://github.com/edurs2602/discord
cd discord
```

Agora, para compilar o Concordo, siga os seguintes passos:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Dessa forma, o Concordo está pronto para rodar:

```bash
./Concordo
```

Para rodar o Concordo com o script de teste atualizado para a parte 2, utilize o seguinte código:

```bash
./Concordo < ../script-test.txt
```

Para rodar o script de teste do valgrin, siga os seguintes passos:

```bash
chmod +x valgrind-test.sh
```

Após dar permissão para o arquivo, digite na raiz do projeto:

```bash
./valgrind-test.sh
```

## Technologies

- [C++](https://learn.microsoft.com/pt-br/cpp/cpp/?view=msvc-170)

#### O projeto utiliza-se somente da linguagem C++. // The project uses only the C++ language.

## Funcionalidades

O Concordo, apresenta as seguintes funcionalidades:

- Sair do sistema
- Criar usuário
- Fazer login
- Deslogar
- Interações com Servidores:
  - Criar servidor
  - Mudar a descrição do servidor
  - Setar código de convite do servidor
  - Listar servidores
  - Remover servidor
  - Entrar em um servidor
  - Sair de um servidor
  - Listar participantes do servidor

Funcionalidades da Parte 2:

- Listar Canais
- Criar Canais
- Entrar em algum Canal
- Sair de algum Canal
- Mandar alguma mensagem de texto
- Listar as mensagens do Servidor

Funcionalidades da Parte 3:

- Salva os usuarios no arquivo: /logs/usuarios.txt
- Salva os servidores no arquivo: /logs/servidores.txt
- Pega as informações dos arquivos: /logs/usuarios.txt e /logs/servidores.txt
  - E salva no sistema ao iniciar o Concordo

## Informações do Aluno

<h3 align="center">Colaborador: <a href="https://github.com/edurs2602"><strong>@edurs2602</strong></a><br />Luis Eduardo - 20220028973</h3>
<h4 align="center">:phone: <i>C O N T A T O S / C O N T A C T S</i> :phone:</h4>
<div align="center">
    <a href = "mailto:edurs.2602@gmail.com"><img src="https://img.shields.io/badge/-Gmail-F80000?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
    <a href="https://www.linkedin.com/in/lu%C3%ADs-eduardo-da-silva-ribeiro-462221233/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
    <a href="https://wa.me/5584996361789/" target="_blank"><img src="https://img.shields.io/badge/-WhatsApp-4EA94B?style=for-the-badge&logo=WhatsApp&logoColor=white" target="_blank"></a>
</div>
