import java.util.ArrayList;

 public class GroupChat extends Chat {
    public GroupChat(String name, ArrayList<String> members)
    {
        super(name);
        this.members=members;
    }
    ArrayList<String> members;
    public ArrayList<String> getMembers()
    {
        return members;
    }

    @Override
    void checkMembers() {
        for(String member:members)
        {
            System.out.println(member+"\n");
        }
    }
}
