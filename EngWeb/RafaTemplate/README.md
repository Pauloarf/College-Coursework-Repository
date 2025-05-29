# TPC 5

**Titulo:** Contratos
**Data:**  2025-03-27  
**Nome:** Rafael Santos Fernandes  
**Número:** A104271  
<img src="../assets/img/foto.jpg" alt="foto" width="200" />

## Resumo
### Enunciado
Criação de uma App para gerir alunos com dois serviços: api de dados e front-end;  
1. API de dados: aplicação em nodejs que recebe pedidos REST, interage com o MongoDB para obter os dados e responde em JSON;
2. Front-end: aplicação em nodejs que responde com uma interface web (templates PUG) a pedidos do utilizador (sempre que precisar de dados pede-os à API de dados).

Nota: ambos os serviços podem ser prototipados com o express e desenvolvidos a partir daí. No caso da API de dados não serão desenvolvidas views.

Ver [enunciado completo](./semana7_api_mdb_alunos.pdf) para mais detalhes.

### Resolução
Comecei por examinar o enunciado, retirando as seguintes conclusões:
1. A aplicação requer três sistemas para o seu funcionamento: uma instância de uma base de dados MongoDB, uma API de dados, e uma interface web.
2. A API de dados deve implementar operações CRUD sobre o contratos individuais, bem como permitir obter uma lista de contratos relativos a uma dada entidade ou tipo de procedimento. Além disso, a aplicação deve permitir obter uma lista das entidades e tipos de procedimentos existentes.
3. A interface deve implementar páginas unicamente de visualização de dados, nomeadamente para a lista de contratos, contratos indivíduais e entidades contratuais.

Examinei de seguida o dataset e retirei do mesmo a estrutura seguinte:
| Chave                       | Tipo de Dados         |
|:----------------------------|:----------------------|
| `idcontrato`                | `String`              |
| `nAnuncio`                  | `String \| undefined` |
| `tipoprocedimento`          | `String`              |
| `objectoContrato`           | `String`              |
| `dataPublicacao`            | `String`              |
| `dataCelebracaoContrato`    | `String`              |
| `precoContratual`           | `String`              |
| `prazoExecucao`             | `String`              |
| `NIPC_entidade_comunicante` | `String`              |
| `entidade_comunicante`      | `String`              |
| `fundamentacao`             | `String`              |

#### Base de Dados
Para a implementação da base de dados, criei um docker container baseado na imagem `mongo:latest`, com a possibilidade de importar automaticamente o dataset presente em [`./db/dataset/db.json`](./db/dataset/db.json) através do uso da flag `--db-prep` no script `run.sh`.

#### API de Dados
Decidi implementar a api de dados através de um serviço em nodejs com recurso ás packages [`express`](https://npmjs.com/package/express) e [`mongoose`](https://npmjs.com/package/mongoose).

#### Interface Web
Decidi implementar a interface web através de um serviço em nodejs com recurso ás packages [`express`](https://npmjs.com/package/express) e [`pug`](https://npmjs.com/package/pug).  
A API de Dados é consumida pela aplicação para a contrução das páginas web no lado do servidor durante o processo de *Server-Side Rendering* dos templates escritos em `pug`.

O diretório `public/assets` contém um `jsconfig.json` de modo a ter acesso ás declarações de tipos da DOM sem poluír o escopo do backend do serviço.

Durante o desenvolvimento da [API de Dados](#api-de-dados) e da [Interface Web](#interface-web), foi utilizado o package manager `pnpm` em vez do normal `npm`, de modo a reduzir o espaço ocupado pelas dependências do projeto. Foi também utilizado o Typescript em conjunto com o ESLint de modo a detetar e corrigir erros mais facilmente. O package manager `npm` pode ser utilizado ao escolher a opção `NPM` ao preparar o ambiente (`prepare.sh`).  

### Execução
Antes da execução da aplicação, é necessária a preparação do ambiente de desenvolvimento. Para tal, execute o script `./prepare.sh` e siga as instruções dadas.

Para a execução da aplicação, foi utilizado o Docker e Docker Compose para a criação e gestão dos containers necessários para os diferentes serviços da mesma, cujo uso é facilitado pelo uso do script `run.sh`. Para executar a aplicação na sua totalidade, execute o script `./run.sh`. Caso ocorra o erro `permission denied while trying to connect to the Docker daemon socket` ao executar o script, utilize permissões de super-utilizador para a sua execução: `sudo ./run.sh`.
