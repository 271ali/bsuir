import java.util.ArrayList;

public abstract class Chat {
    protected Chat(String name)
    {
        this.name=name;
    }
    ArrayList<Message> messages=new ArrayList<>();
    String name;

    public String getName() {
        return name;
    }
    public ArrayList<Message> getMessages() {
        return messages;
    }
    abstract void checkMembers();
    public void checkMessages()
    {
        for(Message message:messages)
        {
            message.toString();
        }
    }
}
