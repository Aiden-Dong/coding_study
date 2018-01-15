# write mode
fout = open("./test.txt","w");
fout.write("hello ");
fout.write("world");
fout.close();

# read mode

fin = open("./test.txt", "r");
print fin.read();
fin.close();
