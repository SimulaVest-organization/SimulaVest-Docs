# SimulaVest Versão Alpha-10

Interface web interna focada em preparação para vestibulares: simulados inteligentes, estatísticas e biblioteca de provas.

[Documentação Geral](https://github.com/SimulaVest-organization/SimulaVest-Docs)

---

## Sumario

1. [Visao Geral](#visao-geral)
2. [Arquitetura e Stack](#arquitetura-e-stack)
3. [Funcionalidades Principais](#funcionalidades-principais)
4. [Estrutura de Pastas](#estrutura-de-pastas)
5. [Comencando (Setup Local)](#comencando-setup-local)
6. [Scripts Disponiveis](#scripts-disponiveis)
7. [Variaveis de Ambiente](#variaveis-de-ambiente)
8. [Padroes e Convencoes](#padroes-e-convencoes)
9. [UI / Design System](#ui--design-system)
10. [Autenticacao e Sessao](#autenticacao-e-sessao)
11. [Contextos Globais](#contextos-globais)
12. [Qualidade de Codigo](#qualidade-de-codigo)
13. [Roadmap / Proximos Passos](#roadmap--proximos-passos)
14. [Deploy no Vercel](#deploy-no-vercel)
15. [Contribuindo (Uso Interno)](#contribuindo-uso-interno)
16. [Licenca / Direitos de Uso](#licenca--direitos-de-uso)
17. [Contato](#contato)

---

## Visao Geral

O front-end do SimulaVest entrega experiência moderna para estudantes que se preparam para vestibulares (ENEM, grandes universidades e provas específicas). Oferece simulados, análise de desempenho e biblioteca de provas históricas. Foco em personalização e feedback orientado por IA (integração em evolução).

> AVISO: Este repositório é PRIVADO e de uso exclusivo da equipe SimulaVest. Nenhum trecho de código deve ser compartilhado externamente sem aprovação formal.

Objetivos:

* Tornar a prática recorrente simples e atrativa.
* Reduzir tempo para identificar lacunas de conhecimento.
* Oferecer métricas claras para evolução contínua.

## Arquitetura e Stack

* **Next.js 15 (App Router + Turbopack)**
* **React 19 + TypeScript 5**
* **Tailwind CSS 4** (com tailwind-merge / class-variance-authority)
* **shadcn/ui** (Radix UI + estilização utilitária)
* **NextAuth** (sessão / extensível para OAuth/JWT)
* **Zod + React Hook Form** (validação e formulários)
* **Recharts** (gráficos)
* **Lucide React** (ícones)
* **EmailJS** (contato)
* **Google Generative AI** (explicações/IA)

## Funcionalidades Principais

* Landing page com proposta de valor.
* Seleção de matérias e navegação temática.
* Estatísticas preliminares (placeholder para dados reais via API).
* Biblioteca de provas (`/library`).
* Página de planos pagos (`/paidPlan`).
* Páginas institucionais: termos, privacidade, contato.
* Tema claro/escuro persistido (localStorage + atributo `data-theme`).
* Pronto para APIs internas (`/src/app/api/*`).

## Estrutura de Pastas

```text
front_simulavest/
  src/
    app/                Rotas (App Router)
      layout.tsx        Root layout + providers globais
      page.tsx          Página inicial
    components/         Componentes reutilizáveis
      ui/               Base shadcn/ui adaptada
    contexts/           Contextos (tema, ícone perfil)
    lib/                Utilidades e dados estáticos
    types/              Tipagens globais (ex: next-auth.d.ts)
  public/               Imagens e assets
  next.config.ts        Configuração Next.js
  postcss.config.mjs    Configuração PostCSS
  tailwind (inline via dependências v4)
```

## Comencando (Setup Local)

Pré-requisitos:

* Node.js LTS (>= 18)
* npm, pnpm ou yarn

Instalação:

```bash
git clone https://github.com/SimulaVest-organization/SimulaVest-Front.git
cd SimulaVest-Front/front_simulavest
npm install --legacy-peer-deps
npm run dev
```

Aplicação: [http://localhost:3000](http://localhost:3000)

## Scripts Disponiveis

| Script  | Descrição                                |
| ------- | ---------------------------------------- |
| `dev`   | Ambiente de desenvolvimento (Turbopack). |
| `build` | Build de produção.                       |
| `start` | Servir build.                            |
| `lint`  | Executa ESLint.                          |

## Variaveis de Ambiente

Arquivo `.env` (exemplo):

```env
NEXTAUTH_URL=http://localhost:3000
NEXTAUTH_SECRET=uma_chave_segura
EMAILJS_PUBLIC_KEY=xxxx
EMAILJS_SERVICE_ID=xxxx
EMAILJS_TEMPLATE_ID=xxxx
GOOGLE_API_KEY=xxxx
```

Use `.env.local` para desenvolvimento e nunca versione chaves sensíveis.

## Padroes e Convencoes

* Componentização orientada a composição.
* Pastas por domínio de rota (App Router) ou reutilização (UI).
* Função `cn()` em `lib/utils.ts` para merge de classes.
* Tipagem estrita e sem uso de `any` não justificado.
* Responsividade mobile-first.

## UI / Design System

* Tailwind + utilidades (`tailwind-merge`, `class-variance-authority`).
* Radix primitives encapsuladas (acessibilidade).
* Temas via `ThemeContext` (`data-theme` no elemento `<html>`).
* Ícones com `lucide-react`.

## Autenticacao e Sessao

* `NextAuthProvider` (wrapper `SessionProvider`).
* Expansível para provedores OAuth e callbacks customizados.
* Tipos estendidos em `types/next-auth.d.ts` (quando necessário).

## Contextos Globais

| Contexto           | Arquivo                               | Descrição                                      |
| ------------------ | ------------------------------------- | ---------------------------------------------- |
| ThemeContext       | `src/contexts/ThemeContext.tsx`       | Tema claro/escuro + persistência localStorage. |
| ProfileIconContext | `src/contexts/ProfileIconContext.tsx` | Estado do ícone/letra do perfil.               |

## Qualidade de Codigo

* ESLint (`eslint-config-next`).
* TypeScript estrito.
* Próximos passos: adicionar testes (Vitest/Jest) + pipeline CI.

## Roadmap / Proximos Passos

*

## Deploy no Vercel

O deploy de produção é feito de forma automática através da \*\*branch \*\*\`\` hospedada no Vercel.

### Passo a passo:

1. Crie uma conta no [Vercel](https://vercel.com/) e conecte-a ao GitHub.
2. Importe o repositório **SimulaVest-Front** da organização.
3. Nas configurações iniciais do projeto no Vercel:

   * **Framework Preset**: `Next.js` (detectado automaticamente).
   * **Production Branch**: `ong-site`.
   * **Build Command**: `next build` (default).
   * **Output Directory**: `.next` (default).
4. Clique em **Deploy**.

Após o deploy:

* Cada \*\*push na branch \*\*\`\` gera automaticamente um novo build em produção.
* Outras branches geram **Preview Deploys** com links únicos para teste.

### Domínio customizado (opcional):

* Vá em **Settings → Domains** no Vercel.
* Adicione o domínio da ONG (ex: `minhaong.org`).
* Configure os registros DNS conforme instruções do Vercel.
* O SSL é habilitado automaticamente (gratuito).

### Fluxo de trabalho:

* Alterações → commit + push na branch `ong-site` → deploy automático em produção ✅

## Contribuindo (Uso Interno)

Fluxo padrão interno:

1. Crie uma issue (se não existir) descrevendo objetivo, escopo, critérios de aceite e riscos.
2. Crie branch a partir de `main`. Convenções:

* feat/area-descricao-curta
* fix/area-breve-erro
* chore/infra-ou-build
* refactor/modulo-alvo

3. Commits semanticos (prefixos: feat:, fix:, refactor:, docs:, chore:, test:) evitar mensagens vagas.
4. Abra Pull Request vinculando issue (Closes #ID). Incluir:

* Resumo da mudanca
* Motivacao / contexto
* Screenshots (UI) ou GIF
* Impacto em performance / UX (se houver)
* Passos de teste manual

5. Checklist antes de pedir review:

*

6. Requer 1+ aprovação (ou 2 em mudanças críticas). Merge via squash.

Políticas rápidas:

* Não subir dependências sem justificar segurança/licença.
* Dados sensíveis: usar `.env` local + segredos no provedor.
* Evitar PII em logs.
* Não expor endpoints internos em comentários públicos.

Labels internas: `bug`, `enhancement`, `performance`, `security`, `design`, `blocked`.

## Licenca / Direitos de Uso

Código proprietário © SimulaVest. Todos os direitos reservados. Uso estritamente interno.

Não distribuir, reproduzir ou derivar sem autorização formal. Caso seja necessária liberação externa (ex: snippet em blog), solicitar aprovação ao responsável técnico e jurídico.

## Contato

E-mail: [mailto\:simulavest.contato@gmail.com](mailto:simulavest.contato@gmail.com)
Organização: [https://github.com/SimulaVest-organization](https://github.com/SimulaVest-organization)

---

> Documento interno. Última atualização: 2025-08.
