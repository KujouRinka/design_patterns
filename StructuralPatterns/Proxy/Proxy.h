#ifndef DATA_STRUCTURES_AND_ALGORITHM_PROXY_H
#define DATA_STRUCTURES_AND_ALGORITHM_PROXY_H

#include <iostream>

using namespace std;

class Event;
class Point {
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int x, y;
};

class Graphic {
public:
    virtual ~Graphic() = default;

    virtual void draw() = 0;
    virtual void handleMouse(Event &event) = 0;

    virtual Point &getExtend() = 0;

    virtual void load(istream &from) = 0;
    virtual void save(ostream &to) = 0;
};

class Image : public Graphic {
public:
    Image(const char *file);
    ~Image() override;

    void draw() override;
    void handleMouse(Event &event) override;

    Point &getExtend() override;

    void load(istream &from) override;
    void save(ostream &to) override;

private:
    char *_filename;
    Point _extent;
};

class ImageProxy : public Graphic {
public:
    ImageProxy(const char *file);
    ~ImageProxy() override;

    void draw() override;
    void handleMouse(Event &event) override;

    Point &getExtend() override;

    void load(istream &from) override;
    void save(ostream &to) override;

protected:
    Image *getImage();

private:
    Image *_image;
    Point _extent;
    char *_filename;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_PROXY_H
