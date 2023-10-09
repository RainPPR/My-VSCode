import os
def convert_line_endings():
    current_dir = os.getcwd()
    for file_name in os.listdir(current_dir):
        if file_name.endswith(".in") or file_name.endswith(".out") or file_name.endswith(".ans"):
            with open(file_name, "rb") as file:
                contents = file.read()
            contents = contents.replace(b"\r\n", b"\n")
            with open(file_name, "wb") as file:
                file.write(contents)
convert_line_endings()