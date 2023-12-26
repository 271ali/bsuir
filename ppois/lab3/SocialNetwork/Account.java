package org.example.SocialNetwork;

import java.util.ArrayList;
import java.util.List;

public class Account{
       private String nickname;
       private int age;
       private Gender gender;
       private Access access;
       private List<Post> posts=new ArrayList<>();
       private List<Chat> chats=new ArrayList<>();
       private List<String> subscribers=new ArrayList<String>();
       private List<String> subscriptions=new ArrayList<String>();
       private String password;
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

       public List<Chat> getChats() {
        return chats;
    }

       public List<String> getSubscribers() {
        return subscribers;
    }

       public List<String> getSubscriptions() {
        return subscriptions;
    }

       public List<Post> getPosts() {
        return posts;
    }


       void setAccess(Access access) {
        this.access = access;

    }


}




