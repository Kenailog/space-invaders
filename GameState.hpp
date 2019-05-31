#ifndef GameState_H
#define GameState_H

class GameState {
    public:
     enum State { INTRO, MENU, GAME, EXIT };
     State state;
     void set_state(State new_state);
};

#endif