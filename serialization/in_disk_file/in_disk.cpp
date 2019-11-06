#include <iostream>
#include <fstream>
#include <csignal>

using namespace std;
bool this_end{false};
const static size_t num_entries = 1<<8;

struct br_data{
    uint32_t log_inst;
    uint16_t br_operstate;
    uint64_t rx_err;
    uint64_t rx_bytes;
    uint64_t tx_bytes;
    uint16_t if0_state;
    uint16_t if1_state;
    uint16_t if0_learn;
    uint16_t if1_learn;
    uint16_t if0_cfg_pend;
    uint16_t if1_cfg_pend;
    uint8_t  br_fwd[8*10]; // store 8 devices
}__attribute__((__pack__));

struct main_data{
    uint32_t boot_count;
    uint32_t buffer_offset;
    struct br_data entries[num_entries];
}__attribute__((__pack__));

main_data log_struct;
struct file_log{
    fstream log;
    string fname;
    main_data& data;
    explicit file_log(string _fname, main_data& dta): fname(_fname), data(dta){
        cout << "init obj\n";
    }
    ~file_log(){
        save();
        cout << "end log and store\n";
    }
    bool file_exists();
    bool create_file();
    bool restore();
    bool save();
};

bool file_log::create_file(){
    log.open(fname, fstream::out|fstream::trunc);
    for (size_t i = 0; i < 100; i++){
        log.put('\0');
    }
    bool state = log.good() && log.is_open();
    log.close();
    return state;
}

bool file_log::file_exists(){
    log.open(fname, fstream::in);
    if(!log.good()){
        cerr << "Error opening the file, tying to create it\n";
        create_file();
    }
    log.close();
    return true;
}

bool file_log::restore(){
    file_exists();
    log.open(fname, fstream::in);
    char* cprt = reinterpret_cast<char*>(&data);
    log.read(cprt, sizeof(main_data));
    log.close();
    return true;
}

bool file_log::save(){
    log.open(fname, fstream::out);
    char* cprt = reinterpret_cast<char*>(&data);
    log.write(cprt, sizeof(main_data));
    log.close();
    return true;
}

void handle_signal(int sig){
    if(sig == SIGINT){
        cout << "catched ctrl c\n";
        this_end = true;
    }
}

int main(int argc, char** argv){
    signal(SIGINT, handle_signal);
    cout << "argc : " << argc << '\n';
    if(argc >= 2){
        cout << argv[1];
    }
    file_log flog(argv[1], log_struct);
    flog.restore();
    cout << "boot count: " << log_struct.boot_count++ << '\n';
    flog.save();
    // read and restore the log
//    while(!this_end){

//    }
    return 0;
}