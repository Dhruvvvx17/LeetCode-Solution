class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        curr = self.root
        for ch in word:
            if ch not in curr.children:
                curr.children[ch] = TrieNode()
            curr = curr.children[ch]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self.root
        found = True

        for ch in word:
            if ch not in curr.children:
                found = False
                break
            else:
                curr = curr.children[ch]

        if not found or not curr.end:
            return False
        
        return True


    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        found = True

        for ch in prefix:
            if ch not in curr.children:
                found = False
                break
            else:
                curr = curr.children[ch]
        
        if not found:
            return False
        
        return True

if __name__ == "__main__":

    obj = Trie()
    obj.insert("apple")
    print(obj.search("apple"))
    print(obj.startsWith("app"))