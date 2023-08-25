''' TRICKY QUESTION '''

def findSubstring(s, words):
    
    # If list is empty, no match is found, return empty string
    if(len(words)==0):
        return []
    
    number_of_words = len(words)
    word_len = len(words[0])
    text_len = len(s)
    res = []

    # CREATE A MAP OF ALL WORDS. WORD:COUNT
    word_map = {}
    for word in words:
        if word in word_map:
            word_map[word] += 1
        else:
            word_map[word] = 1
    
    # OUTER LOOP FOR SETTING A START INDEX (B/W 0 to word_len)
    for i in range(0,word_len):
        count = 0
        match_dict = {}     # Substrings that match a word in words list
        start_index = i

        # INNER LOOP to check ever n characters togthers, n defined by word_len            
        for j in range(start_index, text_len - word_len + 1, word_len):
            curr_word = s[j:j+word_len]
            
            # VALID WORD FOUND
            if curr_word in words:
                
                # INCR COUNT
                count += 1
                
                # ADD WORD:COUNT TO TEMPORARY DICTIONARY
                if curr_word in match_dict:
                    match_dict[curr_word] += 1
                else:
                    match_dict[curr_word] = 1
                
                # INCASE TEMP DICTIONARY HAS A WORD OCCURING MORE THAN THE AVAILABLE NO OF TIMES
                # INCR THE START INDEX, TO IGNORE THE LEFT MOST OCCURING WORD
                # BECAUSE THAT CANNOT BE A PART OF ANY SUBSTRING
                while(match_dict[curr_word]>word_map[curr_word]):
                    match_dict[ s[start_index:start_index + word_len]] -= 1
                    start_index += word_len
                    count -= 1
                
                if(count==number_of_words):
                    res.append(start_index)
                    
            # INVALID WORD FOUND
            else:
                start_index = j + word_len
                count = 0
                match_dict = {}
    
    return res


if __name__ == "__main__":
    print("Enter text string: ",end="")
    s = input()

    print("Enter number of substrings: ",end="")
    n = int(input())
    
    print("Enter substring size: ",end="")
    substring_size = int(input())

    words = []
    for i in range(n):
        print(f"Enter substring {i} of len {substring_size}: ",end="")
        w = input()
        words.append(w)

    res = findSubstring(s,words)
    print(f"Indices at which the concatenation of all the words {words} are found are: ",res)
