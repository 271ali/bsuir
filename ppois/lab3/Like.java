public class Like {
    Like(String nickname)
    {
        author=nickname;
    }
    private String author;
    @Override public String toString(){
        return "like from "+ author;
    }
    public String getAuthor()
    {
        return author;
    }

}
