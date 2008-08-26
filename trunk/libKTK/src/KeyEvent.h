#ifndef KEYEVENT_H
#define KEYEVENT_H
#include "Ktk.h"
#include "Event.h"

namespace Ktk
{

enum {
    KEY_a,
    KEY_b,
    KEY_c,
    KEY_d,
    KEY_f,
    KEY_g,
    KEY_h,
    KEY_i,
    KEY_j,
    KEY_k,
    KEY_l,
    KEY_m,
    KEY_n,
    KEY_o,
    KEY_p,
    KEY_q,
    KEY_r,
    KEY_s,
    KEY_t,
    KEY_u,
    KEY_v,
    KEY_w,
    KEY_x,
    KEY_y,
    KEY_z,

    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z
};

class KeyEvent: public Ktk::Event
{
    public:
        /** Default constructor */
        KeyEvent();
        /** Default destructor */
        virtual ~KeyEvent();

        int mousePositionX;
        int mousePositionY;
        int Key;
        std::string key;
        char ckey;

    protected:
    private:
};

} // Ktk namespace

#endif // KEYEVENT_H
