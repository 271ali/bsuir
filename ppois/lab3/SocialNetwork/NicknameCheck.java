package org.example.SocialNetwork;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class NicknameCheck {
    public boolean check(String nickname)
    {
        String regex = "^[a-zA-Z0-9_.]{6,30}$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(nickname);
        if(matcher.matches())
        {
            System.out.println("password is correct\n");
            return true;
        }
        else
        {
            System.out.println("password is uncorrect\ntry again");
            return false;
        }
    }

}

