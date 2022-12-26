#include "inter_wipe.h"

//获取进度条
extern int num_files;
extern int num_progress_now;
extern int num_progress_end;

inter_wipe::inter_wipe()
{
//    //获取进度条
//    this->v_progress_files = &num_files;
//    this->v_progress_now = &num_progress_now;
//    this->v_progress_end = &num_progress_end;
}

void inter_wipe::show_progress(int &files,int &now,int &end)
{
    files = num_files;
    now = num_progress_now;
    end = num_progress_end;
}

int inter_wipe::open_work(vector<string> vec)
{
    int ret = -1;
    is_runing = true;

    if(vec.empty() == false)
    {
        char *argv[vec.size()];
        for(int i=0;i<(int)vec.size();i++)
        {
            argv[i] = (char *)vec[i].c_str();//const_cast<char *>(vec[i].c_str());
        }

        ret = main_in(vec.size(),argv);
        if(func_finish) func_finish(ret);
    }

    is_runing = false;
    return ret;
}
