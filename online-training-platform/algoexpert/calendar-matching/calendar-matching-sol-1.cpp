#include <vector>

using namespace std;

struct StringMeeting {
  string start;
  string end;
};

struct Meeting {
	int start;
	int end;
};

vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds);
vector<Meeting> mergeCalendars(vector<Meeting> calendar1, vector<Meeting> calendar2);
vector<Meeting> flattenCalendars(vector<Meeting> calendar);
vector<StringMeeting> findAvailableTimesInCalendars(vector<Meeting> calendar1, int meeting);
int timeToMinutes(string time);
string minutesToTime(int minutes);

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration) {
  
	vector<Meeting> updateCalendar1 = updateCalendar(calendar1, dailyBounds1);
	vector<Meeting> updateCalendar2 = updateCalendar(calendar2, dailyBounds2);
	
	vector<Meeting> mergedCalendar = mergeCalendars(updateCalendar1, updateCalendar2);
	vector<Meeting> calendarJoined  = flattenCalendars(mergedCalendar);
	
  return findAvailableTimesInCalendars(calendarJoined, meetingDuration);;
}

vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds){
	vector<StringMeeting> newCalendar;
	newCalendar.push_back({"00:00", dailyBounds.start});
	int n = calendar.size();
	for(int i = 0 ; i < n ; i++){
		newCalendar.push_back({calendar[i].start, calendar[i].end});
	}
	newCalendar.push_back({dailyBounds.end, "23:59"});
	vector<Meeting> calendarInMinutes;
	for(int i = 0 ; i < newCalendar.size() ; i++){
		calendarInMinutes.push_back({
			timeToMinutes(newCalendar[i].start), 
			timeToMinutes(newCalendar[i].end)});
	}
	return calendarInMinutes;
}

vector<Meeting> mergeCalendars(vector<Meeting> calendar1, vector<Meeting> calendar2){
	vector<Meeting> calendarMerged;
	int n = calendar1.size();
	int m = calendar2.size();
	int i =0, j = 0;
	
	while(i < n && j < m){
		if(calendar1[i].start < calendar2[j].start){
			calendarMerged.push_back(calendar1[i]);
			i++;
		}else{
			calendarMerged.push_back(calendar2[j]);
			j++;
		}
	}
	
	while(i < n){
		calendarMerged.push_back(calendar1[i]);
		i++;
	}
	
	while(j < m){
		calendarMerged.push_back(calendar2[j]);
		j++;
	}
	
	return calendarMerged;
}

vector<Meeting> flattenCalendars(vector<Meeting> calendar){
	vector<Meeting> flattenCalendar;
	flattenCalendar.push_back(calendar[0]);
	
	int n = calendar.size();
	for(int i = 1 ; i < n ; i++){
		Meeting previous = flattenCalendar.back();
		Meeting current = calendar[i];
		if(previous.end >= current.start){
			flattenCalendar[flattenCalendar.size() - 1] = {
				previous.start, max(current.end, previous.end)
			};
		}else{
			flattenCalendar.push_back(current);
		}	
	}
	return flattenCalendar;
}

vector<StringMeeting> findAvailableTimesInCalendars(vector<Meeting> calendar,int meeting){
	int n = calendar.size();
	vector<StringMeeting> availableCalendar;;
	for(int i = 1 ; i < n; i++){
		Meeting current = calendar[i];
		Meeting previous = calendar[i - 1];
		int start = previous.end;
		int end = current.start;
		int difference = end - start;
		if(difference >= meeting){
			availableCalendar.push_back({
				minutesToTime(start),
				minutesToTime(end)
			});
		}
	}
	
	return availableCalendar;
}

int timeToMinutes(string time){
	int twoPointsIdx = time.find(":");
	
	int hour = stoi(time.substr(0, twoPointsIdx));
	int minutes = stoi(time.substr(twoPointsIdx + 1));
	
	return hour * 60 + minutes;
}

string minutesToTime(int minutes){
	int hours = minutes/ 60;
	int min = minutes % 60;
	
	string hoursString = to_string(hours);
	string minutesString = min < 10 ? "0" + to_string(min) : to_string(min);
	
	return hoursString + ":" + minutesString;
}

