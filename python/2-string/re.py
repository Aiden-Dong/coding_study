import re;

jobPattern = re.compile(r"\s*<h2>(.*)</h2>\s*");
divPattern = re.compile(r".*div.*list_item_top.*");
divNomal = re.compile(r".*<div.*");
stopPattern = re.compile(r".*</div>.*");
joblink=re.compile(".*<a.*position_link.*?href=\"//(.*?)\".*");
dataPattern = re.compile(".*format-time.*>(.*)<.*");
moneyPattern = re.compile(".*money.*>(.*)<.*")


divDepth = 0;

result = "";

for lineStr in open("index.html", "r"):

    divMatch = divPattern.match(lineStr);
    nomalMatch = divNomal.match(lineStr);
    stopMatch = stopPattern.match(lineStr);
    jobMatch = jobPattern.match(lineStr);
    linkMatch = joblink.match(lineStr);
    dateMatch = dataPattern.match(lineStr);
    moneyMatch = moneyPattern.match(lineStr);

    if (divMatch):
        divDepth = divDepth+1;
    elif (nomalMatch and divDepth > 0):
        divDepth =divDepth +1;



    if(divDepth > 0):
        if(stopMatch):
            divDepth = divDepth -1;
            if(divDepth == 0):
                print result;
                result = "";
        if(jobMatch):
            result = jobMatch.group(1) + "\t" + result ;

        if(linkMatch):
            result = result + linkMatch.group(1)+" \t";

        if(dateMatch):
            result = result + dateMatch.group(1) + "\t";
        if(moneyMatch):
            result = result + moneyMatch.group(1);

print "end";
