package app;

import activities.Atividade;
import users.Utilizador;

import java.util.HashMap;
import java.util.Map;

public class Fitness {
    Map<String, Atividade> atividadeMap;
    Map<String, Utilizador> utilizadorMap;

    public Fitness(){
        this.atividadeMap = new HashMap<>();
        this.utilizadorMap = new HashMap<>();
    }

    public boolean existeutilizador(){

    }
}
