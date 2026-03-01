from pymongo import MongoClient

uri = "mongodb+srv://kajal:kajal123@cluster0.ekvuyix.mongodb.net/"
client = MongoClient(uri)

db = client.toDo
collection = db.tasks

def createtask(desc) : 
    task = {"task" : desc}
    result = collection.insert_one(task)
    print(f"Task created with {result.inserted_id}")


def readtasks():
    tasks = collection.find()
    for docs in tasks : 
        print(f"{docs["task"]}")


while True : 
    print(f"Create Task")
    print(f"Read Tasks")
    print(f"Exit")

    choice = input(f"\nEnter your choice :")
    if choice == "1":
        description = input("Enter your description :")
        createtask(description)
    if choice=="2":
        readtasks()
    if choice=="3":
        break