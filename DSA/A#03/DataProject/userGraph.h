#pragma once
#include"StackandQueue.h"
struct FollowerNode
{
    string username;
    string status;
    FollowerNode* next;

    FollowerNode(string uname)
    {
        username = uname;
        status = "active";
        next = nullptr;
    }
};

class UserProfile
{
public:
    string name;
    string password;
    string city;
    Queue followRequests;
    Queue messages;
    Queue notifications;
    FollowerNode* followerList;
    FollowerNode* friendsList;
    UserProfile* next;
    Stack* posts;

    UserProfile(string uname, string pwd, string cityName)
    {
        name = uname;
        password = pwd;
        city = cityName;
        followerList = nullptr;
        friendsList = nullptr;
        posts = new Stack();
    }
    void addNotification(string notification);
    void receiveMessage(string sender, string message);
    void viewNotifications();
    void viewMessages();
    void addPost(string postContent);
    void showPosts();
    void addFollower(string followerName);
    void addFriend(string friendName);
    void displayFollowers();
    void displayFriends();
};

class UserGraph
{
    UserProfile* head;
    UserProfile* currentUser;

    UserProfile* findUser(UserProfile* root, string username);

public:
    UserGraph()
    {
        head = nullptr;
        currentUser = nullptr;
    }

    void signup(string username, string password, string city);
    bool login(string username, string password);
    void logout();
    void sendFollowRequest(string sender, string receiver);
    void acceptFollowRequest(string username);
    void addFriend(string user1, string user2);
    void displayUserFollowers(string username);
    void displayUserFriends(string username);
    void displayGraph();
    void addPost(string postContent);
    void showPosts();
    void showNewsFeed();
    void sendMessage(string receiver, string message);
    void viewNotifications();
    void viewMessages();
    void blockFriend(string user1, string user2);
    void unblockFriend(string user1, string user2);
};
