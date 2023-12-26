package org.example.SocialNetwork;



import java.util.ArrayList;
import java.util.List;

public abstract class Chat {
    protected Chat(String name)
    {
        this.name=name;
    }
    private List<Message> messages=new ArrayList<>();
    private  String name;

    public String getName() {
        return name;
    }
    public List<Message> getMessages() {
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
