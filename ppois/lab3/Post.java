import java.util.ArrayList;

   public class Post {

    Post(int number,String content,String author)
    {
        this.number=number;
        this.content=content;
        this.author=author;
    }
    String content;
    String author;
    int number;
    ArrayList<Like> likes=new ArrayList<>();
    ArrayList<Message> comments=new ArrayList<>();

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
    public ArrayList<Like> getLikes() {
        return likes;
    }
    public ArrayList<Message> getComments() {
        return comments;
    }
    public int getNumber() {
        return number;
    }
    public String getAuthor() {
        return author;
    }

   }
