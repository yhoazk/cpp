
import json
import sys
import os

hdr_tmplt = "constexpt instance_id = {}"
src_tmplt = '''include "gen_lib/adder.h"\
            int {}(int a, int b){\
                return a+b;
            }'''
cfg_tmplt = '{ "instance_id": {} }'



def parse(cfg_file):
    with open(cfg_file, "r") as f_json:
        return json.load(f_json)


def create_folder_struct():
    os.mkdir("gen_src")
    os.mkdir("gen_lib")
    os.mkdir("gen_cfg")

def generate(cfg):
    create_folder_struct()
    app_name = cfg["app"]
    key  = cfg["key"]
    iid = cfg["instance_id"]
    src = open("gen_src/{}.cpp".format(app_name), "wb")
    hrd = open("gen_lib/{}.h".format(app_name), "wb")
    out_cfg = open("gen_src/{}.json".format(app_name), "wb")

    src.write(src_tmplt.format(app_name))
    hrd.write(hdr_tmplt.format(key))
    out_cfg.write(cfg_tmplt.format(iid))

    src.close()
    hrd.close()
    out_cfg.close()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("No cfg file given", file=sys.stderr)
        exit(1)
    generate(parse(sys.argv[1]))        