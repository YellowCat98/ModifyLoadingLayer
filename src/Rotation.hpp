#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Rotation : public CCNode {
public:
    bool init();
    void rotate();
    static Rotation* create();
};