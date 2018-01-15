fin=open('./index', 'r');
strlen=fin.readline();

obj = eval(strlen);
inpathLine='';
conf=obj["conf"];
property = conf["property"];

for it in property:
	if it["name"] == 'mapreduce.input.fileinputformat.inputdir':
		inpathLine = it['value'];
inpath = inpathLine.split(',',-1);

for it in inpath:
	print it;
