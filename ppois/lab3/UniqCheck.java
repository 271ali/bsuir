import java.util.ArrayList;

public class UniqCheck {
    public boolean check(String nickname,ArrayList <Account> base)
    {
        for(Account account:base)
        {
            if(account.getNickname().equals(nickname))
            {
                System.out.println("Данное имя пользователя уже занято");
                return false;
            }
        }
        return true;
    }

}
