/*
Saar Haber
Lab 12D
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

//implementation of the class Profile
string Profile::getUsername(){

    return username;
}

string Profile::getFullName() {
    string name;
    name = displayname + " (@"
    + getUsername() + ")";
    return name;
}

void Profile::setDisplayName(string dspn) {
    displayname = dspn;
}

Profile::Profile(string usrn, string dspn) {
    username =usrn;
    displayname = dspn;
}

Profile::Profile() {
    username="";
    displayname="";
}

struct Post{
  string username;
  string message;
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;    //size of array                // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn); //look up specific id by searching username-return the id or -1if no user
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
  // following[id1][id2] == true when id1 is following id2
  static const int MAX_POSTS = 100;
  int numPosts;                    // number of posts
  Post posts[MAX_POSTS];           // array of all posts
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);

  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
  // return true if success (if both usernames exist), otherwise return false
  bool follow(string usrn1, string usrn2);
  // Print Dot file (graphical representation of the network)
  void printDot();
  // Add a new post
  bool writePost(string usrn, string msg);
  // Print user's "timeline"
  bool printTimeline(string usrn);
};



int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}

int Network::findID(string usrn) {
	for(int i = 0; i < MAX_USERS; i++) {
		if(profiles[i].getUsername() == usrn) {
			return i; //the index is the id
		}
	}
	return -1;
}

bool Network::addUser(string usrn, string dspn) {

//if username is empty
  if (usrn == "") {
		return false;
	}

//checks if the username exists in the array
	if(findID(usrn) == -1) {
		if(numUsers < MAX_USERS) {
		    for(int i = 0; i < MAX_USERS; i++) {
          //there is no other users int he network witht he same username
			      if(profiles[i].getUsername() == usrn) {
				       return false;
             }
         }
		for (int j = 0; j < usrn.length(); j++) {
			if (!isalnum(usrn[j])) {
				return false;
			}
		} //closinf loop

		Profile temp_prof(usrn, dspn);
		profiles[numUsers] = temp_prof;
		numUsers++;
		return true;

  } // clossing if statement
} //clossing if with netID
return 0; // in case nothing is returned
}

//constror-to initialize the varaibles
Network::Network() {
	numUsers = 0;
  numPosts = 0;
  for (int i=0; i<MAX_USERS; i++) {
    for (int j=0; j<MAX_USERS; j++) {
      following [i][j] = false;
    }
  }
}

bool Network::follow(string usrn1,string usrn2) {
  if (findID(usrn1)!=-1 && findID(usrn2)!=-1 && (findID(usrn1) != findID(usrn2))) {
    following[findID(usrn1)][findID(usrn2)] = true;
  }
  return false;
}
void Network::printDot() {
cout <<  "digraph {" << endl;
  for (int i=0; i<numUsers; i++) {
    cout << "\"@" << profiles[i].getUsername() <<"\"" << endl;
  }
  for (int i=0; i<numUsers; i++) {
    for (int j=0; j<numUsers; j++) {
      if (following[i][j] == true) {
        cout << "\"@" << profiles[i].getUsername() << "\" -> \"@"
        << profiles[j].getUsername() << "\"" << endl;
      }
    }
  }

  cout << "}";
}

bool Network::writePost(string usrn, string msg) {
  int LocationEmpty;
  if (numPosts == MAX_POSTS) {
    return false;
  }
  for (int i=0; i<MAX_POSTS; i++) {
    if (posts[i].message.empty()) {
      LocationEmpty = i;
      break;
    }
  }
  if (findID(usrn)!=-1) {
    posts[LocationEmpty].username = usrn;
    posts[LocationEmpty].message = msg;
    return true;
    numPosts++;
  }
  return false;
}

bool Network::printTimeline(string usrn){
  int id = findID(usrn);
  int j;
  for (int i = MAX_POSTS; i>=0; i--) {
    if (posts[i].username == usrn) {
      cout << profiles[id].getFullName() << ": " <<
      posts[i].message << endl;
    }
    j = 0;
    while (j<numUsers) {
      int id2 =  findID(profiles[j].getUsername());
      string usrn2 = profiles[j].getUsername();
      if (following[id][id2] && posts[i].username == usrn2) {
        cout << profiles[j].getFullName() << ": " <<
        posts[i].message << endl;
      }
      j++;
  }
}
  return true;
}
