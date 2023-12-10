public class Message {
    public Message(int id,String content, String author) {
        this.id=id;
        this.content=content;
        this.author=author;
    }
    private int id;
    private String content;
    private String author;
    public String getContent()
    {
        return content;
    }
    public String getAuthor()
    {
        return author;
    }
    public int getId() {
        return id;
    }

    @Override public String toString(){
        return "from "+ author+" : "+content;
    }

}
