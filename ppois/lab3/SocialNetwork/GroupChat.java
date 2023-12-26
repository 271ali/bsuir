package org.example.SocialNetwork;

import java.util.ArrayList;
import java.util.List;

public class GroupChat extends Chat {
    public GroupChat(String name, ArrayList<String> members)
    {
        super(name);
        this.members=members;
    }
     private List<String> members;
    public List<String> getMembers()
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
