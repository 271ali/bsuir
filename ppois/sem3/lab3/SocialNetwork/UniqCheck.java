package org.example.SocialNetwork;


import java.util.Map;
import java.util.Set;

public class UniqCheck {
    public boolean check(String nickname, Map<String, Account> base)
    {
        Set<String> keys=base.keySet();
        for(String nick:keys)
        {
            if(nick.equals(nickname))
            {
                System.out.println("Данное имя пользователя уже занято");
                return false;
            }
        }
        return true;
    }

}
