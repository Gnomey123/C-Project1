// ant structure (values used by ant)
struct Ant {
    int pos_x;  //  position value
    int pos_y;
    int mem_x;  //  positions of the memory when called
    int mem_y;
    int energy;
    int itchUp;     //  boolean, specific itch for open space above
    int itchDown;   //  boolean, specific itch for open space downward
    int itchLeft;   //  boolean, specific itch for open space to the left
    int itchRight;  //  boolean, specific itch for open space to the right
} Michael;