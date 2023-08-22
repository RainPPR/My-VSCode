import os

def convert_line_endings():
    # Get the current directory
    current_dir = os.getcwd()

    # Loop through all the files in the current directory
    for file_name in os.listdir(current_dir):
        # Check if the file is a .in or .out file
        if file_name.endswith(".in") or file_name.endswith(".out"):
            # Open the file in binary mode
            with open(file_name, "rb") as file:
                # Read the contents of the file
                contents = file.read()

            # Replace CRLF line endings with LF line endings
            contents = contents.replace(b"\r\n", b"\n")

            # Open the file again in binary mode and write the modified contents
            with open(file_name, "wb") as file:
                file.write(contents)

# Call the function to convert line endings
convert_line_endings()