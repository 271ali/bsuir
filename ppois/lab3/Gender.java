public enum Gender {
    female("female"),
    male("male");
    private String title;

    Gender(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}
