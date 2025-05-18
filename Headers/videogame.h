#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>

#include "date.h"

class VideoGame {
    private:
        std::string id;
        std::string name;
        std::string developer;
        std::string category;
        Date releaseDate;

    public:
        VideoGame();
        VideoGame(const VideoGame&);
        VideoGame& operator = (const VideoGame&);

        void setId(const std::string&);
        void setName(const std::string&);
        void setDeveloper(const std::string&);
        void setCategory(const std::string&);
        void setReleaseDate(const Date&);

        std::string getId() const;
        std::string getName() const;
        std::string getDeveloper() const;
        std::string getCategory() const;
        Date getReleaseDate() const;

        std::string toString() const;

        bool operator == (const VideoGame&) const;
        bool operator != (const VideoGame&) const;
        bool operator < (const VideoGame&) const;
        bool operator <= (const VideoGame&) const;
        bool operator > (const VideoGame&) const;
        bool operator >= (const VideoGame&) const;

        friend std::ostream& operator << (std::ostream&, VideoGame&);
        friend std::istream& operator >> (std::istream&, VideoGame&);
};

#endif // VIDEOGAME_H