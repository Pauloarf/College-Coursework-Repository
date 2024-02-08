import javax.swing.text.Utilities;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Fitness  {
    private Map<String,User> usersMap;

    public boolean existUser(String email){

    }

    public Activity moreDemandingActivity(){
        Activity max = null;

        for(User u : usersMap.values()){
            for(Activity a : u.getActivities){
                if(max == null || a.caloricValue(u.getWeight, u.getAge()) > max.caloricValue(u.getWeight, u.getAge)){
                    max = a.clone();
                }
            }
        }
        return max;
    }

    public User mostActiveUser(){
        return usersMap.values().stream().max(Comparator.comparingDouble(User::totalCalorias))
               .map(User::clone).orElse(null);
    }
}
