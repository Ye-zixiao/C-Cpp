#ifndef FUZHU2_H_INCLUDED
#define FUZHU2_H_INCLUDED

#define metric 0
#define US 1
#define PRE_MODE 2

void check_mode(int *mode);
void get_info(int mode,double *distance,double *fuel);
void show_info(int mode,double disatance,double fuel);

#endif // FUZHU2_H_INCLUDED
