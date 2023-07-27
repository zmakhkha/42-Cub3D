import os
import subprocess

# Install c_formatter_42
subprocess.run(["pip", "install", "c_formatter_42"])

# Needs the c_formatter_42 to be installed

def get_c_files(directory):
    c_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".c") or file.endswith(".h"):
                c_files.append(os.path.join(root, file))
    return c_files

def execute_script_on_file(file):
    subprocess.run(["c_formatter_42", file])

directory_path = "headers"
# directory_path_ = "src"

c_files = get_c_files(directory_path)
# c_files_ = get_c_files(directory_path_)

for file in (c_files + c_files_):
    execute_script_on_file(file)
