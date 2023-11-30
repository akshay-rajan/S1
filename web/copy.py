import shutil
import os

def copy_files(source, destination):
    try:
        if os.path.exists(destination_folder):
            shutil.rmtree(destination_folder)

        shutil.copytree(source_folder, destination_folder)

        print("Files copied successfully.")
    except Exception as e:
        print(f"An error occurred: {e}")


choice = int(input("Enter 1 for '/home/superuser1/Desktop/Programs/git/S1/web/' -> '/var/www/html/web/'\nEnter 2 for '/home/exam1/Desktop/git/S1' to '/var/www/html/web/': "))
if choice == 1:
    source_folder = "/home/superuser1/Desktop/Programs/git/S1/web/"
else:
    source_folder = "/home/exam1/Desktop/git/S1/web/"
destination_folder = "/var/www/html/web/"

copy_files(source_folder, destination_folder)
