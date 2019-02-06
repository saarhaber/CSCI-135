/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryashg
Assignment: LAB 10 A, B , C, D;

a new program time.cpp.
Implementing new functions
Using enum and classes
*/

#include <iostream>
#include <string>

using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time {
public:
    int h;
    int m;
};

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

//contains  the two other objects
class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);

void printMovie (Movie m);
void printTimeSlot (TimeSlot ts);

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

bool timeOverlap(TimeSlot ts1, TimeSlot ts2);


int main() {

//part A:
int h1, h2, m1, m2;
cout << "Enter first time: ";
cin >> h1 >> m1;
cout << "Enter second time: ";
cin >> h2 >> m2;


Time time1 = {h1, m1};
Time time2 = {h2, m2};

cout << "These moments of time are " << minutesSinceMidnight(time1) <<
      " and " << minutesSinceMidnight(time2) << " after midnight." << endl
      << "The interval between them is " << minutesUntil(time1, time2) <<
      " minutes." << endl;

//part B:
Time time3 = {8, 10};
Time time4 = addMinutes (time3, 75);
cout << "After adding minutes: ";
printTime (time4);
cout <<endl;

//part C:
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Pulp Fiction", DRAMA, 154};
Movie movie4 = {"Fight Club", DRAMA, 139};


TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie2, {12, 15}};
TimeSlot evening = {movie2, {16, 45}};
TimeSlot daytime2 = {movie3, {14, 10}};
TimeSlot evening2 = {movie4, {20, 30}};

printTimeSlot (morning);
printTimeSlot (daytime);
printTimeSlot (evening);
printTimeSlot (daytime2);
printTimeSlot (evening2);

//part D:
Movie movie5 = {"Inception", ACTION, 148};
printTimeSlot (scheduleAfter(daytime2, movie5));

//part E:
if (timeOverlap (evening, daytime)) {
  cout <<"true";
}
else {
  cout << "false";
}


}

int minutesSinceMidnight(Time time1) {

  return (time1.h * 60 + time1.m);

}
int minutesUntil(Time earlier, Time later) {

  return (minutesSinceMidnight(later) - minutesSinceMidnight(earlier));

}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

Time addMinutes(Time time0, int min) {
  Time timeNew;
  timeNew.h = time0.h;
  timeNew.m = time0.m;
  int minutes = min;
  while (minutes >= 60) {
    timeNew.h++;
    minutes -= 60;
  }

  if (time0.m + minutes >= 60) {
    timeNew.h++;
    minutes = timeNew.m + minutes - 60;
    timeNew.m = minutes;
  }
  else
    timeNew.m += minutes;

  return timeNew;
}

void printMovie (Movie m) {
string g;
  switch (m.genre) {
      case ACTION   : g = "ACTION"; break;
      case COMEDY   : g = "COMEDY"; break;
      case DRAMA    : g = "DRAMA";  break;
      case ROMANCE  : g = "ROMANCE"; break;
      case THRILLER : g = "THRILLER"; break;
  }
  cout << m.title << " " << g << " (" << m.duration << " min)";

}

void printTimeSlot (TimeSlot ts) {

  printMovie(ts.movie);
  cout << " [starts at ";
  printTime(ts.startTime);
  cout << ", ends by ";
  printTime(addMinutes(ts.startTime, ts.movie.duration));
  cout << "]" << endl;

}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
  TimeSlot timeNew;
  timeNew.startTime = addMinutes(ts.startTime, ts.movie.duration);
  timeNew.movie = nextMovie;
  return timeNew;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
  if (minutesUntil(ts1.startTime, ts2.startTime) > 0) {
    if (ts1.movie.duration > minutesUntil(ts1.startTime, ts2.startTime)) {
      return true;
    }
  }
  else {
    if (ts2.movie.duration > minutesUntil(ts2.startTime, ts1.startTime)) {
      return true;
    }
  }
  return false;

}
