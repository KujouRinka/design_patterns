#include "Proxy.h"

#include <cstring>


Image::Image(const char *file) {
    _filename = strdup(file);
    // do load Image action
}

Image::~Image() noexcept {
    free(_filename);
    // may free Image
}

void Image::draw() {
    // do draw
}

void Image::handleMouse(Event &event) {
    // do handleMouse
}

Point &Image::getExtend() {
    return _extent;
}

void Image::load(istream &from) {
    // do load
}

void Image::save(ostream &to) {
    // do save
}


ImageProxy::ImageProxy(const char *file) {
    _filename = strdup(file);
    _extent = Point();
    _image = nullptr;
}

ImageProxy::~ImageProxy() noexcept {
    free(_filename);
}

void ImageProxy::draw() {
    getImage()->draw();
}

void ImageProxy::handleMouse(Event &event) {
    getImage()->handleMouse(event);
}

Point &ImageProxy::getExtend() {
    if (_image == nullptr)
        return _extent;
    return _image->getExtend();
}

void ImageProxy::load(istream &from) {
    from >> _extent >> _filename;
}

void ImageProxy::save(ostream &to) {
    to << _extent << _filename;
}

Image *ImageProxy::getImage() {
    if (_image == nullptr)
        _image = new Image(_filename);
    return _image;
}
