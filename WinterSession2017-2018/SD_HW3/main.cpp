/* Homework 3
 * by
 * Kamena Dacheva, 71672
 *
 * Browser Tabs
 *
 * Type HELP to see the commands you can use.
 * 
 * OS used: Linux
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <ctime>
#include "DlList.h"

using namespace std;

struct Page {
	string name;
	time_t timev;
};

void toLower(string& s) {
	for(int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

int compare(DlList<Page>::iterator itr1, DlList<Page>::iterator itr2) {
    string data1 = itr1->name;
    string data2 = itr2->name;

    int length = (data1.length() < data2.length()) ? data1.length() : data2.length();

    for(int i = 0; i < length; i++) {
        if(data1[i] > data2[i]) return 1;  
    }

    return 0;
}

int compareTime(time_t time1, time_t time2){
    return difftime(time1, time2) > 0.0 ? 1 : 0; 
} 

int main(int argc, char const *argv[]) {

	Page page, page2;

	string text, word, command, argument;

	page.name = "about:blank";
	page.timev = time(NULL);

	DlList<Page> browserTabs;
	DlList<Page>::iterator currentPos = browserTabs.begin();

	currentPos = browserTabs.push_back(page);

    DlList<Page>::iterator itr = browserTabs.begin();
    DlList<Page>::iterator itr2 = browserTabs.begin();

    DlList<Page>::iterator pos = browserTabs.begin();

    int size = browserTabs.size();
    int flag = 1, countSwaps = 0, swapped = 0, count = 0;

	while(command != "exit") {
		
		getline(cin, text);
		istringstream iss(text);
	   
	    while(iss >> word) {
	    	switch(count) {
                case 0: command = word;
                		count++;
                        break;
                case 1: argument = word;
                		count++;
                        break;
                default:break;
            }

	    }
	    count = 0;
	    toLower(command);

        if(command == "go" || command == "insert") {
            page.name = argument;
            page.timev = time(NULL);
        }  

        if(command == "go") {
        	currentPos = browserTabs.addAfter(currentPos, page);
        	currentPos--;
        	currentPos = browserTabs.deleteElement(currentPos);
        } else if(command == "insert") {
        	currentPos = browserTabs.addAfter(currentPos, page);
        } else if(command == "back") {
        	currentPos--;
        } else if(command == "forward") {
        	currentPos++;
        } else if(command == "remove") {
            if(currentPos == currentPos--) {
                page.name = "about:blank";
                page.timev = time(NULL);
                currentPos = browserTabs.push_back(page);
            } 
            currentPos++;

        	currentPos = browserTabs.deleteElement(currentPos);
        } else if(command == "print") {
        	pos = browserTabs.begin();

        	for(pos = browserTabs.begin(); pos != browserTabs.end(); ++pos) {
        		if (pos == currentPos) {
        			cout << ">" << pos->name << " \t\t" << asctime(localtime(&pos->timev));
        		} else cout << pos->name << " \t\t" << asctime(localtime(&pos->timev));
			}

			if (pos == currentPos) {
    			cout << ">" << pos->name << " \t\t" << asctime(localtime(&pos->timev));
    		} else cout << pos->name << " \t\t" << asctime(localtime(&pos->timev));

    		cout << endl;
        } else if(command == "sort") {
            toLower(argument);
            
            if(argument == "url") {
                swapped = 0; 
                size = browserTabs.size();

                while (flag) {
                    itr = browserTabs.begin();
                    itr2 = browserTabs.begin();
                    itr2++;
                    swapped = 0;
                    countSwaps = 0;
                    
                    while (swapped < size) {
                        swapped++;
                        if (compare(itr, itr2)) {                            
                            countSwaps++;

                            page.name = itr->name;
                            page.timev = itr->timev;
                            page2.name = itr2->name;
                            page2.timev = itr2->timev;

                            browserTabs.addAfter(itr, page2);                            
                            browserTabs.deleteElement(itr);

                            browserTabs.addAfter(itr2, page);
                            browserTabs.deleteElement(itr2);
                        }
                        itr++;
                        itr2++;
                    }

                    if(countSwaps == 0) flag = 0;
                }

            } else if (argument == "time") {
                swapped = 0; 
                size = browserTabs.size();

                while (flag) {
                    itr = browserTabs.begin();
                    itr2 = itr;
                    itr2++;
                    swapped = 0;
                    countSwaps = 0;
                    
                    while (swapped < size) {
                        swapped++;
                        if (compareTime(itr->timev, itr2->timev)) {                          
                            countSwaps++;
                            page.name = itr->name;
                            page.timev = itr->timev;
                            page2.name = itr2->name;
                            page2.timev = itr2->timev;

                            browserTabs.addAfter(itr, page2);                            
                            browserTabs.deleteElement(itr);

                            browserTabs.addAfter(itr2, page);
                            browserTabs.deleteElement(itr2);
                        }
                        itr++;
                        itr2++;
                    }

                    if(countSwaps == 0) flag = 0;
                }
            } else {
                cout << "Invalid command. Type HELP to see the available commands and how to use them." << endl;
            }
            currentPos = browserTabs.begin();
        } else if (command == "help") {
            cout << "GO <url>\t\t Opens the page on the same tab you are on now" << endl;
            cout << "INSERT <url>\t\t Opens the page in new tab. The tab is insert after the tab you are on now" << endl;
            cout << "BACK\t\t Navigates to the previous tab" << endl;
            cout << "FORWARD\t\t Navigates to the next tab" << endl;
            cout << "PRINT\t\t Prints all tabs" << endl;
            cout << "SORT <by>\t\t Sort all tabs by url or timestamp" << endl;
        } else if (command != "exit") {
            cout << "Invalid command. Type HELP to see the available commands and how to use them." << endl;
        }       
        
	}

	return 0;
}