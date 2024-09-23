package uminho.dss.turmas3l.data;

import uminho.dss.turmas3l.business.Sala;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class SalaDAO implements Map<String, Sala> {
    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean containsKey(Object key) {
        return false;
    }

    @Override
    public boolean containsValue(Object value) {
        return false;
    }

    @Override
    public Sala get(Object key) {
        return null;
    }

    @Override
    public Sala put(String key, Sala value) {
        return null;
    }

    @Override
    public Sala remove(Object key) {
        return null;
    }

    @Override
    public void putAll(Map<? extends String, ? extends Sala> m) {

    }

    @Override
    public void clear() {

    }

    @Override
    public Set<String> keySet() {
        return Set.of();
    }

    @Override
    public Collection<Sala> values() {
        return List.of();
    }

    @Override
    public Set<Entry<String, Sala>> entrySet() {
        return Set.of();
    }
}
