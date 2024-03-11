package org.example.SocialNetwork;

public enum Access {
    freeForAll("общедоступный"),
    forSubscribers("ограниченный доступ");
    private String title;

    Access(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

