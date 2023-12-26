
import org.example.SocialNetwork.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Optional;


public class SocialNetworkTest {
    boolean postCompare(Post expected, Post result)
    {
        if(expected.getNumber()==result.getNumber())
        {
            if(expected.getContent()==result.getContent())
            {
                if(expected.getAuthor()==result.getAuthor())
                {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
boolean postsCompare(List<Post> expected, List<Post> result)
{
    if(expected.size()!= result.size()) {return false;}
        for(int i=0;i<expected.size();i++) {
            if(postCompare(expected.get(i),result.get(i))) continue;
            else return false;
        }
        return true;
}
    boolean usersCompare(List<String> expected,List<String> result)
    {
        if(expected.size()!= result.size()) {return false;}
        for(int i=0;i<expected.size();i++)
        {
            if(expected.get(i)==result.get(i))
            {
               continue;
            }
            else return false;
        }
        return true;
    }
    boolean messagesCompare(List<Message> expected, List<Message> result)
    {
        if(expected.size()!= result.size()) {return false;}
        for(int i=0;i<expected.size();i++)
        {
            if(expected.get(i).getAuthor()==result.get(i).getAuthor())
            {
                if(expected.get(i).getContent()==result.get(i).getContent())
                {
                    if(expected.get(i).getId()==result.get(i).getId())
                    {
                        continue;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        return true;
    }
    boolean groupChatCompare(GroupChat expected , GroupChat result)
    {
            if(usersCompare(expected.getMembers(),result.getMembers()))
            {
                if(expected.getName().equals(result.getName()))
                {
                    if(messagesCompare(expected.getMessages(),result.getMessages()))
                    {
                        return true;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;

    }
    boolean personalChatCompare(PersonalChat expected , PersonalChat result)
    {
        if(expected.getFirstMember().equals(result.getFirstMember()))
        {
            if(expected.getSecondMember().equals(result.getSecondMember())) {
                if (expected.getName().equals(result.getName())) {
                    if (messagesCompare(expected.getMessages(), result.getMessages())) {
                        return true;
                    } else return false;
                } else return false;
            }else return false;
        } else return false;

    }
    boolean chatsCompare(List<Chat> expected, List<Chat> result) {
        if (expected.size() != result.size()) {
            return false;
        }
        for (int i = 0; i < expected.size(); i++) {
            if (expected.get(i).getClass() == GroupChat.class && expected.get(i).getClass() == GroupChat.class) {
                if (groupChatCompare((GroupChat) expected.get(i), (GroupChat) result.get(i))) {
                    continue;
                } else {
                    return false;
                }
            }
            if (expected.get(i).getClass() == PersonalChat.class && expected.get(i).getClass() == PersonalChat.class) {
                if (personalChatCompare((PersonalChat) expected.get(i), (PersonalChat) result.get(i))) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    @Test
    void nicknameCheck()
    {
        String str="12a";
        NicknameCheck object=new NicknameCheck();
        assertEquals(object.check(str),false);

    }
    @Test
    void passwordCheck()
    {
        String str="12ahh_";
        PasswordCheck object=new PasswordCheck();
        assertEquals(object.check(str),false);

    }
    @Test
    void uniqCheck()
    {
        SocialNetwork sn=new SocialNetwork("sn");
        sn.logIn("aaa111__A",33, Gender.male," ");
        sn.logIn("gg2345J_",13, Gender.female," ");
        sn.logIn("boB4000_000",21, Gender.male," ");
        String nickname4="dima_Fufel5678";
        UniqCheck object=new UniqCheck();
        Assertions.assertEquals(object.check(nickname4,sn.getUsers()),true);

    }

    @Test
    void logIn()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Map<String, Account>users =sn.getUsers();
        assertEquals(myAccount.get(),users.get("alibaba"));
    }
    @Test
    void signIn()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.signIn("alibaba","12345aBc_");
        assertEquals(myAccount2,myAccount1);
    }
    @Test
    void deleteAccount()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        sn.deleteAccount(myAccount);
        Map<String, Account>users =sn.getUsers();
        users.get("alibaba");
        assertEquals(users.get("alibaba"),null);
    }
    @Test
    void addPost()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        sn.addPost(myAccount,"hello");
        Post post=new Post(1,"hello","alibaba");
        List<Post> posts=new ArrayList<>();
        posts.add(post);
        assertTrue(postsCompare(myAccount.get().getPosts(),posts));
    }
    @Test
    void deletePost()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        sn.addPost(myAccount,"hello");
        sn.addPost(myAccount,"bye");
        sn.deletePost(myAccount,1);
        Post post=new Post(1,"bye","alibaba");
        List<Post> posts=new ArrayList<>();
        posts.add(post);
        assertTrue(postsCompare(myAccount.get().getPosts(),posts));
    }
    @Test
    void subscribe()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.subscribe(myAccount1,"oppenheimer");
        ArrayList<String> subscribers=new ArrayList<String>();
        subscribers.add("alibaba");
        assertTrue(usersCompare(myAccount2.get().getSubscribers(),subscribers));
    }
    @Test
    void unsubscribe()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        Optional<Account> myAccount3=sn.logIn("peterParker",16, Gender.male,"Peter2288_");
        sn.subscribe(myAccount1,"oppenheimer");
        sn.subscribe(myAccount1,"peterParker");
        sn.unsubscribe(myAccount1,"oppenheimer");
        ArrayList<String> subscriptions=new ArrayList<String>();
        subscriptions.add("peterParker");
        assertTrue(usersCompare(myAccount1.get().getSubscriptions(),subscriptions));
    }
    @Test
    void createGroupChat()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        Optional<Account> myAccount3=sn.logIn("peterParker",16, Gender.male,"Peter2288_");
        ArrayList<String> members=new ArrayList<>();
        members.add("alibaba");
        members.add("oppenheimer");
        members.add("peterParker");
        sn.createGroupChat(myAccount1,members,"friends");
        GroupChat chat=new GroupChat("friends",members);
        ArrayList<Chat> chats=new ArrayList<>();
        chats.add(chat);
        assertTrue(chatsCompare(myAccount2.get().getChats(),chats));
    }
    @Test
    void createPersonalChat()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.createPersonalChat(myAccount2,"alibaba","name");
        PersonalChat chat=new PersonalChat("oppenheimer","alibaba","name");
        ArrayList<Chat> chats=new ArrayList<>();
        chats.add(chat);
        assertTrue(chatsCompare(myAccount2.get().getChats(),chats));
    }
    @Test
    void findGroupChat()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        Optional<Account> myAccount3=sn.logIn("peterParker",16, Gender.male,"Peter2288_");
        ArrayList<String> members=new ArrayList<>();
        members.add("alibaba");
        members.add("oppenheimer");
        members.add("peterParker");
        sn.createGroupChat(myAccount1,members,"friends");
        GroupChat chat=new GroupChat("friends",members);
        Optional<GroupChat> result=sn.findGroupChat(myAccount1,"friends");
        assertTrue(groupChatCompare(chat,result.get()));
    }
    @Test
    void findPersonalChat()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.createPersonalChat(myAccount1,"oppenheimer","name");
        PersonalChat chat=new PersonalChat("alibaba","oppenheimer","name");
        Optional<PersonalChat> result=sn.findPersonalChat(myAccount1,"name");
        assertTrue(personalChatCompare(result.get(),chat));
    }
    @Test
    void sendMessage()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.createPersonalChat(myAccount1,"oppenheimer","name");
        sn.sendMessage(myAccount1,"hello","name");
        Optional<PersonalChat> chat=sn.findPersonalChat(myAccount2,"name");
        Message myMessage=new Message(1,"hello","alibaba");
        ArrayList<Message>result=new ArrayList<>();
        result.add(myMessage);
        assertTrue(messagesCompare(chat.get().getMessages(),result));
    }

   @Test
   void addMember()
   {
       SocialNetwork sn=new SocialNetwork("odnoklassniki");
       Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
       Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
       Optional<Account> myAccount3=sn.logIn("peterParker",16, Gender.male,"Peter2288_");
       Optional<Account> myAccount4=sn.logIn("ilonMask",53, Gender.male,"spaceX45_");
       ArrayList<String> members=new ArrayList<>();
       members.add("alibaba");
       members.add("oppenheimer");
       members.add("peterParker");
       sn.createGroupChat(myAccount1,members,"friends");
       sn.addMember(myAccount1,"friends","ilonMask");
       Optional<GroupChat> chat=sn.findGroupChat(myAccount1,"friends");
       members.add("ilonMask");
       assertTrue(usersCompare(chat.get().getMembers(),members));
   }

    @Test
    void deleteMember()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        Optional<Account> myAccount3=sn.logIn("peterParker",16, Gender.male,"Peter2288_");
        Optional<Account> myAccount4=sn.logIn("ilonMask",53, Gender.male,"spaceX45_");
        ArrayList<String> members=new ArrayList<>();
        members.add("alibaba");
        members.add("oppenheimer");
        members.add("peterParker");
        members.add("ilonMask");
        sn.createGroupChat(myAccount1,members,"friends");
        sn.deleteMember(myAccount1,"friends","ilonMask");
        members.remove("ilonMask");
        Optional<GroupChat> chat=sn.findGroupChat(myAccount1,"friends");
        assertTrue(usersCompare(chat.get().getMembers(),members));
    }
    @Test
    void changeAccess()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        sn.changeAccess(myAccount1, Access.forSubscribers);
        assertEquals(myAccount1.get().getAccess(), Access.forSubscribers);
    }
    @Test
    void like()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.addPost(myAccount2,"new post");
        sn.like(myAccount1,"oppenheimer",1);
        Optional<Post> post=sn.findPost("oppenheimer",1);
        assertEquals(1,post.get().getLikes().size());
    }
    @Test
    void comment()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        Optional<Account> myAccount2=sn.logIn("oppenheimer",64, Gender.male,"boomMC2_");
        sn.addPost(myAccount2,"new post");
        sn.comment(myAccount1,"oppenheimer",1,"cool");
        Optional<Post> post=sn.findPost("oppenheimer",1);
        assertEquals(post.get().getComments().size(),1);
    }
    @Test
    void findPost()
    {
        SocialNetwork sn=new SocialNetwork("odnoklassniki");
        Optional<Account> myAccount1=sn.logIn("alibaba",19, Gender.female,"12345aBc_");
        sn.addPost(myAccount1,"new post");
        Optional<Post> post=sn.findPost("alibaba",1);
        Post result=new Post(1,"new post","alibaba");
        assertTrue(postCompare(post.get(),result));

    }

}


