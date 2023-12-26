package org.example.SocialNetwork;

import java.util.ArrayList;
import java.util.List;

public class Post {

    public Post(int number, String content, String author)
    {
        this.number=number;
        this.content=content;
        this.author=author;
    }
       private String content;
       private String author;
       private  int number;
       private List<Like> likes=new ArrayList<>();
       private List<Message> comments=new ArrayList<>();

    @Override public String toString(){
        return "Post №"+ number+" "+content+
                "Author:"+author+
                "Likes:" + likes.size()+
                "Comments:"+comments.size();
    }
    public void statistics()
    {
        System.out.println("Likes");
        for(Like like:likes)
        {
            like.toString();
        }
        System.out.println("Comments");
        for(Message comment:comments)
        {
            comment.toString();
        }
    }
    public String getContent() {
           return content;
       }
    public List<Like> getLikes() {
        return likes;
    }
    public List<Message> getComments() {
        return comments;
    }
    public int getNumber() {
        return number;
    }
    public String getAuthor() {
        return author;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}
