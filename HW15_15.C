#include <iostream>
#include <vector>
#include <string>

class Date {
private:
    int daysFromStartOfYear;

public:
    Date(int days) : daysFromStartOfYear(days) {}

    int getDays() const {
        return daysFromStartOfYear;
    }
};

class Guest {
private:
    std::string lastName;
    Date checkInDate;
    Date checkOutDate;
    int roomNumber;

public:
    Guest(const std::string& name, Date in, Date out, int room)
        : lastName(name), checkInDate(in), checkOutDate(out), roomNumber(room) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    const Date& getCheckInDate() const {
        return checkInDate;
    }

    const Date& getCheckOutDate() const {
        return checkOutDate;
    }
};

class Hotel {
private:
    std::vector<int> rooms;
    std::vector<Guest> guests;
    std::vector<int> roomRates;

public:
    Hotel(const std::vector<int>& roomNumbers, const std::vector<int>& rates)
        : rooms(roomNumbers), roomRates(rates) {}

    int getAvailableRooms(Date date) const {
        int availableCount = 0;

        for (int room : rooms) {
            bool isOccupied = false;

            for (const Guest& guest : guests) {
                if (guest.getRoomNumber() == room &&
                    date.getDays() >= guest.getCheckInDate().getDays() &&
                    date.getDays() <= guest.getCheckOutDate().getDays()) {
                    isOccupied = true;
                    break;
                }
            }

            if (!isOccupied) {
                availableCount++;
            }
        }
        return availableCount;
    }

    int findAvailableRoom(Date start, Date end) const {
        for (int room : rooms) {
            bool isAvailable = true;

            for (const Guest& guest : guests) {
                if (guest.getRoomNumber() == room &&
                    !(end.getDays() < guest.getCheckInDate().getDays() ||
                      start.getDays() > guest.getCheckOutDate().getDays())) {
                    isAvailable = false;
                    break;
                }
            }

            if (isAvailable) {
                return room;
            }
        }
        return -1; // No room available
    }

    void addGuest(const Guest& guest) {
        guests.push_back(guest);
    }

    int calculateStayCost(int roomNumber, Date start, Date end) const {
        int roomIndex = -1;

        for (size_t i = 0; i < rooms.size(); ++i) {
            if (rooms[i] == roomNumber) {
                roomIndex = i;
                break;
            }
        }

        if (roomIndex == -1) {
            return -1; // Room not found
        }

        return (end.getDays() - start.getDays()) * roomRates[roomIndex];
    }
};

int main() {
    std::vector<int> rooms = {101, 102, 103, 104};
    std::vector<int> rates = {100, 120, 150, 200};

    Hotel hotel(rooms, rates);

    Date checkIn(5), checkOut(10);
    Guest guest1("Smith", checkIn, checkOut, 101);
    hotel.addGuest(guest1);

    Date date(6);
    std::cout << "Available rooms on day 6: " << hotel.getAvailableRooms(date) << std::endl;

    Date start(12), end(15);
    int room = hotel.findAvailableRoom(start, end);
    if (room != -1) {
        std::cout << "Available room from day 12 to 15: " << room << std::endl;
    } else {
        std::cout << "No rooms available in the given period." << std::endl;
    }

    int cost = hotel.calculateStayCost(101, checkIn, checkOut);
    if (cost != -1) {
        std::cout << "Cost of stay in room 101: $" << cost << std::endl;
    }
}
