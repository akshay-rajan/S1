import os
import shutil

def copy_files(source, destination):
    """Copy or replace files from one folder to another"""

    try:
        if os.path.exists(destination_folder):
            shutil.rmtree(destination_folder)

        shutil.copytree(source_folder, destination_folder)

        print(f"Files copied successfully from {source_folder} to {destination_folder}.")
    except Exception as e:
        print(f"An error occurred: {e}")


choice = int(input("Enter 1 for Personal, 2 for College: "))
direction = int(input("Enter 1 to copy from 'web' to 'var', 2 to copy from 'var' to 'web'"))

if direction == 1:
    if choice == 1:
        source_folder = "/home/superuser1/Desktop/Programs/git/S1/web/"
    elif choice == 2:
        source_folder = "/home/exam1/Desktop/git/S1/web/"
    destination_folder = "/var/www/html/web/"
elif direction == 2:
    if choice == 1:
        destination_folder = "/home/superuser1/Desktop/Programs/git/S1/web/"
    elif choice == 2:
        destination_folder = "/home/exam1/Desktop/git/S1/web/"
    source_folder = "/var/www/html/web/"

copy_files(source_folder, destination_folder)
