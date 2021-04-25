// ant structure (values used by ant)
struct Ant {
    int pos_x;  //  position value
    int pos_y;
    int mem_x;  //  positions of the memory when called
    int mem_y;
    int energy;
    int itchUp;     //  (0: no itch, >0: itch w/ spaces avalible) itch for open space above
    int itchDown;   //  (0: no itch, >0: itch w/ spaces avalible) itch for open space downward
    int itchLeft;   //  (0: no itch, >0: itch w/ spaces avalible) itch for open space to the left
    int itchRight;  //  (0: no itch, >0: itch w/ spaces avalible) itch for open space to the right
} Michael;