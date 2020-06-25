from cs50 import get_string

letter = 0 
word = 0 
sentence = 0

text = get_string("Text: ")
counter = len(text)
for i in range(counter):
    if (text[i].isalpha()):
        letter += 1
    
    if ((text[i].isalpha()) and (not (text[i + 1].isalpha()))):
        if (text[i + 1] != '-'):
            if (text[i + 1] != '\''):
                word += 1
                
    if (text[i] == '?' or text[i] == '!' or text[i] == '.'):
        sentence += 1
        

L = (letter * 100) / word
S = (sentence * 100) / word
index = round(0.0588 * L - 0.296 * S - 15.8)
    
    
if index < 1:
    print("Before Grade 1")
        
    
elif index >= 16:
    print("Grade 16+")
    
    
else:
    print(f"Grade:  {index}")
