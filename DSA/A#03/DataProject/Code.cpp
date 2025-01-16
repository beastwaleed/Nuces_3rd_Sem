#include <iostream>
#include <string>
#include "Header.h"
#include <ctime>

using namespace std;

struct Node
{
    string data;
    Node* next;
    date_time obj;
    Node(string d)
    {
        data = d;
        next = nullptr;
        obj.set_date();
    }
};


class Stack
{
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    date_time getTopDateTime() const
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
        }
        return top->obj;
    }

    void push(string data)
    {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }


    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return "";
        }
        Node* temp = top;
        string data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    string peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return "";
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class Queue
{
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string data)
    {
        Node* newNode = new Node(data);
        if (!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }


    string dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return "";
        }
        string data = front->data;
        Node* temp = front;
        front = front->next;
		
        if (!front)
           rear = nullptr;
        delete temp;
        return data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    Node* getFront()
    {
        return front;
    }
};

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
        next = nullptr;
        posts = new Stack();
    }

    void addNotification(string notification)
    {
        notifications.enqueue(notification);
    }

    void receiveMessage(string sender, string message)
    {
        messages.enqueue("From " + sender + ": " + message);
        addNotification("New message received from " + sender);
    }

    void viewNotifications()
    {
        if (notifications.isEmpty())
        {
            cout << "No new notifications for " << name << "." << endl;
            return;
        }
        cout << "Notifications for " << name << ":" << endl;

        while (!notifications.isEmpty())
        {
            Node* temp = notifications.getFront(); // Access the current node
            cout << "- " << temp->data << " ";
            temp->obj.display(); // Display timestamp
            notifications.dequeue(); // Remove the node
        }
    }


    void viewMessages()
    {
        if (messages.isEmpty())
        {
            cout << "No new messages for " << name << "." << endl;
            return;
        }
        cout << "Messages for " << name << ":" << endl;

        while (!messages.isEmpty())
        {
            Node* temp = messages.getFront(); // Access the current node
            cout << "- " << temp->data << " ";
            temp->obj.display(); // Display timestamp
            messages.dequeue(); // Remove the node
        }
    }



    void addPost(string postContent)
    {
        posts->push(postContent);
        cout << "Post added successfully!" << endl;
    }

    void showPosts()
    {
        if (posts->isEmpty())
        {
            cout << "No posts to display for " << name << "." << endl;
            return;
        }

        cout << "Posts by " << name << ":" << endl;
        Stack tempStack;

        while (!posts->isEmpty())
        {
            string postContent = posts->peek(); // Access the top post data
            posts->getTopDateTime().display(); // Display the timestamp
            cout << "- " << postContent << endl;

            tempStack.push(posts->pop());      // Move the post to the temporary stack
        }

        while (!tempStack.isEmpty())
        {
            posts->push(tempStack.pop());      // Restore the original stack
        }
    }
	
    void addFollower(string followerName)
    {
        FollowerNode* newFollower = new FollowerNode(followerName);
        newFollower->next = followerList;
        followerList = newFollower;
    }

    void addFriend(string friendName)
    {
        FollowerNode* newFriend = new FollowerNode(friendName);
        newFriend->next = friendsList;
        friendsList = newFriend;
    }

    void displayFollowers()
    {
        FollowerNode* temp = followerList;
        cout << "Followers of " << name << ":" << endl;
        while (temp)
        {
            cout << "- " << temp->username << endl;
            temp = temp->next;
        }
    }

    void displayFriends()
    {
        FollowerNode* temp = friendsList;
        cout << "Friends of " << name << ":" << endl;
        while (temp)
        {
            cout << "- " << temp->username << endl;
            temp = temp->next;
        }
    }
};

class UserGraph
{
    UserProfile* head;
    UserProfile* currentUser;

    UserProfile* findUser(UserProfile* root, string username)
    {
        // Base case: If the node is null or we found the username
        if (root == nullptr || root->name == username)
            return root;

        // If the username is lexicographically smaller, go left
        if (username < root->name)
            return findUser(root->next, username);

        // Else, go right
        return findUser(root->next, username);
    }

public:
    UserGraph()
    {
        head = nullptr;
        currentUser = nullptr;
    }

    void signup(string username, string password, string city)
    {
        if (findUser(head, username))
        {
            cout << "Username already exists!" << endl;
            return;
        }
        UserProfile* newUser = new UserProfile(username, password, city);
        newUser->next = head;
        head = newUser;
        cout << "User " << username << " signed up successfully!" << endl;
    }

    bool login(string username, string password)
    {
        if (currentUser)
        {
            cout << "A user is already logged in as " << currentUser->name << ". Please sign out first." << endl;
            return false;
        }

        UserProfile* user = findUser(head, username);
        if (!user)
        {
            cout << "User not found!" << endl;
            return false;
        }
        if (user->password != password)
        {
            cout << "Invalid password!" << endl;
            return false;
        }
        currentUser = user;
        cout << "Login successful for " << username << endl;
        return true;
    }

    void logout()
    {
        if (!currentUser)
        {
            cout << "No user is currently logged in." << endl;
            return;
        }
        cout << "User " << currentUser->name << " has been logged out." << endl;
        currentUser = nullptr;
    }

    void sendFollowRequest(string sender, string receiver)
    {
        if (!currentUser || currentUser->name != sender)
        {
            cout << "You must be logged in as " << sender << " to send a follow request." << endl;
            return;
        }

        if (sender == receiver)
        {
            cout << "Error: You cannot send a follow request to yourself!" << endl;
            return;
        }

        UserProfile* senderUser = findUser(head, sender);
        UserProfile* receiverUser = findUser(head, receiver);

        if (!senderUser || !receiverUser)
        {
            cout << "User(s) not found!" << endl;
            return;
        }

        FollowerNode* followerTemp = receiverUser->followerList;
        while (followerTemp)
        {
            if (followerTemp->username == sender)
            {
                cout << "Error: You are already following " << receiver << "!" << endl;
                return;
            }
            followerTemp = followerTemp->next;
        }

        Node* requestTemp = receiverUser->followRequests.getFront();
        while (requestTemp)
        {
            if (requestTemp->data == sender)
            {
                cout << "Error: Follow request already sent to " << receiver << "!" << endl;
                return;
            }
            requestTemp = requestTemp->next;
        }

        receiverUser->followRequests.enqueue(sender);
        cout << "Follow request sent from " << sender << " to " << receiver << endl;
    }

    void acceptFollowRequest(string username)
    {
        if (!currentUser || currentUser->name != username)
        {
            cout << "You must be logged in as " << username << " to accept follow requests." << endl;
            return;
        }

        UserProfile* user = findUser(head, username);
        if (!user)
        {
            cout << "User not found!" << endl;
            return;
        }

        cout << "Pending Follow Requests for " << username << ":" << endl;
        Node* temp = user->followRequests.getFront();
        if (!temp)
        {
            cout << "No pending follow requests!" << endl;
            return;
        }

        while (temp)
        {
            cout << "- " << temp->data << endl;
            temp = temp->next;
        }

        cout << "Enter the username to respond to the follow request: ";
        string followerUsername;
        cin >> followerUsername;

        bool requestFound = false;
        temp = user->followRequests.getFront();
        Queue tempQueue;

        while (temp)
        {
            if (temp->data == followerUsername)
            {
                requestFound = true;
                user->followRequests.dequeue();
                break;
            }
            tempQueue.enqueue(temp->data);
            temp = temp->next;
        }

        while (!tempQueue.isEmpty())
        {
            user->followRequests.enqueue(tempQueue.dequeue());
        }

        if (!requestFound)
        {
            cout << "No such follow request found!" << endl;
            return;
        }

        UserProfile* followerUser = findUser(head, followerUsername);
        if (followerUser)
        {
            user->addFollower(followerUsername);
            cout << followerUsername << " is now following " << username << "!" << endl;
        }
        else
        {
            cout << "Follower user not found!" << endl;
        }
    }

    void addFriend(string user1, string user2)
    {
        if (!currentUser || currentUser->name != user1)
        {
            cout << "You must be logged in as " << user1 << " to add a friend." << endl;
            return;
        }

        UserProfile* user1Profile = findUser(head, user1);
        UserProfile* user2Profile = findUser(head, user2);

        if (!user1Profile || !user2Profile)
        {
            cout << "One or both users not found!" << endl;
            return;
        }

        bool user1FollowsUser2 = false;
        FollowerNode* temp = user1Profile->followerList;
        while (temp)
        {
            if (temp->username == user2)
            {
                user1FollowsUser2 = true;
                break;
            }
            temp = temp->next;
        }

        bool user2FollowsUser1 = false;
        temp = user2Profile->followerList;
        while (temp)
        {
            if (temp->username == user1)
            {
                user2FollowsUser1 = true;
                break;
            }
            temp = temp->next;
        }

        if (user1FollowsUser2 && user2FollowsUser1)
        {
            user1Profile->addFriend(user2);
            user2Profile->addFriend(user1);
            cout << user2 << " and " << user1 << " are now friends!" << endl;
        }
        else
        {
            cout << "Both users must follow each other before they can become friends!" << endl;
        }
    }


    void displayUserFollowers(string username)
    {
        UserProfile* user = findUser(head, username);
        if (user)
        {
            user->displayFollowers();
        }
        else
        {
            cout << "User not found!" << endl;
        }
    }

    void displayUserFriends(string username)
    {
        UserProfile* user = findUser(head, username);
        if (user)
        {
            user->displayFriends();
        }
        else
        {
            cout << "User not found!" << endl;
        }
    }
    void displayGraph()
    {
        UserProfile* temp = head;
        while (temp)
        {
            cout << temp->name << " (" << temp->city << ")" << endl;

            cout << "  Followers: ";
            FollowerNode* followerTemp = temp->followerList;
            if (followerTemp)
            {
                while (followerTemp)
                {
                    cout << followerTemp->username << " ";
                    followerTemp = followerTemp->next;
                }
            }
            else
            {
                cout << "No followers.";
            }
            cout << endl;

            cout << "  Friends: ";
            FollowerNode* friendsTemp = temp->friendsList;
            if (friendsTemp)
            {
                while (friendsTemp)
                {
                    cout << friendsTemp->username << " ";
                    friendsTemp = friendsTemp->next;
                }
            }
            else
            {
                cout << "No friends.";
            }
            cout << endl;

            temp = temp->next;
        }
    }


    void addPost(string postContent)
    {
        if (!currentUser)
        {
            cout << "No user is currently logged in." << endl;
            return;
        }
        currentUser->addPost(postContent);
    }

    void showPosts()
    {
        if (!currentUser)
        {
            cout << "No user is currently logged in." << endl;
            return;
        }
        currentUser->showPosts();
    }

    void showNewsFeed()
    {
        if (!currentUser)
        {
            cout << "No user is currently logged in." << endl;
            return;
        }

        cout << "Newsfeed for " << currentUser->name << ":" << endl;

        currentUser->showPosts();

        FollowerNode* follower = currentUser->followerList;
        while (follower)
        {
            UserProfile* followerProfile = findUser(head, follower->username);
            if (followerProfile)
            {
                followerProfile->showPosts();
            }
            follower = follower->next;
        }
    }
    void sendMessage(string receiver, string message)
    {
        if (!currentUser)
        {
            cout << "You must be logged in to send messages." << endl;
            return;
        }

        // Find the receiver user profile
        UserProfile* receiverProfile = findUser(head, receiver);
        if (!receiverProfile)
        {
            cout << "Receiver not found!" << endl;
            return;
        }

        bool isFriend = false;
        FollowerNode* temp = currentUser->friendsList;
        while (temp)
        {
            if (temp->username == receiver)
            {
                if (temp->status == "blocked")
                {
                    cout << "You cannot send a message to " << receiver << " because they are blocked." << endl;
                    return;
                }
                isFriend = true;
                break;
            }
            temp = temp->next;
        }

        if (!isFriend)
        {
            cout << "You can only send messages to your friends!" << endl;
            return;
        }

        receiverProfile->receiveMessage(currentUser->name, message);
        cout << "Message sent to " << receiver << "." << endl;
    }



    void viewNotifications()
    {
        if (!currentUser)
        {
            cout << "You must be logged in to view notifications." << endl;
            return;
        }
        currentUser->viewNotifications();
    }

    void viewMessages()
    {
        if (!currentUser)
        {
            cout << "You must be logged in to view messages." << endl;
            return;
        }
        currentUser->viewMessages();
    }
    void blockFriend(string user1, string user2)
    {
        if (!currentUser || currentUser->name != user1)
        {
            cout << "You must be logged in as " << user1 << " to block a friend." << endl;
            return;
        }

        UserProfile* user1Profile = findUser(head, user1);
        UserProfile* user2Profile = findUser(head, user2);

        if (!user1Profile || !user2Profile)
        {
            cout << "One or both users not found!" << endl;
            return;
        }

        FollowerNode* temp = user1Profile->friendsList;
        while (temp)
        {
            if (temp->username == user2)
            {
                temp->status = "blocked";  // Change the status to "blocked"
                cout << user2 << " has been blocked!" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << user2 << " is not a friend of " << user1 << "!" << endl;
    }

    void unblockFriend(string user1, string user2)
    {
        if (!currentUser || currentUser->name != user1)
        {
            cout << "You must be logged in as " << user1 << " to unblock a friend." << endl;
            return;
        }

        UserProfile* user1Profile = findUser(head, user1);
        UserProfile* user2Profile = findUser(head, user2);

        if (!user1Profile || !user2Profile)
        {
            cout << "One or both users not found!" << endl;
            return;
        }

        FollowerNode* temp = user1Profile->friendsList;
        while (temp)
        {
            if (temp->username == user2)
            {
                temp->status = "active";  // Change the status to "active"
                cout << user2 << " has been unblocked!" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << user2 << " is not a friend of " << user1 << "!" << endl;
    }

};

int main()
{
    UserGraph userGraph;

    int choice;
    string username, password, city, followerUsername, postContent;

    while (true)
    {
        cout << "\n===== Main Menu =====" << endl;
        cout << "\t1. Sign Up" << endl;
        cout << "\t2. Login" << endl;
        cout << "\t3. Logout" << endl;
        cout << "\t4. Find User" << endl;
        cout << "\t5. Send Follow Request" << endl;
        cout << "\t6. Accept Follow Request" << endl;
        cout << "\t7. Add Friend" << endl;
        cout << "\t8. Add Post" << endl;
        cout << "\t9. Send Messages" << endl;
        cout << "\t10. View Message" << endl;
        cout << "\t11. Notifications" << endl;
        cout << "\t12. Display Followers" << endl;
        cout << "\t13. Display Friends" << endl;
        cout << "\t14. Display User Graph" << endl;
        cout << "\t15. Show My Posts" << endl;
        cout << "\t16. Show Newsfeed" << endl;
        cout << "\t17. Block Friend" << endl;
        cout << "\t18. Unblock Friend" << endl;
        cout << "\t19. Exit" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter city: ";
            cin >> city;
            userGraph.signup(username, password, city);
            break;

        case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (!userGraph.login(username, password))
            {
                cout << "Login failed!" << endl;
            }
            break;

        case 3:
            userGraph.logout();
            break;

        case 4:
            cout << "Enter username: ";
            cin >> username;
            cout << "Searched User Profile\n";
            userGraph.displayUserFollowers(username);
            break;

        case 5:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter the username to follow: ";
            cin >> followerUsername;
            userGraph.sendFollowRequest(username, followerUsername);
            break;

        case 6:
            cout << "Enter your username: ";
            cin >> username;
            userGraph.acceptFollowRequest(username);
            break;

        case 7:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter the username to add as a friend: ";
            cin >> followerUsername;
            userGraph.addFriend(username, followerUsername);
            break;

        case 8:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter post content: ";
            cin.ignore();
            getline(cin, postContent);
            userGraph.addPost(postContent);
            break;

        case 9:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter the username to send a message to: ";
            cin >> followerUsername;
            cout << "Enter message content: ";
            cin.ignore();
            getline(cin, postContent);
            userGraph.sendMessage(followerUsername, postContent);
            break;

        case 10:
            userGraph.viewMessages();
            break;
        case 11:
            userGraph.viewNotifications();
            break;

        case 12:
            cout << "Enter username: ";
            cin >> username;
            userGraph.displayUserFollowers(username);
            break;

        case 13:
            cout << "Enter username: ";
            cin >> username;
            userGraph.displayUserFriends(username);
            break;

        case 14:
            userGraph.displayGraph();
            break;

        case 15:
            userGraph.showPosts();
            break;

        case 16:
            userGraph.showNewsFeed();
            break;
        case 17:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter the username to block: ";
            cin >> followerUsername;
            userGraph.blockFriend(username, followerUsername);
            break;

        case 18:
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter the username to unblock: ";
            cin >> followerUsername;
            userGraph.unblockFriend(username, followerUsername);
            break;

        case 19:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}