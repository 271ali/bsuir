package org.example.SocialNetwork;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Optional;
public class SocialNetwork {
    private String name;
    private Map<String, Account> Users = new HashMap<String, Account>();

    private PasswordCheck passCheck=new PasswordCheck();
    private NicknameCheck nickCheck=new NicknameCheck();
    private UniqCheck uniqCheck=new UniqCheck();
    public SocialNetwork(String name)
    {
        this.name=name;
    }

    public Optional<Account> logIn(String nickname, int age , Gender gender, String password)
    {
        if(passCheck.check(password)&&nickCheck.check(nickname)&&uniqCheck.check(nickname,Users)) {
            Account account=new Account(nickname,age,gender,password);
            Users.put(nickname,account);
            return Optional.of(account);
        }
        else
            return Optional.empty();
    }
    public Optional<Account> signIn(String nickname, String password)
    {
        Account account=Users.get(nickname);
        if(account!=null)
        {
            if(account.getPassword().equals(password))return Optional.of(account);
            else {
                System.out.println("Uncorrect password");
                return Optional.empty();
            }
        }
        else {
            System.out.println("Uncorrect nickname");
            return Optional.empty();
        }
    }
    public void deleteAccount(Optional<Account> account)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Users.remove(account.get().getNickname());
        account=null;
    }

    public void addPost (Optional<Account> account, String content)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Post post=new Post(account.get().getPosts().size()+1,content,account.get().getNickname());
        account.get().getPosts().add(post);
    }
    public void deletePost(Optional<Account> account, int postNumber)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        int index=0;
        for(Post post: account.get().getPosts()) {
            if (post.getNumber() == postNumber) {
                index=post.getNumber();
              account.get().getPosts().remove(post);
              break;
            }
        }
        for(Post post: account.get().getPosts()) {
            if (post.getNumber()>index) {
                int number=post.getNumber();
                number--;
                post.setNumber(number);
            }
        }
    }
    public void subscribe(Optional<Account> account, String userNickname)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
       Account userAccount=Users.get(userNickname);
       account.get().getSubscriptions().add(userNickname);
       userAccount.getSubscribers().add(account.get().getNickname());
    }
    public void unsubscribe(Optional<Account> account, String userNickname)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Account userAccount=Users.get(userNickname);
        account.get().getSubscriptions().remove(userNickname);
        userAccount.getSubscribers().remove(account.get().getNickname());
    }
    public Chat createGroupChat(Optional<Account> account, ArrayList<String> members, String name)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        members.add(account.get().getNickname());
        for(Chat chat:account.get().getChats());
        GroupChat groupChat=new GroupChat(name,members);
        for(String memberName:members)
        {
            Account member=Users.get(memberName);
            member.getChats().add(groupChat);
        }
        return groupChat;
    }
    public Chat createPersonalChat(Optional<Account> account, String nickname, String name)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Account member=Users.get(nickname);
        PersonalChat personalChat=new PersonalChat(account.get().getNickname(),nickname,name);
        member.getChats().add(personalChat);
        account.get().getChats().add(personalChat);
        return personalChat;
    }

    public void sendMessage(Optional<Account> account, String content, String chatName)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        for(Chat chat: account.get().getChats()) {
            if(chat.getName().equals(chatName)) {
                Message message = new Message(chat.getMessages().size() + 1, content, account.get().getNickname());
                chat.getMessages().add(message);
            }
        }
        System.out.println("Chat doesn't exist.Try again or create new chat");
    }
    public Optional<GroupChat> findGroupChat(Optional<Account> account, String chatName)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        List<Chat> chats=account.get().getChats();
        for(Chat chat:chats)
        {
            if(chat.getName().equals(chatName)&&chat.getClass()== GroupChat.class) return Optional.of((GroupChat)chat);
        }
        return Optional.empty();
    }
    public Optional<PersonalChat> findPersonalChat(Optional<Account> account, String chatName)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        List<Chat> chats=account.get().getChats();
        for(Chat chat:chats)
        {
            if(chat.getClass()== PersonalChat.class&&chat.getName().equals(chatName)) return Optional.of((PersonalChat)chat);
        }
        return Optional.empty();
    }
    public void addMember(Optional<Account> account, String chatName, String member)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        for(Chat chat:account.get().getChats())
        {
            if(chat.getClass()== GroupChat.class && chat.getName().equals(chatName))
            {

                ((GroupChat) chat).getMembers().add(member);
                return;
            }
        }
    }
    public void deleteMember(Optional<Account> account, String chatName, String member)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        for(Chat chat:account.get().getChats())
        {
            if(chat.getClass()== GroupChat.class && chat.getName().equals(chatName))
            {
                ((GroupChat) chat).getMembers().remove(member);
                return;
            }
        }
    }

    public void like(Optional<Account> account, String nickname, int id)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id).get();
        Like like=new Like(account.get().getNickname());
        post.getLikes().add(like);
    }
   public void comment(Optional<Account> account, String nickname, int id, String content)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id).get();
        Message comment=new Message(post.getComments().size()+1,content,account.get().getNickname());
        post.getComments().add(comment);
    }
    public void changeAccess(Optional<Account> account, Access access)throws IllegalArgumentException
    {
        if (!account.isPresent()) {
            throw new IllegalArgumentException("Пустой аккаунт");
        }
        account.get().setAccess(access);
    }
    public Optional<Post> findPost(String nickname, int id)
    {
        Account account=Users.get(nickname);
        List<Post>posts=account.getPosts();
        for(Post post:posts)
        {
            if(post.getNumber()==id)
            {
                return Optional.of(post);
            }
        }
        return Optional.empty();
    }
    public Optional<Account> findById(String nick) {
        return Optional.ofNullable(Users.get(nick));
    }
    public String getName() {
        return name;
    }

    public Map<String, Account> getUsers() {
        return Users;
    }
}
