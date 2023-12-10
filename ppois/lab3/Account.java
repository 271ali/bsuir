import java.util.ArrayList;
import java.util.Objects;
   public class Account {
    String nickname;
    int age;
    Gender gender;
    Access access;
    ArrayList<Post>posts=new ArrayList<>();
    ArrayList<Chat> chats=new ArrayList<>();
    ArrayList<String> subscribers=new ArrayList<String>();
    ArrayList<String> subscriptions=new ArrayList<String>();
    String password;
    Account(String nickname,  int age, Gender gender,String password)
    {
        this.nickname=nickname;
        this.gender=gender;
        this.age=age;
        this.password=password;
        access= Access.freeForAll;
    }
       public String getNickname() {
           return nickname;
       }
       public String getGender(){return gender.getTitle();}
       public int getAge() {
           return age;
       }
       public String getPassword() {
           return password;
       }

       public Access getAccess() {
           return access;
       }

       public ArrayList<Chat> getChats() {
        return chats;
    }

       public ArrayList<String> getSubscribers() {
        return subscribers;
    }

       public ArrayList<String> getSubscriptions() {
        return subscriptions;
    }

       public ArrayList<Post> getPosts() {
        return posts;
    }

    void setAccess(Access access) {
        this.access = access;

    }


}




