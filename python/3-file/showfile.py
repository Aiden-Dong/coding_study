import os;

dirName="/home/saligia/python"

for cFile in os.listdir(dirName):

    chPath=os.path.join(dirName,cFile);

    if os.path.isdir(chPath):
        print("D : " + cFile);
    else:
        print("F : " + cFile + " : " + str(os.path.getsize(chPath)));
