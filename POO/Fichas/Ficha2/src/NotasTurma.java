import java.util.Arrays;

public class NotasTurma {

    public void updateNotas(int aluno, int[][] turma, int[] notas){
        for(int i = 0; i < notas.length; i++){
            turma[aluno-1][i] = notas[i];
        }
    }

    public void printTurma(int[][] turma) {
        for(int i = 0; i < turma.length; i++){
            System.out.printf("Aluno " + (i+1) + ": ");
            System.out.print("[");
            for(int j : turma[i]){
                System.out.printf(" " + j + " ");
            }
            System.out.print("]\n");
        }
        System.out.println();
    }

    public int somaUC(int[][] turma, int uc){
        int res = 0;
        for(int i = 0; i < turma.length; i++){
            res += turma[i][uc-1];
        }
        return res;
    }

    public double mediaAluno(int[][] turma, int aluno){
        double media = 0;
        for(int i : turma[aluno]){
            media += i;
        }
        media /= 5;
        return media;
    }

    public double mediaUc(int[][] turma, int uc){
        double media = 0;
        for(int[] i : turma){
            media += i[uc];
        }
        media /= 5;
        return media;
    }

    public void notasMaisAltas(int[][] turma){
        int[] notas = new int[5];
        for(int i = 0; i < 5; i++){
            int notaMaisAlta = 0;
            for(int[] j : turma){
                if(j[i] > notaMaisAlta) notaMaisAlta = j[i];
            }
            notas[i] = notaMaisAlta;
        }
        System.out.println("Notas mais altas(indice corresponde a uc): " + Arrays.toString(notas));
    }

    public void notasMaisBaixas(int[][] turma){
        int[] notas = new int[5];
        for(int i = 0; i < 5; i++){
            int notaMaisAlta = 5; //escolho 5 como nota mais alta... pode ser Integer.MAX_VALUE
            for(int[] j : turma){
                if(j[i] < notaMaisAlta) notaMaisAlta = j[i];
            }
            notas[i] = notaMaisAlta;
        }
        System.out.println("Notas mais baixas(indice corresponde a uc): " + Arrays.toString(notas));
    }
}
