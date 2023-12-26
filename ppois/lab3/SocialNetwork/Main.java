package org.example.SocialNetwork;

public class Main {
    public static void main(String[] args) {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Account myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Account myAccount2=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
    }
}
