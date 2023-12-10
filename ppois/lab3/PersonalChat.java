public class PersonalChat extends Chat {
    public PersonalChat(String firstMember,String secondMember,String name)
    {
        super(name);
        this.firstMember=firstMember;
        this.secondMember=secondMember;
    }
    String firstMember;
    String secondMember;

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