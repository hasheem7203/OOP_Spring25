#include <iostream>
using namespace std;

class ticket {
protected:
    int ticketId;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    ticket(int id, string pname, double price, string date, string destination)
        : ticketId(id), passengerName(pname), price(price), date(date), destination(destination) {}

    void reserve() {
        cout << "Ticket reserved successfully!" << endl;
    }

    void cancel() {
        cout << "Ticket cancelled!" << endl;
    }

    virtual void displayinfo() {
        cout << "Ticket ID: " << ticketId << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Ticket Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public ticket {
private:
    string airlinename;
    int flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string pname, double price, string date, string destination,
                 string airline, int flightNum, string seatCls)
        : ticket(id, pname, price, date, destination), airlinename(airline), flightNumber(flightNum), seatClass(seatCls) {}

    void displayinfo() override {
        ticket::displayinfo();
        cout << "Airline Name: " << airlinename << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class trainTicket : public ticket {
private:
    int trainNumber;
    string coachType;
    string departureTime;

public:
    trainTicket(int id, string pname, double price, string date, string destination,
                int trainNum, string coach, string departure)
        : ticket(id, pname, price, date, destination), trainNumber(trainNum), coachType(coach), departureTime(departure) {}

    void reserve() {
        cout << "Train ticket reserved! Auto-assigning seat..." << endl;
    }

    void displayinfo() override {
        ticket::displayinfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public ticket {
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string pname, double price, string date, string destination,
              string company, int seatNum)
        : ticket(id, pname, price, date, destination), busCompany(company), seatNumber(seatNum) {}

    void cancel() {
        cout << "Bus ticket cancelled. Last-minute refund issued!" << endl;
    }

    void displayinfo() override {
        ticket::displayinfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string pname, double price, string date, string destination,
                  string artist, string venueName, string seat)
        : ticket(id, pname, price, date, destination), artistName(artist), venue(venueName), seatType(seat) {}

    void displayinfo() override {
        ticket::displayinfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket f1(101, "ali asgher", 350.50, "2025-04-10", "Kaarachi", "Emirates", 5678, "Business");
    trainTicket t1(202, "Mustafa", 120.75, "2025-05-15", "Quetta", 456, "AC Coach", "10:30 AM");
    BusTicket b1(303, "Zain", 40.00, "2025-06-20", "islamabad", "Faisal Movers", 12);
    ConcertTicket c1(404, "Alison Burgers", 75.99, "2025-07-25", "Las Vegas", "leonardo de caprio", "MGM Grand", "VIP");

    cout << "\nFlight Ticket Info:\n";
    f1.displayinfo();
    
    cout << "\nTrain Ticket Info:\n";
    t1.displayinfo();

    cout << "\nBus Ticket Info:\n";
    b1.displayinfo();
    b1.cancel();

    cout << "\nConcert Ticket Info:\n";
    c1.displayinfo();

    return 0;
}
