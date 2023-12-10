import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PasswordCheck {
    boolean check(String password)
    {
        String regex = "((?=.*\\d+)(?=.*[a-z])(?=.*[A-Z])(?=.*[_]).{6,15})$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(password);
        if(matcher.matches())
        {
            System.out.println("password is correct\n");
            return true;
        }
        else {
            System.out.println("password is uncorrect\ntry again");
            return false;
        }
    }

}
