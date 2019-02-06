/*
Saar Haber
Lab 12B

*/

#include <iostream>
#include <cctype>
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
    name = displayname + "(@ "
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


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;    //size of array                // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn); //look up specific id by searching username-return the id or -1if no user
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};


int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0) //*
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)//*
}

int Network::findID(string usrn) {
	for(int i = 0; i < 20; i++) {
		if(profiles[i].getUsername() == usrn) {
			return i; //the index is the id
		}
		else {
			return -1; //aka false
		}
	}
	return 0;
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
}
