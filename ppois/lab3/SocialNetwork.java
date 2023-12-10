import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
public class SocialNetwork {
    private String name;
    private Map<String, Account> Users = new HashMap<String, Account>();
    private ArrayList<Account>users=new ArrayList<>();
    private PasswordCheck passCheck=new PasswordCheck();
    private NicknameCheck nickCheck=new NicknameCheck();
    private UniqCheck uniqCheck=new UniqCheck();

    public SocialNetwork(String name)
    {
        this.name=name;
    }

    public Account logIn(String nickname, int age , Gender gender, String password)
    {
        if(passCheck.check(password)&&nickCheck.check(nickname)&&uniqCheck.check(nickname,users)) {
            Account account=new Account(nickname,age,gender,password);
            Users.put(nickname,account);
            return account;
        }
        return null;
    }
    public Account signIn(String nickname, String password)
    {
        Account account=Users.get(nickname);
        if(account!=null)
        {
            if(account.password.equals(password)) return account;
            else {
                System.out.println("Uncorrect password");
                return null;
            }
        }
        else {
            System.out.println("Uncorrect nickname");
            return null;
        }
    }
    public void deleteAccount(Account account)
    {
        Users.remove(account.nickname);
        account=null;
    }

    public void addPost (Account account, String content)
    {
        Post post=new Post(account.posts.size()+1,content,account.nickname);
        account.posts.add(post);
    }
    public void deletePost(Account account, int postNumber)
    {
        int index=0;
        for(Post post: account.posts) {
            if (post.number == postNumber) {
                index=post.number;
              account.posts.remove(post);
              break;
            }
        }
        for(Post post: account.posts) {
            if (post.number>index) {
                post.number--;
            }
        }
    }
    public void subscribe(Account account, String userNickname)
    {
       Account userAccount=Users.get(userNickname);
       account.subscriptions.add(userNickname);
       userAccount.subscribers.add(account.getNickname());
    }
    public void unsubscribe(Account account, String userNickname)
    {
        Account userAccount=Users.get(userNickname);
        account.subscriptions.remove(userNickname);
        userAccount.subscribers.remove(account.nickname);
    }
    public Chat createGroupChat(Account account, ArrayList<String> members, String name)
    {
        members.add(account.nickname);
        for(Chat chat:account.chats);
        GroupChat groupChat=new GroupChat(name,members);
        for(String memberName:members)
        {
            Account member=Users.get(memberName);
            member.chats.add(groupChat);
        }
        return groupChat;
    }
    public Chat createPersonalChat(Account account, String nickname,String name)
    {
        Account member=Users.get(nickname);
        PersonalChat personalChat=new PersonalChat(account.nickname,nickname,name);
        member.chats.add(personalChat);
        account.chats.add(personalChat);
        return personalChat;
    }

    public void sendMessage(Account account, String content, String chatName)
    {
        for(Chat chat: account.chats) {
            if(chat.name.equals(chatName)) {
                Message message = new Message(chat.messages.size() + 1, content, account.nickname);
                chat.messages.add(message);
            }
        }
        System.out.println("Chat doesn't exist.Try again or create new chat");
    }
    public GroupChat findGroupChat(Account account, String chatName)
    {
        ArrayList<Chat> chats=account.getChats();
        for(Chat chat:chats)
        {
            if(chat.getName().equals(chatName)&&chat.getClass()== GroupChat.class) return (GroupChat) chat;
        }
        return null;
    }
    public PersonalChat findPersonalChat(Account account, String chatName)
    {
        ArrayList<Chat> chats=account.getChats();
        for(Chat chat:chats)
        {
            if(chat.getClass()== PersonalChat.class&&chat.getName().equals(chatName)) return (PersonalChat)chat;
        }
        return null;
    }
    public void addMember(Account account, String chatName, String member)
    {
        for(Chat chat:account.chats)
        {
            if(chat.getClass()== GroupChat.class && chat.name.equals(chatName))
            {

                ((GroupChat) chat).members.add(member);
                return;
            }
        }
    }
    public void deleteMember(Account account, String chatName, String member)
    {
        for(Chat chat:account.chats)
        {
            if(chat.getClass()== GroupChat.class && chat.name.equals(chatName))
            {
                ((GroupChat) chat).members.remove(member);
                return;
            }
        }
    }

    public void like(Account account, String nickname, int id)
    {
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id);
        Like like=new Like(account.getNickname());
        post.likes.add(like);
    }
   public void comment(Account account, String nickname, int id, String content)
    {
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id);
        Message comment=new Message(post.getComments().size()+1,content,account.getNickname());
        post.comments.add(comment);
    }
    public void changeAccess(Account account, Access access)
    {
        account.setAccess(access);
    }
    Post findPost(String nickname, int id)
    {
        Account account=Users.get(nickname);
        ArrayList<Post>posts=account.getPosts();
        for(Post post:posts)
        {
            if(post.getNumber()==id)
            {
                return post;
            }
        }
        return null;
    }

    public String getName() {
        return name;
    }

    Map<String, Account> getUsers() {
        return Users;
    }
}
