package org.example.SocialNetwork;

import java.util.*;

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

    public Account logIn(String nickname, int age , Gender gender, String password)
    {
        try {
        if (!passCheck.check(password) || !nickCheck.check(nickname) || !uniqCheck.check(nickname, Users)) {
            throw new Exception("Wrong data");
        }
       } catch (Exception ex) {
        System.out.println("Wrong data for Log In");
        throw new RuntimeException(ex);
      }
        Account account=new Account(nickname,age,gender,password);
        Users.put(nickname,account);
        return account;
    }
    public Account signIn(String nickname, String password)
    {
        Account account=Users.get(nickname);
            try {
                if (account==null||!Objects.equals(account.getPassword(), password)) {
                    throw new Exception("Wrong data");
                }
            } catch (Exception ex) {
                System.out.println("Wrong data for Sign In");
                throw new RuntimeException(ex);
            }
            return account;
    }
    public void deleteAccount(Account account)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Users.remove(account.getNickname());
        account=null;
    }

    public void addPost (Account account, String content)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Post post=new Post(account.getPosts().size()+1,content,account.getNickname());
        account.getPosts().add(post);
    }
    public void deletePost(Account account, int postNumber)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        int index=0;
        for(Post post: account.getPosts()) {
            if (post.getNumber() == postNumber) {
                index=post.getNumber();
              account.getPosts().remove(post);
              break;
            }
        }
        for(Post post: account.getPosts()) {
            if (post.getNumber()>index) {
                int number=post.getNumber();
                number--;
                post.setNumber(number);
            }
        }
    }
    public void subscribe(Account account, String userNickname)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
       Account userAccount=Users.get(userNickname);
       account.getSubscriptions().add(userNickname);
       userAccount.getSubscribers().add(account.getNickname());
    }
    public void unsubscribe(Account account, String userNickname)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Account userAccount=Users.get(userNickname);
        account.getSubscriptions().remove(userNickname);
        userAccount.getSubscribers().remove(account.getNickname());
    }
    public Chat createGroupChat(Account account, ArrayList<String> members, String name)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        members.add(account.getNickname());
        for(Chat chat:account.getChats());
        GroupChat groupChat=new GroupChat(name,members);
        for(String memberName:members)
        {
            Account member=Users.get(memberName);
            member.getChats().add(groupChat);
        }
        return groupChat;
    }
    public Chat createPersonalChat(Account account, String nickname, String name)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Account member=Users.get(nickname);
        PersonalChat personalChat=new PersonalChat(account.getNickname(),nickname,name);
        member.getChats().add(personalChat);
        account.getChats().add(personalChat);
        return personalChat;
    }

    public void sendMessage(Account account, String content, String chatName)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        for(Chat chat: account.getChats()) {
            if(chat.getName().equals(chatName)) {
                Message message = new Message(chat.getMessages().size() + 1, content, account.getNickname());
                chat.getMessages().add(message);
            }
        }
        System.out.println("Chat doesn't exist.Try again or create new chat");
    }
    public GroupChat findGroupChat(Account account, String chatName)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
            List<Chat> chats = account.getChats();
            Optional<GroupChat> answer=Optional.ofNullable(null);
            for (Chat chat : chats) {
                if (chat.getName().equals(chatName) && chat.getClass() == GroupChat.class) {
                    answer=Optional.of((GroupChat) chat);
                }
            }
            try
            {
                if(answer.isEmpty()) throw new Exception("Chat doesn't exist");
            }catch (Exception ex)
            {
            System.out.println("Chat with the same name doesn't exist");
                throw new RuntimeException(ex);
            }

           return answer.get();
    }
    public PersonalChat findPersonalChat(Account account, String chatName)
    {

        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        List<Chat> chats = account.getChats();
        Optional<PersonalChat> answer=Optional.ofNullable(null);
        for (Chat chat : chats) {
            if (chat.getName().equals(chatName) && chat.getClass() == PersonalChat.class) {
                answer=Optional.of((PersonalChat) chat);
            }
        }
        try
        {
            if(answer.isEmpty()) throw new Exception("Chat doesn't exist");
        }catch (Exception ex)
        {
            System.out.println("Chat with the same name doesn't exist");
            throw new RuntimeException(ex);
        }

        return answer.get();
    }
    public void addMember(Account account, String chatName, String member)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        for(Chat chat:account.getChats())
        {
            if(chat.getClass()== GroupChat.class && chat.getName().equals(chatName))
            {

                ((GroupChat) chat).getMembers().add(member);
                return;
            }
        }
    }
    public void deleteMember(Account account, String chatName, String member)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        for(Chat chat:account.getChats())
        {
            if(chat.getClass()== GroupChat.class && chat.getName().equals(chatName))
            {
                ((GroupChat) chat).getMembers().remove(member);
                return;
            }
        }
    }

    public void like(Account account, String nickname, int id)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id);
        Like like=new Like(account.getNickname());
        post.getLikes().add(like);
    }
   public void comment(Account account, String nickname, int id, String content)
    {
        if (account == null) {
            throw new RuntimeException("Wrong data");
        }
        Account user=Users.get(nickname);
        Post post=findPost(nickname,id);
        Message comment=new Message(post.getComments().size()+1,content,account.getNickname());
        post.getComments().add(comment);
    }
    public void changeAccess(Account account, Access access)
    {
            if (account == null) {
                throw new RuntimeException("Wrong data");
            }

        account.setAccess(access);
    }
    public Post findPost(String nickname, int id)
    {
        Account account=Users.get(nickname);
        List<Post>posts=account.getPosts();
        Optional<Post> answer=Optional.ofNullable(null);
        for(Post post:posts)
        {
            if(post.getNumber()==id)
            {
                answer=Optional.ofNullable(post);
            }
        }
        try
        {
            if(answer.isEmpty()) throw new Exception("Post doesn't exist");
        }catch (Exception ex)
        {
            System.out.println("Post doesn't exist");
            throw new RuntimeException(ex);
        }

        return answer.get();
    }
    public Account findById(String nick) {
        Optional<Account> answer;
        try {
            if (Users.get(nick) == null)throw new Exception("Account doesn't exist");
        }catch (Exception ex)
        {
            System.out.println("Account doesn't exist");
            throw new RuntimeException(ex);
        }
        return Users.get(nick);
    }
    public String getName() {
        return name;
    }

    public Map<String, Account> getUsers() {
        return Users;
    }
}
