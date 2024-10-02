package uminho.dss.turmas3l.data;

import uminho.dss.turmas3l.business.Aluno;
import uminho.dss.turmas3l.business.Sala;

import java.sql.*;
import java.util.*;

public class SalaDAO implements Map<String, Sala> {
    private static SalaDAO singleton = null;

    private SalaDAO() {
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stmt = conn.createStatement()) {
            String sql = "CREATE TABLE IF NOT EXISTS salas (" +
                    "Num varchar(10) NOT NULL PRIMARY KEY," +
                    "Edificio varchar(45) DEFAULT NULL," +
                    "Capacidade int(4) DEFAULT 0)";
            stmt.executeUpdate(sql);
            sql = "CREATE TABLE IF NOT EXISTS turmas (" +
                    "Id varchar(10) NOT NULL PRIMARY KEY," +
                    "Sala varchar(10) DEFAULT NULL," +
                    "foreign key(Sala) references salas(Num))";
            stmt.executeUpdate(sql);
            sql = "CREATE TABLE IF NOT EXISTS alunos (" +
                    "Num varchar(10) NOT NULL PRIMARY KEY," +
                    "Nome varchar(45) DEFAULT NULL," +
                    "Email varchar(45) DEFAULT NULL," +
                    "Turma varchar(10), foreign key(Turma) references turmas(Id))";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            // Erro a criar tabela...
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
    }

    public static SalaDAO getInstance() {
        if (singleton == null) {
            singleton = new SalaDAO();
        }
        return singleton;
    }

    @Override
    public int size() {
        int i = 0;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT COUNT(*) FROM salas")) {
            if (rs.next()) {
                i = rs.getInt(1);
            }
        } catch (SQLException e) {
            // Erro a criar tabela...
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return i;
    }

    @Override
    public boolean isEmpty() {
        return this.size() == 0;
    }

    @Override
    public boolean containsKey(Object key) {
        boolean r;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL,DAOconfig.USERNAME,DAOconfig.PASSWORD);
            PreparedStatement pstm = conn.prepareStatement("SELECT Num FROM salas WHERE Num=?")) {

            pstm.setString(1, key.toString());
            try (ResultSet rs = pstm.executeQuery()) {
                r = rs.next();
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return r;
    }

    @Override
    public boolean containsValue(Object value) {
        Sala s = (Sala) value;
        return this.containsValue(s.getNumero());
    }

    @Override
    public Sala get(Object key) {
        Sala s = null;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
            PreparedStatement pstm = conn.prepareStatement("SELECT * FROM salas WHERE Num=?")) {
            pstm.setString(1, key.toString());
            try (ResultSet rs = pstm.executeQuery()){
                if(rs.next()) {
                    s = new Sala(rs.getString("Num"), rs.getString("Edificio"), rs.getInt("Capacidade"));
                }
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return s;
    }

    @Override
    public Sala put(String key, Sala value) {
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement()) {
            stm.executeUpdate("INSERT INTO salas (Num,Edificio,Capacidade) VALUES (" + value.getNumero() + ", '" + value.getEdificio() + "','" + value.getCapacidade() + "') " + "ON DUPLICATE KEY UPDATE Num=Num");
            //TODO MUDAR ISTO
            return value;
        } catch (SQLException e){
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
    }

    @Override
    public Sala remove(Object key) {
        Sala s = this.get(key);
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL,DAOconfig.USERNAME,DAOconfig.PASSWORD);
            PreparedStatement pstm = conn.prepareStatement("DELETE FROM salas WHERE Num=?")) {
            pstm.setNull(1, Types.VARCHAR);
            pstm.executeUpdate();
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return s;
    }

    @Override
    public void putAll(Map<? extends String, ? extends Sala> salas) {
        for(Sala t : salas.values()) {
            this.put(t.getNumero(), t);
        }
    }

    @Override
    public void clear() {
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement()) {
            stm.executeUpdate("TRUNCATE salas");
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
    }

    @Override
    public Set<String> keySet() {
        throw new NullPointerException("Not implemented!");
    }

    @Override
    public Collection<Sala> values() {
        Collection<Sala> res = new HashSet<>();
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement();
             ResultSet rs = stm.executeQuery("SELECT Num FROM salas")) { // ResultSet com os ids de todas as turmas
            while (rs.next()) {
                String idt = rs.getString("Num"); // Obtemos um id de turma do ResultSet
                Sala t = this.get(idt);                    // Utilizamos o get para construir as turmas uma a uma
                res.add(t);                                 // Adiciona a turma ao resultado.
            }
        } catch (Exception e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return res;
    }

    @Override
    public Set<Entry<String, Sala>> entrySet() {
        throw new NullPointerException("public Set<Map.Entry<String,Aluno>> entrySet() not implemented!");
    }
}
