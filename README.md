#  Sistema de Elegibilidade para Concurso Público (Linguagem C)

Este repositório contém o projeto prático desenvolvido para a atividade extra da disciplina de **Bases de Programação** do curso de **Ciência da Computação**.

O projeto consiste em um módulo de validação de elegibilidade de candidatos para um concurso público, aplicando conceitos fundamentais de lógica de programação, modularização, validação rigorosa de dados de entrada e automação de compilação/testes em C (padrão C99).

---

##  Requisitos do Enunciado e Lógica de Negócio

O candidato é considerado **APTO** a participar do concurso se, e somente se, atender a ambas as condições:
1. **Idade mínima:** $\ge 18$ anos (definida via constante predefinida);
2. **Escolaridade:** Possuir Ensino Médio completo (sinalizado pelo flag `1`).

### Regra de Validação
```c
idade >= IDADE_MINIMA && ensino_medio_completo == 1