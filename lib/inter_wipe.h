#ifndef INTER_WIPE_H
#define INTER_WIPE_H

#include <iostream>
#include <vector>
#include <thread>
#include <functional>

//#include <time.h>
#include <unistd.h>

#include "wipe/wipe.h"

using namespace std;

class inter_wipe
{
public:
    inter_wipe();
    void show_progress(int &files,int &now,int &end);
    int open_work(vector<string> vec);

    function<void(int)> func_finish = nullptr;

protected:
    bool is_runing = false;
//    int* v_progress_files;
//    int* v_progress_now;
//    int* v_progress_end;

};

#endif // INTER_WIPE_H
