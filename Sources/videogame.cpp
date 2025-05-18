#include "videogame.h"

using namespace std;

// Public

VideoGame::VideoGame() {}

VideoGame::VideoGame(const VideoGame& v) : id(v.id), name(v.name), developer(v.developer), category(v.category), releaseDate(v.releaseDate) {}

VideoGame& VideoGame::operator = (const VideoGame& v) {
    id = v.id;
    name = v.name;
    developer = v.developer;
    category = v.category;
    releaseDate = v.releaseDate;

    return *this;
}

void VideoGame::setId(const string& id_) {
    id = id_;
}

void VideoGame::setName(const string& n) {
    name = n;
}

void VideoGame::setDeveloper(const string& d) {
    developer = d;
}

void VideoGame::setCategory(const string& c) {
    category = c;
}

void VideoGame::setReleaseDate(const Date& d) {
    releaseDate = d;
}

string VideoGame::getId() const {
    return id;
}

string VideoGame::getName() const {
    return name;
}

string VideoGame::getDeveloper() const {
    return developer;
}

string VideoGame::getCategory() const {
    return category;
}

Date VideoGame::getReleaseDate() const {
    return releaseDate;
}

string VideoGame::toString() const {
    string result;

    result = id;
    result += " | ";
    result += name;
    result += " | ";
    result += developer;
    result += " | ";
    result += category;
    result += " | ";
    result += releaseDate.toString();

    return result;
}

bool VideoGame::operator == (const VideoGame& v) const {
    return id == v.id;
}

bool VideoGame::operator != (const VideoGame& v) const {
    return id != v.id;
}

bool VideoGame::operator < (const VideoGame& v) const {
    return id < v.id;
}

bool VideoGame::operator <= (const VideoGame& v) const {
    return id <= v.id;
}

bool VideoGame::operator > (const VideoGame& v) const {
    return id > v.id;
}

bool VideoGame::operator >= (const VideoGame& v) const {
    return id >= v.id;
}

ostream& operator << (ostream& os, VideoGame& v) {
    os << v.id << endl;
    os << v.name << endl;
    os << v.developer << endl;
    os << v.category << endl;
    os << v.releaseDate << endl;

    return os;
}

istream& operator >> (istream& is, VideoGame& v) {
    getline(is, v.id);
    getline(is, v.name);
    getline(is, v.developer);
    getline(is, v.category);
    is >> v.releaseDate;

    return is;
}