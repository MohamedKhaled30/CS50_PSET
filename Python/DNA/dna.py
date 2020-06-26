from sys import exit, argv
import csv

# this function take a txt file and sequence i follow as an input and returning max count of it 


def get_max(s, sub):
    count = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i+len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                count[i] = 1
            else:
                count[i] = 1 + count[i + len(sub)]
    return max(count)
  
# this function take a csv file as an input beside counts and comparing it with every one in csv file 


def print_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match")

    
csv_path = argv[1]
txt_path = argv[2]

if len(argv) != 3:
    print("invalid usage dna.py file.csv file.txt")
    exit(1)

with open(csv_path) as csv_file:
    reader = csv.reader(csv_file) 
    all_seq = next(reader)[1:] 
        
    with open(txt_path)as txt_file:
        s = txt_file.read()
        actual = [get_max(s, seq) for seq in all_seq]
        
    print_match(reader, actual)

exit(0)    
