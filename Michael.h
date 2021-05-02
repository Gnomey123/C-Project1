/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
void CJPI();
void BJPI();
void CLEAR();
void PEEK();
void POP();
void PUSH();
void CWB();
void CWF();
void CWR();
void CWL();
void MOVE_R();
void MOVE_L();
void MOVE_B();
void MOVE_F();
void MARK();

int pos_r;  //  position value
int pos_c;
int mem_x;  //  positions of the memory when called
int mem_y;
int energy;
int itchUp;     //  (0: no itch, >0: itch w/ spaces avalible) itch for open space above
int itchDown;   //  (0: no itch, >0: itch w/ spaces avalible) itch for open space downward
int itchLeft;   //  (0: no itch, >0: itch w/ spaces avalible) itch for open space to the left
int itchRight;
