package org.example.SocialNetwork;

public class PersonalChat extends Chat {
    public PersonalChat(String firstMember,String secondMember,String name)
    {
        super(name);
        this.firstMember=firstMember;
        this.secondMember=secondMember;
    }
    private String firstMember;
    private String secondMember;

    public String getFirstMember() {
        return firstMember;
    }

    public String getSecondMember() {
        return secondMember;
    }

    @Override
    void checkMembers() {
        System.out.println(secondMember);
    }
}